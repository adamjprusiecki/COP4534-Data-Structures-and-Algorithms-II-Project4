/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Driver.cpp
  DSA2-Project4

  Driver.cpp is the file that handles all of the implementation/flow logic 
  and Input/Output for the program.
***************************************************************/

#include "Driver.hpp"
#include <fstream>
#include <vector>
//#include <sstream>

Driver::Driver()
{

}

void Driver::Run()
{
	std::cout << "********************************************************************* PART 1 START" << std::endl;
	SimulationChip sc1(1,1);
	this->ReadFileDataChip("t1.txt",sc1);
	sc1.PrintValues();
	sc1.GenerateDatasets();
	sc1.MonteCarlo();

	SimulationChip sc2(2,201);
	this->ReadFileDataChip("t2.txt",sc2);
	sc2.PrintValues();
	sc2.GenerateDatasets();
	sc2.MonteCarlo();

	SimulationChip sc3(3,401);
	this->ReadFileDataChip("t3.txt",sc3);
	sc3.PrintValues();
	sc3.GenerateDatasets();
	sc3.MonteCarlo();

	SimulationChip sc4(4,601);
	this->ReadFileDataChip("t4.txt",sc4);
	sc4.PrintValues();
	sc4.GenerateDatasets();
	sc4.MonteCarlo();

	std::cout << "********************************************************************* PART 1 END" << std::endl << std::endl;
	
	std::cout << "********************************************************************* PART 2 START" << std::endl;
	SimulationReading sr;
	this->ReadFileDataReading("readings.txt",sr);
	sr.PrintValues();
	sr.PrintAnalyticalModel();
	sr.PrintSimulationModel();
	std::cout << "********************************************************************* PART 2 END" << std::endl << std::endl;
}

void Driver::ReadFileDataChip(std::string fileName,SimulationChip &sc)
{
	int numberOfBatches;
	int numberOfItems;
	float percentageBatches;
	float percentageItems;
	int itemsSampled;

	std::ifstream file;
	file.open(fileName);
	if(!file)
	{
		std::cout << "File \'" << fileName << "\' does not exist" << std::endl;
	}
	else
	{
		std::string s;

		//numberOfBatches
		file >> s;
		numberOfBatches = std::stoi(s);

		//numberOfItems
		file >> s;
		numberOfItems = std::stoi(s);

		//percentageBatches
		file >> s;
		percentageBatches = std::stof(s) / 100;

		//percentageItems
		file >> s;
		percentageItems = std::stof(s) / 100;

		//itemsSampled
		file >> s;
		itemsSampled = std::stoi(s);

		sc.SetValues(numberOfBatches,numberOfItems,percentageBatches,percentageItems,itemsSampled);
		
		file.close();
	}
}

void Driver:: ReadFileDataReading(std::string fileName,SimulationReading &sr)
{
	int numDays = 0;
	int numCategories = 0;

	std::vector<std::string> ranges;
	std::string units = "";
	std::string s = "";

	std::ifstream file;
	file.open(fileName);
	if(!file)
	{
		std::cout << "File \'" << fileName << "\' does not exist" << std::endl;
	}
	else
	{
		//numDays
		file >> s;
		numDays = std::stoi(s);

		//numCategories
		file >> s;
		numCategories = std::stoi(s);

		//Get each range and day, in an arbitrary range
		std::getline(file,s);
		for(int i = 0; i < numCategories; i++)
		{
			std::getline(file,s);
			ranges.push_back(s);
		}

		//units
		file >> units;

		sr.SetValues(numDays,numCategories,ranges,units);
	}
	file.close();
}