#include <iostream>
#include <vector>

using namespace std;

struct Console_key
{
    string file_name;
    string optional_key; // выбор типа шифрования 
};

void check_console_input(int argc, char* argv[], Console_key &console_input);

int verification_encryption_decryption(string file_name);

int count_char_text(string file_name);

void reading_file(vector <unsigned __int8>& simple_text, string file_name);

void encryption_and_recording(vector <unsigned __int8>& simple_text, string file_name);

void decryption_and_recording(vector <unsigned __int8>& cipher_text_vector, string file_name);

int output_result(char* argv[]);
