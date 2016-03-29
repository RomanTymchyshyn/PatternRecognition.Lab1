#pragma once

#include <vector>
#include <algorithm>

class Patient
{
	private:
		int _size;
		int _numOfIndicators;
		std::vector<std::vector<double>> _data;

	public:

		Patient(): _size(0), _numOfIndicators(0) {_data = std::vector<std::vector<double>>(); };
		
		Patient(std::vector<std::vector<double>> data);

		int GetSize() const {return _size;};

		int GetNumOfIndicators() const {return _numOfIndicators;};

		std::vector<double> operator[](const int & i) const {return _data[i];};

		std::vector<double> GetObservation(const int & i) const {return _data[i];};

		std::vector<double> GetIndicatorSample(const int & i) const;
};