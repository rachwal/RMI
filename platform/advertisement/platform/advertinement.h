// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef PLATFORM_ADVERTISEMENT_ADVERTISEMENT_H_
#define PLATFORM_ADVERTISEMENT_ADVERTISEMENT_H_

#include <message/message.h>

namespace rmi
{
namespace platform
{
class Advertisement
{
	public:
	Advertisement(message::Message* brand, message::Message* product);

	std::string Broadcast() const;

	private:
	message::Message* brand_message_;
	message::Message* product_message_;
};
}
}

#endif

