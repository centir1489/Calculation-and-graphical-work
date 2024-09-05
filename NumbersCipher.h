#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include <stdlib.h>
#include <stdio.h>
#include <cstdint> 
#include<windows.h>

using namespace std;

map<char, uint8_t> CreateEncryptMap(string StrAlphabet);
map<uint8_t, char> CreateDecryptMap(string StrAlphabet);

vector<char> AddCpecialSymbols(string StrSpecialSymbs);
bool IsInadmissSymbols(char Symbol);

string ToLowerText(string OriginalText);

vector<char> EncryptVec(string EncryptText, string Alphabet);

string NumbCiphEncrypt(string OriginalText, string Alphabet);
string NumbCiphDecrypt(string DecryptText, string Alphabet);