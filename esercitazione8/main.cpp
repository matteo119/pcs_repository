#include <iostream>
#include <Eigen/Dense>
#include "gradiente_coniugato.hpp"

int main() {
	Eigen::Matrix3d A;
	A << 4, 1, 2,
         1, 3, 0,
         2, 0, 5;

    Eigen::Vector3d x_true = Eigen::Vector3d::Ones();
	Eigen::Vector3d b = A * x_true;
	Eigen::Vector3d x_0 = Eigen::Vector3d::Zero();

    Eigen::Vector3d x = gradiente_coniugato(A, b, x_0, 1e-12, 100);

    std::cout << "Soluzione trovata:\n" << x << "\n\n";
    std::cout << "Errore ||x - x_true|| = " << (x - x_true).norm() << "\n";
	return 0;
}