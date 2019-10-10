#include <iostream>
#include <cmath>
#include <random>

double f(const double& x) {
	return (-1) * sqrt(x) * sin(x);
}

double findMinimum(const double& a, const double& b,
		           const double& P, const double& q) {
	// вычисляем количество точек
	size_t N = size_t(log(1 - P) / log(1 - q)) + 1;
	// за минимум берем максимально возможное значение у double
	double min = std::numeric_limits<double>::max();
	// создаем генератор
	std::random_device rd;
    std::mt19937_64 randomGenerator(rd());
	for (size_t i = 0; i < N; i++) {
		// генерируем значение от 0 до 1, тк
		// сгенерированное число делим на предел генератора
		double x = double(randomGenerator()) / std::mt19937_64::max();
		// растягиваем это число по данному интервалу [a,b]
    	x = (b - a) * x + a;
    	std::cout << "x: " << x << std::endl;
    	// попутно ищем минимальное значение сгенерированных точек
    	if (f(x) < f(min)) {
    		min = f(x);
    	}
	}

	return min;
}

int main() {
	double a = 0;
	double b = 3;
	double P;
	double q;
	for (double P = 0.9; P < 1.; P += 0.01) {
		for (double q = 0.005; q <= 0.1; q+= 0.005) {
			std::cout << "P: " << P << std::endl;
			std::cout << "q: " << q << std::endl;
			std::cout << findMinimum(a,b,P,q) << std::endl << std::endl;
		}
	}
	
	return 0;
}
