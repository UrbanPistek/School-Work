/*
Urban Pistek (20802700)
Julia Baribeau (20792386)

Run to main file to demonstrate functionallity

*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "MTE140_PracEx2.hpp"

using namespace std;

const int MAX_NUM = 1000000;

    //Parametric constructor
    //***********Urban*************
    Graph::Graph(int new_size){
        size = new_size;
        names.resize(new_size);
        matrix  = new int* [new_size];

        for(int idx = 0; idx < new_size; idx++){
            matrix[idx] = new int[new_size];
        }
    }
    
    //Destructor
    Graph::~Graph(){}

    //Insert helper
    bool Graph::insert_node(string name, int affiliates[]){
        if(size == 0){
            names[0] = name;
            for(int idx = 0; idx < size; idx++){
                matrix[0][idx] = affiliates[idx];
            }
        ++size;
        return true;
        }
        else{
            int curr = 0;
            while(matrix[curr] != NULL){
                curr++;
            }
            names[curr] = name;
            for(int idx = 0; idx < size; idx++){
                matrix[curr][idx] = affiliates[idx];
            }
            ++size;
            return true;
        }
    }

    //Print Function
    void Graph::print(){
        cout << "Size of Graph: " << size << endl;
        for(int row = 0; row < size; row++){
            cout << "****Node " << row << "****" << endl;
            cout << "Name: " << names[row] << endl;
            for(int col = 0; col < size; col++){
                cout << names[col] << endl;
                if(matrix[row][col] == 0){
                    cout << "No Affiliation, ";
                }
                else{
                    cout << matrix[row][col] << ", ";
                }
                cout << " | " << endl;
            }
            cout << "**********************************" << endl;
        }

    }

    //Dijkstra path traversal
    void Graph::dijkstra(int startNode){
	    int minDists[size];
	    bool visited[size];
	    for(int i=0; i<size; i++){
	        minDists[i] = MAX_NUM;
	        visited[i] = false;
	        visited[i] = false;
	    }
	    minDists[startNode] = 0;
	    for(int i = 0; i<size; i++){
	        int cur = minAffinity(minDists, visited);
	        visited[cur] = true;
	        for(int node = 0; node<size; node++){
	            if(matrix[cur][node]!=11 && !visited[node] && minDists[cur]!=MAX_NUM && minDists[cur]+matrix[cur][node]<minDists[node])
	                minDists[node] = minDists[cur]+matrix[cur][node];
	        }

	    }
	    cout<<"From "<<names[startNode]<<endl;
	    for(int i=0; i<size; i++){
	        cout<<"Dist to: "<<names[i]<<"\t\t"<<minDists[i]<<endl;
	    }

	}

	int Graph::minAffinity(int minDists[], bool visited[]){
	    int minimum = MAX_NUM;
	    int minIndex;
	    for(int i=0; i<size; i++){
	        if(!visited[i] && minDists[i]<=minimum){
	            minimum = minDists[i];
	            minIndex = i;
	        }
	    }
	    return minIndex;
	}

    //Creat new grpah from a file
    bool Graph::create_graph_from_file(string affiliate_file, string name_file){
    	cout << "Name File: " << name_file << endl;
		cout << "Affiliate File: " << affiliate_file << endl;
        ifstream nameFile;
		ifstream affFile;
        nameFile.open(name_file.c_str());
        affFile.open(affiliate_file.c_str());

		if (!nameFile && !affFile) {
    	cout << "Unable to open file " << endl;
		return false;   // call system to stop
		}
		else{
			cout << "File Opened Successfully " << endl;
		}

        int file_size;
        affFile >> file_size;
		cout << "File_Size: " << file_size << endl;

		//Initialize the graph appropiately
		size = file_size;
        names.resize(file_size);
        matrix  = new int* [file_size];

        for(int idx = 0; idx < file_size; idx++){
            matrix[idx] = new int[file_size];
        }

		//Read data from files
        for(int row = 0; row < file_size; row++){
            nameFile >> names[row];
            for(int col = 0; col < file_size; col++){
                affFile >> matrix[row][col];
            }
        }
    return true;
    }

