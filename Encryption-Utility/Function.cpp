#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

void check_file_name_and_key(int argc, char* argv[])
{
	string file_name = argv[1];
	string key = argv[2];
	int count_key = argc;
	
	//�������� ������������� ����� � ������������ ����� �����
   // ������ �� ��������� ��� � ������ ������������ ������
	
	if (count_key > 3)
	{
		while (count_key > 3)
		{
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			cout << "\nExceeded the allowed number of keys,  you will have to repeat the input:\n";
			//cout << "Enter two keys in the form <file name> <Key> ";
			cout << "Enter the file name >>> ";
			cin >> file_name;//�������� ����� �� ������������� �����  ����� ������� ����� ������� ���� .exe � ��������� ����������?
			cout << "Enter the key >>> ";
			cin >> key;

			/*
			�������� ����� �����
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
			�������� ����� �����
		*/
		int hint = 0;
		while (key != "des" && key != "DES")//�������� �����
		{ // ���� � ���������� ������ key argv[] �� while ���������� �����������. ��� key ���� �������� ���������
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
  // � ����� � ���� ����� ���������� ��� ����� � ����, �� ��� �������� ��� ������� � main?
// ��� ���� ������� ������������ �������� ������� ?


int verification_encryption_or_decryption(char* argv[])
{
    //�������� ���������� ���� ��� ��� 
    // ����� ������ ���� ������ ����������� ������������� ����
    //����� ������ ���� ������ ������������ �� ������������� ����
    // ���� ��� ������ return 0
    // ���� ������ return 1
	return 0;
}


int count_char_text(char* argv[])// ������� ����������� �������� ��� ������� ������� �������.
{
	fstream in;
	in.open(("Test.txt"), fstream::binary | ios::in); // ������ Test.txt ������ ���� ���� � ������ �����
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

void reading_file(vector <unsigned __int8>&inputf, char* argv[])// ��������� � ������ ������ �� ����� �� �� �������� ���������?
{// ��� ���� �������� ������� �����, �� � �������� ���� binary �� ���� ������ �������� �������?
	fstream in;
	in.open(("Test.txt"), fstream::binary | ios::in );// ������ Test.txt ������ ���� ���� � ������ �����

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
    // ����������� ������
}

int output_result(char* argv[])
{
    // ����� ���������� ����� ��� ������ 
    // ������������� ��������� ����� ������ 
    // ���� ��� ������ return 0
    // ���� ������ return ��� ������
	return 0;
}