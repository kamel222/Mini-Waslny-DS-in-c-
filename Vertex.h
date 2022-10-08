#pragma once

#include<string>
#include<list>
#include<iterator>


using namespace std;

class Vertex {
private:
    string TownName;
public:
    list<pair<Vertex, int>> EdgeList;

    Vertex(string TownName);

    Vertex();

    void addEdge(Vertex V, int cost);

    void UpdateEdge(string V,int cost);

    void DeleteEdge(string V);

    void printEdgeList();

    void setTownName(string CN);

    string getTownName();

    list<pair<Vertex, int>> getEdgeList();

	void saveEdgeList(string, Vertex);
};
