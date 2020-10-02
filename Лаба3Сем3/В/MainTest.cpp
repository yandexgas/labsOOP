
#include <iostream>
#include"C:\Users\79044\source\repos\BigInt-dinamic\BigInt-dinamic\BigInt-dinamic.cpp"
int main()
{
    using namespace BigInt;
    using namespace std;
    using bi = BigIntClass;
	int n = 0;
	cout << "1 - +\n2 - -\n3- -x\n5 - *10\n6 - /10" << std::endl;
	while (n > -1) {
		cin >> n;
		switch (n)
		{
		case	1: {
			bi* A = new bi;
			bi* B = new bi;
			cin >> *A;
			cin >> *B;
			cout << (int)(*A + *B);
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
			cout << *A * 10;
			delete A;
			break;
		}
		case 6: {
			bi* A = new bi;
			bi* B = new bi;
			cin >> *A;
			cout << *A / 10;
			delete A;
			break;
		}
		default:
			break;
		}
	}

    
   
   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
