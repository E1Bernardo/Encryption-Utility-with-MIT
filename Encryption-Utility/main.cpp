#include <iostream>
#include <vector>
#include"Header_function.h"


using namespace std;
// Аргумены 1- имя файла  2- ключ шифрование
// Пусть ключем шифрования будет название типа шифрования DES or des
int main(int argc, char* argv[]) // можно ли перед вводом данных написать в консоль, что имеено нужно ввести?   //string file_name, string key
{// Арнументы какие-то корявые вышли 
   cout << "Hello World!\n";
    
   std::cout << "There are " << argc << " arguments:\n";

   /* ниже просто проверка
    Перебираем каждый аргумент и выводим его порядковый номер и значение
   for (int count = 0; count < argc; ++count)
       std::cout << count << " " << argv[count] << '\n';*/


    check_file_name_and_key(argc, argv);
    verification_encryption_or_decryption(argv);

    vector <unsigned __int8>inputf(count_char_text(argv));

    reading_file(inputf, argv);

    // проверочный вывод на экран
    //for (size_t i = 0; i < size(inputf); i++)
       // cout << inputf[i] << endl;
    

    //if (argv[2] == "des" || argv[2] == "DES")
    
        encryption(inputf);
    
    //else
    {
        decryption(argv);
    }

    output_result(argv);
}

