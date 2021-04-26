
// Author: Maitra Patel
// Class: CIS 310
// Year: 2017
// Program name: Program 0 - Number Conversions
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;

void DecimalToBinary(ofstream&, int, int);
void DecimalToHexadecimal(ofstream&, int num);
void DecimalToBCD(ofstream&, int num);
string hexFinder(int x);

int main()
{
	//Open file
	ofstream file;
	file.open("MaitraPatel_Conversions.txt");
	//Write Header
	file << "DECIMAL" << left << setw(11) << " "<<  "BINARY" << left << setw(18) << " " << "HEXADECIMAL" << left << setw(6) << " " << "BCD" << endl;
	//Loop Conversions from 0-255 Decimals
	for (int i = 0; i < 256; i++)
	{
		//Print Decimal in file
		file << left << setw(3);
		file << i;
		file << left << setw(15) << " ";
		//Print Binary in file
		DecimalToBinary(file, i, 8);
		file << left << setw(15) << " ";
		//Print Hexadecimal in file
		DecimalToHexadecimal(file, i);
		file << left << setw(15) << " ";
		//Print BCD in file
		DecimalToBCD(file, i);
		file << endl;
	}
	cout << "Results have been written to a text file named 'MaitraPatel_Conversions.txt'" << endl;
	//Close File
	file.close();
	return 0;
}
//Decimal to Binary
//Pre: Output File, Decimal number, and bit size
//Post: Returns or Prints Binary number
void DecimalToBinary(ofstream& file, int num, int size)
{
	//Initialize size bits to 0
	vector <int> binaryNum(size, 0);
	if (num != 0)
	{
		int iterator = size;
		//Computation & Storage
		while (num > 0 && iterator >= 0)
		{
			binaryNum.at(iterator - 1) = num % 2;
			num = num / 2;
			iterator--;
		}
	}		
	//Print
	for (int i = 0; i < binaryNum.size(); i++)
	{
		if (i == 4)
		{
			file << " " << binaryNum[i];
		}
		else
		{
			file << binaryNum[i];
		}
	}
}
//Decimal to HexaDecimal
//Pre: Output File, Decimal number
//Post: Returns or Prints Hexadecimal number
void DecimalToHexadecimal(ofstream& file, int num) //Use stack
{
	//Initialize 2 bits of space
	vector <int> hexaDecimal(2, 0);
	if(num != 0)
	{
		//Computation & storage
		int iterator = 2;
		while (num > 0)
		{
			if (iterator >= 0)
			{
				hexaDecimal.at(iterator - 1) = (num % 16);
			}
			else
			{
				break;
			}
			num = num / 16;
			iterator--;
		}
		

	}
	//Print to file
	for (int i = 0; i < hexaDecimal.size(); i++)
	{
		file << hexFinder(hexaDecimal[i]);
	}
}
//Decimal to BCD
//Pre: File, Decimal number
// --Decimal to Binary function must be implemented first
//Post: Returns BCD of a Decimal number
void DecimalToBCD(ofstream& file, int num)
{
	stack<int> numbers;
	int count = 0;
	while (num > 0)
	{
		numbers.push(num % 10);
		num = num / 10;
		++count;
	}
	if (count < 3)
	{
		for (int i = count; i < 3; i++)
		{
			numbers.push(0);
		}
	}

	while (!numbers.empty())
	{
		DecimalToBinary(file, numbers.top(), 4);
		file << " ";
		numbers.pop();
	}
}
//Structure for Grabbing Hexadecimals
//Pre: Number must be provided
//Post: Returns corresponding Hex
string hexFinder(int x)
{
	string numInHex;
	switch (x)
	{
	case 0:
		numInHex = '0';
		break;
	case 1:
		numInHex = '1';
		break;
	case 2:
		numInHex = '2';
		break;
	case 3:
		numInHex = '3';
		break;
	case 4:
		numInHex = '4';
		break;
	case 5:
		numInHex = '5';
		break;
	case 6:
		numInHex = '6';
		break;
	case 7:
		numInHex = '7';
		break;
	case 8:
		numInHex = '8';
		break;
	case 9:
		numInHex = '9';
		break;
	case 10:
		numInHex = 'A';
		break;
	case 11:
		numInHex = 'B';
		break;
	case 12:
		numInHex = 'C';
		break;
	case 13:
		numInHex = 'D';
		break;
	case 14:
		numInHex = 'E';
		break;
	case 15:
		numInHex = 'F';
		break;
	}
	return numInHex;
}
