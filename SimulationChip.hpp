/***************************************************************
  Student Name: Adam Prusiecki
  File Name: SimulationChip.hpp
  DSA2-Project4

  Is the header file for the 'SimulationChip' class
***************************************************************/

#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

class SimulationChip
{
	private:
		int numberOfBatches;
		int numberOfItems;
		float percentageBatches;
		float percentageItems;
		int itemsSampled;
		int id;
		int dataSetStartNumber;
	public:
		SimulationChip(int id,int dataSetStartNumber);
		void SetValues(int numberOfBatches,int numberOfItems,
			float percentageBatches,float percentageItems,int itemsSampled);	
		void PrintValues();
		void GenerateDatasets();
		void MonteCarlo();
};

#endif // SIMULATION_HPP_