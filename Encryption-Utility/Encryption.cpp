#include <iostream>
#include <vector>
#include<fstream>
#include<ctime>

struct Key
{
	unsigned __int64 exhibitor;
	unsigned __int64 mod; // сокращение от модуль   the abbreviation for module
};




int checking_number_simplicity();// Ввод и проверка числа на простоту  Enteringand checking a number for simplicity

void finding_open_exponents(vector <unsigned __int64> & open_exhibitor_array, unsigned __int64 f_Euler);
unsigned __int64 selection_open_exhibitors(vector <unsigned __int64>open_exhibitor_array);

using namespace std;
// проверку на простоту и прочие большие куски можно сделать в отдельные функции 
void encryption(vector <unsigned __int8>& inputf)
{
	unsigned __int64 p, q; // Да простых числа   Two prime number
	cout << "Enter two prime number:\n";
	p = checking_number_simplicity();
	q = checking_number_simplicity();

	unsigned __int64 module = p * q;  // Модуль   Module
	unsigned __int64 f_Euler = (p - 1) * (q - 1);  // Функция Эйлера   Function Euler
	unsigned __int64 open_exhibitor;  // Открытая экспонента   Open Exhibitor

	vector <unsigned __int64>open_exhibitor_array(0);

	finding_open_exponents(open_exhibitor_array, f_Euler);

	open_exhibitor = selection_open_exhibitors(open_exhibitor_array);

	Key open_key = { open_exhibitor,module};


	// нужно сделать что бы из вектора выбиралась рандомная открытая экспонента 
	// сгенерировать число до границы вектора и этим числом по индексу вектора взять элемент 
	//можно сделать что бы выбирал из второй половины, что бы числа были по больше 


	cout << "yeap";
}

int checking_number_simplicity()
{
	bool bool_check = false;
	int number;
	do // Проверка на натуральность первого числа  Checking for the naturalness of the first number
	{
		int check_number = 0;
		cout << "Enter prime number\n";
		cout << "number = ";
		cin >> number;
		for (unsigned __int64 i = 2; i <= sqrt(number); i++) {
			if (number % i == 0) check_number++;
		}
		if (check_number == 0){
			bool_check = true;
		}else{
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			cout << "\nEntered number is not prime, repeat the entry:\n";
		}
	} while (bool_check == false);

	return number;
}

void finding_open_exponents(vector <unsigned __int64> & open_exhibitor_array, unsigned __int64 f_Euler)
{
	for (unsigned __int64 i = 2; i < f_Euler; i++) {
		int check = 0;
		for (unsigned __int64 j = 1; j <= sqrt(i); j++) {
			if (i % j == 0) check++;
		}
		if (check == 1 && i % f_Euler != 0) {
			open_exhibitor_array.insert(open_exhibitor_array.end(), i);
		}
	}
}


unsigned __int64 selection_open_exhibitors(vector <unsigned __int64>open_exhibitor_array)
{
	srand(time(NULL));
	int size = sizeof(open_exhibitor_array);

	int choice = 1 + rand() % sizeof(open_exhibitor_array) + 1;

	return open_exhibitor_array[choice];
}