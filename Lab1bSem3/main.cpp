#include <iostream>
#include "Versiera.h"
int main() {
	using namespace Lab2;
	ProectionPoint p(0, 0);
	Versiera v(p, 1);
	int ff = 1;
	char* s = nullptr;
	while (ff) {
		std::cout << "Your Versiera is: " << std::endl;
		s = v.Equation();
		std::cout << s << std::endl;
		std::cout << "Inflection point 1:( " << v.Inflections()[0].x<<","<<v.Inflections()[0].y<<")" << std::endl;
		std::cout << "Inflection point 2:( " << v.Inflections()[1].x << "," << v.Inflections()[1].y << ")" << std::endl;
		std::cout << "Space: "<< v.Space() << std::endl;
		std::cout << "Volume: "<< v.Volume() << std::endl;
		std::cout << "D = " << v.getD() << std::endl;
		std::cout << "Proection point: " << v.getp().x << "," << v.getp().y << std::endl;
		double x0;
		std::cout << "Input x0" << std::endl;
		v.Gets(x0);
		std::cout << "y(x0)=" << v.y(x0) << std::endl;
		std::cout << "Please, input betwin Enter, new X and Y of new Proection point" << std::endl;
		v.Gets(p.x);
		v.Gets(p.y);
		v.setP(p);
		std::cout << "Proection point: " << v.getp().x << "," << v.getp().y << std::endl;
		std::cout << "Input D:" << std::endl;
		v.Gets(x0);
		v.setD(x0);
		std::cout << "D = " << v.getD() << std::endl;
		std::cout << "Input 0 if you want to end, or different int value if you want to retry" << std::endl;
		v.Gets(ff);
		std::cin.ignore();
	}
	delete[] s;
}