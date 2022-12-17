//#pragma once

#include<iostream>
#include <sstream>
#include "base64.h"
using namespace std;


void str_delete_space(std::string& str);
void str_delete_enter(std::string& str);
void str_reverse_by_1byte(std::string& str);
void str_reverse_by_4byte(std::string& str);
void str_word_internal_reverse(std::string& str);
void str_insert_by_XByte(std::string& str, std::string& substr, int x);
int check_is_only_hex(std::string& str);
int xor_u8(std::string& str1, std::string& str2, std::string& str3);
void delete_0x(std::string& str);

std::string StringToHex(const std::string& data);
std::string HexToString(const std::string& str);

void oct_str2bin_str(std::string& str, std::string& res);

void Upper(std::string& str);
void Lower(std::string& str);
