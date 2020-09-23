#include <stdio.h>
#include <string.h>
#include "Versiera.h"
#include <iostream>
#define M_PI            3.14159265358979323846

namespace Lab2 {

	Versiera::Versiera(double diam) : p(0, 0) {
		if (diam == 0)
			throw std::exception("degeneration into a straight line");
		A = diam;
	}
	Versiera::Versiera(const ProectionPoint& p0, double diam) : p(p0) {
		if (diam == 0)
			throw std::exception("degeneration into a straight line");
		A = diam;
	}
	Versiera::Versiera(double x0, double y0, double diam) : p(x0, y0) {
		if (diam == 0)
			throw std::exception("degeneration into a straight line");
		A = diam;
	}
	Versiera& Versiera::setD(double diam) {
		if (diam == 0)
			throw std::exception("degeneration into a straight line");
		A = diam;
		return *this;
	}
	ProectionPoint* Versiera::Inflections() const {
		try {
			ProectionPoint* inflects = new ProectionPoint[2];
			inflects[0] = { A / sqrt(3) + p.x,3 * A / 4 +p.y };
			inflects[1] = { -A / sqrt(3) + p.x,3 * A / 4 +p.y};
			return inflects;
		}
		catch (std::bad_alloc & ba) {
			std::cout << ba.what() << std::endl;
		}
	}
	double Versiera::Space() const {
		double S = M_PI * A * A;
		if (S == 0)
			std::cout << "degeneration into a straight line";
		return S;
	}
	double Versiera::Volume() const {
		double V = M_PI * M_PI * A * A * A / 2;
		if (V == 0)
			std::cout << "degeneration into a straight line";
		return V;
	}
	char* Versiera::Equation()const {
		int l = 27;
		char num[20];
		sprintf_s(num, 20, "%.2f", A * A * A);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", A * A);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", p.x);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", p.y);
		l += strlen(num);
		char* s = new char[l];
		if (A == 0) {
			sprintf_s(s, l, "y = %.2f", p.y);
			return s;
		}
		else {
			sprintf_s(s, l, "y = (%.2f) / (%.2f + (x", A * A * A, A * A);
			int k = strlen(s);
			if (p.x == 0) {
				sprintf_s(s + k, l - k, ")^2) ");
				k = strlen(s);
			}
			else {
				sprintf_s(s + k, l - k, " + %.2f)^2) ", p.x);
				k = strlen(s);
			}
			if (p.y != 0)
				sprintf_s(s + k, l - k, "+ %.2f", p.y);
			return s;
		}
	}
}