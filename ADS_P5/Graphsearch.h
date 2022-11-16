#pragma once
#include "EdgeWeightedDigraph.h"
#include "EdgeWeightedGraph.h"
#include <iostream>
#include<queue>
using namespace std;
namespace Graphsearch {

	/**
		* Fuehrt eine rekursive Tiefensuche im Graphen G,
		* ab dem Knoten v aus und markiert alle besuchten
		* Knoten in marked.
		* Alle besuchten Knoten werden ausgegeben.
		*
		* \param[in]	 G			Graph
		* \param[in]	 v			Startknoten
		* \param[in/out] marked		Bereits besuchte Knoten
		* \param[in/out] edgeTo		Vektor mit dem Nachfolgeknoten zu jedem Knoten
		*/
	void DFS_recursive(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		/*
		 * TODO
		 */
		int counter1 = 0;
		
		marked[v] = true;
		counter1++;
		std::cout << v;
		if (counter1 !=G.getV()) {
			std::cout << " -> ";
		}

		
		for (int i = 0; i != G.getAdj(v).size(); i++) {
			
			if (!marked[G.getAdj(v)[i].other(v)]) {
				edgeTo[G.getAdj(v)[i].other(v)] = v;
				DFS_recursive(G, G.getAdj(v)[i].other(v), marked, edgeTo);
			}
		}
		
	
	}

	/**
		* Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus.
		* Alle besuchten Knoten werden ausgegeben.
		* Starterfunktion zu DFS_recursive(EdgeWeigtedGraph, int, std::vector<bool>, std::vector<int>)
		*
		* \param[in]  G			Graph
		* \param[out] marked	Bereits besuchte Knoten
		* \param[out] edgeTo	Vektor mit dem Nachfolgeknoten zu jedem Knoten
		* \param[in]  v			Startknoten
		* \return	  true		Graph ist zusammenhaengend
		*			  false		Graph ist nicht zusammenhaengend
		*/

	bool DFS(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		/*
		 * TODO
		 */
		std::cout << "Tiefensuche(Depth - First - Search(DFS)) - Startknoten: " << v << std::endl;
		std::cout << "Besuchsreihenfolge :" << std::endl;
		for (int i = 0; i < marked.size(); i++) {
			marked[i] = false;
		}
		for (int i = 0; i < edgeTo.size(); i++) {
			edgeTo[i] = -1;
		}
		int s = v;
		marked[v] = true;
		
		DFS_recursive(G, s, marked, edgeTo);

		for (int j = 0; j < G.getAdj(v).size(); j++) {
			if (!marked[j]){
				return false;
			    
			}
		}
		std::cout << std::endl;
		std::cout << "Graph ist zusammenhaengend" << std::endl;
		return true;
	}
	
	

	
	/**
		* Fuehrt eine iterative Breitensuche im Graphen g, ab dem Knoten v aus.
		* Alle besuchten Knoten werden ausgegeben.
		*
		* \param[in]  G			Graph
		* \param[in]  v			Startknoten
		* \param[out] marked	Gibt an welche Knoten besucht wurden bei der Suche
		* \param[out] edgeTo	Gibt den Nachfolgerknoten eines Knoten an
		* \return	  true		Graph ist zusammenhaengend
		*			  false		Graph ist nicht zusammenhaengend
		*/
	bool BFS(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		/*
		 * TODO:
		 */
		std::cout << "Breitensuche (Breadth-First-Search (BFS)) - Startknoten: " << v << std::endl;
		std::cout << "Besuchsreihenfolge :" << std::endl;
		for (int i = 0; i < marked.size(); i++) {
			marked.at(i) = false;
		}
		for (int j = 0; j < edgeTo.size(); j++) {
			edgeTo.at(j) = -1;
		}
		std::queue  <int> q;
		q.push(v);
		 int counter = 0;
		while (!q.empty()) {
			
			int test = q.front();
			if (marked[test] == false) {// wenn noch nicht visited dann ausgeben
				std::cout << test;
				counter++;
				if (counter!=G.getV()) {
					std::cout << " -> ";
				}
			}
			q.pop();
			if (marked[test] == true)
				continue;
			marked[test] = true; //das Element markieren
			int adj;
			for (int w = 0; w < G.getAdj(test).size(); ++w) {
				adj = G.getAdj(test).at(w).other(test);
				if (marked[adj] == false) {
					edgeTo[adj] = test;
					q.push(adj);
				}
			}
			
			
		}
		for (int k = 0; k < G.getAdj().size(); k++) {// prüfen ob der Graph zusammenhängend ist
			if (marked.at(k) == false) {
				return false;
			}

		}
		std::cout << std::endl;
		std::cout << "Graph ist zusammenhaengend"<<std::endl;
		return true;

	}
}
