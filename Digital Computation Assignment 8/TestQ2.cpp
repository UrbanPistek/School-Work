
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

void readInParkingCurrent(ifstream & inFile, int parkingAssociationCurrent[],
string parkingNameCurrent[], int parkingSpotCurrent[])
{
	for (int index = 0; index < MAXPARKINGSPACE; index++)
	{
		inFile >> parkingAssociationCurrent[index] >> parkingNameCurrent[index] >> parkingSpotCurrent[index]; 
	}
}

void readInAddorRemove(ifstream & inFile, int parkingAssociation[], string parkingName[])
{
	for (int index = 0; index < MAXPARKINGSPACE; index++)
	{
		inFile >> parkingAssociation[index] >> parkingName[index]; 
	}
}

void deletePerson(int indexDelete, int parkingAssociationCurrent[], string parkingNameCurrent[], string parkingNameRemove[])
{
	if (parkingNameRemove[indexDelete] == parkingNameCurrent[indexDelete])
		{
			parkingNameCurrent[indexDelete] = " ";
			parkingAssociationCurrent[indexDelete] = 2; 
		}
}

int availibleParkingIndex(int parkingAssociationCurrent[])
{
	int index = 0;
	while ( index < MAXPARKINGSPACE && parkingAssociationCurrent[index - 1] != 2) 
	{
		index++;
	}
	
	return index; 
}

//Updated 
void assignParking(int parkingAssociationCurrent[], string parkingNameCurrent[], string personName, int personAssociation)
{
	int availibleSpot = 0; 
	availibleSpot = availibleParkingIndex(parkingAssociationCurrent); 
	
	parkingAssociationCurrent[availibleSpot] = personAssociation; 
	parkingNameCurrent[availibleSpot] = personName; 
}

//Updated
void stafforFacultySwap(int parkingAssociationCurrent[], string parkingNameCurrent[], int parkingAssociationAdd[], string parkingNameAdd[])
{
	for (int index = 0; index < 25; index++)
	{
		int indexfree = 0; 
		indexfree = availibleParkingIndex(parkingAssociationCurrent); 
		
		if (parkingAssociationAdd[index + 25] == 1 )
		{
			parkingAssociationCurrent[indexfree] = 1;
			parkingNameCurrent[indexfree] = parkingNameAdd[index + 25]; 
		}
	}
}

void outputData(ofstream & outFile, int parkingAssociationCurrent[], string parkingNameCurrent[], int parkingSpotCurrent[])
{
	for (int index = 0; index < MAXPARKINGSPACE; index++) 
	{
		outFile << setw(16) << "Association" << setw(30) << "Name" << setw(16) << "Parking Spot" << endl; 
		outFile << setw(16) << parkingAssociationCurrent[index] << setw(30) << parkingNameCurrent[index] << setw(16) << parkingSpotCurrent[index] << endl; 
		outFile << "End" <<  endl; 
	}
}


int main()
{
	ifstream inFilePCurrent ("parking_current.txt");
	ifstream inFilePRemove ("parking_remove.txt");
	ifstream inFilePAdd ("parking_add.txt");

	ofstream outFile("parkingdata.txt");
	
	int parkingAssociationCurrent[MAXPARKINGSPACE] = {0}; 
	string parkingNameCurrent[MAXPARKINGSPACE]; 
	int parkingSpotCurrent[MAXPARKINGSPACE] = {0}; 
	
	int parkingAssociationRemove[MAXPARKINGCHANGE] = {0}; 
	string parkingNameRemove[MAXPARKINGCHANGE]; 
	
	int parkingAssociationAdd[MAXPARKINGCHANGE] = {0}; 
	string parkingNameAdd[MAXPARKINGCHANGE]; 
	
	readInParkingCurrent(inFilePCurrent, parkingAssociationCurrent, parkingNameCurrent, parkingSpotCurrent);
	readInAddorRemove(inFilePRemove, parkingAssociationRemove, parkingNameRemove);
	readInAddorRemove(inFilePAdd, parkingAssociationAdd, parkingNameAdd);
	
	int count = 0; 
	
	do
	{
		deletePerson(count,parkingAssociationCurrent, parkingNameCurrent, parkingNameRemove); 
		
		stafforFacultySwap(parkingAssociationCurrent, parkingNameCurrent, parkingAssociationAdd, parkingNameAdd);
		
		assignParking(parkingAssociationCurrent, parkingNameCurrent, parkingNameAdd[count], parkingAssociationAdd[count]);
	
	count++; 	
	} while (count <= 50); 
	
	outputData(outFile, parkingAssociationCurrent, parkingNameCurrent, parkingSpotCurrent); 

	inFilePCurrent.close();
	inFilePRemove.close();
	inFilePAdd.close();
	outFile.close();
	
		system("PAUSE");
    return EXIT_SUCCESS;
}


