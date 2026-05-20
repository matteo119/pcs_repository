#pragma once
#include <queue>
#include <stack>

class fifo {
	std::queue<int> coda;
public:
	fifo() : coda() {}
	void put(const int value) {coda.push(value);}
	int get() {
		int value = coda.front();
		coda.pop();
		return value;
		}
	bool empty() const {return coda.empty();}
};

class lifo {
	std::stack<int> pila;
public:
	lifo() : pila() {}
	void put(const int value) {pila.push(value);}
	int get() {
		int value = pila.top();
		pila.pop();
		return value;
		}
	bool empty() const {return pila.empty();}
};