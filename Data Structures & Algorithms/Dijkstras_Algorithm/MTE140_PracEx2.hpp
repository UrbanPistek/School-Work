/*
Urban Pistek (20802700)
Julia Baribeau (20792386)

Run to main file to demonstrate functionallity

*/
#ifndef MTE140_PRACEX2_HPP
#define MTE140_PRACEX2_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

class Graph{

protected:
    vector<string> names;
    int size = 0;
    int **matrix;
public:

    //Parametric constructor
    Graph(int size);
	
	//Destructor
	~Graph();  

    //Insert helper
    bool insert_node(string name, int affiliates[]);

    //Print Function
    void print();

    //Dijkstra path traversal
    void dijkstra(int startNode);

    //Helper Function for Dikstra
    int minAffinity(int minDists[], bool visited[]);

    //Creat new grpah from a file
    bool create_graph_from_file(string affiliate_file, string name_file); 

};

#endif
