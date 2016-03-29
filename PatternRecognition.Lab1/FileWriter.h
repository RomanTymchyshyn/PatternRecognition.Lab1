#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "IFileWriter.h"

class FileWriter: public IFileWriter
{
	public:
		virtual bool WriteMatrix(const std::string & nameOfFile, const std::vector<std::vector<double>> & matrix) const;
};