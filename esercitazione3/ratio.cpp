#include <iostream>
#include "rational.hpp"

int main() {
	rational<int> r1;
	rational<int> r2(-2,5);
	rational<int> r3(5,0);
	rational<int> r4(-2,0);
	rational<int> r5(0,0);
	std::cout << "r1 = " << r1 << "\n";
	std::cout << "r2 = " << r2 << "\n";
	std::cout << "r3 = " << r3 << "\n";
	std::cout << "r4 = " << r4 << "\n";
	std::cout << "r5 = " << r5 << "\n";
	std::cout << "r4*r1 = " << r4*r1 << "\n";
	std::cout << "r4*r2 = " << r4*r2 << "\n";
	std::cout << "r4*r3 = " << r4*r3 << "\n";
	std::cout << "r4*r4 = " << r4*r4 << "\n";
	std::cout << "r4*r5 = " << r4*r5 << "\n";
	std::cout << "r4+r1 = " << r4+r1 << "\n";
	std::cout << "r4+r2 = " << r4+r2 << "\n";
	std::cout << "r4+r3 = " << r4+r3 << "\n";
	std::cout << "r4+r4 = " << r4+r4 << "\n";
	std::cout << "r4+r5 = " << r4+r5 << "\n";
	std::cout << "r4-r1 = " << r4-r1 << "\n";
	std::cout << "r4-r2 = " << r4-r2 << "\n";
	std::cout << "r4-r3 = " << r4-r3 << "\n";
	std::cout << "r4-r4 = " << r4-r4 << "\n";
	std::cout << "r4-r5 = " << r4-r5 << "\n";
	std::cout << "r4/r1 = " << r4/r1 << "\n";
	std::cout << "r4/r2 = " << r4/r2 << "\n";
	std::cout << "r4/r3 = " << r4/r3 << "\n";
	std::cout << "r4/r4 = " << r4/r4 << "\n";
	std::cout << "r4/r5 = " << r4/r5 << "\n\n";
	rational<int> r6(5,-1);
	std::cout << "r2 = " << r2 << "\n";
	std::cout << "r6 = " << r6 << "\n";
	std::cout << "r2 + r6 = " << r2+r6 << "\n";
	std::cout << "r2 - r6 = " << r2-r6 << "\n";
	std::cout << "r2 * r6 = " << r2*r6 << "; denominatore: " << (r2*r6).den() << "\n";
	std::cout << "r2 / r6 = " << r2/r6 << "\n";
	return 0;
}