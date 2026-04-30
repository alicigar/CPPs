#include <iostream>
#include <string>
#include <fstream>

void	search_and_replace(std::string &buffer, std::string &s1, std::string &s2)
{
	size_t pos = 0;
	while ((pos = buffer.find(s1, pos)) != std::string::npos)
	{
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
		pos += s2.length();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Oh no! Wrong number of arguments, honey. " << std::endl;
		return (1);
	}

	std::string file = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty() || s2.empty() )
	{
		std::cout << "Error: Hey, the string couldn't be empty, darling." << std::endl;
		return (1);
	}
	std::string fileOutput = file + ".replace";
	std::ifstream inFile(file.c_str());
	if (!inFile.is_open())
	{
		std::cout << "Error: Ooops, this file doesn't exists, sweetie." << std::endl;
		return (1);
	}
	std::string fileContent;
	std::string line;
	while (std::getline(inFile, line))
		fileContent += line + "\n";
	inFile.close();
	search_and_replace(fileContent, s1, s2);
	std::ofstream outFile(fileOutput.c_str());
	outFile << fileContent;
	outFile.close();
	return (0);
}
