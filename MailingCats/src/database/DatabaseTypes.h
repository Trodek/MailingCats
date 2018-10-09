#pragma once

#include <string>
#include "../serialization/MemoryStream.h"

struct Message
{
	std::string senderUsername;
	std::string receiverUsername;
	std::string subject;
	std::string body;

	void Serialize(OutputMemoryStream &stream)
	{
		stream.Write(senderUsername);
		stream.Write(receiverUsername);
		stream.Write(subject);
		stream.Write(body);
	}
};
