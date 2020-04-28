#include <iostream>
#include <vector>

using namespace std;

void check_file_name_and_key(int argc, char* argv[]);

int verification_encryption_or_decryption(char* argv[]);

int count_char_text(char* argv[]);

void reading_file(vector <unsigned __int8>& simple_text, char* argv[]);

void encryption(vector <unsigned __int8>& simple_text);

Key do_private_key(std::vector <unsigned __int64>& private_exhibitor_array, unsigned __int64 p, unsigned __int64 q, unsigned __int64 f_Euler, Key public_key);

void decryption(vector <unsigned __int8>& cipher_text_vector);


int output_result(char* argv[]);
