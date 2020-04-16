#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

void check_file_name_and_key(char** argv, char** argvv)
{
    //проверка существования файла и правильности ввода ключа
   // запрос на повторный вод в случае неправильных данных
}

int verification_encryption_or_decryption(char** argv)
{
    //проверка зашифрован файл или нет 
    // вывод ошибки если просят зашифровать зашифрованный файл
    //вывод ошибки если просят расшифровать не зашифрованный файл
    // если все хорошо return 0
    // если ошибка return 1
	return 0;
}


int count_char_text(char** argv)// Считаем колличество символов для задания вектору размера.
{
	fstream in;
	in.open(("Test.txt"), fstream::binary | ios::in); // Вместо Test.txt должен быть ключ с именем файла
	int count_char = 0;
	if (!in.is_open())
	{
		cerr << "error";
		exit(1);
	}
	else
	{
		
		char ch;
		while (!in.eof())
		{
			in.read((char*)&ch, sizeof(ch));
			count_char++;
		}
	}
	in.close();
	return count_char;
}

void reading_file(vector <unsigned __int8>&inputf, char** argv)// Считываем в вектор данные из файла мы же побитово считываем?
{// сам фаил содержит обычный текст, но я поставил ключ binary он ведь должен побитово считать?
	fstream in;
	in.open(("Test.txt"), fstream::binary | ios::in );// Вместо Test.txt должен быть ключ с именем файла

	if (!in.is_open())
	{
		cerr << "error";
		exit(1);
	}
	else
	{
		for (size_t i = 0; i < 641; i++)
		{
			in.read((char*)&inputf[i], sizeof(unsigned __int8));
		}
	}
	in.close();
}


void encryption(char** argv)
{
// шифрование данных
}

void decryption(char** argv)
{
    // расшифровка данных
}

int output_result(char** argv)
{
    // вывод результата успех или ошибка 
    // предусмотреть несколько кодов ошибок 
    // если все хорошо return 0
    // если ошибка return код ошибки
	return 0;
}