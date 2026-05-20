#pragma once
#include <iostream>
#include <set>
#include <vector>
#include "undirected_graph.hpp"
#include "contenitori.hpp"

template<typename T>
undirected_graph graph_visit(const undirected_graph& G, int sorgente, T& c) {
	std::cout << "Non hai usato i contenitori fifo o lifo\n";
	return undirected_graph();
}

template<>
undirected_graph graph_visit<fifo>(const undirected_graph& G, int sorgente, fifo& c) {
	int n = G.all_nodes().size(); //numero di nodi
	std::vector<bool> reached(n, false);
	std::set<int> nodes = G.all_nodes();
	std::set<undirected_edge> edges;
	c.put(sorgente);
	reached[sorgente] = true;
	while (!c.empty()) {
		int u = c.get();
		for (const auto& node : G.neighbours(u)) {
			if (!reached[node]){
				reached[node] = true;
				c.put(node);
				undirected_edge edge(u, node);
				edges.insert(edge);
			}
		}
	}
	return undirected_graph(nodes,edges);
}

template<>
undirected_graph graph_visit<lifo>(const undirected_graph& G, int sorgente, lifo& c) {
	int n = G.all_nodes().size(); //numero di nodi
	std::vector<bool> reached(n, false);
	std::vector<int> padre(n, -1);
	/*padre.resize(n);
	for (int i=0; i<n; i++) {
		padre[i] = -1;
	}*/
	std::set<int> nodes = G.all_nodes();
	std::set<undirected_edge> edges;
	
	c.put(sorgente);
	while (!c.empty()) {
		int u = c.get();
		if (reached[u]) {
			continue;
		}
		if (padre[u]!=-1) {
			undirected_edge edge(u, padre[u]);
			edges.insert(edge);
		}
		reached[u] = true;
		for (const auto& node : G.neighbours(u)) {
			if (!reached[node]){
				c.put(node);
				padre[node] = u;
			}
		}
	}
	return undirected_graph(nodes,edges);
}

void visita(const undirected_graph& G, int u, std::vector<bool>& reached, undirected_graph& dfsG)
{
    reached[u] = true;
	std::set<int> neigh = G.neighbours(u);
    for (auto it = neigh.end(); it != neigh.begin();) {
		--it;
		int v = *it;
        if (!reached[v]) {
			undirected_edge path(u,v);
            dfsG.add_edges(path);
            visita(G, v, reached, dfsG);
        }
    }
}

undirected_graph recursive_dfs(const undirected_graph& G, int sorgente)
{
    undirected_graph dfsG;
    int n = G.all_nodes().size(); //numero di nodi
	std::vector<bool> reached(n, false);

    visita(G, sorgente, reached, dfsG);

    return dfsG;
}
