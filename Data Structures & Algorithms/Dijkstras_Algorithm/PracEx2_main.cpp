/*
Urban Pistek (20802700)
Julia Baribeau (20792386)

Be sure to input your own grpah files and run our test for two different graphs created from files

PLEASE NOTE:
Have a seperate file for names and a seperate file for affiliates 
Esnure that a value of 11 means unreachable and 0 means the node is referencing itself in your afffiliates files

PLEASE ENSURE THAT OUR TEST FILES ARE INCULDED IN THE FOLDER:
"affiliations.txt", "names.txt" 
"affiliations2.txt", "names2.txt"

Thank you
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>

#include "MTE140_PracEx2.cpp"

using namespace std;

void Graph_test(){
	cout << "############################## TEST START #############################" << endl;
	Graph graph1(10);
    Graph graph2(0);
    Graph graph3(6);
    cout << "******************************Graph Initialized*******************************" << endl;
    cout << "|||||||||||||||||||||||||||||Inserting Data|||||||||||||||||||||||||||||||||||" << endl;
    graph2.create_graph_from_file("affiliations.txt", "names.txt");
    graph2.print();
    graph3.create_graph_from_file("affiliations2.txt", "names2.txt");
    graph3.print();
    cout << "******************************Dijkstra*******************************" << endl;
    cout << "File 1" << endl; 
    graph2.dijkstra(0);
    cout<<endl;
    cout << "File 2" << endl;
    graph3.dijkstra(2);
    cout << "############################## TEST END #############################" << endl;
}

int main(){

	bool working = true; 
	string name_file = ""; 
	string affiliates_file = ""; 
	string input = ""; 
	
	while(working){
		
		cout << "Please ensure that you have the files in the same folder as this program, and that one file " << endl; 
		cout<< "contains the names listed by index, whereas the other has the affiliations corresponding. "<< endl;
		cout<< "Esnure that a value of 11 means unreachable and 0 means the node is referencing itself "<< endl;
		cout<< "If you are ready to continue please enter y" << endl;
		cin >> input;
		if(input == "n"){
			working = false; 
		}
		
		Graph graph1(0);
		cout << "Please Enter Name of files from which you would like a create a Graph:" << endl;
		cout << "Please Enter the name of the names file (in which the names of the nodes are sorted according to their index): " << endl; 
		cin >> name_file; 
		cout << "Please Enter the name of the affiliates file (in which the nodes are sorted by row and its affiliates sorted by columns): " << endl;
		cin >> affiliates_file; 
		cout << "Would you like to create a graph? Please type y or n" << endl;
		cin >> input; 
		
		if(input == "y"){
			
			graph1.create_graph_from_file(affiliates_file, name_file);	
			graph1.print();
		}
		
		cout << "Would you like to run Dijstra? Please type y or n" << endl; 
		cin >> input;
		if(input == "y"){
			int start; 
			cout << "PLease enter the index of the node you would like to start at: " << endl; 
			cin >> start; 
			graph1.dijkstra(start);
		}
		
		cout << "Would you like to run our standard test? Please type y or n" << endl; 
		cin >> input;
		if(input == "y"){
			Graph_test(); 
		}
		
		cout << "Would you like to continue? Please type y or n" << endl;
		cin >> input;
		if(input == "n"){
			working = false; 
		}
		
	}
	
    system("PAUSE");
    return EXIT_SUCCESS;
}
