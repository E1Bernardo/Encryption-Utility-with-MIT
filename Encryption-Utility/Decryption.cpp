#include <iostream>
#include <vector>
#include<fstream>
#include<ctime>
#include<cmath>
#include"Header_function.h"


using namespace std;


void decryption_and_recording(vector <unsigned __int8>& cipher_text_vector, string file_name)
{
	unsigned __int64 p, q, open_exhibitor, close_exhibitor;
	cout << "Enter key of decryption:\n";
	cout << "First part of the key:";
	cin >> p;
	cout << "Second part of the key:";
	cin >> q;
	cout << "Third part of the key:";
	cin >> open_exhibitor;
	unsigned __int64 f_Euler = (p-1) * (q-1);
	vector <unsigned __int64>private_exhibitor_array(0);

	for (unsigned __int64 i = 0; i < p * q; i++) {
		if ((i * open_exhibitor) % f_Euler == 1) {
			private_exhibitor_array.insert(private_exhibitor_array.end(), i);
		}
	}
	srand(time(NULL));
	int choice = rand() % std::size(private_exhibitor_array);
	

	close_exhibitor = private_exhibitor_array[choice];



	reading_file(cipher_text_vector, file_name);


	fstream cipher_text;
	cipher_text.open((file_name),  ios::out | ios::trunc);
	if (!cipher_text.is_open()){
		cerr << "error";
		exit(1);
	}else
	{
		for (size_t i = 1; i < size(cipher_text_vector); i++) { // вот тут проблема, как получить закрытый ключ ?
			unsigned __int64 res;
			res = cipher_text_vector[i];
			res = pow(res, 17);
			res  = res % 21;
			cipher_text << (char)res<<"text";
			int a = 1;
		}
	}
	cipher_text.close();
	


}


/*fstream cipher_text;
	cipher_text.open((file_name), fstream::binary | ios::in );
	if (!cipher_text.is_open()){
		cerr << "error";
		exit(1);
	}else
	{
		for (size_t i = 0; i < size(cipher_text_vector); i++){
			cipher_text.read((char*)&cipher_text_vector[i], sizeof(unsigned __int8));
		}
	}
	cipher_text.close();*/