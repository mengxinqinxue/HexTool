#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

class base64 {
public:
	base64();
	string encode(string s);
	string decode(string d);
private:
	string e_three(string source);
	string e_two(string s);
	string e_one(string s);
	string d_four(string str);
	map<int, char> encode_table;
	map<char, int> decode_table;
};