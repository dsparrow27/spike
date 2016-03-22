#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <FreeImage.h>


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
			std::cerr << "Failed to read file! \n " << filePath << e.what() << "\n" ;
		}
		const std::string fcontents = content.c_str();
		return fcontents;
	}
	static BYTE* loadImage(const char* path, int* width, int* height)
	{
		//image format
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		//pointer to the image, once loaded
		FIBITMAP *dib = nullptr;
		
		//check the file signature and deduce its format
		fif = FreeImage_GetFileType(path, 0);
		//if still unknown, try to guess the file format from the file extension
		if (fif == FIF_UNKNOWN)
			fif = FreeImage_GetFIFFromFilename(path);
		//if still unkown, return failure
		if (fif == FIF_UNKNOWN)
			return nullptr;

		//check that the plugin has reading capabilities and load the file
		if (FreeImage_FIFSupportsReading(fif))
			dib = FreeImage_Load(fif, path);
		//if the image failed to load, return failure
		if (!dib)
			return nullptr;

		//retrieve the image data
		BYTE* result = FreeImage_GetBits(dib);
		//get the image width and height
		*width = FreeImage_GetWidth(dib);
		*height = FreeImage_GetHeight(dib);

		return result;
	}
};