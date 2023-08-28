/***************************************************************
  Student Name: Adam Prusiecki
  File Name: main.cpp
  DSA2-Project4

  main.cpp is the file that contains the int main() function
***************************************************************/

#include <iostream>
#include "Driver.hpp"

int main()
{
	srand(time(0)); //Seeding for the random number generation
	Driver d;
	d.Run();
	
	return 0;
}