#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include "graph_visit.hpp"
#include "undirected_graph.hpp"

struct path_info {
    std::vector<int> pred;
    std::vector<int> dist;
};

path_info dijkstra(const undirected_graph& G, int sorgente, std::vector<std::vector<int>>& pesi) {
	std::priority_queue<
		std::pair<int,int>,
		std::vector<std::pair<int,int>>,
		std::greater<std::pair<int,int>>
	> PQ; //cambio il comparatore, top() restituisce la minima distanza
	path_info sssp;
	
	int n = G.all_nodes().size();
	int INF = 1e7;
	sssp.pred.resize(n);
	sssp.dist.resize(n);
	for (int i=0; i<n; i++) {
		sssp.pred[i] = -1;
		sssp.dist[i] = INF;
	}
	sssp.pred[sorgente] = sorgente;
	sssp.dist[sorgente] = 0;
	PQ.push({0,sorgente});
	
	while (!PQ.empty()) {
		auto [prior_dist, u] = PQ.top();
		PQ.pop();
		if (prior_dist > sssp.dist[u]) continue;
		for (const auto& node : G.neighbours(u)) {
			if (sssp.dist[node] > sssp.dist[u] + pesi[u][node]) {
				sssp.dist[node] = sssp.dist[u] + pesi[u][node];
				sssp.pred[node] = u;
				PQ.push({sssp.dist[node], node});
			}
		}
	}
	return sssp;
}