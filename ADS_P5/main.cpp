#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include "EdgeWeightedGraph.h"
#include "PrimMST.h"
#include "Graphsearch.h"
#include "KruskalMST.h"
#include "DijkstraSP.h"
#include<iomanip>
using namespace std;

void print_Adj(EdgeWeightedGraph graph) {
	vector<vector<Edge>> adj = graph.getAdj();

	for (int i = 0; i < adj.size(); i++) {
		cout << i;
		for (int j = 0; j < adj[i].size(); j++) {
			cout << " -> " << adj[i][j].other(i) << " [" << adj[i][j].weight() << "]";
		}
		cout << endl;
	}
}
int main() {
	// Starte Unit-Tests
	Catch::Session().run();
	EdgeWeightedGraph graph("graph1.txt");
	int start = 0;

	vector<bool> marked;
	vector<int>  edgeTo;
	marked.resize(42, false);	// Dummy values, damit die unit-Tests mit 
	edgeTo.resize(42, -1);

	while (true) {
		cout << "Praktikum 5: Graphenalgorithem: " << endl;
			cout<<" 1) Graph einlesen" << endl;
			cout <<" 2) Tiefensuche" << endl;
			cout <<" 3) Breitensuche" << endl;
			cout << "4) MST nach Prim" << endl;
			cout << "5) MST nach Kruskal" << endl;
			cout << "6) K¨urzeste Wege nach Dijkstra" << endl;
			cout << "7) Ausgabe der Adjazenzliste" << endl;
			cout << "8) Programm beenden" << endl;
			cout << "Weiter mit beliebiger Eingabe ..." << endl;
			int k;
			cin >> k;
			if(k==1){
				cout << "wählen Sie ein Dokument :? ";
					int i;
					cin >> i;
					if (i == 1)
					{
						graph =EdgeWeightedGraph("graph1.txt") ;
						cout << "Der Graph 1 wurde ausgewaehlt." << endl;
						print_Adj(graph);
					}
					else if (i == 2) {
						 graph = EdgeWeightedGraph("graph2.txt");
						cout << "Der Graph 2 wurde ausgewaehlt." << endl;
						print_Adj(graph);
					}
					else if (i == 3) {
						graph = EdgeWeightedGraph("graph3.txt");
						cout << "Der Graph 3 wurde ausgewaehlt." << endl;
						print_Adj(graph);
					}
					cout << "was wollen Sie noch machen ?: ";
					cin >> k;
			}
			if (k == 2) {
				
				cout << "Was ist der Startknoten ? : ";
				cin >> start;
				cout << endl;
				Graphsearch::DFS(graph, start,  marked,  edgeTo);
				cout << endl;
				cout << "was wollen Sie noch machen ?: ";
				cin >> k;
			}
			if (k == 3) {
				
				cout << "Was ist der Startknoten ? : ";
				cin >> start;
				cout << endl;
				Graphsearch::BFS(graph, start, marked, edgeTo);
				cout << endl;
				cout << "was wollen Sie noch machen ?: ";
				cin >> k;
			}
			if (k == 4) {
				cout << "Was ist der Startknoten ? : ";
				cin >> start;
				cout << endl;
				PrimMST prim(graph, start);
				EdgeWeightedGraph test=EdgeWeightedGraph(graph.getV(), prim.get_mst());
				print_Adj(test);
				cout << "was wollen Sie noch machen ?: ";
				cin >> k;
			}

			if (k == 5) {
				KruskalMST kruskal(graph);
				EdgeWeightedGraph test = EdgeWeightedGraph(graph.getV(), kruskal.get_mst());
				print_Adj(test);
				cout << "was wollen Sie noch machen ?: ";
				cin >> k;
			
			}
			if (k == 6) {
				cout << "Was ist der Startknoten ? : ";
				cin >> start;
				cout << endl;
				int ziel = 0;
				cout << "Was ist der Zielknoten ? : ";
				cin >> ziel;
				cout << endl;

				string str = "";
				cout << "Wählen sie einen Graph aus ?: ";
				cin >> str;
				EdgeWeightedDigraph diagraph =EdgeWeightedDigraph(str);
				DijkstraSP dijkstra= DijkstraSP( diagraph , start);

				
				vector<DirectedEdge> adj =dijkstra.pathTo(ziel);

				for (int i = 0; i < adj.size(); i++) {
					cout << adj[i].from();
					
						cout << " -> " << adj[i].to() << " [" << adj[i].weight() << "]";
					
					
				}
				cout << endl;
				cout << "was wollen Sie noch machen ?: ";
				cin >> k;
            }
			if (k == 7) {
				print_Adj(graph);
				cout << endl;
				cout << "was wollen Sie noch machen ?: ";
				cin >> k;
			}
			if (k == 8) {
				break;
			}
		//------------------------------------------------------------------------
		// 1. Ausgabe eines Graphen als Adjazenzliste implementieren
		//------------------------------------------------------------------------



		//------------------------------------------------------------------------
		// 2. Suche in Graphen
		//------------------------------------------------------------------------
		// Verwenden Sie hierf�r die Vorlagen in Graphsearch.h
		//
		// Beispielaufruf der Tiefensuche: 
		// std::vector<bool> marked;
		// std::vector<int>  edgeTo;
		// bool connected = Graphsearch::DFS(G1, start, marked, edgeTo);



		//------------------------------------------------------------------------
		// 3. Minimaler Spannbaum mit Prim und Kruskal
		//------------------------------------------------------------------------
		// Vorlage f�r Prim ist die Klasse PrimMST (PrimMST.h + PrimMST.cpp)
		// Vorlage f�r Kruskal ist die Klasse KruskalMST (KruskalMST.h + KruskalMST.cpp)
		//
		// Beispielaufruf von Prim:
		// PrimMST prim(G, 0);



		//------------------------------------------------------------------------
		// 4. Kuerzeste Wege mit Dijkstra
		//------------------------------------------------------------------------
		// Beispielaufruf von Dijkstra
		//
		// EdgeWeightedDigraph G1_directed("graph1.txt");
		// Dijkstra dijkstra(G1_directed, start);
		// path = dijkstra.pathTo(target);



		//------------------------------------------------------------------------
		// 5. Men� f�r Benutzereingaben
		//------------------------------------------------------------------------
		// Alle Funktionalit�ten aus der Aufgabenstellung muessen umgesetzt werden

	}

	return 0;
}