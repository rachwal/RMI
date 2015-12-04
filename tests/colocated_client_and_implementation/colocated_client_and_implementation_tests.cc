// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "CppUnitTest.h"

#include <omniORB4/CORBA.h>

#include <omni_orb/omni_orb_message_service.h>
#include <zeroc_ice/zeroc_ice_message_service.h>

#include <platform/advertinement.h>

namespace colocated_client_and_implementation_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace rmi::message;
using namespace omniorb_example::omniorb;

TEST_CLASS(ColocatedClientAndImplementationTests)
{
	TEST_CLASS_INITIALIZE(ClassInitialize)
	{
		InitializeIce();
		InitializeOrb();

		Logger::WriteMessage("Initialise the ORB.");
	}

	TEST_CLASS_CLEANUP(ClassCleanup)
	{
		adapter_->destroy();
		orb_->destroy();

		Logger::WriteMessage("Clean up all the resources.");
	}

	TEST_METHOD(ShouldExchangeIformatinoBetweenLocalAndRemoteMessagesByMessageServiceOverOmniOrb)
	{
		//GIVEN
		std::string expected_first_content_check = "first message";
		std::string expected_second_context_check = "second message";

		auto omni_orb_message_service = new OmniOrbMessageService(&orb_);
		omni_orb_message_service->Activate();
		omni_orb_message_service->SetContext("test", "example");

		MessageService* message_service = omni_orb_message_service;

		//WHEN		
		Message* local_message = message_service->Create("message_01");
		local_message->content("first message");

		Message* remote_message = message_service->Retrieve("message_01");
		auto first_content_check = remote_message->content();

		remote_message->content("second message");
		auto second_context_check = local_message->content();

		//THEN
		Assert::AreEqual(expected_first_content_check, first_content_check);
		Assert::AreEqual(expected_second_context_check, second_context_check);

		delete omni_orb_message_service;
	}

	TEST_METHOD(ShouldExchangeIformatinoBetweenLocalAndRemoteMessagesByMessageServiceOverZerocIce)
	{
		//GIVEN
		std::string expected_first_content_check = "first message";
		std::string expected_second_context_check = "second message";

		MessageService* message_service = new zeroc_example::zeroc::ZerocIceMessageService(&adapter_);

		//WHEN		
		Message* local_message = message_service->Create("message_01");
		local_message->content("first message");

		Message* remote_message = message_service->Retrieve("message_01");
		auto first_content_check = remote_message->content();

		remote_message->content("second message");
		auto second_context_check = local_message->content();

		//THEN
		Assert::AreEqual(expected_first_content_check, first_content_check);
		Assert::AreEqual(expected_second_context_check, second_context_check);

		delete message_service;
	}

	TEST_METHOD(ShouldCreateAdvertisementBroadcastBasedOnInformationFromTwoDifferent3rdPartyLibraries)
	{
		//GIVEN
		std::string expected_advertisement_broadcast = "<AIST|OpenRTM>";
		auto omni_orb_message_service = new OmniOrbMessageService(&orb_);
		omni_orb_message_service->Activate();
		omni_orb_message_service->SetContext("test", "example");

		auto zeroc_ice_message_service = new zeroc_example::zeroc::ZerocIceMessageService(&adapter_);

		//WHEN		
		auto brand_message = omni_orb_message_service->Create("brand_01");
		brand_message->content("AIST");

		auto product_message = zeroc_ice_message_service->Create("procudt_01");
		product_message->content("OpenRTM");

		auto advertisement = new rmi::platform::Advertisement(brand_message, product_message);
		auto broadcast = advertisement->Broadcast();

		//THEN
		Assert::AreEqual(expected_advertisement_broadcast, broadcast);

		delete omni_orb_message_service;
		delete zeroc_ice_message_service;
		delete advertisement;
	}

	private:
	static void InitializeOrb()
	{
		auto argc = 2;
		char* argv[] = {"-ORBInitRef", "NameService=corbaloc:iiop:localhost:2809/NameService"};

		orb_ = CORBA::ORB_init(argc, argv);
		CORBA::Object_var obj = orb_->resolve_initial_references("RootPOA");
		auto poa = PortableServer::POA::_narrow(obj);

		PortableServer::POAManager_var poa_manager = poa->the_POAManager();
		poa_manager->activate();
	};

	static void InitializeIce()
	{
		auto argc = 0;
		char* argv[] = {""};

		Ice::InitializationData initData;
		initData.properties = Ice::createProperties();
		initData.properties->setProperty("MessageIce.Endpoints", "tcp -p 10000:udp -p 10001:ws -p 10003");
		initData.properties->setProperty("Ice.Default.Host", "localhost");
		initData.properties->setProperty("Ice.Warn.Connections", "1");
		initData.properties->setProperty("Ice.Admin.InstanceName", "server");
		initData.properties->setProperty("IceMX.Metrics.Debug.GroupBy", "id");
		initData.properties->setProperty("IceMX.Metrics.ByParent.GroupBy", "parent");

		auto communicator = initialize(argc, argv, initData);
		adapter_ = communicator->createObjectAdapter("MessageIce");
		adapter_->activate();
	}

	static Ice::ObjectAdapterPtr adapter_;
	static CORBA::ORB_var orb_;
};

Ice::ObjectAdapterPtr ColocatedClientAndImplementationTests::adapter_;
CORBA::ORB_var ColocatedClientAndImplementationTests::orb_;
}

