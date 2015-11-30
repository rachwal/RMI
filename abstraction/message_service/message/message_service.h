// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMNI_ORB_EXAMPLE_ABSTRACTION_MESSAGE_SERVICE_MESSAGE_SERVICE_H_
#define OMNI_ORB_EXAMPLE_ABSTRACTION_MESSAGE_SERVICE_MESSAGE_SERVICE_H_

#include "../../message/message/message.h"

namespace omniorb_example
{
namespace message
{
class MessageService
{
	public:
	virtual ~MessageService() { }

	virtual Message *Create(std::string id) const = 0;
	virtual Message *Retrieve(std::string id) const = 0;
	virtual void Update(std::string id, Message* message) const = 0;
	virtual void Destroy(std::string id) const = 0;
};
}
}

#endif

