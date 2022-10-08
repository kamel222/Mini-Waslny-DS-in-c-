#pragma once

#include"Graph.h"
#include "Vertex.h"
#include <iostream>
#include<iterator>
#include<string>
#include<list>
#include<sstream>
//
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
//
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//constructor

Graph::Graph() {

}

Graph::Graph(list<Vertex> Vertices) {
    this->Vertices = Vertices;
}

///////////////////////////////////////////////////////////////////////////////
//permanent used functions

bool Graph::checkIfVertexExist(string name) {

    for (auto it = Vertices.begin(); it != Vertices.end(); it++)
    {
        if (it->getTownName() == name)
            return true;
    }
    return false;

}

Vertex Graph::getVertex(string vname) {

    for (auto it = Vertices.begin(); it != Vertices.end(); it++) {

        if (it->getTownName() == vname)
        {
            return *it;
        }
    }
}

bool Graph::checkIfEdgeExist(string fromVertex, string toVertex) {
    Vertex v = getVertex(fromVertex);
    list<pair<Vertex, int>>e;
    e = v.getEdgeList();
    for (auto it = e.begin(); it != e.end(); it++) {

        if (it->first.getTownName() == toVertex)
        {
            return true;
        }
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////////
//Add

void Graph::AddVertex(const string& vname) {

    if (checkIfVertexExist(vname) == true) {
        cout << endl << "#Town with this ID already exist#" << endl << endl;
    }
    else {
        Vertex v(vname);
        Vertices.emplace_back(v);
        cout << endl <<"#new vertex is added#" << endl;
    }
}

void Graph::AddEdge(string v1, string v2, int cost, bool gtype) {
    bool check1 = checkIfVertexExist(v1);
    bool check2 = checkIfVertexExist(v2);

    bool check3 = checkIfEdgeExist(v1, v2);
    if (check1 == true && check2 == true)
    {
        if (check3 == true)
        {
            cout << endl << "#Edge between " << "(" << v1 << ") and " << "(" << v2 << ") Already Exist#" << endl;
        }
        else {

            for (auto it = Vertices.begin(); it != Vertices.end(); it++) {
                if (it->getTownName() == v1) {
                    it->addEdge(v2, cost);

                }
                if (it->getTownName() == v2 && gtype == false) {
                    it->addEdge(v1, cost);

                }
            }
            cout << endl << "#Edge between " << v1 << " and " << v2 << " added Successfully#" << endl;
        }

    }
    else {
        cout << endl << "#Invalid Vertex ID entered#";
    }

}

/////////////////////////////////////////////////////////////////////////////////
//Update

void Graph::UpdateEdge(string v1, string v2, int cost, bool gtype) {
    bool check = checkIfEdgeExist(v1, v2);

    if (check == true)
    {
        for (auto it = Vertices.begin(); it != Vertices.end(); it++) {
            if (it->getTownName() == v1) {
                it->UpdateEdge(v2, cost);
            }
            if (it->getTownName() == v2 && gtype == false) {
                it->UpdateEdge(v1, cost);
            }
        }
        cout << endl << "#Edge Weight Updated Successfully# " << endl;
    }
    else {
        cout << endl << "#Edge between " << "(" << v1 << ") and " << "(" << v2 << ") DOES NOT Exist#" << endl;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//Delete

void Graph::RemoveVertex(string vname) {
    bool check = checkIfVertexExist(vname);

    if (check == true) {
        
        for (auto it = Vertices.begin(); it != Vertices.end(); it++) {
            (*it).DeleteEdge(vname);
        }

        for (auto it = Vertices.begin(); it != Vertices.end(); it++) {
            
            if (it->getTownName() == vname) {
                Vertices.erase(it);
                cout << endl << "#Vertex deletted#" << endl;
                return;
            }
        }
    }
    else {
        cout << endl <<"#Invalid input#" << endl;
    }

}

void Graph::RemoveEdge(string v1, string v2, bool gtype) {
    bool check1 = checkIfVertexExist(v1);
    bool check2 = checkIfVertexExist(v2);
    bool check3 = checkIfEdgeExist(v1, v2);

    if (check1 == true && check2 == true)
    {
        if (check3 == true) {
            for (auto it = Vertices.begin(); it != Vertices.end(); it++) {
                if (it->getTownName() == v1) {
                    it->DeleteEdge(v2);
                }
                if (it->getTownName() == v2 && gtype == false) {
                    it->DeleteEdge(v1);
                }
            }
            cout << endl <<"#new edge is removed#" << endl;
        }
        else {
            cout << endl <<"#there is no edge between (" << v1 << ") and (" << v2 << ")#" << endl;
        }
    }
    else {
        cout << endl <<"#Invalid input#" << endl;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//Print

void Graph::printGraph() {

    for (auto it = Vertices.begin(); it != Vertices.end(); it++)
    {
        cout << it->getTownName() << " --> ";
        it->printEdgeList();
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//load Graph

void Graph::loadGraph(bool check, string fname) {

    string filename(fname);
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;

    }

    while (getline(input_file, line)) {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++) {

        if (lines[i] == "vertex") {
            for (int j = i + 1; j < lines.size(); j++) {

                if (lines[j] == "connection") {
                    break;
                }
                AddVertex(lines[j]);
            }
        }

    }
    string a, b;
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i] == "connection") {
            a = lines[i + 1];
            b = lines[i + 2];
            int n = stoi(lines[i + 3]);
            AddEdge(a, b, n, check);
            continue;
        }

    }

    input_file.close();

}

///////////////////////////////////////////////////////////////////////////////////////////////
// Save GRaph
void Graph::saveGraph(string fname) {

    fstream myFiles;

    myFiles.open(fname, ios::out | ios::app);
    if (myFiles.is_open())
    {

        myFiles << "vertex" << endl;
        for (auto it = Vertices.begin(); it != Vertices.end(); it++) {

            myFiles << it->getTownName() << endl;

        }
        Vertex v;
        for (auto k = Vertices.begin(); k != Vertices.end(); k++) {
            v = *k;
            v.saveEdgeList(fname, v);
        }

    }

}

////////////////////////////////////////////////////////////////////////////
//file name

void Graph :: addtotextfile(string text)
{
    ofstream myfile;
    myfile.open("filename.txt", ios::out | ios::app);
    myfile << endl << text;
    myfile.close();

}

/////////////////////////////////////////////////////////////////////////////
//read files

list<string> Graph::readFiles() {

    string filename("filename.txt");
    list<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;

    }

    while (getline(input_file, line)) {
        lines.push_back(line);
    }
    
    input_file.close();
    return lines;

}




