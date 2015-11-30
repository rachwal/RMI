// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMNI_ORB_EXAMPLE_OMNI_ORB_MESSAGE_OMNI_ORB_LOCAL_MESSAGE_H_
#define OMNI_ORB_EXAMPLE_OMNI_ORB_MESSAGE_OMNI_ORB_LOCAL_MESSAGE_H_

#include <message/message.h>

#include <omni_orb/message.hh>

namespace omniorb_example
{
namespace omniorb
{
class OmniOrbLocalMessage :public message::Message, public POA_MessageIdl, public PortableServer::RefCountServantBase
{
	public:
	OmniOrbLocalMessage(std::string id, CORBA::ORB_var* orb);

	virtual std::string content() const override;
	virtual void content(const std::string& text) override;

	std::string id() const override;

	MessageIdl_ptr getRef();

	char *getContent() override;
	void setContent(const char* text) override;

	private:
	std::string content_;

	CORBA::ORB_var* orb_;
	std::string id_;
};
}
}

#endif

