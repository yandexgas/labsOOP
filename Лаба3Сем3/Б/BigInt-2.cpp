#include<iostream>
#include "pch.h"
#include "framework.h"
#include "BigInt.h"
#include<string.h>

namespace BigInt {
	using bi = BigIntClass;
	bi::BigIntClass() {
		for (int i = 0;i < MaxLen + 1;i++)
			num[i] = '0';
	}
	bi::BigIntClass(int a) :BigIntClass() {
		try {
			num[0] = a < 0 ? '9' : '0';
			a = a < 0 ? -a : a;
			int i = 10, k = 1;
			while (a/ i > 0) {
				i *= 10;
				k++;
			}
			if (k > MaxLen)
				throw "Overflow";
			for (int l = 1;l <= MaxLen - k + 1;l++)
				num[l] = '0';
			for (int l = MaxLen;l >= MaxLen - k + 1;l--) {
				num[l] = (char)(((int)'0') + a% 10);
				a /= 10;
			}
		}
		catch (...) {
			std::cout << "Your value is bigger then MaxSize." << std::endl;
		}
	}
	bi::BigIntClass(long int a) :BigIntClass() {
		try {
			num[0] = a < 0 ? '9' : '0';
			a = a < 0 ? -a : a;
			int i = 10, k = 1;
			while (a / i > 0) {
				i *= 10;
				k++;
			}
			if (k > MaxLen)
				throw "Overflow";
			for (int l = 1;l <= MaxLen - k + 1;l++)
				num[l] = '0';
			for (int l = MaxLen;l >= MaxLen - k + 1;l--) {
				num[l] = (char)(((int)'0') + a % 10);
				a /= 10;
			}
		}
		catch (...) {
			std::cout << "Your value is bigger then MaxSize." << std::endl;
		}
	}
	bi::BigIntClass(const char* str) :BigIntClass() {
		try {
			if (str == nullptr)
				throw - 1;
			bool zero = true;
			int l = strlen(str), z = 0;
			if (l > MaxLen)
				throw "Overflow";
			if(str[0]=='-') {
				num[0] = '9';
				z++;
				l--;
			}
			else num[0] = '0';
			if (l != strspn(str + (num[0] == '9' ? 1 : 0), "0123456789"))
				throw "Data error!";
			for (int k = 1;k <= MaxLen - l;k++) {
				num[k] = '0';
			}
			for (int k = MaxLen - l + 1;k <= MaxLen; k++) {
				num[k] = str[z];
				z++;
				if (zero && num[k] != '0')
					zero = false;
			}
			if (zero)
				num[0] = '0';
		}
		catch (const char* a) {
			if (a == "Overflow")
				std::cout << "Too big number!" << std::endl;
			if (a == "Data error!") {
				std::cout << "The number should include only '-'at the begin and '0-9' chars." << std::endl;
				num[0] = '0';
			}
		}
		catch (...) {
			std::cout << "Nullptr" << std::endl;
		}
	}
	/*bi::BigIntClass(const bi& orig) {
		for (int i = 0;i < MaxLen + 1;i++)
			num[i] = orig.num[i];
	}*/
	const BigIntClass bi::operator~ ()const {
		if (num[0] == '0')
			return *this;
		bool pr = true;//"запас" перенос +1 в след разряд
		BigIntClass res;
		for (int i = MaxLen;i > 0;i--) {
				if (pr && num[i] != '0') {
					res.num[i] = (char)10 - (num[i] - '0') + '0';
					pr = false;
				}
				else if (!pr)
					res.num[i] = (char)9 - (num[i] - '0') + '0';
		}
		res.num[0] = '9';
		return res;
	}
	std::istream& operator>>(std::istream& i,BigIntClass& the) {
		try {

			char n[the.MaxLen + 1];
			i >> n;
			bool zero = true;
			int l = strlen(n), z = 0;
			if (l > the.MaxLen)
				throw "Overflow";
			if ((l - (n[0] == '-' ? 1 : 0)) != strspn(n + (n[0] == '-' ? 1 : 0), "0123456789"))
				throw "Data error!";
			if (n[0] == '-') {
				the.num[0] = '9';
				z++;
				l--;
			}
			else the.num[0] = '0';
			for (int k = 1;k <= the.MaxLen - l;k++) {
				the.num[k] = '0';
			}
			for (int k = the.MaxLen - l + 1;k <= the.MaxLen; k++) {
				the.num[k] = n[z];
				z++;
				if (zero && the.num[k] != '0')
					zero = false;
			}
			if (zero)
				the.num[0] = '0';
		}
		catch (const char* a) {
			if (a == "Overflow")
				std::cout << "Too big number!" << std::endl;
			if (a == "Data error!") {
				std::cout << "The number should include only '-'at the begin and '0-9' chars." << std::endl;
			}
		}
		catch (...) {
			std::cout << "Nullptr" << std::endl;
		}
	}
	std::ostream& operator <<(std::ostream& c, const BigIntClass& the) {
		if (the.num[0] == '9')
			c << "-";
		bool print = false;
		for (int i = 1;i <= the.MaxLen;i++) {
			if (!print && the.num[i] != '0')
				print = true;
			if (print)
				c << the.num[i];
		}
		if (!print)
			c << '0';
		c << std::endl;
		return c;
	}
	bi operator+(const bi& the, const bi& BSlg) {
		try {
			bool prInd = (the.num[0] == BSlg.num[0] );
			bi slg1(~the), slg2(~BSlg);
			int rs, pr = 0;
			for (int i = the.MaxLen;i >= 0;i--) {
				if (slg1.num[i] - '0' + slg2.num[i] - '0' + pr < 10) {
					slg1.num[i] = (char)slg1.num[i] - '0' + slg2.num[i] - '0' + pr + '0';
					pr = 0;
				}
				else {
					slg1.num[i] = (char)slg1.num[i] - '0' + slg2.num[i] - '0' + pr + '0' - 10;
					pr = 1;
				}
			}
			if (pr > 0 && prInd && slg1.num[1] == '0')
				throw - 1;
			slg1 = ~slg1;
			return slg1;
		}
		catch (...) {
			std::cout << "Overflow!!!" << std::endl;
			return 0;
		}
	}
	const BigIntClass bi::operator-() const {
		bi res = *this;
		for (int i = 0;i <= MaxLen;i++) {
			if (num[i] != '0') {
				res.num[0] = num[0] == '0' ? '9' : '0';
				break;
			}				
		}
		return res;
	}
	const BigIntClass bi:: operator*(const int& a) {
		try {			
			if (a != 10)
				throw 2;
			bi res;
			if (num[1] != '0')
				throw  1;
			for (int i = 1;i < MaxLen;i++)
				res.num[i] = num[i + 1];
			res.num[MaxLen] = '0';
			res.num[0] = num[0];
			return res;
		}
		catch (int a) {
			std::cout << "Overflow!!!!" << std::endl;
			return *this;
		}
	}
	const BigIntClass bi::operator /(const int& i) {
		if (i != 10)
			throw 1;
		BigIntClass res;
		int n=0;
		bool zero = true;
		res.num[0] = num[0];
		for (int i = MaxLen;i > 1;i--) {
			res.num[i] = num[i - 1];
			if (zero && (num[i] != '0')&&i<MaxLen)
				zero = false;
		}
		res.num[1] = '0';
		if (zero)
			res.num[0] = '0';
		return res;
	}
}