#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include "undirected_graph.hpp"
#include "contenitori.hpp"
#include "graph_visit.hpp"
#include "dijkstra.hpp"
#include "randfiller.h"

int main() {
//prima parte: bfs e dfs
	randfiller rf;
	int e = 20; //numero di archi
	int n = 9; //10 nodi numerati 0-9
	std::vector<int> v;
	v.resize(2*e);
	rf.fill(v, 0, n);
	std::set<int> nodes;
	std::set<undirected_edge> edges;
	
	for (int i=0; i<=n; i++) {
		nodes.insert(i);
	}
	
	for (int i=0; i<e; i++) {
		undirected_edge arco(v[2*i],v[2*i+1]);
		edges.insert(arco);
	}
	
	undirected_graph G(nodes,edges);
	
	std::cout << "\n\n----------G----------\n";
	for (const auto& node : G.all_nodes()) {
		std::cout << "[" << node << "] = { ";
		for (const auto& neighbour : G.neighbours(node))
			std::cout << neighbour << " ";
		std::cout << "}\n";
	}
	
	auto G_result = recursive_dfs(G,2);
	std::cout << "\n\n----dfsG source:2----\n";
	for (const auto& node : G_result.all_nodes()) {
		std::cout << "[" << node << "] = { ";
		for (const auto& neighbour : G_result.neighbours(node))
			std::cout << neighbour << " ";
		std::cout << "}\n";
	}
	
	lifo s;
	auto dfsG = graph_visit(G,2,s);
	std::cout << "\n\n----dfsG source:2----\n";
	for (const auto& node : dfsG.all_nodes()) {
		std::cout << "[" << node << "] = { ";
		for (const auto& neighbour : dfsG.neighbours(node))
			std::cout << neighbour << " ";
		std::cout << "}\n";
	}
	
	fifo q;
	auto bfsG = graph_visit(G,2,q);
	std::cout << "\n\n----bfsG source:2----\n";
	for (const auto& node : bfsG.all_nodes()) {
		std::cout << "[" << node << "] = { ";
		for (const auto& neighbour : bfsG.neighbours(node))
			std::cout << neighbour << " ";
		std::cout << "}\n";
	}
	
//seconda parte: dijkstra

	int INF = 1e7;
	std::set<int> nodes_dijk = {0,1,2,3};
	undirected_edge edge1(0,1);
	undirected_edge edge2(1,2);
	undirected_edge edge3(2,3);
	undirected_edge edge4(0,3);
	undirected_edge edge5(1,3);
	std::set<undirected_edge> edges_dijk = {edge1,edge2,edge3,edge4,edge5};
	std::vector<std::vector<int>> pesi =
	{
		{0,1,INF,6},
		{1,0,1,1},
		{INF,1,0,1},
		{6,1,1,0}
	};

	undirected_graph G_dijk(nodes_dijk,edges_dijk);
	std::cout << "\n\n--------G_dijk-------\n";
	for (const auto& node : G_dijk.all_nodes()) {
		std::cout << "[" << node << "] = { ";
		for (const auto& neighbour : G_dijk.neighbours(node))
			std::cout << neighbour << " ";
		std::cout << "}\n";
	}
	
	int sorgente = 0;
	auto results = dijkstra(G_dijk,sorgente,pesi);
	
	int actual_node;
	for (auto arrivo : nodes_dijk) {
		std::cout << "\nCammino minimo (" << sorgente << "," << arrivo << "): ";
		actual_node = arrivo;
		while (actual_node != sorgente) {
			std::cout << actual_node << " ";
			actual_node = results.pred[actual_node];
		}
		std::cout << sorgente << "\ndistanza: " << results.dist[arrivo] << "\n";
	}
	
	return 0;
}