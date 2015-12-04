// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMNI_ORB_EXAMPLE_ABSTRACTION_MESSAGE_MESSAGE_H_
#define OMNI_ORB_EXAMPLE_ABSTRACTION_MESSAGE_MESSAGE_H_

#include <string>

namespace rmi
{
namespace message
{
class Message
{
	public:
	virtual ~Message() { }

	virtual std::string content() const = 0;
	virtual void content(const std::string& text) = 0;

	virtual std::string id() const = 0;
};
}
}

#endif

