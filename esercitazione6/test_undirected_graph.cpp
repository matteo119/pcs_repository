#include <iostream>
#include <vector>
#include "randfiller.h"
#include "undirected_graph.hpp"

int main() {
	randfiller rf;
	int e = 50; //numero di archi
	int n = 19; //20 nodi numerati 0-19
	std::vector<int> v;
	v.resize(2*e);
	rf.fill(v, 0, n);
	std::set<int> nodes;
	std::set<undirected_edge> edges;
	
	std::cout << "\nINPUT archi G:\n";
	for (int i=0; i<e; i++) {
		undirected_edge arco(v[2*i],v[2*i+1]);
		edges.insert(arco);
		std::cout << arco << " ";
	}
	
	std::cout << "\n\nINPUT nodi G:\n";
	for (int i=0; i<=n; i++) {
		nodes.insert(i);
		std::cout << i << " ";
	}
	
	undirected_graph G(nodes,edges);
	
	std::cout << "\n\nall_edges() G\n";
	for (auto& edge : G.all_edges()) {
		std::cout << edge << " ";
	}
	
	std::cout << "\n\nneighbours G\n";
	for (auto& node : G.all_nodes()) {
		std::cout << "[" << node << "] = { ";
		for (auto& neighbour : G.neighbours(node))
			std::cout << neighbour << " ";
		std::cout << "}\n";
	}
	
	int e_add=30;
	std::vector<int> v_add;
	v_add.resize(2*e_add);
	rf.fill(v_add, 0, n);
	std::cout << "\nINPUT nuovi archi G:\n";
	for (int i=0; i<e_add; i++) {
		undirected_edge arco(v_add[2*i],v_add[2*i+1]);
		G.add_edges(arco);
		std::cout << arco << " ";
	}
	
	std::cout << "\n\nall_edges() G\n";
	for (auto& edge : G.all_edges()) {
		std::cout << edge << " ";
	}
	
	std::cout << "\n\nneighbours G\n";
	for (auto& node : G.all_nodes()) {
		std::cout << "[" << node << "] = { ";
		for (auto& neighbour : G.neighbours(node))
			std::cout << neighbour << " ";
		std::cout << "}\n";
	}
	
	int t=5; //prove di ricerca
	std::vector<int> v_number;
	v_number.resize(t);
	rf.fill(v_number, 0, e+e_add);
	std::cout << "\n\nricerca archi in G\n";
	for (int i=0; i<t; i++) {
		std::cout << "arco in posizione " << v_number[i] << ": " << G.edge_at(v_number[i]) << "\n";
	}
	
	std::vector<int> v_search;
	v_search.resize(2*t);
	rf.fill(v_search, 0, n);
	std::cout << "\n\nricerca posizione arco in G\n";
	for (int i=0; i<t; i++) {
		undirected_edge arco(v_search[2*i], v_search[2*i+1]);
		std::cout << "l'arco " << arco << " si trova in posizione: " << G.edge_number(arco) << "\n";
	}
	
	std::vector<int> v1;
	v.resize(2*e);
	rf.fill(v, 0, n);
	std::set<int> nodes1;
	std::set<undirected_edge> edges1;
	
	std::cout << "\nINPUT archi G1:\n";
	for (int i=0; i<e; i++) {
		undirected_edge arco(v[2*i],v[2*i+1]);
		edges1.insert(arco);
		std::cout << arco << " ";
	}
	
	std::cout << "\n\nINPUT nodi G1:\n";
	for (int i=0; i<=n; i++) {
		nodes1.insert(i);
		std::cout << i << " ";
	}
	
	undirected_graph G1(nodes1,edges1);
	undirected_graph G2 = G-G1;
	std::cout << "\n\nneighbours G1\n";
	for (auto& node : G.all_nodes()) {
		std::cout << "[" << node << "] = { ";
		for (auto& neighbour : G1.neighbours(node))
			std::cout << neighbour << " ";
		std::cout << "}\n";
	}
	std::cout << "\n\nneighbours G2\n";
	for (auto& node : G2.all_nodes()) {
		std::cout << "[" << node << "] = { ";
		for (auto& neighbour : G2.neighbours(node))
			std::cout << neighbour << " ";
		std::cout << "}\n";
	}
	
	return 0;
}