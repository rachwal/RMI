// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "zeroc_ice_message_service.h"

#include <zeroc_ice/zeroc_ice_local_message.h>
#include <zeroc_ice/zeroc_ice_remote_message.h>

namespace zeroc_example
{
namespace zeroc
{
ZerocIceMessageService::ZerocIceMessageService(Ice::ObjectAdapterPtr* adapter) : adapter_(adapter) {}

rmi::message::Message *ZerocIceMessageService::Create(const std::string& id) const
{
	zerocexample::MessageIcePtr local_message_ptr = new ZerocIceLocalMessage(id);

	(*adapter_)->add(local_message_ptr, (*adapter_)->getCommunicator()->stringToIdentity(id));

	auto message = Retrieve(id);
	return message;
}

rmi::message::Message *ZerocIceMessageService::Retrieve(const std::string& id) const
{
	std::ostringstream proxy;
	proxy << id << ":tcp -p 10000:udp -p 10001";
	(*adapter_)->getCommunicator()->getProperties()->setProperty("MessageIce.Proxy", proxy.str());

	auto handle = zerocexample::MessageIcePrx::checkedCast((*adapter_)->getCommunicator()->propertyToProxy("MessageIce.Proxy")->ice_twoway()->ice_secure(false));
	auto message = new ZerocIceRemoteMessage(id, handle);
	return message;
}

void ZerocIceMessageService::Update(const std::string& id, rmi::message::Message* message) const {}

void ZerocIceMessageService::Destroy(const std::string& id) const {}
}
}

