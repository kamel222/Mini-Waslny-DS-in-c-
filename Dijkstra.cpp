#include "Dijkstra.h"
#include <iostream>
#include<iterator>
#include<string>
#include<list>
pair<list<string>, int> Dijkstra::dijkstra(string source, string destination, list<Vertex> Graph) {
    // o(v * e)
    // We can optimize it to o(v + e log(e))
    queue<Vertex> q;
    unordered_map<string, pair<int, string>> table;

    //first is the total cost
    //second is the parent of the vertex
    for (Vertex vertex : Graph) {
        table[vertex.getTownName()].first = INT_MAX;
        if (vertex.getTownName() == source)
            q.push(vertex);//d
    }
    table[source] = { 0, source };

    //a ->{[10b],[20c] }
    // a,b,c,d,f
    while (!q.empty()) {
        list<pair<Vertex, int>> Edges;
        for (auto vertex : Graph) {
            if (vertex.getTownName() == q.front().getTownName()) {
                Edges = vertex.getEdgeList();
                break;
            }
        }
        for (auto Edge : Edges) { //{5b,c,d}         a-(0)>a  a-(5)>b
            int cost = table[q.front().getTownName()].first + Edge.second;
            //total cost of th current node + the cost to travel for the next node
            int TotalCost = table[Edge.first.getTownName()].first;
            //total cost of the next node
            if (cost < TotalCost) {
                q.push(Edge.first);
                table[Edge.first.getTownName()] = { cost, q.front().getTownName() };
            }

        }
        q.pop();
    }
    //back tracking
    list<string> path;
    path.push_back(destination);
    string parent = table[destination].second;
    path.push_front(parent);
    while (parent != source) {
        parent = table[parent].second;
        path.push_front(parent); //kant push_back
    }
    for (auto it : table) {
        cout << "Distance covered: " << it.second.first << endl;
    }
    return { path, table[destination].first };
}