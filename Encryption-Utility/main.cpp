#include <iostream>
#include <vector>
#include"Header_function.h"


using namespace std;
// Аргумены 1- имя файла  2- ключ шифрования

int main(int argc, char* argv[]) // можно ли перед вводом данных написать в консоль, что имеено нужно ввести?   //string file_name, string key
{
   cout << "Hello World!\n";
   Console_key console_input;

   check_console_input(argc, argv, console_input);

   int сhecking_file_status = verification_encryption_decryption(console_input.file_name); // 1 - файл зашифрован  0 - файл простой

    if (сhecking_file_status == 0){
        vector <unsigned __int8>simple_text(count_char_text(console_input.file_name));

        reading_file(simple_text, console_input.file_name);
        encryption_and_recording(simple_text, console_input.file_name);
    }
    else if (сhecking_file_status == 1){
        vector <unsigned __int8>cipher_text_vector(count_char_text(console_input.file_name));
        decryption_and_recording(cipher_text_vector, console_input.file_name);
    }

    output_result(argv);
}

