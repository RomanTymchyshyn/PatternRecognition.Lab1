#include "Calculator.h"

Calculator::Calculator(std::vector<Patient> group1, 
	std::vector<Patient> group2, 
	IMeasureCalculator* measureCalculator)
{
	_measureCalculator = measureCalculator;
	_group1 = group1;
	_group2 = group2;
}

std::vector<Patient> Calculator::GetPatientsPair(const AverageType & typeOfAverage, 
	const int & i, const int & j)
{
	std::vector<Patient> res;

	Patient p1 = typeOfAverage == FirstFirst || typeOfAverage == FirstSecond ?
		_group1[i] : _group2[i];
	res.push_back(p1);

	Patient p2 = typeOfAverage == FirstFirst || typeOfAverage == SecondFirst ?
		_group1[j] : _group2[j];
	res.push_back(p2);

	return res;
}

double Calculator::Measure(const AverageType & typeOfAverage, const int & indicator, 
	const int & firstPatientIndex, const int & secondPatientIndex)
{
	std::vector<Patient> patients = GetPatientsPair(typeOfAverage, firstPatientIndex, secondPatientIndex);

	return _measureCalculator->Calculate(patients[0].GetIndicatorSample(indicator), 
										 patients[1].GetIndicatorSample(indicator));
}

double Calculator::AverageByPatientAndIndicator(const AverageType & typeOfAverage, 
	const int & indicator, const int & patient)
{
	int numberOfComparedPatients = 0;

	switch(typeOfAverage)
	{
		case FirstFirst:
			numberOfComparedPatients = _group1.size() - 1;
			break;

		case FirstSecond:
			numberOfComparedPatients = _group2.size();
			break;

		case SecondFirst:
			numberOfComparedPatients = _group1.size();
			break;

		case SecondSecond:
			numberOfComparedPatients = _group2.size() - 1;
			break;
	}

	double sumOfMeasures = 0;
	int comparedToGroupSize = typeOfAverage == FirstFirst || typeOfAverage == SecondFirst ? 
		_group1.size() : _group2.size();

	for (int i = 0; i < comparedToGroupSize; ++i)
	{
		if ((typeOfAverage != FirstFirst && typeOfAverage != SecondSecond) || i != patient)
		{
			sumOfMeasures += Measure(typeOfAverage, indicator, patient, i);
		}
	}

	return sumOfMeasures / numberOfComparedPatients;
}

std::vector<double> Calculator::AllAverageByPatientAndIndicator(const AverageType & typeOfAverage, 
	const int & indicator)
{
	std::vector<double> res;
	int size = typeOfAverage == FirstFirst || typeOfAverage == FirstSecond ? 
		_group1.size() : _group2.size();

	for (int i = 0; i < size; ++i)
		res.push_back(AverageByPatientAndIndicator(typeOfAverage, indicator, i));

	return res;
}

double Calculator::AverageByIndicator(const AverageType & typeOfAverage, const int & indicator)
{
	int size = typeOfAverage == FirstFirst || typeOfAverage == FirstSecond ?
		_group1.size() : _group2.size();

	double sumOfAverages = 0;

	for (int i = 0; i < size; ++i)
		sumOfAverages += AverageByPatientAndIndicator(typeOfAverage, indicator, i);

	return sumOfAverages / size;
}

std::vector<std::vector<double>> Calculator::AverageMatrix(const int & numOfIndicators)
{
	std::vector<std::vector<double>> res;

	for (int i = 0; i < 4; ++i)
	{
		std::vector<double> row;
		
		for (int j = 0; j < numOfIndicators; ++j)
		{
			row.push_back(AverageByIndicator((AverageType)i, j));
		}

		res.push_back(row);
	}

	return res;
}