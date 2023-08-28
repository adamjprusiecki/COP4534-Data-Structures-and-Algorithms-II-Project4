/***************************************************************
  Student Name: Adam Prusiecki
  File Name: SimulationChip.cpp
  DSA2-Project4

  This file contains all the logic and methods to carry out the 
  requested functionalilty for part 1

  Assigns bad batches based on a modulo number, that determines
  how many iterations are required to achieve the required percentage

  Monte Carlo algorithm reads the dataset into a char array of size
  this->numberOfItems, finds a random index in that array, and iterates
  this->itemsSampled number of times, checking if it is a bad chip
***************************************************************/

#include "SimulationChip.hpp"

#include <iostream>
#include <fstream>
#include <math.h>

SimulationChip::SimulationChip(int id,int dataSetStartNumber)
{
	this->numberOfBatches = 0;
	this->numberOfItems = 0;
	this->percentageBatches = 0.0;
	this->percentageItems = 0.0;
	this->itemsSampled = 0;
	this->id = id;
	this->dataSetStartNumber = dataSetStartNumber;
}

void SimulationChip::SetValues(int numberOfBatches,int numberOfItems,float percentageBatches,float percentageItems,int itemsSampled)
{
	this->numberOfBatches = numberOfBatches;
	this->numberOfItems = numberOfItems;
	this->percentageBatches = percentageBatches;
	this->percentageItems = percentageItems;
	this->itemsSampled = itemsSampled;
}

void SimulationChip::GenerateDatasets()
{
	int currentDatasetNumber = this->dataSetStartNumber;
	int modNum = 0;
	char arr[this->numberOfItems];
	std::string filename = "";
	std::string fileNumber ="";
	int badBatchIndex = 0;
	int badItemIndex = 0;
	float dbadPct = 0.0;
	int badPct = 0;

	for(int i = 0; i < this->numberOfItems; i++) 
	{
		arr[i] = '0';
	}

	modNum = this->numberOfBatches * this->percentageBatches;
	modNum = this->numberOfBatches / modNum;

	std::cout << "Generating data sets:" << std::endl << std::endl;

	for(int i = 0; i < this->numberOfBatches; i++)
	{
		if(i % modNum == 0) // If Bad Batch
		{
			badBatchIndex++;
			if(i < 10)
			{
				std::cout << "	Create bad set batch #   " << i << ", ";
			}
			else if(i < 100)
			{
				std::cout << "	Create bad set batch #  " << i << ", ";
			}
			else if(i < 1000)
			{
				std::cout << "	Create bad set batch # " << i << ", ";
			}
			int randNum = rand() % 100;
			for(int j = 0; j < this->numberOfItems; j++)
			{
				if(randNum < (this->percentageItems)*100) // If bad chip
				{
					arr[j] = 'b';
					badItemIndex++;
				}
				else // If good chip
				{
					arr[j] = 'g';
				}
				randNum = rand() % 100;
			}

			dbadPct = (double(badItemIndex)/double(this->numberOfItems)) * 100;
			badPct = dbadPct;
			std::cout << "totBad =  " << badItemIndex << " | total =  " << this->numberOfItems 
					  << " | badpct =  " << badPct << std::endl;
			badItemIndex = 0;
			badPct = 0;
		}
		else // If Good Batch
		{
			for(int j = 0; j < this->numberOfItems; j++) // Every Chip is Good
			{
				arr[j] = 'g';
			}
		}

		fileNumber = std::to_string(currentDatasetNumber);
		filename = "Outputs/ds" + fileNumber + ".txt";

		std::ofstream dsFile(filename);
		for(int j = 0; j < this->numberOfItems; j++)
		{
			dsFile << arr[j] << '\n';
		}
		dsFile.close();

		filename = "";
		fileNumber ="";
		currentDatasetNumber++;

		for(int j = 0; j < this->numberOfItems; j++) 
		{
			arr[j] = '0';
		}
	}
	std::cout << "	Total bad sets = " << badBatchIndex << std::endl << std::endl;;
}

void SimulationChip::MonteCarlo()
{
	int currentDatasetNumber = 0;
	std::string filename = "";
	std::string fileNumber = "";
	std::string input = "";
	char chipArr[this->numberOfItems];

	if(this->id == 1)
	{
		currentDatasetNumber = 1;
	}
	if(this->id == 2)
	{
		currentDatasetNumber = 201;
	}
	if(this->id == 3)
	{
		currentDatasetNumber = 401;
	}
	if(this->id == 4)
	{
		currentDatasetNumber = 601;
	}

	int randNum = 0;
	int badBatchIndex = 0;
	int index = 0;
	int element = 0;

	std::cout << "Analyzing Data Sets:" << std::endl;

	for(int i = 0; i < this->numberOfBatches; i++)
	{
			fileNumber = std::to_string(currentDatasetNumber);
			filename = "Outputs/ds" + fileNumber + ".txt";
			std::ifstream inFile;
			inFile.open(filename);
			if(!inFile)
			{
				std::cout << "File " << filename << " does not exist" << std::endl;
			}
			else
			{
				for(int j = 0; j < this->numberOfItems; j++)
				{
					inFile >> input;
					chipArr[j] = input[0];
				}
				inFile.close();
			}
			currentDatasetNumber++;
			randNum = rand() % this->numberOfItems;
			do
			{
				if(randNum + element == this->numberOfItems) // Wrap the array
				{
					randNum = 0;
					element = 0;
				}
				if(chipArr[randNum + element] == 'b')
				{
					std::cout << "	batch #" << i << " is bad" << std::endl;
					badBatchIndex++;
					break;
				}
			index++;
			element++;
			}while(index < this->itemsSampled);
			index = 0;
			element = 0;
	}
	std::cout << std::endl;

	std::cout << "Base = " << (1.0 - this->percentageItems) << " exponent = " << this->itemsSampled << std::endl;
	std::cout << "P(failure to detect bad batch) = " << pow((1.0 - this->percentageItems),double(this->itemsSampled)) << std::endl;
	std::cout << "Percentage of bad batches actually detected = " << double(badBatchIndex)/((double(this->numberOfBatches)*this->percentageBatches)) * 100 << "%" << std::endl;
	std::cout << std::endl;
}

void SimulationChip::PrintValues()
{
	std::cout << "Simulation " << this->id << ":"  << std::endl;
	std::cout << "	Number of batches of items:                      " << this->numberOfBatches << std::endl;
	std::cout << "	Number of items in each batch                    " << this->numberOfItems << std::endl;
	std::cout << "	Percentage of batches containing bad items       " << this->percentageBatches*100 << "%" << std::endl;
	std::cout << "	Percentage of items that are bad in a bad set    " << this->percentageItems*100 << "%" << std::endl;
	std::cout << "	Items sampled from each set                      " << this->itemsSampled << std::endl << std::endl;
}