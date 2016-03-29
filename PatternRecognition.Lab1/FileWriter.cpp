#include "FileWriter.h"

bool FileWriter::WriteMatrix(const std::string & nameOfFile, const std::vector<std::vector<double>> & matrix) const
{
	try
	{
		std::ofstream fout(nameOfFile);
		int numOfRows = matrix.size();
		fout.precision(10);

		for (int i = 0; i < numOfRows; ++i)
		{
			int numOfColumns = matrix[i].size();
			
			for (int j = 0; j < numOfColumns; ++j)
			{
				fout.width(15);
				fout << std::right << matrix[i][j];
			}
			
			if (i != numOfRows - 1)
				fout<< std::endl;
		}

		fout.close();
		return true;
	}
	catch(const std::exception &)
	{
		return false;
	}
}