//David Sayer
//CIS 1202 800
//4/21/22

//#include <bits/stdc++.h>
#include<iostream>

using namespace std;

//Classes that represent the different exeptions that can occur
class invalidCharacter
{

};
class invalidRange
{

};
class caseConversion
{

};

//Function to find character
char character(char start, int offset)
{
	//Will assign the ascii value of the start variable to asciiValue
	int asciiValue = int(start);

	//Adds the offset value to asciiValue to get the target letter
	int target = asciiValue + offset;

	//Try statement used to check and make sure that the target and asciiValue are valid letters either lower or upper case.
	try
	{
		if (asciiValue < 65 || (asciiValue > 90 && asciiValue < 97) || asciiValue > 122)
		{
			throw invalidCharacter();
		}
		else if (target < 65 || (target > 90 && target < 97) || target > 122)
		{
			throw invalidRange();
		}
		else if ((target >= 65 && target <= 90 && asciiValue >= 95 && asciiValue <= 122) || (target >= 95 && target <= 122 && asciiValue >= 65 && asciiValue <= 90))
		{
			throw caseConversion();
		}
	}

	//Catch for all of the invalid expressions
	catch (invalidCharacter exception1)
	{
		cout << "Invalid Character Exception";
		return ' ';
	}
	catch (invalidRange exception2)
	{
		cout << "Invalid Range Exception";
		return ' ';
	}
	catch (caseConversion exception3)
	{
		cout << "Cannot make case changes from upper to lower or otherwise";
		return ' ';
	}
	//If no exections were found returns target
	return target;
}

//Main function
int main()
{
	cout << character('a', 1) << endl;
	cout << character('a', -1) << endl;
	cout << character('Z', -1) << endl;
	cout << character('?', 5) << endl;
	cout << character('A', 32) << endl;
	cout << character('D', 3) << endl;




}