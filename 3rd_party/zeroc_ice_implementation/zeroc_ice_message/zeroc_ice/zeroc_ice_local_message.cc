// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "zeroc_ice_local_message.h"

namespace zeroc_example
{
namespace zeroc
{
ZerocIceLocalMessage::ZerocIceLocalMessage(std::string id) : id_(id) {}

std::string ZerocIceLocalMessage::content() const
{
	return content_;
}

void ZerocIceLocalMessage::content(const std::string& text)
{
	content_ = text;
}

std::string ZerocIceLocalMessage::id() const
{
	return id_;
}

std::string ZerocIceLocalMessage::getContent(const ::Ice::Current&)
{
	return content();
}

void ZerocIceLocalMessage::setContent(const std::string& text, const ::Ice::Current&)
{
	content(text);
}
}
}

