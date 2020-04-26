#include <iostream>
#include <vector>
#include<fstream>
#include<ctime>
#include<cmath>

struct Key
{
	unsigned __int64 exhibitor;
	unsigned __int64 mod; // ���������� �� ������   the abbreviation for module
};


int checking_number_simplicity();// ���� � �������� ����� �� ��������  Enteringand checking a number for simplicity

void finding_public_exponents(std::vector <unsigned __int64> & open_exhibitor_array, unsigned __int64 f_Euler);
unsigned __int64 selection_public_exhibitors(std::vector <unsigned __int64>open_exhibitor_array);

void finding_private_exponents(std::vector <unsigned __int64>& close_exhibitor_array, unsigned __int64 p, unsigned __int64 q);
unsigned __int64 selection_private_exhibitors(std::vector <unsigned __int64>close_exhibitor_array);

using namespace std;
// �������� �� �������� � ������ ������� ����� ����� ������� � ��������� ������� 
void encryption(vector <unsigned __int8>& inputf)
{
	unsigned __int64 p, q; // �� ������� �����   Two prime number
	cout << "Enter two prime number:\n";
	p = checking_number_simplicity();
	q = checking_number_simplicity();

	unsigned __int64 module = p * q;  // ������   Module
	unsigned __int64 f_Euler = (p - 1) * (q - 1);  // ������� ������   Function Euler
	unsigned __int64 public_exhibitor;  // �������� ����������   Public Exhibitor

	vector <unsigned __int64>public_exhibitor_array(0);

	finding_public_exponents(public_exhibitor_array, f_Euler);
	public_exhibitor = selection_public_exhibitors(public_exhibitor_array);

	Key public_key = { public_exhibitor,module };


	unsigned __int64 private_exhibitor;  // �������� ����������   Private Exhibitor
	vector <unsigned __int64>private_exhibitor_array(0);

	finding_private_exponents(private_exhibitor_array, p, q);
	private_exhibitor = selection_private_exhibitors(private_exhibitor_array);

	Key private_key = { private_exhibitor,module };




	for (size_t i = 0; i < size(inputf); i++)// ����� ������������ ������
	{
		cout << inputf[i];
	}
	cout << "\n\n\n\n";


	fstream out;
	out.open(("shifr.txt"), fstream::binary | ios::out);//����� ������ ������� ��������� � ����

	if (!out.is_open())
	{
		cerr << "error";
		exit(1);
	}
	else
	{
		for (size_t i = 0; i < size(inputf); i++)
		{
			unsigned __int8 res;
			res = (unsigned __int8)pow(inputf[i], public_key.exhibitor) % public_key.mod;
			out.write((char*)&res, sizeof(unsigned __int8));
			cout << res;
		}
	}
	out.close();




		// ����� ������� ��� �� �� ������� ���������� ��������� �������� ���������� 
		// ������������� ����� �� ������� ������� � ���� ������ �� ������� ������� ����� ������� 
		//����� ������� ��� �� ������� �� ������ ��������, ��� �� ����� ���� �� ������ 


		cout << "yeap";
	
}

int checking_number_simplicity()
{
	bool bool_check = false;
	int number;
	do // �������� �� ������������� ������� �����  Checking for the naturalness of the first number
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

void finding_public_exponents(std::vector <unsigned __int64> & open_exhibitor_array, unsigned __int64 f_Euler)
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


unsigned __int64 selection_public_exhibitors(std::vector <unsigned __int64>open_exhibitor_array)
{
	srand(time(NULL));
	int size = std::size(open_exhibitor_array);

	int choice = rand() % std::size(open_exhibitor_array);

	return open_exhibitor_array[choice];
}


void finding_private_exponents(std::vector <unsigned __int64>& close_exhibitor_array, unsigned __int64 p, unsigned __int64 q)
{
	
	for (unsigned __int64 i = 0; i < p*q; i++) {
		if ((i*5)%12 == 1) {
			close_exhibitor_array.insert(close_exhibitor_array.end(), i);
		}
	}
}

unsigned __int64 selection_private_exhibitors(std::vector <unsigned __int64>close_exhibitor_array)
{
	srand(time(NULL));
	int size = std::size(close_exhibitor_array);

	int choice = rand() % std::size(close_exhibitor_array);

	return close_exhibitor_array[choice];
}