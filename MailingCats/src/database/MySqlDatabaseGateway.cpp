#include "MySqlDatabaseGateway.h"
#include "DBConnection.h"
#include "../imgui/imgui.h"
#include <cstdarg>
#include <string>

// You can use this function to create the SQL statements easily, works like the printf function
std::string stringFormat(const char *fmt, ...)
{
	// Find out the final string length
	va_list ap;
	va_start(ap, fmt);
	int size = vsnprintf(nullptr, 0, fmt, ap);
	va_end(ap);

	// Format the actual resulting string
	std::string resultString;
	resultString.resize(size + 1, '\0');
	va_start(ap, fmt);
	vsnprintf(&resultString[0], resultString.size(), fmt, ap);
	va_end(ap);

	return resultString;
}


MySqlDatabaseGateway::MySqlDatabaseGateway()
{
}


MySqlDatabaseGateway::~MySqlDatabaseGateway()
{
}

void MySqlDatabaseGateway::insertMessage(const Message & message)
{
	DBConnection db(bufMySqlHost, bufMySqlPort, bufMySqlDatabase, bufMySqlUsername, bufMySqlPassword);

	if (db.isConnected())
	{
		DBResultSet res;

		Message msg = message;
		Escape(msg.senderUsername);
		Escape(msg.receiverUsername);
		Escape(msg.subject);
		//Escape(msg.body);

		std::string sqlStatement;
		sqlStatement = "INSERT INTO messages(sender, receiver, subject, body) VALUES('" +
						msg.senderUsername + "', '" +
						msg.receiverUsername + "', '" +
						msg.subject + "', '" +
						msg.body + "')";

		// insert some messages
		db.sql(sqlStatement.c_str());
	}
}

std::vector<Message> MySqlDatabaseGateway::getAllMessagesReceivedByUser(const std::string & username)
{
	std::vector<Message> messages;

	DBConnection db(bufMySqlHost, bufMySqlPort, bufMySqlDatabase, bufMySqlUsername, bufMySqlPassword);

	if (db.isConnected())
	{
		std::string sqlStatement;
		// TODO: Create the SQL statement to query all messages from the given user (SELECT)
		sqlStatement = "SELECT * FROM messages WHERE receiver = '" + username + "';";

		// consult all messages
		DBResultSet res = db.sql(sqlStatement.c_str());

		// fill the array of messages
		for (auto & messageRow : res.rows)
		{
			Message message;
			message.id = atoi(messageRow.columns[0].c_str());
			message.senderUsername = messageRow.columns[1];
			message.receiverUsername = messageRow.columns[2];
			message.subject = messageRow.columns[3];
			message.body = messageRow.columns[4];
			message.new_msg = (messageRow.columns[6] == "1") ? true : false;
			message.deleted = (messageRow.columns[7] == "1") ? true : false;
			messages.push_back(message);
		}
	}


	return messages;
}

void MySqlDatabaseGateway::MessageOpened(int msg_id)
{
	DBConnection db(bufMySqlHost, bufMySqlPort, bufMySqlDatabase, bufMySqlUsername, bufMySqlPassword);

	if (db.isConnected())
	{
		std::string sqlStatement;
		sqlStatement = "UPDATE messages SET new = 0 WHERE message_id = " + std::to_string(msg_id) + ";";

		DBResultSet res = db.sql(sqlStatement.c_str());
	}

}

void MySqlDatabaseGateway::DeleteMessage(int msg_id)
{
	DBConnection db(bufMySqlHost, bufMySqlPort, bufMySqlDatabase, bufMySqlUsername, bufMySqlPassword);

	if (db.isConnected())
	{
		std::string sqlStatement;
		sqlStatement = "UPDATE messages SET deleted = 1 WHERE message_id = " + std::to_string(msg_id) + ";";

		DBResultSet res = db.sql(sqlStatement.c_str());
	}
}

void MySqlDatabaseGateway::RemoveMessage(int msg_id)
{
	DBConnection db(bufMySqlHost, bufMySqlPort, bufMySqlDatabase, bufMySqlUsername, bufMySqlPassword);

	if (db.isConnected())
	{
		std::string sqlStatement;
		sqlStatement = "DELETE FROM messages WHERE message_id = " + std::to_string(msg_id) + ";";

		DBResultSet res = db.sql(sqlStatement.c_str());
	}
}

void MySqlDatabaseGateway::updateGUI()
{
	ImGui::Separator();

	ImGui::Text("MySQL Server info");
	ImGui::InputText("Host", bufMySqlHost, sizeof(bufMySqlHost));
	ImGui::InputText("Port", bufMySqlPort, sizeof(bufMySqlPort));
	ImGui::InputText("Database", bufMySqlDatabase, sizeof(bufMySqlDatabase));
	ImGui::InputText("Username", bufMySqlUsername, sizeof(bufMySqlUsername));
	ImGui::InputText("Password", bufMySqlPassword, sizeof(bufMySqlUsername), ImGuiInputTextFlags_Password);
}
