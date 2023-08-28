/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Driver.hpp
  DSA2-Project4

  Is the header file for the 'driver' class
***************************************************************/

#ifndef DRIVER_HPP_
#define DRIVER_HPP_

#include <iostream>
#include "SimulationChip.hpp"
#include "SimulationReading.hpp"

class Driver
{
	private:
	public:
		Driver();
		void Run();
		void ReadFileDataChip(std::string fileName,SimulationChip &sc);
		void ReadFileDataReading(std::string fileName,SimulationReading &sr);
};

#endif // DRIVER_HPP_