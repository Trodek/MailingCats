#include <string>


std::string ToCat(std::string cat_text)
{

}

void ProcessMessage(std::string& msg)
{
	bool cat_found = true;

	while (cat_found)
	{
		cat_found = false;

		std::string cat = "\n";

		size_t pos;
		if (pos = msg.find("[MoonCat]") != std::string::npos)
		{
			cat_found = true;
			cat += ToCat("MoonCat");
			msg.replace(pos, 9, cat);
		}
		else if (pos = msg.find("[Cat]") != std::string::npos)
		{
			cat_found = true;
			cat += ToCat("Cat");
			msg.replace(pos, 5, cat);
		}
		else if (pos = msg.find("[SleepCat]") != std::string::npos)
		{
			cat_found = true;
			cat += ToCat("SleepCat");
			msg.replace(pos, 10, cat);
		}
		else if (pos = msg.find("[SmallCat]") != std::string::npos)
		{
			cat_found = true;
			cat += ToCat("SmallCat");
			msg.replace(pos, 9, cat);
		}
		else if (pos = msg.find("[LaCaja]") != std::string::npos)
		{
			cat_found = true;
			cat += ToCat("LaCaja");
			msg.replace(pos, 8, cat);
		}
	}
}