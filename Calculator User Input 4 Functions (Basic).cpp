// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cstring>

int main()
{	
	// User Input
	std::string User_Input;
	std::cout << "Please enter your equation with no spaces: ";
	std::cin >> User_Input;

	//Delaring Term and Operand Vectors
	std::vector <std::string> User_Input_Terms;
	std::vector <std::string> Operands;

	//Parsing the string into Term and Operand Vectors
	int Parsing_Index = 0, Previouse_Position = 0, Current_Position = 0;
	Current_Position = User_Input.find_first_of("+-*/", Previous_Position + 1) + 1;			//Locates first operand

	while (Current_Position - 1 != std::string::npos)																		//Ends loop at end of string
	{
		User_Input_Terms.push_back(User_Input.substr(Previous_Position, Current_Position - Previous_Position - 1));			//Places term into vector based on location of operand within the User_Input
		Operands.push_back(User_Input.substr(Current_Position - 1, 1));											//Place operand into User_Input_Operand vector
		Parsing_Index = Parsing_Index + 1;																					//Index 
		Previous_Position = Current_Position;																				//Replaces previous position with current position
		Current_Position = User_Input.find_first_of("+-*/", Previous_Position + 1) + 1;										//Locates next position
	}

	//Adding in the last value to User_Terms (The code exits the loops before the last value can be recorded)
	User_Input_Terms.push_back(User_Input.substr(Previous_Position, User_Input.length() - Previous_Position));

	//Converting term string vector into vector of doubles
	std::vector <double> Terms_Doubles;
	for (int Index = 0; Index < User_Input_Terms.size(); Index++)
	{
		Terms_Doubles.push_back(strtod(User_Input_Terms[Index].c_str(), nullptr));
	}

	//Putting case statement for multiplication and division
	double Temp_Operation = 0;
	for (int Index = 0; Index < Operands.size();)
	{
		switch (Operands[Index][0])
		{
		case '*':
			Terms_Doubles[Index + 1] = Terms_Doubles[Index] * Terms_Doubles[Index + 1];
			Terms_Doubles.erase(Terms_Doubles.begin() + Index);
			Operands.erase(Operands.begin() + Index);
			break;
		case '/':
			Terms_Doubles[Index + 1] = Terms_Doubles[Index] / Terms_Doubles[Index + 1];
			Terms_Doubles.erase(Terms_Doubles.begin() + Index);
			Operands.erase(Operands.begin() + Index);
			break;
		default:
			Index = Index + 1;
		}
	}

	for (int Index = 0; Index < Operands.size();)
	{
		switch (Operands[Index][0])
		{
		case '+':
			Terms_Doubles[Index + 1] = Terms_Doubles[Index] + Terms_Doubles[Index + 1];
			Terms_Doubles.erase(Terms_Doubles.begin() + Index);
			Operands.erase(Operands.begin() + Index);
			break;
		case '-':
			Terms_Doubles[Index + 1] = Terms_Doubles[Index] - Terms_Doubles[Index + 1];
			Terms_Doubles.erase(Terms_Doubles.begin() + Index);
			Operands.erase(Operands.begin() + Index);
			break;
		default: 
			Index = Index + 1;
		}
	}

	return 0;
}