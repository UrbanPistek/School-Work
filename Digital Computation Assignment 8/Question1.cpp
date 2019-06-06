//Group 26 Urban Pistek Question 1
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

//Assume array element number 0 corresponds to parking spot 1

const int MAXPARKINGSPACE = 50; 
const int MAXPARKINGCHANGE = 25;

void readInParkingCurrent(ifstream & inFile, parkingAssociationCurrent[MAXPARKINGSPACE],
parkingNameCurrent[MAXPARKINGSPACE], parkingSpotCurrent[MAXPARKINGSPACE])
{
	while (inFile >> parkingAssociationCurrent[MAXPARKINGSPACE] >> parkingNameCurrent[MAXPARKINGSPACE] >> parkingSpotCurrent[MAXPARKINGSPACE])
	{}
}

void readInAddorRemove(ifstream & inFile, parkingAssociation[MAXPARKINGCHANGE], parkingName[MAXPARKINGCHANGE])
{
	while (inFile >> parkingAssociation[MAXPARKINGCHANGE], parkingName[MAXPARKINGCHANGE])
	{}
}

void deletePerson(parkingNameRemove[MAXPARKINGCHANGE], parkingAssociationCurrent[MAXPARKINGSPACE], parkingNameCurrent[MAXPARKINGSPACE])
{
	for (index = 0; index < MAXPARKINGSPACE; index++)
	{
		if (parkingNameRemove[index] == parkingNameCurrent[index])
		{
			parkingNameCurrent[index] = " ";
			parkingAssociationCurrent[index] = 2; 
		}
	}
}

int availibleParkingIndex(parkingAssociationCurrent[MAXPARKINGSPACE])
{
	for (index = 0; index < MAXPARKINGSPACE; index++) 
	{
		if (parkingAssociationCurrent[index] == 2)
		{
			return index; 
		}
	}
}

void assignParking(parkingAssociationCurrent[MAXPARKINGSPACE], parkingNameCurrent[MAXPARKINGSPACE], 
parkingAssociationAdd[index], parkingNameAdd[index])
{
	while (availibleParkingIndex(parkingAssociationCurrent[MAXPARKINGSPACE]) < MAXPARKINGSPACE )
	{
		parkingAssociationCurrent[availibleParkingIndex(parkingAssociationCurrent[MAXPARKINGSPACE])] = parkingAssociationAdd[index]; 
		parkingNameCurrent[availibleParkingIndex(parkingAssociationCurrent[MAXPARKINGSPACE])] = parkingNameAdd[index]; 
	}
}

void stafforFacultySwap(parkingAssociationCurrent[MAXPARKINGSPACE], parkingAssociationAdd[MAXPARKINGCHANGE], parkingNameAdd[MAXPARKINGCHANGE])
{
	if (availibleParkingIndex(parkingAssociationCurrent[MAXPARKINGSPACE]) >= 26 && availibleParkingIndex(parkingAssociationCurrent[MAXPARKINGSPACE]) <=50 )
	{
		assignParking(parkingAssociationCurrent[MAXPARKINGSPACE], parkingNameCurrent[MAXPARKINGSPACE], 
		parkingAssociationAdd[stafforStudent(parkingAssociationAdd[MAXPARKINGCHANGE], parkingNameAdd[MAXPARKINGCHANGE])], 
		parkingNameAdd[stafforStudent(parkingAssociationAdd[MAXPARKINGCHANGE], parkingNameAdd[MAXPARKINGCHANGE])])
	}
}

void outputData (ofstream & outFile, parkingAssociationCurrent[MAXPARKINGSAPCE], parkingNameCurrent[MAXPARKINGSAPCE], parkingSpotCurrent[MAXPARKINGSAPCE])
{
	for (index = 0; index < MAXPARKINGSPACE; index++) 
	{
		outFile << setw(16) << "Association" << setw(30) << "Name" << setw(16) << "Parking Spot" << endl; 
		outFile << setw(16) << parkingAssociationCurrent[index] << setw(30) << parkingNameCurrent[index] << setw(16) << parkingSpotCurrent[index] << endl; 
	}
}

int stafforStudent(parkingAssociationAdd[MAXPARKINGCHANGE], parkingNameAdd[MAXPARKINGCHANGE])
{
	int index = 0; 
	string name = parkingNameAdd[index]; 
	while (parkingAssociationAdd[index] != 1 && parkingNameAdd[index] != parkingNameAdd[index - 1] )
	{
		index++; 
	}
	return index; -
}

int main()
{
	ifstream inFilePCurrent ("parking_current.txt");
	ifstream inFilePRemove ("parking_remove.txt");
	ifstream inFilePAdd ("parking_add.txt");

	ofstream outFile("parkingdata.txt");
	
	int parkingAssociationCurrent[MAXPARKINGSAPCE] = {0}; 
	string parkingNameCurrent[MAXPARKINGSAPCE]; 
	int parkingSpotCurrent[MAXPARKINGSAPCE] = {0}; 
	
	int parkingAssociationRemove[MAXPARKINGCHANGE] = {0}; 
	string parkingNameRemove[MAXPARKINGCHANGE]; 
	
	int parkingAssociationAdd[MAXPARKINGCHANGE] = {0}; 
	string parkingNameAdd[MAXPARKINGCHANGE]; 
	
	
		system("PAUSE");
    return EXIT_SUCCESS;
}

