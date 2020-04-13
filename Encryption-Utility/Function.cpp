#include <iostream>

using namespace std;

void check_file_name_and_key(string &file_name, string &key)
{
    //проверка существования файла и правильности ввода ключа
   // запрос на повторный вод в случае неправильных данных
}

int verification_encryption_or_decryption(string file_name)
{
    //проверка зашифрован файл или нет 
    // вывод ошибки если просят зашифровать зашифрованный файл
    //вывод ошибки если просят расшифровать не зашифрованный файл
    // если все хорошо return 0
    // если ошибка return 1
}

// тут у меня вопрос возник
// нужно считывать файл в буфер потом шифровать и перезаписывать
// или можно сразу в файле шифровать?


void encryption(string file_name)
{
// шифрование данных
}

void decryption(string file_name)
{
    // расшифровка данных
}

int output_result(string file_name)
{
    // вывод результата успех или ошибка 
    // предусмотреть несколько кодов ошибок 
    // если все хорошо return 0
    // если ошибка return код ошибки
}