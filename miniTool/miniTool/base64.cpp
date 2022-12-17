#include "base64.h"


base64::base64()
{
	char c = 'A';
	for (int i = 0; i < 26; i++) {
		encode_table[i] = c++;
	}
	c = 'a';
	for (int i = 26; i < 52; i++) {
		encode_table[i] = c++;
	}
	c = '0';
	for (int i = 52; i < 62; i++) {
		encode_table[i] = c++;
	}
	encode_table[62] = '+';
	encode_table[63] = '/';
	for (int i = 0; i < 64; i++) {
		decode_table[encode_table[i]] = i;
		cout << i << " : " << encode_table[i] << endl;
	}
}

string base64::encode(string s)
{
	string res;
	int n = s.size();
	for (int i = 0; i < n - 2; i += 3) {
		res.append(e_three(s.substr(i, 3)));
	}
	if (n % 3 == 2) {
		res.append(e_two(s.substr(n - 2)));
	}
	else if (n % 3 == 1) {
		res.append(e_one(s.substr(n - 1)));
	}
	return res;
}

string base64::decode(string d)
{
	string res;
	while (d.back() == '=') {
		d.pop_back();
	}
	for (int i = 0; i < d.size(); i += 4) {
		res.append(d_four(d.substr(i, 4)));
	}
	return res;
}

string base64::e_three(string source)
{
	vector<int> dest(4);
	dest[0] = source[0] >> 2;
	int t = source[0] & 3;
	dest[1] = (source[1] >> 4) | (t << 4);
	t = source[1] & 0xf;
	dest[2] = (source[2] >> 6) | t << 2;
	dest[3] = source[2] & 0x3f;
	string res = "====";
	for (int i = 0; i < 4; i++) {
		res[i] = encode_table[dest[i]];
	}
	return res;
}

string base64::e_two(string s) 
{
	vector<int> d(3);
	d[0] = s[0] >> 2;
	int t = s[0] & 3;
	d[1] = (s[1] >> 4) | (t << 4);
	t = s[1] & 0xf;
	d[2] = t << 2;
	string res = "====";
	for (int i = 0; i < 3; i++) {
		res[i] = encode_table[d[i]];
	}
	return res;
}

string base64::e_one(string s)
{
	vector<int> d(2);
	d[0] = s[0] >> 2;
	int t = s[0] & 3;
	d[1] = t << 4;
	string res = "====";
	res[0] = encode_table[d[0]];
	res[1] = encode_table[d[1]];
	return res;
}

string base64::d_four(string str)
{
	vector<int > d(4);
	string res;
	int t2;
	string t1 = " ";
	if (str.size() == 4) {
		for (int i = 0; i < 4; i++) {
			d[i] = decode_table[str[i]];
		}
		t1[0] = (d[0] << 2) | (d[1] >> 4);
		res.append(t1);
		t2 = d[1] & 0xf;
		t1[0] = (t2 << 4) | (d[2] >> 2);
		res.append(t1);
		t2 = d[2] & 3;
		t1[0] = (t2 << 6) | d[3];
		res.append(t1);
		return res;
	}
	else if (str.size() == 3) {
		for (int i = 0; i < 3; i++) {
			d[i] = decode_table[str[i]];
		}
		t1[0] = (d[0] << 2) | (d[1] >> 4);
		res.append(t1);
		t2 = d[1] & 0xf;
		t1[0] = (t2 << 4) | (d[2] >> 2);
		res.append(t1);
		return res;
	}
	else if (str.size() == 2) {
		for (int i = 0; i < 2; i++) {
			d[i] = decode_table[str[i]];
		}
		t1[0] = (d[0] << 2) | (d[1] >> 4);
		res.append(t1);
		return res;
	}

	return res;
}