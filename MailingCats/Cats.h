#include <string>


std::string ToCat(std::string cat_text)
{
	std::string temp;
	if (cat_text == "Cat")
	{
		temp = "                                 _\n";
		temp += "                                | \\\n";
		temp += "                                | |\n";
		temp += "                                | |\n";
		temp += "           |\\                   | |\n";
		temp += "          /, ~\\                / /\n";
		temp += "         X     `-.....-------./ /\n";
		temp += "          ~-. ~  ~              |\n";
		temp += "             \\             /    |\n";
		temp += "              \\  /_     ___\\   / \n";
		temp += "              | /\\ ~~~~~   \\ | \n";
		temp += "              | | \\        || | \n";
		temp += "              | |\\ \\       || )\n";
		temp += "             (_/ (_/      ((_/ \n";
	}
	else if (cat_text == "SleepCat")
	{
		temp =  " |\\__/,|   (`\\ \n";
		temp += " |_ _  |.--.) )\\ \n";
		temp += " ( T   )     / \n";
		temp += " (((^_(((/(((_> \n";
	}
	else if (cat_text == "SmallCat")
	{
		temp = "      \\    /\\\n";
		temp += "       )  ( ·)\n";
		temp += "      (  /  ) \n";
		temp += "       \\(__)| \n";
	}
	else
	{
		temp = "HARRY SOS UN GATO";
	}
	return temp;

}

void ProcessMessage(std::string& msg)
{
	bool cat_found = true;

	while (cat_found)
	{
		cat_found = false;

		std::string cat = "\n";

		size_t pos;
		if ((pos = msg.find("[Cat]")) != std::string::npos)
		{
			cat_found = true;
			cat += ToCat("Cat");
			msg.replace(msg.begin() + pos, msg.begin() + pos + 5, cat);
		}
		else if ((pos = msg.find("[SleepCat]")) != std::string::npos)
		{
			cat_found = true;
			cat += ToCat("SleepCat");
			msg.replace(msg.begin() + pos, msg.begin() + pos + 10, cat);
		}
		else if ((pos = msg.find("[SmallCat]")) != std::string::npos)
		{
			cat_found = true;
			cat += ToCat("SmallCat");
			msg.replace(msg.begin() + pos, msg.begin() + pos + 10, cat);
		}
	}
}