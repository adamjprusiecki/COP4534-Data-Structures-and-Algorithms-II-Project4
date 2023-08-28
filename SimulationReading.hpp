/***************************************************************
  Student Name: Adam Prusiecki
  File Name: SimulationReading.hpp
  DSA2-Project4

  Is the header file for the 'SimulationReading' class
***************************************************************/

#ifndef SIMULATIONREADING_HPP_
#define SIMULATIONREADING_HPP_

#include <iostream>
#include <vector>

class SimulationReading
{
	private:
		int numDays;
		int numCategories;
		std::vector<std::string> ranges;
		std::string units;
	public:
		SimulationReading();
		void SetValues(int numDays,int numCategories,std::vector<std::string> ranges,std::string units);
		void PrintValues();
		void PrintAnalyticalModel();
		void PrintSimulationModel();
};

#endif // SIMULATIONREADING_HPP_