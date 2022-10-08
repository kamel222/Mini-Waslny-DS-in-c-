#pragma once
#include<iostream>
#include"Graph.h"
#include "Dijkstra.h"
#include<iterator>
#include<string>
#include<list>
#include<fstream>
using namespace std;


int main()
{
    cout << "*Welcome to Mini-Waslny*" << endl;
    Graph g;
    string s1, s2, sname;
    Dijkstra d;
    int cost, option, type;
    bool gtype = false;
    list<string> f;


    while(true)
    {
        cout << "=============================================" << endl;
        cout << "1. Direct Graph " << endl;
        cout << "2. Undirect Graph " << endl;
        cin >> type;
        if (type == 1 || type == 2)
        {
            if (type == 1) {
                gtype = true;
            }
                break;
        }
        else {
            cout << endl;
            cout << "#Invalid input#" << endl;
            continue;
        }

    }

    do {
        cout << "=============================================" << endl;
        cout << "What operation do you want to perform? " <<
            " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Add Vertex" << endl;
        cout << "2. Update Vertex" << endl;
        cout << "3. Delete Vertex" << endl;
        cout << "4. Add Edge" << endl;
        cout << "5. Update Edge" << endl;
        cout << "6. Delete Edge" << endl;
        cout << "7. Print Graph" << endl;
        cout << "8. store Graph" << endl;
        cout << "9. Measure The Shortest Path" << endl;
        cout << "10. Load Graph" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        cout << endl;
;       Vertex v1;

        switch (option) {
        case 0:

            break;

        case 1:
            cout << "Add Vertex Operation -" << endl;
            //cout << "Enter State ID :";
            //cin >> id1;
            cout << "Enter State Name :";
            cin >> sname;
            //v1.setTownID(id1);
            //v1.setTownName(sname);
            g.AddVertex(sname);

            break;

        case 2:
            cout << "Update Vertex Operation -" << endl;
            cout << "Enter State ID of Vertex(State) to update :";
            // cin >> id1;
            cout << "Enter State Name :";
            cin >> sname;
            //g.(id1, sname);

            break;

        case 3:
            cout << "Delete Vertex Operation -" << endl;
            cout << "Enter ID of Vertex(State) to Delete : ";
            cin >> s1;
            g.RemoveVertex(s1);

            break;

        case 4:
            cout << "Add Edge Operation -" << endl;
            cout << "Enter ID of Source Vertex(State): ";
            cin >> s1;
            cout << "Enter ID of Destination Vertex(State): ";
            cin >> s2;
            cout << "Enter Weight of Edge: ";
            cin >> cost;
            g.AddEdge(s1, s2, cost, gtype);

            break;

        case 5:
            cout << "Update Edge Operation -" << endl;
            cout << "Enter ID of Source Vertex(State): ";
            cin >> s1;
            cout << "Enter ID of Destination Vertex(State): ";
            cin >> s2;
            cout << "Enter UPDATED Weight of Edge: ";
            cin >> cost;
            g.UpdateEdge(s1, s2, cost, gtype);

            break;

        case 6:
            cout << "Delete Edge Operation -" << endl;
            cout << "Enter ID of Source Vertex(State): ";
            cin >> s1;
            cout << "Enter ID of Destination Vertex(State): ";
            cin >> s2;
            g.RemoveEdge(s1, s2, gtype);

            break;

        case 7:
            cout << "Print Graph Operation -" << endl;
            g.printGraph();

            break;

        case 8:{
            string fname;
            cout << "store Graph Operation -" << endl;
            cout << "Enter Graph's name   (example: #20) -" << endl;
            cin >> fname;
            g.saveGraph(fname);
            g.addtotextfile(fname);

            break;
        }
        case 9: {
            cout << "dijkstra -" << endl;
            cout << "enter source:";
            cin >> s1; cout << endl;
            cout << "enter destinstion:";
            cin >> s2; cout << endl;

            pair <list<string>, int> lst = d.dijkstra(s1, s2, g.Vertices);
            for (auto it = lst.first.begin(); it != lst.first.end(); it++)
            {
                cout << "(" << (*it) << ") --> ";
            }
            cout << "*arrived*" << endl;
            cout << "Total Distance covered: " << lst.second << endl;
            

            break;
        }

        case 10:{
            string fname;
            cout << "Load Graph Operation -" << endl;
            cout << "Enter Graph's ID   (example: #20) -" << endl;
            f = g.readFiles();
            for (auto it = f.begin(); it != f.end();it++) {
                cout << *it << " - ";
            }
            cout << endl;
            cin >> fname;
            g.loadGraph(gtype, fname);

            break;
        }
        default:
            cout << "Enter Proper Option number " << endl;
        }
        cout << endl;

    } while (option != 0);


    return 0;
}