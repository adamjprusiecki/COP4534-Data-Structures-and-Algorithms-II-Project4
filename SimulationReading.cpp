/***************************************************************
  Student Name: Adam Prusiecki
  File Name: SimulationReading.cpp
  DSA2-Project4

  This file contains all the logic and methods to carry out the 
  requested functionalilty for part 2

  Analytical model gets the median value for a range, multiplies
  it by the number of days for that range, adds the values for every 
  range, then divides by the total number of days

  Simulation generates a random number on the given range, numDays
  number of times and adds it to a total, once all ranges are 
  calculated, divide the total by the total number of days
***************************************************************/

#include "SimulationReading.hpp"

SimulationReading::SimulationReading()
{

}

void SimulationReading::SetValues(int numDays,int numCategories, std::vector<std::string> ranges,std::string units)
{
	this->numDays = numDays;
	this->numCategories = numCategories;
	this->ranges = ranges;
	this->units = units;
}

void SimulationReading::PrintValues()
{
	std::cout << "Simulated days: " << this->numDays << std::endl;
	std::cout << "Number of categories: " << this->numCategories << std::endl;
	std::cout << "Ranges and occurrences in each range:" << std::endl;
	for(int i = 0; i < this->numCategories; i++)
	{
		std::cout << this->ranges.at(i) << std::endl;
	}
	std::cout << "Units of measure: " << this->units << std::endl;
}

void SimulationReading::PrintAnalyticalModel()
{
	std::string s = "";
	std::string token = "";
	int low = 0;
	int high = 0;
	int days = 0;

	int totalData = 0;
	int median = 0;

	for(int i = 0; i < this->numCategories; i++)
	{
		s = this->ranges.at(i);
		
		token = s.substr(0,s.find("-"));
		low = std::stoi(s);
		s.erase(0,s.find("-") + 1);

		token = s.substr(0,s.find(" "));
		high  = std::stoi(s);
		s.erase(0,s.find(" "));

		days = std::stoi(s);

		median = ((high - low) / 2) + low;
		totalData += (median * days);
	}

	std::string expectedRange = "";
	for(int i = 0; i < this->numCategories; i++)
	{
		s = this->ranges.at(i);

		token = s.substr(0,s.find("-"));
		low = std::stoi(s);
		s.erase(0,s.find("-") + 1);

		token = s.substr(0,s.find(" "));
		high  = std::stoi(s);
		s.erase(0,s.find(" "));

		if((totalData / this->numDays) > low && (totalData / this->numDays) < high)
		{
			expectedRange = std::to_string(low) + "-" + std::to_string(high);
			break;
		}
	}

	std::cout << "Analytical model: " << totalData / this->numDays << ". Expected value is in the " 
			  << expectedRange << "/" << this->units << " range." << std::endl;
}

void SimulationReading::PrintSimulationModel()
{
	std::string s = "";
	std::string token = "";
	int low = 0;
	int high = 0;
	int days = 0;

	int totalData = 0;
	int randNum = 0;

	for(int i = 0; i < this->numCategories; i++)
	{
		s = this->ranges.at(i);
		
		token = s.substr(0,s.find("-"));
		low = std::stoi(s);
		s.erase(0,s.find("-") + 1);

		token = s.substr(0,s.find(" "));
		high  = std::stoi(s);
		s.erase(0,s.find(" "));

		days = std::stoi(s);

		for(int j = 0; j < days; j++)
		{
			randNum = rand() % high + low;
			while(randNum > high)
			{
				randNum = rand() % high + low;
			}
			totalData += randNum;
			randNum = 0;
		}
	}

	std::string expectedRange = "";
	for(int i = 0; i < this->numCategories; i++)
	{
		s = this->ranges.at(i);

		token = s.substr(0,s.find("-"));
		low = std::stoi(s);
		s.erase(0,s.find("-") + 1);

		token = s.substr(0,s.find(" "));
		high  = std::stoi(s);
		s.erase(0,s.find(" "));

		if((totalData / this->numDays) > low && (totalData / this->numDays) < high)
		{
			expectedRange = std::to_string(low) + "-" + std::to_string(high);
			break;
		}
	}

	std::cout << "Simulation: " << (totalData / this->numDays) << ". Expected value is in the " 
			  << expectedRange << "/" << this->units << " range." << std::endl;
}