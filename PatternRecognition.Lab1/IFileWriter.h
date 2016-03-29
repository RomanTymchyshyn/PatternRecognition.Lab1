#pragma once

#include <vector>
#include <string>

class IFileWriter
{
	public:
		virtual bool WriteMatrix(const std::string & nameOfFile, const std::vector<std::vector<double>> & matrix) const = 0;
};