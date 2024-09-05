#pragma once
#include<vector>
#include<random>
#include<string>

using namespace std;

size_t RandomValues(size_t LeftBorder, size_t RightBorder);

size_t ChangSymb(size_t TextSymb, size_t &KeySymb);

vector<size_t> SpecialGenerateKey(string OriginalText);
vector<size_t> GenerateKey(size_t KeyLength);

vector<size_t> KeyStrToVecSizet(string Key);
string KeyVecSizetToStr(vector<size_t> VecKey);


string VernamXorText(string OriginalText, string Key);