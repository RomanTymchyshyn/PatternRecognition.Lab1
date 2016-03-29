#pragma once

#include <vector>
#include <string>

class IFileReader
{
	public:
		virtual bool ReadMatrix(std::vector<std::vector<double>> & result, const std::string & nameOfFile = "", const int & rows = -1, const int & cols = 15) const = 0;
};