/*
using namespace std;

//Assume array element number 0 corresponds to parking spot 1

const int MAXPARKINGSPACE = 50; 
const int MAXPARKINGCHANGE = 25;

void readInParkingCurrent(ifstream & inFile, int parkingAssociationCurrent[],
string parkingNameCurrent[], int parkingSpotCurrent[])
{
	for (int index = 0; index < MAXPARKINGSPACE; index++)
	{
		inFile >> parkingAssociationCurrent[index] >> parkingNameCurrent[index] >> parkingSpotCurrent[index]; 
	}
}

void readInAddorRemove(ifstream & inFile, int parkingAssociation[], string parkingName[])
{
	for (int index = 0; index < MAXPARKINGSPACE; index++)
	{
		inFile >> parkingAssociation[index] >> parkingName[index]; 
	}
}

void deletePerson(int indexDelete, int parkingAssociationCurrent[], string parkingNameCurrent[], string parkingNameRemove[])
{
	if (parkingNameRemove[indexDelete] == parkingNameCurrent[indexDelete])
		{
			parkingNameCurrent[indexDelete] = " ";
			parkingAssociationCurrent[indexDelete] = 2; 
		}
}

int availibleParkingIndex(int parkingAssociationCurrent[])
{
	int index = 0;
	while ( index < MAXPARKINGSPACE && parkingAssociationCurrent[index - 1] != 2) 
	{
		index++;
	}
	
	return index; 
}

//Updated 
void assignParking(int parkingAssociationCurrent[], string parkingNameCurrent[], string personName, int personAssociation)
{
	int availibleSpot = 0; 
	availibleSpot = availibleParkingIndex(parkingAssociationCurrent); 
	
	parkingAssociationCurrent[availibleSpot] = personAssociation; 
	parkingNameCurrent[availibleSpot] = personName; 
}

//Updated
void stafforFacultySwap(int parkingAssociationCurrent[], string parkingNameCurrent[], int parkingAssociationAdd[], string parkingNameAdd[])
{
	for (int index = 0; index < 25; index++)
	{
		int indexfree = 0; 
		indexfree = availibleParkingIndex(parkingAssociationCurrent); 
		
		if (parkingAssociationAdd[index + 25] == 1 )
		{
			parkingAssociationCurrent[indexfree] = 1;
			parkingNameCurrent[indexfree] = parkingNameAdd[index + 25]; 
		}
	}
}

void outputData (ofstream & outFile, int parkingAssociationCurrent[], string parkingNameCurrent[], int parkingSpotCurrent[])
{
	for (int index = 0; index < MAXPARKINGSPACE; index++) 
	{
		outFile << setw(16) << "Association" << setw(30) << "Name" << setw(16) << "Parking Spot" << endl; 
		outFile << setw(16) << parkingAssociationCurrent[index] << setw(30) << parkingNameCurrent[index] << setw(16) << parkingSpotCurrent[index] << endl; 
	}
}


int main()
{
	ifstream inFilePCurrent ("parking_current.txt");
	ifstream inFilePRemove ("parking_remove.txt");
	ifstream inFilePAdd ("parking_add.txt");

	ofstream outFile("parkingdata.txt");
	
	int parkingAssociationCurrent[MAXPARKINGSPACE] = {0}; 
	string parkingNameCurrent[MAXPARKINGSPACE]; 
	int parkingSpotCurrent[MAXPARKINGSPACE] = {0}; 
	
	int parkingAssociationRemove[MAXPARKINGCHANGE] = {0}; 
	string parkingNameRemove[MAXPARKINGCHANGE]; 
	
	int parkingAssociationAdd[MAXPARKINGCHANGE] = {0}; 
	string parkingNameAdd[MAXPARKINGCHANGE]; 
	
	readInParkingCurrent(inFilePCurrent, parkingAssociationCurrent, parkingNameCurrent, parkingSpotCurrent);
	readInAddorRemove(inFilePRemove, parkingAssociationRemove, parkingNameRemove);
	readInAddorRemove(inFilePAdd, parkingAssociationAdd, parkingNameAdd);
	
	int count = 0; 
	
	do
	{
		deletePerson(count,parkingAssociationCurrent, parkingNameCurrent, parkingNameRemove); 
		
		stafforFacultySwap(parkingAssociationCurrent, parkingNameCurrent, parkingAssociationAdd, parkingNameAdd);
		
		assignParking(parkingAssociationCurrent, parkingNameCurrent, parkingNameAdd[count], parkingAssociationAdd[count]);
	
	count++; 	
	} while (count <= 50); 
	
	outputData (outFile, parkingAssociationCurrent, parkingNameCurrent, parkingSpotCurrent); 

	inFilePCurrent.close();
	inFilePRemove.close();
	inFilePAdd.close();
	outFile.close();
	
		system("PAUSE");
    return EXIT_SUCCESS;
}
*/
