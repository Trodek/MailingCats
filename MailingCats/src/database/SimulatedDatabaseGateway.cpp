#include "SimulatedDatabaseGateway.h"



SimulatedDatabaseGateway::SimulatedDatabaseGateway()
{
}


SimulatedDatabaseGateway::~SimulatedDatabaseGateway()
{
}

void SimulatedDatabaseGateway::insertMessage(const Message & message)
{
	Message msg = message;
	msg.id = msg_id++;
	msg.new_msg = true;
	msg.deleted = false;
	allMessages.push_back(msg);
}

std::vector<Message> SimulatedDatabaseGateway::getAllMessagesReceivedByUser(const std::string & username)
{
	std::vector<Message> messages;
	for (const auto & message : allMessages)
	{
		if (message.receiverUsername == username)
		{
			messages.push_back(message);
		}
	}
	return messages;
}

void SimulatedDatabaseGateway::MessageOpened(int msg_id)
{
	for (int m = 0; m < allMessages.size(); ++m)
	{
		if (allMessages[m].id == msg_id)
		{
			allMessages[m].new_msg = false;
			break;
		}
	}
}

void SimulatedDatabaseGateway::DeleteMessage(int msg_id)
{
	for (int m = 0; m < allMessages.size(); ++m)
	{
		if (allMessages[m].id == msg_id)
		{
			allMessages[m].deleted = true;
			break;
		}
	}
}

void SimulatedDatabaseGateway::RemoveMessage(int msg_id)
{
	for (std::vector<Message>::iterator it = allMessages.begin(); it != allMessages.end(); ++it) {
		if ((*it).id == msg_id)
		{
			allMessages.erase(it);
			break;
		}
	}
}
