#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

void check_file_name_and_key(char** argv, char** argvv)
{
    //�������� ������������� ����� � ������������ ����� �����
   // ������ �� ��������� ��� � ������ ������������ ������
}

int verification_encryption_or_decryption(char** argv)
{
    //�������� ���������� ���� ��� ��� 
    // ����� ������ ���� ������ ����������� ������������� ����
    //����� ������ ���� ������ ������������ �� ������������� ����
    // ���� ��� ������ return 0
    // ���� ������ return 1
	return 0;
}


int count_char_text(char** argv)// ������� ����������� �������� ��� ������� ������� �������.
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

void reading_file(vector <unsigned __int8>&inputf, char** argv)// ��������� � ������ ������ �� ����� �� �� �������� ���������?
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
		for (size_t i = 0; i < 641; i++)
		{
			in.read((char*)&inputf[i], sizeof(unsigned __int8));
		}
	}
	in.close();
}


void encryption(char** argv)
{
// ���������� ������
}

void decryption(char** argv)
{
    // ����������� ������
}

int output_result(char** argv)
{
    // ����� ���������� ����� ��� ������ 
    // ������������� ��������� ����� ������ 
    // ���� ��� ������ return 0
    // ���� ������ return ��� ������
	return 0;
}