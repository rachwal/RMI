// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMNI_ORB_EXAMPLE_OMNI_ORB_MESSAGE_SERVICE_OMNI_ORB_MESSAGE_SERVICE_H_
#define OMNI_ORB_EXAMPLE_OMNI_ORB_MESSAGE_SERVICE_OMNI_ORB_MESSAGE_SERVICE_H_

#include <omni_orb/omni_orb_local_message.h>
#include <omni_orb/omni_orb_remote_message.h>

#include <message/message_service.h>

#include <omniORB4/CORBA.h>

namespace omniorb_example
{
namespace omniorb
{
class OmniOrbMessageService :public message::MessageService
{
	public:
	explicit OmniOrbMessageService(CORBA::ORB_var* orb);

	virtual OmniOrbLocalMessage *Create(std::string id) const override;
	virtual OmniOrbRemoteMessage *Retrieve(std::string id) const override;
	virtual void Update(std::string id, message::Message* message) const override;
	virtual void Destroy(std::string id) const override;

	void SetContext(std::string id, std::string kind);
	bool Activate();

	private:
	CORBA::ORB_var* orb_;
	CosNaming::NamingContext_var root_context_;
	CosNaming::Name context_name_;
};
}
}

#endif

