/*
 Final Grade Calculation App

	Summary: Quick C++ based application that can be used to 
	calculate the grade needed to get a desired grade in a class

	Functions:
	
	CheckFailure: Takes an input string that outputs desired 
	question, takes input from user and makes sure that said 
	input is valid. There is another boolean value that is used
	for finding percentage values, associated with weight.

	Main: that drives the program, calls CheckFailure and preforms 
	the arithemetic operations involved in calculating the required grade.
	Parameters only include command line arguments.


*/


#include <iostream>
#include <string>

//Used to check in case input was not actually a number, or not the 
//kind of number that was desired.
double CheckFailure(std::string sInputMessage, bool bIsPercent){

	//Initialize double to store value we want, output given message
	//and use cin.fail()/cin.clear()/cin.ignore to make sure our value 
	//is correct.
	double dCorrectVal; 

	std::cout << sInputMessage;
	std::cin >> dCorrectVal;
	while(std::cin.fail()){

		std::cin.clear();
		std::cin.ignore(999, '\n');	
		std::cout << "Try again. Double this time: ";
		std::cin >> dCorrectVal;
	
	}

	//Make sure that all numbers received are positive
	while(dCorrectVal < 0){
		std::cout << "I really hope that you did not mean to enter a negative number, please try again: ";
		std::cin >> dCorrectVal;
	}


	//Account for percentage values that are not betweeo 0 and 100%
	if(bIsPercent == true){
		while((dCorrectVal > 1) || (dCorrectVal < 0)){
			std::cout << "For the weight, please enter a decimal percentage from 0 to 1: ";
			std::cin >> dCorrectVal;
		}
	}

	return dCorrectVal;
}


int main(int argc, char* argv[]){

	//Initialize the double vairables that we will be using in our arithmetic formula. 
	double dCurrGrade, dFinalWeight, dDesiredGrade = 0;

	dCurrGrade = CheckFailure("What is your current grade? ", false);
	dFinalWeight = CheckFailure("What is the weight of the final exam/project? (0.0-1.0) ", true);
	dDesiredGrade = CheckFailure("What grade do you hope to receive after the exam? ", false);

	//Now that we have the correct values, we can then use a basic formula to automate the calculation of the desired grade
	double dRequiredFinal = (dDesiredGrade - (dCurrGrade * (1 - dFinalWeight) )  ) / (dFinalWeight);

	std::cout << "You will need to receive a " << dRequiredFinal << " on the final to receive a " << dDesiredGrade << std::endl;
	
	if(dRequiredFinal > 100){
		std::cout << "You might have trouble with that one... " << std::endl;
	}

	else if(dRequiredFinal <65){
		std::cout << "It shouldn't be too bad!" << std::endl;
	}

	return 0;


}
