#pragma once

#include "IDatabaseGateway.h"

class MySqlDatabaseGateway :
	public IDatabaseGateway
{
public:

	// Constructor and destructor

	MySqlDatabaseGateway();

	~MySqlDatabaseGateway();


	// Virtual methods from IDatabaseGateway

	void insertMessage(const Message &message) override;

	std::vector<Message> getAllMessagesReceivedByUser(const std::string &username) override;

	virtual void updateGUI() override;

private:

	// Text buffers for ImGUI
	char bufMySqlHost[64] = "localhost";
	char bufMySqlPort[64] = "3306";
	char bufMySqlDatabase[64] = "losmagos";
	char bufMySqlTable[64] = "messages";
	char bufMySqlUsername[64] = "root";
	char bufMySqlPassword[64] = "";
};

inline void Escape(std::string& str, const char c = '\'')
{
	size_t pos = str.find(c);
	while (pos != std::string::npos) 
	{
		str.insert(pos, "\\");
		pos = str.find(c);
	}
}
