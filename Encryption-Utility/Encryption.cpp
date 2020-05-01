#include <iostream>
#include <vector>
#include<fstream>
#include<ctime>
#include<cmath>

struct Encryption_key
{
	unsigned __int64 exhibitor;
	unsigned __int64 mod; // сокращение от модуль   the abbreviation for module
};

int checking_number_simplicity();// Ввод и проверка числа на простоту  Enteringand checking a number for simplicity
Encryption_key do_public_key(std::vector <unsigned __int64> & public_exhibitor_array, unsigned __int64 f_Euler, unsigned __int64 module);
Encryption_key do_private_key(std::vector <unsigned __int64>& private_exhibitor_array, unsigned __int64 p, unsigned __int64 q, unsigned __int64 f_Euler, Encryption_key public_key);


using namespace std;

void encryption_and_recording(vector <unsigned __int8>& simple_text, string file_name)
{
	unsigned __int64 p, q; // Да простых числа   Two prime number
	cout << "Enter two prime number:\n";
	p = checking_number_simplicity();
	q = checking_number_simplicity();

	unsigned __int64 module = p * q;  // Модуль   Module
	unsigned __int64 f_Euler = (p - 1) * (q - 1);  // Функция Эйлера   Function Euler

	vector <unsigned __int64>public_exhibitor_array(0);
	Encryption_key public_key = do_public_key(public_exhibitor_array, f_Euler, module);

	vector <unsigned __int64>private_exhibitor_array(0);
	Encryption_key private_key = do_private_key(private_exhibitor_array, p, q, f_Euler, public_key);

	fstream encrypted_text;
	encrypted_text.open((file_name), fstream::binary | ios::out | ios::trunc);
	if (!encrypted_text.is_open()){
		cerr << "Error, the file didn't open";
		exit(1);
	}else
	{
		char mark = '!';
		mark = ((unsigned __int64)pow(mark, 5)) % 35;// числа для шифрования метки, применяются только в функции verification_encryption_decryption и в этой функции
		encrypted_text.write((char*)&mark, sizeof(unsigned __int8));
		

		for (size_t i = 0; i < size(simple_text); i++){
			unsigned __int64  res;
			res = simple_text[i];
			res = pow(res, 5);
			res = res % 21;
			encrypted_text.write((char*)&res, sizeof(unsigned __int8));
			int a = 1;
		}
	}
	encrypted_text.close();
	cout << "Your key for decryption text" << " || " << p <<" || " << q << " || " << public_key.exhibitor << " || " << endl;
}

int checking_number_simplicity()
{
	bool bool_check = false;
	int number;
	do // Проверка на натуральность первого числа  Checking for the naturalness of the first number
	{
		int check_number = 0;
		cout << "\nEnter prime number:  ";
		cin >> number;

		while (number < 10){
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			cout << "\nThe number must be greater than 10\n";
			cout << "Enter prime number:";
			cin >> number;
		}

		for (unsigned __int64 i = 2; i <= sqrt(number); i++) {
			if (number % i == 0) check_number++;
		}
		if (check_number == 0){
			bool_check = true;
		}else
		{
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			cout << "\nEntered number is not prime, repeat the entry:\n";
		}
	} while (bool_check == false);

	return number;
}

Encryption_key do_public_key(std::vector <unsigned __int64> & public_exhibitor_array, unsigned __int64 f_Euler, unsigned __int64 module)
{
	for (unsigned __int64 i = 2; i < f_Euler; i++) {
		int check = 0;
		for (unsigned __int64 j = 1; j <= sqrt(i); j++) {
			if (i % j == 0) {
				check++;
			}
		}
		if (check == 1 && i % f_Euler != 0) {
			public_exhibitor_array.insert(public_exhibitor_array.end(), i);
		}
	}

	srand(time(NULL));
	int choice = rand() % std::size(public_exhibitor_array);
	Encryption_key open_key{ public_exhibitor_array[choice] , module };

	return open_key;
}

Encryption_key do_private_key(std::vector <unsigned __int64>& private_exhibitor_array, unsigned __int64 p, unsigned __int64 q, unsigned __int64 f_Euler, Encryption_key public_key)
{
	
	for (unsigned __int64 i = 0; i < (p*q); i++) {
		if ((i* public_key.exhibitor)% f_Euler == 1) {
			private_exhibitor_array.insert(private_exhibitor_array.end(), i);
		}
	}
	srand(time(NULL));
	int choice = rand() % private_exhibitor_array.size();
	Encryption_key close_key{ private_exhibitor_array[choice], public_key.mod };

	return close_key;
}