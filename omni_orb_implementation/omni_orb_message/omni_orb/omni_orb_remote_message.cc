// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "omni_orb_remote_message.h"

namespace omniorb_example
{
namespace omniorb
{
OmniOrbRemoteMessage::OmniOrbRemoteMessage(std::string id, CORBA::ORB_var* orb) : message_idl_ptr_(nullptr), orb_(orb), id_(id) { }

std::string OmniOrbRemoteMessage::content() const
{
	return message_idl_ptr_->getContent();
}

void OmniOrbRemoteMessage::content(const std::string& text)
{
	message_idl_ptr_->setContent(text.c_str());
}

std::string OmniOrbRemoteMessage::id() const
{
	return id_;
}

void OmniOrbRemoteMessage::setRef(MessageIdl_ptr& ref)
{
	message_idl_ptr_ = ref;
}
}
}

