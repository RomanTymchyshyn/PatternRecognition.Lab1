#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "IFileReader.h"

class PokFileReader: public IFileReader
{
	public:
		virtual bool ReadMatrix(std::vector<std::vector<double>> & result, const std::string & nameOfFile = "", const int & rows = -1, const int & cols = 15) const;
};