#include <iostream>
#include"Header_function.h"



using namespace std;

int main(string file_name, string key) // можно ли перед вводом данных написать в консоль, что имеено нужно ввести?
{
   cout << "Hello World!\n";
    
    check_file_name_and_key(file_name, key);
    verification_encryption_or_decryption(file_name);

    if (key == "ключ для шифрования")
    {
        encryption(file_name);
    }
    else
    {
        decryption(file_name);
    }

    output_result(file_name);
}

