#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

void check_file_name_and_key(int argc, char* argv[])
{
	string file_name = argv[1];
	string key = argv[2];
	int count_key = argc;
	
	//проверка существования файла и правильности ввода ключа
   // запрос на повторный вод в случае неправильных данных
	
	if (count_key > 3)
	{
		while (count_key > 3)
		{
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			cout << "\nExceeded the allowed number of keys,  you will have to repeat the input:\n";
			//cout << "Enter two keys in the form <file name> <Key> ";
			cout << "Enter the file name >>> ";
			cin >> file_name;//проверку файла на существование можно  будет сделать когда пропишу свой .exe в системные переменные?
			cout << "Enter the key >>> ";
			cin >> key;

			/*
			проверка имени файла
			*/

			int hint = 0;
			while (key != "des" || key != "DES")
			{
				std::cin.clear();
				std::cin.ignore(3000, '\n');
				cout << "\nError, entering a nonexistent key: \n";
				cout << "Enter the key >>> ";
				cin >> key;
				hint++;
				if (hint > 3) cout << "\nThere is only one key in this program - [DES] or [des]\n";
			}
		}
	}
	else
	{
		/*
			проверка имени файла
		*/
		int hint = 0;
		while (key != "des" && key != "DES")//проверка ключа
		{ // если я подставляю вместо key argv[] то while становится бесконечным. При key цикл работает нормально
			cout << "\nError, entering a nonexistent key: \n";
			cout << "Enter the key >>> ";
			cin >> key;
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			hint++;
			if (hint >= 3) cout << "\nThere is only one key in this program - [DES] or [des]\n";
		}
	}
}
  // в итоге у меня будет правильное имя файла и ключ, но как передать это обратно в main?
// или есть вариант перезаписать аргумент функции ?


int verification_encryption_or_decryption(char* argv[])
{
    //проверка зашифрован файл или нет 
    // вывод ошибки если просят зашифровать зашифрованный файл
    //вывод ошибки если просят расшифровать не зашифрованный файл
    // если все хорошо return 0
    // если ошибка return 1
	return 0;
}


int count_char_text(char* argv[])// Считаем колличество символов для задания вектору размера.
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

void reading_file(vector <unsigned __int8>&inputf, char* argv[])// Считываем в вектор данные из файла мы же побитово считываем?
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
		for (size_t i = 0; i < size(inputf); i++)
		{
			in.read((char*)&inputf[i], sizeof(unsigned __int8));
		}
	}
	in.close();
}


void decryption(char* argv[])
{
    // расшифровка данных
}

int output_result(char* argv[])
{
    // вывод результата успех или ошибка 
    // предусмотреть несколько кодов ошибок 
    // если все хорошо return 0
    // если ошибка return код ошибки
	return 0;
}