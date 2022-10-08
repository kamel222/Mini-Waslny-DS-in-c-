#include "Vertex.h"
#include <iostream>
#include<iterator>
#include<string>
#include<list>
#include<fstream>


void Vertex::setTownName(string TN) {
    TownName = TN;
}

Vertex :: Vertex()
{

}

string Vertex::getTownName() {
    return TownName;
}

list<pair<Vertex, int>> Vertex::getEdgeList() {
    return EdgeList;
}

Vertex::Vertex(string TownName) {
    this->TownName = TownName;

}

///////////////////////////////////////////////////////////////////////////////
//Add

void Vertex::addEdge(Vertex V, int cost) {
    EdgeList.emplace_back(V,cost);
}

///////////////////////////////////////////////////////////////////////////////
//Update
void Vertex::UpdateEdge(string V, int cost) {
    for (auto it = EdgeList.begin(); it != EdgeList.end(); it++) {
        if (it->first.TownName == V) {
            it->second = cost;
            return;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////
//Delete
void Vertex::DeleteEdge(string V) {
    for (auto it = EdgeList.begin(); it != EdgeList.end(); it++) {
        if (it->first.TownName == V) {
            EdgeList.erase(it);
            return;
        }
    }

}

///////////////////////////////////////////////////////////////////////////////
//Print Edge List function
void Vertex::printEdgeList() {
	cout << "[";
	for (auto it = EdgeList.begin(); it != EdgeList.end(); it++) {
		cout << it->first.getTownName() << "(" << it->second << ") | ";
	}
	cout << "]";
	cout << endl;
}

//
////////////////////////////////////////////////////////////////////////////////////////
////Files
void Vertex::saveEdgeList(string fname, Vertex m) {
	fstream myFiles;
	myFiles.open(fname, ios::out | ios::app);
    for (auto i = m.EdgeList.begin(); i != m.EdgeList.end(); i++) {
        myFiles << "connection" << endl;
        myFiles << m.getTownName() << endl;
        myFiles << i->first.getTownName() << endl;
        myFiles << i->second << endl;
    }
	
}

