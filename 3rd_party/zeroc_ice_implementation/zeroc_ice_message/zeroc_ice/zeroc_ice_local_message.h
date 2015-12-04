// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef ZEROC_ICE_EXAMPLE_ZEROC_ICE_MESSAGE_ZEROC_ICE_LOCAL_MESSAGE_H_
#define ZEROC_ICE_EXAMPLE_ZEROC_ICE_MESSAGE_ZEROC_ICE_LOCAL_MESSAGE_H_

#include <zeroc_ice/message.h>

#include <message/message.h>

#include <Ice/Ice.h>

namespace zeroc_example
{
	namespace zeroc
	{
		class ZerocIceLocalMessage :public rmi::message::Message, public zerocexample::MessageIce
		{
		public:
			explicit ZerocIceLocalMessage(std::string id);

			virtual std::string content() const override;
			virtual void content(const std::string& text) override;

			std::string id() const override;

			std::string getContent(const ::Ice::Current&) override;
			void setContent(const ::std::string&, const ::Ice::Current&) override;

		private:
			std::string content_;
			std::string id_;
		};
	}
}

#endif

