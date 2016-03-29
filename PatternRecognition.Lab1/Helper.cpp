#include "Helper.h"

Helper::Helper(IFileReader* reader, IFileWriter* writer)
{
	_reader = reader;
	_writer = writer;
}

std::string Helper::GiveString(const int & num)
{
	char* temp = new char[5];
	std::string number;
	itoa(num, temp, 10);
	if(num < 10)
		number += "0";
	number += temp;
	return number;
}

std::vector<Patient> Helper::ReadGroup(const std::string & nameOfDirectory, const std::string & nameOfGroup, 
	const std::string & fileExtension, const int & numberOfPatients)
{
	std::vector<Patient> res;

	for (int i = 0, patients = 0; patients < numberOfPatients; ++i)
	{
		std::string nameOfFile = nameOfDirectory + "\\" + nameOfGroup + GiveString(i + 1) + fileExtension;

		std::vector<std::vector<double>> data;
		bool success = _reader->ReadMatrix(data, nameOfFile);

		if (success)
		{
			++patients;
			res.push_back(Patient(data));
		}
	}

	return res;
}