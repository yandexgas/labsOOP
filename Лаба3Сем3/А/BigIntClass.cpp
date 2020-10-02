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
	template <class in>
	bi::BigIntClass(in & a,bool b):BigIntClass() {
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
			for (int l = 1;l <= MaxLen - k+1;l++)
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
	bi::BigIntClass(const char* str):BigIntClass() {
		try {
			bool zero=true;
			int l = strlen(str), z = 0;
			if (l > MaxLen)
				throw "Overflow";
			if (str[0] == '-') {
				num[0] = '9';
				z++;
				l--;
			}
			else num[0] = '0';
			if (l != strspn(str+ (num[0] == '9' ? 1 : 0), "0123456789"))
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
				std::cout << "The number should include only '-'at the begin and '0-9' chars."<<std::endl;
				num[0] = '0';
			}
		}
		catch (...) {
			std::cout << "Nullptr" << std::endl;
		}
	}
	bi::BigIntClass(std::istream& i):BigIntClass(){
		Input(i);
	}
	bi::BigIntClass(const bi& orig) {
		for (int i = 0;i < MaxLen + 1;i++)
			num[i] = orig.num[i];
	}
	char* bi::Inverce(char* obr)const {
		bool sgn = num[0] == '0' ? false : true;
		bool pr = true;
		bool zero = true;
		obr[0] = num[0];
		for (int i = MaxLen;i >0 ;i--) {
			if (sgn) {				
					if (pr) {
						if (num[i] == '0') {
							obr[i] = num[i];
						}
						else {
							obr[i] = (char)10 - (num[i] - '0') + '0';
							pr = false;
							zero = false;
						}
					}
					else
					obr[i] = (char)9 - (num[i] - '0') + '0';				
			}
			else obr[i] = num[i];
		}
		if (zero) obr[0] = '0';
		return obr;
	}
	char* bi::Inverce(char* num,int p)const {
		bool sgn = num[0] == '0' ? false : true;
		bool pr = true;
		bool zero = true;
		for (int i = MaxLen ;i > 0;i--) {
			if (sgn) {					
					if (pr&&num[i]!='0') {
						num[i] = (char)10 - (num[i] - '0') + '0';
						pr = false;
						zero = false;
					}
					else if(!pr)
						num[i] = (char)9 - (num[i] - '0') + '0';				
			}
		}
		if (zero) num[0] = '0';
		return num;
	}
	std::istream& bi::Input(std::istream& i) {
		try {
			char n[MaxLen + 1];
			i >> n;
			bool zero = true;
			int l = strlen(n), z = 0;
			if (l > MaxLen)
				throw "Overflow";
			if ((l - (n[0] == '-' ? 1 : 0)) != strspn(n + (n[0] == '-' ? 1 : 0), "0123456789"))
				throw "Data error!";
			if (n[0] == '-') {
				num[0] = '9';
				z++;
				l--;
			}
			else num[0] = '0';		
			for (int k = 1;k <= MaxLen - l;k++) {
				num[k] = '0';
			}
			for (int k = MaxLen - l + 1;k <= MaxLen; k++) {
				num[k] = n[z];
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
			}
		}
		catch (...) {
			std::cout << "Nullptr" << std::endl;
		}
	}
	std::ostream& bi::Output(std::ostream& c) const {
		if (num[0] == '9')
			c << "-";
		bool print = false;
		for (int i = 1;i <= MaxLen;i++) {
			if (!print && num[i] != '0')
				print = true;
			if (print)
				c << num[i];
		}
		if (!print)
			c << '0';
		c << std::endl;
		return c;
	}
	bi& bi::Add(const bi& BSlg,int sgn) {
		try {
			char slg1[MaxLen+1];
			bool prInd = ((num[0] == BSlg.num[0] && sgn == 0) || (num[0] != BSlg.num[0] && sgn != 0));
			Inverce(slg1);
			char slg2[MaxLen + 1];
			BSlg.Inverce(slg2);
			if (sgn != 0) {
				if (slg2[0] == '9') {
					Inverce(slg2,0);
					slg2[0] = '0';
				}
				else {
					slg2[0] = '9';
					Inverce(slg2,0);
				}
			}
			int rs, pr = 0;
			for (int i = MaxLen;i >= 0;i--) {
				if (slg1[i] - '0' + slg2[i] - '0' + pr < 10) {
					slg1[i] = (char)slg1[i] - '0' + slg2[i] - '0' + pr + '0';
					pr = 0;				
				}
				else {
					slg1[i] = (char)slg1[i] - '0' + slg2[i] - '0' + pr + '0' - 10;
					pr = 1;					
				}
			}
			if (pr > 0 && prInd && slg1[1] == '0')
				throw - 1;
			Inverce(slg1,0);
			for (int i = 0;i <= MaxLen;i++)
				num[i] = slg1[i];
			return *this;
		}
		catch (...) {
			std::cout << "Overflow!!!" << std::endl;
			return *this;
		}
	}
	/*BigIntClass& bi::Add(long int& slg, int sgn) {
		BigIntClass slg2(slg);
		return Add(slg2,sgn);
	}*/
	BigIntClass& bi::Mult10() {
		try {
			if (num[1] != '0')
				throw - 1;
			for (int i = 2;i < MaxLen;i++)
				num[i] = num[i + 1];
			num[MaxLen] = '0';
			return *this;
		}
		catch (...) {
			std::cout << "Overflow!!!!" << std::endl;
			return *this;
		}
	}
	BigIntClass& bi::Dev10() {
		bool zero = true;
		for (int i = MaxLen;i > 1;i--) {
			num[i] = num[i - 1];
			if(zero&&(num[i]!='0'||num[i-1]!='0'))
				zero =false;
		}
		num[1] = '0';
		if (zero)
			num[0] = '0';
		return *this;
	}
}
