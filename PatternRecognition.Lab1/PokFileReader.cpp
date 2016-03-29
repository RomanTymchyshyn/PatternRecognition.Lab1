#include "PokFileReader.h"

bool PokFileReader::ReadMatrix(std::vector<std::vector<double>> & result, const std::string & nameOfFile, const int & rows, const int & cols) const
{
	std::ifstream fin(nameOfFile);
	
	if (!fin)
	{
		return false;
	}

	int n = 0;
	double unused = 0;
	
	if (rows == -1)
		fin >> n >> unused;

	result = std::vector<std::vector<double>>(n, std::vector<double>(15, 0));
	
	for (int i = 0; i < n; ++i)
	{
		fin >> unused;
		for (int j = 0; j < cols; ++j)
		{
			double temp = 0;
			fin >> temp;
			result[i][j] = temp;
		}
	}
	
	fin.close();

	return true;
}