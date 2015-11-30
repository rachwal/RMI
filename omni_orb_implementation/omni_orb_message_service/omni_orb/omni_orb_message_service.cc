// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "omni_orb_message_service.h"

namespace omniorb_example
{
namespace omniorb
{
OmniOrbMessageService::OmniOrbMessageService(CORBA::ORB_var* orb) : orb_(orb) { }

OmniOrbLocalMessage *OmniOrbMessageService::Create(std::string id) const
{
	try
	{
		CORBA::Object_var context_ptr = root_context_->resolve(context_name_);
		auto context = CosNaming::NamingContext::_narrow(context_ptr);

		CosNaming::Name object_name;
		object_name.length(1);
		object_name[0].id = id.c_str();
		object_name[0].kind = "Object";

		auto message = new OmniOrbLocalMessage(id, orb_);
		auto message_ref = message->getRef();

		context->rebind(object_name, message_ref);

		return message;
	}
	catch (CORBA::SystemException&)
	{
		return nullptr;
	}
}

OmniOrbRemoteMessage *OmniOrbMessageService::Retrieve(std::string id) const
{
	CORBA::Object_var context_ptr = root_context_->resolve(context_name_);
	auto context = CosNaming::NamingContext::_narrow(context_ptr);

	CosNaming::Name object_name;
	object_name.length(1);
	object_name[0].id = id.c_str();
	object_name[0].kind = "Object";

	try
	{
		auto message_ptr = context->resolve(object_name);
		auto message_idl = MessageIdl::_narrow(message_ptr);
		auto message = new OmniOrbRemoteMessage(id, orb_);
		message->setRef(message_idl);
		return message;
	}
	catch (CORBA::SystemException&)
	{
		return nullptr;
	}
}

void OmniOrbMessageService::Update(std::string id, message::Message* message) const { }

void OmniOrbMessageService::Destroy(std::string id) const { }

void OmniOrbMessageService::SetContext(std::string id, std::string kind)
{
	context_name_ = CosNaming::Name();
	context_name_.length(1);
	context_name_[0].id = id.c_str();
	context_name_[0].kind = kind.c_str();

	try
	{
		root_context_->bind_new_context(context_name_);
	}
	catch (CosNaming::NamingContext::AlreadyBound&) { }
}

bool OmniOrbMessageService::Activate()
{
	CORBA::Object_var obj;
	obj = (*orb_)->resolve_initial_references("NameService");

	root_context_ = CosNaming::NamingContext::_narrow(obj);

	return is_nil(root_context_) ? false : true;
}
}
}

