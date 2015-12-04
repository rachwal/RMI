// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "advertinement.h"

#include <sstream>

namespace rmi
{
	namespace platform
	{
		Advertisement::Advertisement(message::Message* brand, message::Message* product) : brand_message_(brand), product_message_(product) {}

		std::string Advertisement::Broadcast() const
		{
			std::ostringstream broadcast;
			broadcast << "<" << brand_message_->content() << "|" << product_message_->content() << ">";
			return broadcast.str();
		}
	}
}
