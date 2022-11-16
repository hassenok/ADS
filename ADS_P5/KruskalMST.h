
#pragma once
#include <vector>
#include <queue>
#include "EdgeWeightedGraph.h"

class KruskalMST
{
private:
	std::vector<Edge> mst;				// MST-Kanten
	std::vector<int> treeID;			// BaumId zu jedem Knoten
public:
	std::vector<Edge>get_mst() { return mst; };
	KruskalMST() {};
	KruskalMST(EdgeWeightedGraph G);
	std::vector<Edge> edges() const;	// liefert MST
	double weight() const;     			// berechnet Gesamtkosten des MST
};

