#include <set>
#include <unordered_map>
#include <iostream>

class undirected_edge {
	int node1, node2;
public:
	undirected_edge(int n1, int n2) : node1(n1), node2(n2) {
		if (node1 > node2) {
			node1 = n2;
			node2 = n1;
		};
	}
	int from() const {return node1;}
	int to() const {return node2;}
	
	bool operator==(const undirected_edge& other) const {
		if (node1 == other.from() && node2 == other.to()) return true;
		return false;
		}
		
	bool operator<(const undirected_edge& other) const {
		if (*this == other) return false;
		if (node1 < other.from()) return true;
		if (node1 == other.from()) {
			if (node2 < other.to()) return true;
			else return false;
		}
		return false;
	}
};

std::ostream& operator<<(std::ostream& os, const undirected_edge& edge) {
	os << "(" << edge.from() << ", " << edge.to() << ")";
	return os;
}

class undirected_graph {
	std::set<int> nodes;
	std::set<undirected_edge> edges;
	std::unordered_map<int,std::set<int>> neighborhood;
	
	void neighborhood_function() {
		for (const auto& edge : edges) {
			int a = edge.from();
			int b = edge.to();
			neighborhood[a].insert(b);
			neighborhood[b].insert(a);
		}
	}
public:
	undirected_graph() : nodes(), edges(), neighborhood() {}
	undirected_graph(std::set<int> n, std::set<undirected_edge> e) : nodes(n), edges(e), neighborhood() {
		neighborhood_function();
	}

	undirected_graph(const undirected_graph& other) : nodes(other.nodes), edges(other.edges), neighborhood() {
		neighborhood_function();
	};
	
	undirected_graph& add_edges(const undirected_edge& new_edge) {
		edges.insert(new_edge);
		
		int node1 = new_edge.from();
		int node2 = new_edge.to();
		
		nodes.insert(node1);
		nodes.insert(node2);
		
		neighborhood[node1].insert(node2);
		neighborhood[node2].insert(node1);
	
		return *this;
	}
	
	std::set<undirected_edge> all_edges() const {return edges;}
	std::set<int> all_nodes() const {return nodes;}
	
	undirected_edge edge_at(const int number) {
		int i=0;
		for (const auto& e : edges) {
			if (i==number) return e;
			i++;
		}
		std::cout << "Indice non valido.\n";
		return undirected_edge(0,0); //restituisce l'arco (0,0) se l'indice non è valido
	}
	
	int edge_number(const undirected_edge& edge) {
		int i=0;
		for (const auto& e : edges) {
			if (e==edge) return i;
			i++;
		}
		std::cout << "Arco non trovato.\n";
		return -1; // restituisce -1 se l'arco non c'è
	}
	
	std::set<int> neighbours(const int node) {
		if (neighborhood.contains(node)) return neighborhood[node];
		return {};
	}
	
	undirected_graph operator-(const undirected_graph& other) const {
		std::set<undirected_edge> diff_edges;
		std::set<undirected_edge> g_edges = other.all_edges();
		for (const auto& edge : edges) {
			if (!g_edges.contains(edge)) {
				diff_edges.insert(edge);
			}
		}
		undirected_graph diff_graph(nodes,diff_edges);
		return diff_graph;
	}
};