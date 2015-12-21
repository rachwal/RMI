// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef ZEROC_ICE_EXAMPLE_ZEROC_ICE_MESSAGE_ZEROC_ICE_REMOTE_MESSAGE_H_
#define ZEROC_ICE_EXAMPLE_ZEROC_ICE_MESSAGE_ZEROC_ICE_REMOTE_MESSAGE_H_

#include <message/message.h>

#include <zeroc_ice/message.h>

#include <Ice/Ice.h>

namespace zeroc_example
{
namespace zeroc
{
class ZerocIceRemoteMessage :public rmi::message::Message
{
	public:
	explicit ZerocIceRemoteMessage(const std::string& id, IceInternal::ProxyHandle<IceProxy::zerocexample::MessageIce> proxy_handle);

	virtual std::string content() const override;
	virtual void content(const std::string& text) override;

	std::string id() const override;

	private:
	std::string content_;
	std::string id_;

	IceInternal::ProxyHandle<IceProxy::zerocexample::MessageIce> proxy_handle_;
};
}
}

#endif

