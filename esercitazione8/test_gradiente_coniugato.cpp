#include <iostream>
#include <Eigen/Dense>
#include "gradiente_coniugato.hpp"

int main() {
    const double tol = 1.0e-15;
	unsigned int n = 10;

	Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
	while (abs(B.determinant()) < tol)
		B = Eigen::MatrixXd::Random(n, n);
	
	//se la matrice B è non singolare, A = B*B' è simmetrica definita positiva
	Eigen::MatrixXd A = B.transpose() * B;
	
	Eigen::VectorXd x_true = Eigen::VectorXd::Random(n);
	Eigen::VectorXd b = A * x_true;
	Eigen::VectorXd x_0 = Eigen::VectorXd::Zero(n);
	
    Eigen::VectorXd x = gradiente_coniugato(A, b, x_0, 1e-12, 500);

    double err = (x - x_true).norm();

    std::cout << "Errore soluzione: ||x - x_true|| = " << err << "\n";

    if (err < 1e-6)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}
