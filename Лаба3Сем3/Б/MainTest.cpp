// MainTest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "C:\Users\79044\source\repos\BigInt-2\BigInt-2\BigInt-2.cpp"
using namespace BigInt;
using namespace std;
int main()
{
	using bi =  BigInt::BigIntClass;
	int n = 0;
	cout << "1 - +\n2 - -\n3- -x\n5 - *10\n6 - /10"<<std::endl;
	while (n > -1) {
		cin >> n;
		switch (n)
		{
		case	1: {
			bi* A = new bi;
			bi* B = new bi;
			cin >> *A;
			cin >> *B;
			cout << *A + *B;
			delete A;
			delete B;
			break;
		}
		case 2: {
			bi* A = new bi;
			bi* B = new bi;
			cin >> *A;
			cin >> *B;
			cout << *A - *B;
			delete A;
			delete B;
			break;
		}
		case 3: {
			bi* A = new bi;
			cin >> *A;
			cout << -*A;
			delete A;
			break;
		}
		case 4: {
			bi* A = new bi;
			cin >> *A;
			cout << ~*A;
			delete A;
			break;
		}
		case 5: {
			bi* A = new bi;
			cin >> *A;
			cout << *A *10;
			delete A;
			break;
		}
		case 6: {
			bi* A = new bi;
			bi* B = new bi;
			cin >> *A;
			cout << *A/10;
			delete A;
			break;
		}
		default:
			break;
		}
	}


}

