#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

void encryption(vector <unsigned __int64>& inputf)
{
	unsigned __int8 IP[64]  // Матрица начальной перестановки IP
	{
		58,  50,  42,  34,  26,  18,  10,  2,  60,  52,  44,  36,  28,  20,  12,  4,
		62,  54,  46,  38,  30,  22,  14,  6,  64,  56,  48,  40,  32,  24,  16,  8,
		57,  49,  41,  33,  25,  17,  9,  1,  59,  51,  43,  35,  27,  19,  11,  3,
		61,  53,  45,  37,  29,  21,  13,  5,  63,  55,  47,  39,  31,  23,  15,  7,
	};

	unsigned __int64 block64=0, new_block64=0;

	for (size_t i = 0; i < size(inputf); i++)
	{
		block64 = inputf[i];
		cout << block64<<endl;
		for (size_t j = 0; j < 64; j++)
		{
			new_block64 |= ((block64 >> (64 - IP[j])) & 0b01) << (63 - j);
		}
		inputf[i] = new_block64;
		cout << new_block64 << endl;
		cout << inputf[i] << endl;
	}

}