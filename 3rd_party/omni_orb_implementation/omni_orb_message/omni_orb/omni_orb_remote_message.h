// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMNI_ORB_EXAMPLE_OMNI_ORB_MESSAGE_OMNI_ORB_REMOTE_MESSAGE_H_
#define OMNI_ORB_EXAMPLE_OMNI_ORB_MESSAGE_OMNI_ORB_REMOTE_MESSAGE_H_

#include <message/message.h>

#include <omni_orb/message.hh>

namespace omniorb_example
{
namespace omniorb
{
class OmniOrbRemoteMessage :public rmi::message::Message
{
	public:
	OmniOrbRemoteMessage(std::string id, CORBA::ORB_var* orb);

	virtual std::string content() const override;
	virtual void content(const std::string& text) override;

	std::string id() const override;

	void setRef(MessageIdl_ptr& ref);

	private:
	MessageIdl_ptr message_idl_ptr_;

	CORBA::ORB_var* orb_;
	std::string id_;
};
}
}

#endif

