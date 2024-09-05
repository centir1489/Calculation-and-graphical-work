#pragma once
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void InputPassword();

pair<string, string> ConversStrToPair(string ContentFile);
pair<string, string> ReadFileToPair(string Path);

void WriteFile(string Path, pair<string, string> PairKeyMess);

pair<vector<size_t>, vector<size_t>> ReadKey(string Key);