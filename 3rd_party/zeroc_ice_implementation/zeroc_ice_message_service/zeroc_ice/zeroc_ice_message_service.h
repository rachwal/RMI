// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef ZEROC_ICE_EXAMPLE_ZEROC_ICE_MESSAGE_SERVICE_ZEROC_ICE_MESSAGE_SERVICE_H_
#define ZEROC_ICE_EXAMPLE_ZEROC_ICE_MESSAGE_SERVICE_ZEROC_ICE_MESSAGE_SERVICE_H_

#include <message/message_service.h>

#include <Ice/Ice.h>

namespace zeroc_example
{
namespace zeroc
{
class ZerocIceMessageService :public rmi::message::MessageService
{
	public:
	explicit ZerocIceMessageService(Ice::ObjectAdapterPtr* communicator);

	virtual rmi::message::Message *Create(std::string id) const override;
	virtual rmi::message::Message *Retrieve(std::string id) const override;
	virtual void Update(std::string id, rmi::message::Message* message) const override;
	virtual void Destroy(std::string id) const override;

	private:
	Ice::ObjectAdapterPtr* adapter_;
};
}
}

#endif

