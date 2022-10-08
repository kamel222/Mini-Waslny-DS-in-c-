#pragma once

#include <queue>
#include <climits>
#include "Graph.h"
#include <unordered_map>
#include<iterator>
#include<string>
#include<list>

class Dijkstra {
public:

    pair<list<string>, int> dijkstra(string source, string destination, list<Vertex> Graph);

};