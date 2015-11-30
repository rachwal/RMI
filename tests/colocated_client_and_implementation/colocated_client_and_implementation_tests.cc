// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "CppUnitTest.h"

#include <omniORB4/CORBA.h>

#include <omni_orb/omni_orb_message_service.h>

namespace colocated_client_and_implementation_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace omniorb_example::message;
using namespace omniorb_example::omniorb;

TEST_CLASS(ColocatedClientAndImplementationTests)
{
	TEST_CLASS_INITIALIZE(ClassInitialize)
	{
		Logger::WriteMessage("Initialise the ORB.");

		auto argc = 2;
		char* argv[] = {"-ORBInitRef", "NameService=corbaloc:iiop:localhost:2809/NameService"};

		orb_ = CORBA::ORB_init(argc, argv);
		CORBA::Object_var obj = orb_->resolve_initial_references("RootPOA");
		auto poa = PortableServer::POA::_narrow(obj);

		PortableServer::POAManager_var poa_manager = poa->the_POAManager();
		poa_manager->activate();
	}

	TEST_CLASS_CLEANUP(ClassCleanup)
	{
		Logger::WriteMessage("Clean up all the resources.");
		orb_->destroy();
	}

	TEST_METHOD(RemoteMessageShouldSetLocalMessageContentByMessageService)
	{
		//GIVEN
		std::string expected_local_message_1_content = "alpha";
		std::string expected_local_message_2_content = "beta";
		std::string expected_local_message_3_content = "gamma";

		auto message_service = new OmniOrbMessageService(&orb_);
		message_service->Activate();
		message_service->SetContext("test", "example");

		Message* local_message_1 = message_service->Create("test01");
		Message* local_message_2 = message_service->Create("test02");
		Message* local_message_3 = message_service->Create("test03");

		Message* remote_message_1 = message_service->Retrieve("test01");
		Message* remote_message_2 = message_service->Retrieve("test02");
		Message* remote_message_3 = message_service->Retrieve("test03");

		//WHEN
		remote_message_1->content("alpha");
		remote_message_2->content("beta");
		remote_message_3->content("gamma");

		//THEN
		auto local_message_1_content = local_message_1->content();
		auto local_message_2_content = local_message_2->content();
		auto local_message_3_content = local_message_3->content();

		Assert::AreEqual(expected_local_message_1_content, local_message_1_content);
		Assert::AreEqual(expected_local_message_2_content, local_message_2_content);
		Assert::AreEqual(expected_local_message_3_content, local_message_3_content);
	}

	TEST_METHOD(ShouldExchangeIformatinoBetweenLocalAndRemoteMessagesByMessageService)
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
	}

	private:
	static CORBA::ORB_var orb_;
};

CORBA::ORB_var ColocatedClientAndImplementationTests::orb_;
}

