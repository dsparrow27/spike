#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

class FileUtils
{
public:
	static std::string readFile(const char* filePath)
	{
		/*Loads a text file and returns the contents
		*/
		std::string content;
		std::ifstream file;
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{	
			// open file
			file.open(filePath, std::ios::in);
			std::stringstream fileStream;
			//read file contents into stream
			fileStream << file.rdbuf();
			//close handlers
			file.close();
			//convert stream int string
			content = fileStream.str();
		}
		catch (std::ios_base::failure& e)
		{
			std::cerr << "Failed to read file!\n" << e.what() << "\n" ;
		}
		const std::string fcontents = content.c_str();
		return fcontents;
	}
};