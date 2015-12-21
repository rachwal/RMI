// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "omni_orb_local_message.h"

namespace omniorb_example
{
namespace omniorb
{
OmniOrbLocalMessage::OmniOrbLocalMessage(const std::string& id, CORBA::ORB_var* orb) : orb_(orb), id_(id) { }

std::string OmniOrbLocalMessage::content() const
{
	return content_;
}

void OmniOrbLocalMessage::content(const std::string& text)
{
	content_ = text;
}

std::string OmniOrbLocalMessage::id() const
{
	return id_;
}

MessageIdl_ptr OmniOrbLocalMessage::getRef()
{
	CORBA::Object_var obj = (*orb_)->resolve_initial_references("RootPOA");
	PortableServer::POA_var poa = PortableServer::POA::_narrow(obj);
	PortableServer::ObjectId_var myechoid = poa->activate_object(this);

	auto ref = this->_this();
	return ref;
}

char *OmniOrbLocalMessage::getContent()
{
	return CORBA::string_dup(content_.c_str());
}

void OmniOrbLocalMessage::setContent(const char* text)
{
	content_ = text;
}
}
}

