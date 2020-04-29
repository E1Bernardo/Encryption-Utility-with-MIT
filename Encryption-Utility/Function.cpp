#include <iostream>
#include <vector>
#include<fstream>

struct Console_key
{
	string file_name;
	string optional_key; // ����� ���� ���������� 
};


using namespace std;

void check_console_input(int argc, char* argv[], Console_key &console_input)
{
	string file_name = argv[1];
	string key = argv[2];
	int count_key = argc;
	//�������� ������������� ����� � ������������ ����� �����
   // ������ �� ��������� ��� � ������ ������������ ������
	if (count_key > 3){
		while (count_key > 3){
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			cout << "\nExceeded the allowed number of keys,  you will have to repeat the input:\n";
			cout << "Enter the file name in the form <example.txt> >>> ";
			cin >> file_name;//�������� ����� �� ������������� �����  ����� ������� ����� ������� ���� .exe � ��������� ����������?
			cout << "Enter the key >>> ";
			cin >> key;
			/*
			�������� ����� �����
			*/
			int hint = 0;
			while (key != "rsa" || key != "RSA"){
				std::cin.clear();
				std::cin.ignore(3000, '\n');
				cout << "\nError, entering a nonexistent key: \n";
				cout << "Enter the key >>> ";
				cin >> key;
				hint++;
				if (hint > 3) {
					cout << "\nThere is only one key in this program - [RSA] or [rsa]\n";
				}
			}
		}
	}else
	{
		/*
			�������� ����� �����
		*/
		int hint = 0;
		while (key != "rsa" || key != "RSA"){
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			cout << "\nError, entering a nonexistent key: \n";
			cout << "Enter the key >>> ";
			cin >> key;
			hint++;
			if (hint > 3) {
				cout << "\nThere is only one key in this program - [RSA] or [rsa]\n";
			}
		}
	}
	console_input = { file_name , key };
}

int verification_encryption_decryption(string file_name)
{
	file_name;
    //�������� ���������� ���� ��� ��� 
    // ����� ������ ���� ������ ����������� ������������� ����
    //����� ������ ���� ������ ������������ �� ������������� ����
    // ���� ��� ������ return 0
    // ���� ������ return 1
	return 0;
}


int count_char_text(string file_name)// ������� ����������� �������� ��� ������� ������� �������.
{
	fstream in;
	in.open((file_name), fstream::binary | ios::in);
	int count_char = 0;
	if (!in.is_open()){
		cerr << "Error, the file didn't open";
		exit(1);
	}else
	{
		char ch;
		while (!in.eof()){
			in.read((char*)&ch, sizeof(ch));
			count_char++;
		}
	}
	in.close();
	return count_char;
}

void reading_file(vector <unsigned __int8>& simple_text, string file_name)
{
	fstream in;
	in.open((file_name), fstream::binary | ios::in );

	if (!in.is_open()){
		cerr << "Error, the file didn't open";
		exit(1);
	}else
	{
		for (size_t i = 0; i < size(simple_text); i++){
			in.read((char*)&simple_text[i], sizeof(unsigned __int8));
		}
	}
	in.close();
}


int output_result(char* argv[])
{
    // ����� ���������� ����� ��� ������ 
    // ������������� ��������� ����� ������ 
    // ���� ��� ������ return 0
    // ���� ������ return ��� ������
	return 0;
}