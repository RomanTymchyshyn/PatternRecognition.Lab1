#pragma once

#include <vector>
#include "IMeasureCalculator.h"
#include "Patient.h"

enum AverageType { FirstFirst, FirstSecond, SecondSecond, SecondFirst };

class Calculator
{
	private:
		
		IMeasureCalculator* _measureCalculator;
		
		std::vector<Patient> _group1;

		std::vector<Patient> _group2;

		std::vector<Patient> GetPatientsPair(const AverageType & typeOfAverage, const int & i, const int & j);
		
	public:
		
		Calculator(std::vector<Patient> group1, std::vector<Patient> group2, IMeasureCalculator* measureCalculator);

		double Measure(const AverageType & typeOfAverage, const int & indicator, const int & firstPatientIndex, const int & secondPatientIndex);

		double AverageByPatientAndIndicator(const AverageType & typeOfAverage, const int & indicator, const int & patient);

		std::vector<double> AllAverageByPatientAndIndicator(const AverageType & typeOfAverage, const int & indicator);

		double AverageByIndicator(const AverageType & typeOfAverage, const int & indicator);

		std::vector<std::vector<double>> AverageMatrix(const int & numOfIndicators);
};