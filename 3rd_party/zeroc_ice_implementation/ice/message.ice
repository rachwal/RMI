#pragma once

module zerocexample
{

interface MessageIce
{
	idempotent string getContent();
	void setContent(string text);
};

};

