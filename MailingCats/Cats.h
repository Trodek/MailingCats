#include <string>


std::string ToCat(std::string cat_text)
{
	std::string temp;
	if (cat_text == "MoonCat")
	{
		temp =  "            *      ,MHARRY&.            * \n";
		temp += "                  MMMSOS&&&&&    .       \n";
		temp += "                 MMMMUN&&&&&&&           \n";
		temp += "     *           MMM8GATO&&&&&           \n";
		temp += "                 MMM88&&&&&&&&           \n";
		temp += "                 'MMM88&&&&&&'           \n";
		temp += "                   'MMM8&&&'      *      \n";
		temp += "          |\___/|\n";
		temp += "          )     (             .              '\n";
		temp += "         =\     /=\n";
		temp += "           )===(       *\n";
		temp += "          /     \\n";
		temp += "          |     |\n";
		temp += "         /       \\n";
		temp += "         \       /\n";
		temp += "  _/\_/\_/\__  _/_/\_/\_/\_/\_/\_/\_/\_/\_/\_\n";
		temp += "  |  |  |  |( (  |  |  |  |  |  |  |  |  |  |\n";
		temp += "  |  |  |  | ) ) |  |  |  |  |  |  |  |  |  |\n";
		temp += "  |  |  |  |(_(  |  |  |  |  |  |  |  |  |  |\n";
		temp += "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
		temp += "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
	}
	else if (cat_text == "Cat")
	{
		temp =  "                                 _\n";
		temp += "                                | \\n";
		temp += "                                | |\n";
		temp += "                                | |\n";
		temp += "           |\                   | |\n";
		temp += "          /, ~\                / /\n";
		temp += "         X     `-.....-------./ /\n";
		temp += "          ~-. ~  ~              |\n";
		temp += "             \             /    |\n";
		temp += "              \  /_     ___\   /\n";
		temp += "              | /\ ~~~~~   \ |\n";
		temp += "              | | \        || |\n";
		temp += "              | |\ \       || )\n";
		temp += "             (_/ (_/      ((_/\n";
	}
	else if (cat_text == "SleepCat")
	{
		temp =  " |\__/,|   (`\\n";
		temp += " |_ _  |.--.) )\\n";
		temp += " ( T   )     /\n";
		temp += " (((^_(((/(((_> \n";
	}
	else if (cat_text == "SmallCat")
	{
		temp =  "      \    /\\n";
		temp += "       )  ( ')\n";
		temp += "      (  /  )\n";
		temp += "       \(__)| \n";
	}
	else if (cat_text == "LaCaja")
	{
		temp =  "                                     ,\n";
		temp += "              ,-.       _,---._ __  / \\n";
		temp += "            /  )    .-'       `./ /   \\n";
		temp += "            (  (   ,'            `/    /|\n";
		temp += "             \  `-'             \'\   / |\n";
		temp += "              `.              ,  \ \ /  |\n";
		temp += "               /`.          ,'-`----Y   |\n";
		temp += "              (            ;        |   '\n";
		temp += "              |  ,-.    ,-'         |  /\n";
		temp += "              |  | (   |            | /\n";
		temp += "              )  |  \  `.___________|/ \n";
		temp += "              `--'   `--'\n";
	}
	else
	{
		temp = "HARRY SOS UN GATO";
	}
	return temp;
}