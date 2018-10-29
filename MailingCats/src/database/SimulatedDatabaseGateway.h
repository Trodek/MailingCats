#pragma once

#include "IDatabaseGateway.h"
#include <vector>

class SimulatedDatabaseGateway :
	public IDatabaseGateway
{
public:

	// Constructor and destructor

	SimulatedDatabaseGateway();

	~SimulatedDatabaseGateway();


	// Virtual methods from IDatabaseGateway

	void insertMessage(const Message &message) override;

	std::vector<Message> getAllMessagesReceivedByUser(const std::string &username) override;

	void MessageOpened(int msg_id) override;

	void DeleteMessage(int msg_id) override;

	void RemoveMessage(int msg_id) override;

private:

	std::vector<Message> allMessages;
	int msg_id = 0;
};
