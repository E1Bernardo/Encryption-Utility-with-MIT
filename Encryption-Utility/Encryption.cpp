#include <iostream>
#include <vector>
#include<fstream>

using namespace std;
// проверку на простоту и прочие большие куски можно сделать в отдельные функции 


void encryption(vector <unsigned __int8>& inputf)
{
	unsigned __int64 p, q;
	bool check_p_2 = false , check_q_2 = false;
	do // Проверка на натуральность первого числа  Checking for the naturalness of the first number
	{
		int check_p = 0;
		cout << "Enter first prime number\n";
		cout << "p = ";
		cin >> p;
		for (unsigned __int64 i = 2; i <= sqrt(p); i++)
			if (p % i == 0) check_p++;

		if (check_p == 0) check_p_2 = true;
		else 
		{
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			cout << "\nEntered number is not prime, repeat the entry:\n";
		}
	} while (check_p_2 == false);
	cout << endl;
	do //Проверка на натуральность второго числа   Checking for the naturalness of the second number
	{
		int check_q = 0;
		cout << "Enter second prime number\n";
		cout << "q = ";
		cin >> q;
		for (unsigned __int64 i = 2; i <= sqrt(q); i++)
			if (q % i == 0) check_q++;

		if (check_q == 0) check_q_2 = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			cout << "\nEntered number is not prime, repeat the entry:\n";
		}
	} while (check_q_2 == false);


	unsigned __int64 module = p * q;  // Модуль   Module
	unsigned __int64 f_Euler = (p - 1) * (q - 1);  // Функция Эйлера   Func Euler
	unsigned __int64 open_exhibitor;  // Открытая экспонента   Open Exhibitor
	vector <unsigned __int64>open_exhibitor_array(0);

	for (unsigned __int64 i = 2; i < f_Euler; i++)
	{
		int check = 0;
		for (unsigned __int64 j = 1; j <= sqrt(i); j++)
			if (i % j == 0) check++;
		
			if (check == 1 && i % f_Euler !=0)
			{
				open_exhibitor_array.insert(open_exhibitor_array.end(),i);
			}
	}

	for (size_t i = 0; i < size(open_exhibitor_array); i++)
	{
		cout << open_exhibitor_array[i] << endl;
	}

	// нужно сделать что бы из вектора выбиралась рандомная открытая экспонента 
	// сгенерировать число до границы вектора и этим числом по индексу вектора взять элемент 
	//можно сделать что бы выбирал из второй половины, что бы числа были по больше 


	cout << "yeap";
}