#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>
using namespace std;

class modAlphaCipher
{
private:
    int newkey;
    string getValidOpenText(const string & s); 
public:
    modAlphaCipher()=delete;
    modAlphaCipher(const int& key) :newkey(key) {};   
    string encrypt(const string& open_st);   
    string decrypt(const string& cipher_st); 
};
class cipher_error: public invalid_argument {
public:
	explicit cipher_error (const string& what_arg):
		invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg):
		invalid_argument(what_arg) {}
};
