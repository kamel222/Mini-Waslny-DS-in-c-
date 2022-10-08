#pragma once
#include<vector>
#include"Vertex.h"
#include<iterator>
#include<string>
#include<list>
using namespace std;



class Graph
{
public:
    list<Vertex> Vertices;
    
    

    Graph();

    Graph(list<Vertex> Vertices);
    void AddVertex(const string& vname);
    void RemoveVertex(string vname);
    void UpdateEdge(string v1, string v2, int cost, bool gtype);
    void AddEdge(string v1, string v2, int cost, bool gtype);
    void RemoveEdge(string v1, string v2, bool gtype);
    void printGraph();
    bool checkIfVertexExist(string vname);
    bool checkIfEdgeExist(string fromVertex, string toVertex);
    Vertex getVertex(string vname);
    void loadGraph(bool check, string);
    void saveGraph(string);
    void addtotextfile(string text);
    list<string> readFiles();
     //	void printGraph();
     //	void saveGraph();
};

