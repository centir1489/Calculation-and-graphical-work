#pragma once
#include<vector>
#include<string>
#include<iterator>
#include<random>
#include<cmath>

using namespace std;
string ConversStringKeys(pair<vector<size_t>, vector<size_t>> PairKeys); 

string FillinMessage(string Message, size_t SizeRowTable);

size_t RandomValues(size_t Border);


pair<size_t, size_t> DefineBorders(string Message);

pair<vector<size_t>, vector<size_t>> InitKeys(string Message);


string TabloToStr(vector<vector<char>> Tablo, size_t Border);

string ReversTabloToStr(vector<vector<char>> Tablo, size_t Border);

vector<vector<char>> CreateTabloRow(string Message);

vector<vector<char>> CreateTabloColumn(string Message);

vector<vector<char>> EncFirstMixTablo(string Message, vector<size_t> FirstKey);

vector<vector<char>> EncSecondMixTablo(string Message, vector<size_t> SecondKey);

vector<vector<char>> DecFirstMixTablo(string Message, vector<size_t> FirstKey);

vector<vector<char>> DecSecondMixTablo(string Message, vector<size_t> SecondKey);


pair<vector<size_t>, vector<size_t>> ReadKey(string Key);

string ConversStringKeys(pair<vector<size_t>, vector<size_t>> PairKeys);

string EncryptMessageDP(string Message, pair<vector<size_t>, vector<size_t>> PairKeys);

string DecryptMessageDP(string Message, pair<vector<size_t>, vector<size_t>> PairKeys);
