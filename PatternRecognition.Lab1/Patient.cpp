#include "Patient.h"

Patient::Patient(std::vector<std::vector<double>> data)
{
	_data = data;
	
	_size = data.size();

	_numOfIndicators = data[0].size();
	for (int i = 1; i < _size; ++i)
	{
		int size = data[i].size();
		if (_numOfIndicators > size)
			_numOfIndicators = size;
	}
}

std::vector<double> Patient::GetIndicatorSample(const int & index) const
{
	std::vector<double> res;

	if (index < _numOfIndicators)
	{
		for (int i = 0; i < _size; ++i)
		res.push_back(_data[i][index]);
	}

	return res;
}
