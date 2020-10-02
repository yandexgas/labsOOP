#pragma once
#include <iostream>

namespace BigInt {
	class BigIntClass {
	private:
		static const int MaxLen = 47;
		char num[MaxLen+1];
		char* Inverce(char*, int p) const;
		char* Inverce(char*) const;
		template <class in>
		BigIntClass(in&,bool b);

	public:
		BigIntClass();
		BigIntClass(std::istream&);
		BigIntClass(long int& a) :BigIntClass(a, true) {};
		BigIntClass(int& a) :BigIntClass(a, true) {};
		BigIntClass(const char* str);
		//BigIntClass(BigIntClass&&);
		BigIntClass(const BigIntClass&);
		std::istream& Input(std::istream& i = std::cin);
		std::ostream& Output(std::ostream& c = std::cout) const;
		BigIntClass& Add(const BigIntClass&,int sgn =0);
		//BigIntClass& Add(long int&,int sgn=0);
		BigIntClass& Sub(const BigIntClass& a) { return Add(a, 1); };
		//BigIntClass& Sub(long int& a) {return Add(a, 1); };
		BigIntClass& Mult10();
		BigIntClass& Dev10();		
	};
}
