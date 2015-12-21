// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "zeroc_ice_remote_message.h"

namespace zeroc_example
{
namespace zeroc
{
ZerocIceRemoteMessage::ZerocIceRemoteMessage(const std::string& id, IceInternal::ProxyHandle<IceProxy::zerocexample::MessageIce> proxy_handle)
	: id_(id), proxy_handle_(proxy_handle) {}

std::string ZerocIceRemoteMessage::content() const
{
	return proxy_handle_->getContent();
}

void ZerocIceRemoteMessage::content(const std::string& text)
{
	return proxy_handle_->setContent(text);
}

std::string ZerocIceRemoteMessage::id() const
{
	return id_;
}
}
}

