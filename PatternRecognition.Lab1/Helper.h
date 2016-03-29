#pragma once

#include <vector>
#include <string>
#include "IFileReader.h"
#include "IFileWriter.h"
#include "Patient.h"

class Helper
{
	private:
		IFileReader* _reader;
		IFileWriter* _writer;

		std::string GiveString(const int & num);

	public:
		Helper(IFileReader* reader, IFileWriter* writer);
		std::vector<Patient> ReadGroup(const std::string & nameOfDirectory, const std::string & nameOfGroup, 
			const std::string & fileExtension, const int & numberOfPatients);
};