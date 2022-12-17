#include"Common.h"
#include "pch.h"


//delete space
void str_delete_space(std::string& str)
{
	string tmp_str = "";
	for (int i = 0; i < str.length(); i++)
		if (str[i] != ' ')
			tmp_str += str[i];
	str = tmp_str;
}


//delete enter
void str_delete_enter(std::string& str)
{
	string tmp_str = "";
	for (int i = 0; i < str.length(); i++)
		if (str[i] != '\n')
			tmp_str += str[i];
	str = tmp_str;
}


//1byte reverse
void str_reverse_by_1byte(std::string& str)
{
	string tmp_str = "";
	long int len = str.length();

	while (len > 0)
	{
		len -= 2;
		for (int i = 0; i < 2; i++)
			tmp_str += str[len + i];
	}
	str = tmp_str;
}


//4byte reverse, 
//coution:
//	1.please make sure length is a multiple of 4
void str_reverse_by_4byte(std::string& str)
{
	string tmp_str = "";
	long int len = str.length();

	while (len > 0)
	{
		len -= 8;
		for (int i = 0; i < 8; i++)
			tmp_str += str[len + i];
	}
	str = tmp_str;
}


//function: every 4byte reverse itself
//coution:
//	1.please make sure length is a multiple of 4
void str_word_internal_reverse(std::string& str)
{
	string tmp_str = "";
	long int len = str.length();

	for (int i = 0; i < len / 8; i++)
	{
		for (int j = 0; j < 8; j++)
			tmp_str += str[i * 8 + j];

		str_reverse_by_1byte(tmp_str);

		for (int j = 0; j < 8; j++)
			str[i * 8 + j] = tmp_str[j];
	}
}


void str_insert_by_XByte(std::string& str, std::string& substr, int x)
{
	string tmp_str = substr;
	int len = str.length();
	x = x << 1;

	for (int i = 0; i < len; i++)
	{
		tmp_str += str[i];
		if ((i + 1) % x == 0 && i != len - 1)
		{
			tmp_str += substr;
		}
	}
	str = tmp_str;
}


//xor
int xor_u8(std::string& str1, std::string& str2, std::string& str3)
{
	int a, b;

	if (str1.length() != str2.length())
	{
		return 1;
	}

	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] >= 'a' && str1[i] <= 'f')
			str1[i] -= 32;
		else
			if (str1[i] >= '0' && str1[i] <= '9')
			{
				;
			}
			else
				return 1;

		if (str2[i] >= 'a' && str2[i] <= 'f')
			str2[i] -= 32;
		else
			if (str2[i] >= '0' && str2[i] <= '9')
			{
				;
			}
			else
				return 1;
	}

	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] >= '0' && str1[i] <= '9')
			a = str1[i] - '0';
		else
			a = str1[i] - 'A' + 10;

		if (str2[i] >= '0' && str2[i] <= '9')
			b = str2[i] - '0';
		else
			b = str2[i] - 'A' + 10;

		a ^= b;
		if (a >= 0 && a <= 9)
			str3[i]= a + '0';
		else
			str3[i]= a + 'A' - 10;
	}

	return 0;
}


//check string whether is hex()
int check_is_only_hex(std::string& str)
{
	for (int i = 0; i < str.length(); i++)
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))
			continue;
		else
			return 1;
	return 0;
}


//delete 0x
void delete_0x(std::string &str)
{
	std::string substr;
	str += " ";

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0' && str[i + 1] == 'x')
		{
			i++;
			continue;
		}
		else if (str[i] == ',')
			continue;
		else
			substr += str[i];
	}

	str = substr.substr(0, substr.length() - 1);

	return;
}


//StringToHex
std::string StringToHex(const std::string& data)
{
	const std::string hex = "0123456789ABCDEF";
	std::stringstream ss;

	for (std::string::size_type i = 0; i < data.size(); ++i)
		ss << hex[(unsigned char)data[i] >> 4] << hex[(unsigned char)data[i] & 0xf];
	return ss.str();
}

//HexToStr
std::string HexToString(const std::string& str)
{
	std::string result;
	for (size_t i = 0; i < str.length(); i += 2)
	{
		std::string byte = str.substr(i, 2);
		char chr = (char)(int)strtol(byte.c_str(), NULL, 16);
		result.push_back(chr);
	}
	return result;
}


//oct_str2bin_str
void oct_str2bin_str(std::string& str, std::string& res)
{
	std::string tmp_str;
	int num, delta;

	res = "";

	//check is hex str
	//...

	for (int i = 0; i < str.length(); i++)
	{
		tmp_str = "";

		if (str[i] >= 'a' && str[i] <= 'f')
			num = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = str[i] - 'A' + 10;
		else
			num = str[i] - '0';

		while (num > 0)
		{
			if (num % 2 == 0)
			{
				tmp_str += "0";
			}
			else
			{
				tmp_str += "1";
			}
			num /= 2;
		}

		delta = 4 - tmp_str.length();
		for (int j = 0; j < delta; j++)
			tmp_str += "0";

		for (int j = 0; j < 2; j++)
		{
			char c = tmp_str[j];
			tmp_str[j] = tmp_str[tmp_str.length() - j - 1];
			tmp_str[tmp_str.length() - j - 1] = c;
		}

		res += tmp_str;
	}

	return;
}


//Upper
void Upper(std::string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
	}
	return;
}


//Lower
void Lower(std::string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
	}
	return;
}

