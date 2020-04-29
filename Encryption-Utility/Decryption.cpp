#include <iostream>
#include <vector>
#include<fstream>
#include<cmath>

struct Key
{
	unsigned __int64 exhibitor;
	unsigned __int64 mod; // сокращение от модуль   the abbreviation for module
};

using namespace std;


void decryption_and_recording(vector <unsigned __int8>& cipher_text_vector, string file_name)
{
	fstream cipher_text;
	cipher_text.open((file_name), fstream::binary | ios::in);// Вместо Test.txt должен быть ключ с именем файла
	if (!cipher_text.is_open()){
		cerr << "error";
		exit(1);
	}else
	{
		for (size_t i = 0; i < size(cipher_text_vector); i++){
			cipher_text.read((char*)&cipher_text_vector[i], sizeof(unsigned __int8));
		}
	}
	cipher_text.seekg(0);

	for (size_t i = 0; i < size(cipher_text_vector); i++){ // вот тут проблема, как получить закрытый ключ ?
		unsigned __int8 res;
		res = cipher_text_vector[i];
		res = ((unsigned __int64)pow(cipher_text_vector[i], private_key.exhibitor)) % private_key.mod;
		cipher_text.write((char*)&res, sizeof(unsigned __int8));
		cout << res;
	}
	cipher_text.close();
}


