#pragma once

#include <string>
#include "../serialization/MemoryStream.h"

struct Message
{
	int id;
	std::string senderUsername;
	std::string receiverUsername;
	std::string subject;
	std::string body;
	bool new_msg;
	bool deleted;

	void Serialize(OutputMemoryStream &stream)
	{
		stream.Write(id);
		stream.Write(senderUsername);
		stream.Write(receiverUsername);
		stream.Write(subject);
		stream.Write(body);
		stream.Write(new_msg);
		stream.Write(deleted);
	}
};
