// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMNI_ORB_EXAMPLE_ABSTRACTION_MESSAGE_SERVICE_MESSAGE_SERVICE_H_
#define OMNI_ORB_EXAMPLE_ABSTRACTION_MESSAGE_SERVICE_MESSAGE_SERVICE_H_

#include "../../message/message/message.h"

namespace rmi
{
namespace message
{
class MessageService
{
	public:
	virtual ~MessageService() { }

	virtual Message *Create(const std::string& id) const = 0;
	virtual Message *Retrieve(const std::string& id) const = 0;
	virtual void Update(const std::string& id, Message* message) const = 0;
	virtual void Destroy(const std::string& id) const = 0;
};
}
}

#endif

