#include <Eigen/Dense>

Eigen::VectorXd gradiente_coniugato(
		Eigen::MatrixXd A,
		Eigen::VectorXd b,
		Eigen::VectorXd x,
		const double res_tol,
		const unsigned int it_max)
	{
	Eigen::VectorXd res = b - A * x;
	double res_norm = res.norm();
	Eigen::VectorXd p = res;
    unsigned int it = 0;
	
	while(it < it_max && res.norm() > res_tol * res_norm) {
		const double alpha = ((p.transpose() * res)/(p.transpose() * A * p)).value();
		x = x + alpha * p;
		res = b - A * x;
		const double beta = ((p.transpose() * A * res)/(p.transpose() * A * p)).value();
		p = res - beta * p;
		it++;
	}
	return x;
}