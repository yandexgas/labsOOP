#include<math.h>
#include<iostream>
namespace Lab2 {
	struct ProectionPoint
	{
		double x, y;
		ProectionPoint(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}
	};
	class Versiera
	{
	private:
		double A;
		ProectionPoint p;
	public:
		Versiera(double diam = 1);
		Versiera(const ProectionPoint& p0, double diam = 1);
		Versiera(double x0, double y0, double diam = 1);
		Versiera& setP(const ProectionPoint p0) { p = p0; return *this; }
		Versiera& setD(double diam);
		ProectionPoint getp() const { return p; };
		double getD()const { return A; };
		double y(double x)const { return (A * A * A) / (A * A + ((x - p.x) * (x - p.x))) + p.y; };
		ProectionPoint* Inflections()const;
		double Space()const;
		double Volume()const;
		char* Equation()const;
		template <class storage>
		int Gets(storage& a)const {
			int k= 1;
			while (k== 1) {
				std::cin >> a;
				if (!std::cin.good()) {
					std::cout << ">>>>> Incorrect data!";
					std::cin.clear();
				}
				else k = 0;
			}
			return 1;
		}
	};
}
