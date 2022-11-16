#include <assert.h>
#include "DijkstraSP.h"
using namespace std;
/**
 * F�ge eine Kante mit minimalen Kosten hinzu, die von einem
 * Baumknoten zu einem Nicht-Baumknoten verl�uft und deren
 * Ziel w dem Startknoten s am n�chsten ist.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  v		Zielknoten
 */
void DijkstraSP::relax(EdgeWeightedDigraph G, int v)
{
	/*
	 * TODO
	 */
	std::vector<DirectedEdge> edges = G[v]; // adjazente Knoten zum Knoten v
	for (DirectedEdge e : edges)
		 {
		 int w = e.to();
		 if (distToVect[w] > distToVect[v] + e.weight())
			 {
			 distToVect[w] = distToVect[v] + e.weight();
			 edgeTo[w] = e;
			 if (pq.contains(w)) pq.change(w, distToVect[w]);
			 else pq.push(w, distToVect[w]);
			 }
		 }

}

/**
 * Fuert den Dijkstra Algorithmus von s, im Graph G aus.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  s		Startknoten
 */
DijkstraSP::DijkstraSP(EdgeWeightedDigraph G, int s)
{
	/*
	 * TODO
	 */
	distToVect.resize(G.getV());
	for (int v = 0; v < G.getV(); v++) {
		distToVect[v] = DBL_MAX;

	}
	distToVect[s] = 0.0;

	pq.push(s, 0.0);
	while (!pq.empty()) {
		// Füge immer eine Kante mit minimalen Pfadkosten zu s hinzu
		int min = pq.top().value;
		pq.pop();
		// Füge immer eine Kante mit minimalen Pfadkosten zu s der PQ hinzu
		relax(G, min);
	}
}

/**
 * Gibt die Distanz von s zum Knoten v zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Summe der Gewichte auf dem Pfad zu v
 */
double DijkstraSP::distTo(int v) const
{
	/*
	 * TODO
	 */
	return distToVect.at(v);
}

/**
 * Gibt zurueck ob es einen Pfad zu v von s aus gibt
 *
 * \param[in]  v		Zielknoten
 * \return true, wenn es einen Pfad von s nach v gibt, sonst false
 */
bool DijkstraSP::hasPathTo(int v) const
{
	/*
	 * TODO
	 */
	if (distTo(v) > 0)
		return true;
	return false;
}

/**
 * Gibt den Pfad von s nach v als Vektor zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Vektor mit allen Kanten des Pfades von s nach v
 */

std::vector<DirectedEdge> DijkstraSP::pathTo(int v)
{
	/*
	 * TODO
	 */
	std::vector<DirectedEdge> path;
	int akt = v;

	while (distToVect[akt] != 0.0) {                    //Gehe von v rueckwaerts, bis zu s
		path.push_back(edgeTo[akt]);                    //Schreibe den Pfad auf

		akt = edgeTo[akt].from();
	}

	std::vector<DirectedEdge> rev_path;
	rev_path.resize(path.size());

	for (int i = path.size()-1; i >= 0; i--) {                //Pfad rückwerts
		rev_path[path.size() -1 - i] = path[i];
	}

	return rev_path;
}