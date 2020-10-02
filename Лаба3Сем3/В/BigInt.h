#pragma once
#include <iostream>

namespace BigInt {
	class BigIntClass {
	private:
		static const int MaxLen = 47;
		int len;
		char* num;
		BigIntClass(const char*, int&);
		BigIntClass(const BigIntClass& orig,int);
		BigIntClass(int, int);
		void correction();

	public:
		BigIntClass();
		BigIntClass(std::istream& i) :BigIntClass() { i >> *this; };
		BigIntClass(long int a);
		BigIntClass( int a);
		BigIntClass(const char* str);
		BigIntClass(BigIntClass&& orig) :len(orig.len), num(orig.num) {orig.num = nullptr;}
		BigIntClass(const BigIntClass&);
		const BigIntClass operator ~ () const;
		friend std::istream& operator >> (std::istream& i, BigIntClass&);
		friend std::ostream& operator <<(std::ostream& c, const BigIntClass&);
		friend BigIntClass operator +(const BigIntClass&, const BigIntClass&);
		const BigIntClass operator-() const;
		friend BigIntClass operator -(const BigIntClass& a, const BigIntClass& b) { return a + (-b); };
		friend BigIntClass& operator +=(BigIntClass& left, const BigIntClass& right) { left = left + right; return left; };
		friend BigIntClass& operator -=(BigIntClass& left, const BigIntClass& right) { left = left + (-right); return left; };
		const BigIntClass operator*(const int&);
		const BigIntClass operator / (const int&);
		friend BigIntClass& operator *=(BigIntClass& left, const int& right) { left = left * right; return left; };
		friend BigIntClass& operator /=(BigIntClass& left, const int& right) { left = left / right; return left; };
		BigIntClass& operator=(const BigIntClass&);
		BigIntClass& operator=(BigIntClass&&);
		explicit operator int() const;
		~BigIntClass() { delete[]num; }
	};
}
