//Group 26 Urban Pistek Question 1
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

const int MAXROW = 4; 
const int MAXCOL = 8; 

void inputData(ifstream & inFile, coffeeData[][])
{
	for (int row = 0; row < MAXROW; row++ )
	{
		for (int col = 0; col < MAXROW; col++ )
		{
			int temp = 0;
			int course = 0; 
			int rating = 0; 
			
			while (inFile >> temp >> course >> rating)
			{
				if (temp ==  91 + col && course = row + 1 )
				{
					coffeeData[][] += rating; 
				}
			}
		}
	}
		
}

// Let 0 = col and 1 = row for the boolean 
int addRowOrCol (coffeeData[][], bool rowOrCol, int index)
{
	if (rowOrCol == 0)
	{
		int total = 0; 
		for (int count = 0; count < MAXROW; count ++ )
		{
			total += coffeeData[count][index]; 
			
		}
		return total; 
	}
	else 
	{
		int total = 0; 
		for (int count = 0; count < MAXROW; count ++ )
		{
			total += coffeeData[index]count]; 
		}
		return total; 
	}
}


void displayConsole( int coffeeData[MAXROW][MAXCOL])
{
int temp = 90;
int coarse = 1; 
for(int row = 0; row < MAXROW; row++)
{ 
for(int col = 0; col < MAXCOL; col++)
{
if(row == 0)
cout << setw(20) << temp++;
else
cout << setw(20) << coffeeData[row][col];
}
cout << endl;
}
}


int bestCombination(int coffeeData[MAXROW][MAXCOL], int & bestTemp,
int & bestCoarse)
{
int tempRating[MAXROW]={0};
int coarseRating[MAXCOL] = {0};

for(int row = 0; row < MAXROW; row++)
{
for(int col = 0; col < MAXCOL; col++)
{
coarseRating[row]+= coffeeData[row][col];
}
}
for(int col = 0; col < MAXCOL; col++)
{
for(int row = 0; row < MAXROW; row++)
{
tempRating[col]+= coffeeData[row][col];
}
} 
for(int row1 = 0; row1 < MAXROW; row1++)
{
if (tempRating[row1] > bestTemp)
bestTemp = temprating[row1]
}
for(int col1 = 0; col1 < MAXCOL; col1++)
{
if (coarseRating[col] > bestCoarse)
bestCoarse = coarseRating[col]; 
} 
}



int main()
{
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
