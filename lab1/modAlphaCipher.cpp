#include "modAlphaCipher.h"
modAlphaCipher::modAlphaCipher(const string& skey)
{
 	for (unsigned i=0; i<numAlpha.size(); i++) {
 		alphaNum[numAlpha[i]]=i;
 	}
 	newkey = convert(getValidKey(skey));
}
string modAlphaCipher::decrypt(const string& cipher_st) 
{
	string s = getValidOpenText(cipher_st);
    string n_s = s;
    int l0ng, position, line, a; 
    l0ng = cipher_st.size(); 
    line = (l0ng - 1) / newkey + 1; 
    a = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) { 
        for (int line_number = 0; line_number < line; line_number++) { 
            position = newkey*line_number+colum_number; 
            if (position-1 < l0ng) {
                n_s[position-1] = cipher_st[a];
                a++;
            }
        }
    }
    return n_s;
}
string modAlphaCipher::encrypt(const string& open_st) 
{
	string s = getValidOpenText(open_st);
    string n_s = s;
    int l0ng, line, position, a; 
    l0ng = open_st.size(); 
    line = (l0ng - 1) / newkey + 1; 
    a = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) { 
        for (int line_number = 0; line_number < line; line_number++) { 
            position = colum_number+newkey*line_number;
            if (position-1 < l0ng) {
                n_s[a] = open_st[position-1];
                a++;
            }
        }
    }
    return n_s;
}
inline string modAlphaCipher::getValidOpenText(const string & s)
{
	string tmp;
	for (auto c:s) {
		if (isalpha(c)) {
			if (islower(c))
				tmp.push_back(toupper(c));
			else
 				tmp.push_back(c);
 		}
 	}
 	if (tmp.empty())
 		throw cipher_error("Empty open text");
 return tmp;
}
inline string modAlphaCipher::getValidKey(const string & s)
{
 	if (s.empty())
 		throw cipher_error("Empty key");
 	string tmp(s);
 	for (auto & c:tmp) {
 		if (!isalpha(c))
 			throw cipher_error(string("Invalid key ")+s);
 		if (islower(c))
 			c = toupper(c);
 		}
 	return tmp;
}
