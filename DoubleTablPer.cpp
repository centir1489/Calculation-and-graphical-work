#include"DoubleTablPer.h"

string FillinMessage(string Message, size_t SizeRowTable){
    if(Message.length() % SizeRowTable == 0){
        return Message;
    }
    size_t AmountSymb = SizeRowTable - (Message.length() % SizeRowTable);
    while(AmountSymb--){
        Message += ' ';
    } 
    return Message;
}

pair<size_t, size_t> DefineBorders(string Message){
    size_t SizeRow = size_t(sqrt(Message.length()));
    size_t SizeElemn = size_t(Message.length() / SizeRow);
    return {SizeRow, SizeElemn};
}

size_t RandomValues(size_t Border){
    ranlux24 generator(random_device{}());
    uniform_int_distribution<size_t> distribution(0, Border);
    size_t RdValue = distribution(generator);
    return RdValue;
}

bool CheckValue(vector<size_t> Key, size_t Values){
    for(size_t p = 0; p < Key.size(); p++){
        if(Key[p] == Values){
            return false;
        }
    }
    return true;
}

pair<vector<size_t>, vector<size_t>> InitKeys(string Message){
    pair<size_t, size_t> PairBorder = DefineBorders(Message);
    vector<vector<size_t>> ListKeys;
    ListKeys.push_back(vector<size_t>(PairBorder.first, 0));  
    ListKeys.push_back(vector<size_t>(PairBorder.second, 0));
    
    vector<size_t> VecBords = {PairBorder.first - 1, PairBorder.second - 1};
    
    size_t NumbRow, RdPos;
    for(size_t p = 0; p < 2; p++){
        for(vector<size_t>::iterator Iter {begin(ListKeys[p]) + 1}; Iter != end(ListKeys[p]); Iter++){
            NumbRow = RandomValues(VecBords[p]);
            if(!CheckValue(ListKeys[p], NumbRow)){
                Iter--;
                continue;
            }
            *Iter = NumbRow;
        }
        RdPos = RandomValues(VecBords[p]);
        NumbRow = ListKeys[p][RdPos];
        ListKeys[p][RdPos] = 0;
        ListKeys[p][0] = NumbRow;
    }
    return {ListKeys[0], ListKeys[1]};
}

string TabloToStr(vector<vector<char>> Tablo, size_t Border){
    string Message;
    for(vector<char> Symbols : Tablo){
        for(char Symbol : Symbols){
            if(Message.length() == Border){
                return Message;
            }
            Message += Symbol;
        }
    }
    return Message;
}

string ReversTabloToStr(vector<vector<char>> Tablo, size_t Border){
    string Message;
    size_t SizeRow = Tablo.size(), AmountElem = Tablo[0].size();
    for(size_t p = 0; p < AmountElem; p++){
        for(size_t q = 0; q < SizeRow; q++){
            if(Message.length() == Border){
                return Message;
            }
            Message += Tablo[q][p];
        }
    }
    return Message;
}

vector<vector<char>> CreateTabloRow(string Message){
    vector<vector<char>> TabloSumbolsRow;
    size_t SizeRow = size_t(sqrt(Message.length()));
    

    vector<char> BuffRow;
    for(size_t p = 0; p < Message.length(); p++){
        if(p != 0 && p % SizeRow == 0){
            TabloSumbolsRow.push_back(BuffRow);
            BuffRow.clear();
        }
        BuffRow.push_back(Message[p]);
    }
    TabloSumbolsRow.push_back(BuffRow);
    return TabloSumbolsRow;
}

vector<vector<char>> CreateTabloColumn(string Message){
    size_t SizeRow = size_t(sqrt(Message.length()));
    vector<vector<char>> TabloColumn(SizeRow);
    size_t Counter = 0;
    for(size_t p = 0; p < Message.length(); p++){
        TabloColumn[Counter].push_back(Message[p]);
        Counter++;
        Counter = Counter % SizeRow;
    }
        
    return TabloColumn;
}

vector<vector<char>> EncFirstMixTablo(string Message, vector<size_t> FirstKey){
    vector<vector<char>> Tablo = CreateTabloColumn(Message);
    
    vector<vector<char>> NewTablo = Tablo;
    for(size_t p = 0; p < FirstKey.size(); p++){
        NewTablo[FirstKey[p]] = Tablo[p] ;
    }
    return NewTablo;
}

vector<vector<char>> EncSecondMixTablo(string Message, vector<size_t> SecondKey){
    vector<vector<char>> Tablo = CreateTabloRow(Message);

    vector<vector<char>> NewTablo = Tablo;
    for(size_t p = 0; p < SecondKey.size(); p++){
        NewTablo[SecondKey[p]] = Tablo[p] ;
    }
    return NewTablo;
}

vector<vector<char>> DecFirstMixTablo(string Message, vector<size_t> FirstKey){
    vector<vector<char>> Tablo = CreateTabloColumn(Message);

    vector<vector<char>> NewTablo = Tablo;
    for(size_t p = 0; p < FirstKey.size(); p++){
        NewTablo[p] = Tablo[FirstKey[p]];
    }
    return NewTablo;
}

vector<vector<char>> DecSecondMixTablo(string Message, vector<size_t> SecondKey){
    vector<vector<char>> Tablo = CreateTabloRow(Message);
    
    vector<vector<char>> NewTablo = Tablo;
    for(size_t p = 0; p < SecondKey.size(); p++){
        NewTablo[p] = Tablo[SecondKey[p]];
    }
    return NewTablo;
}

string EncryptMessageDP(string Message, pair<vector<size_t>, vector<size_t>> PairKeys){
    vector<vector<char>> Encrypt;
    size_t Border = Message.length();
    
    Encrypt = EncFirstMixTablo(Message, PairKeys.first);
    Message = ReversTabloToStr(Encrypt, Border);

    Encrypt = EncSecondMixTablo(Message, PairKeys.second);
    Message = TabloToStr(Encrypt, Border);

    return Message;
}   

string DecryptMessageDP(string Message, pair<vector<size_t>, vector<size_t>> PairKeys){
    vector<vector<char>> Decrypt;
    size_t Border = Message.length();

    Decrypt = DecSecondMixTablo(Message, PairKeys.second);
    Message = TabloToStr(Decrypt, Border);

    Decrypt = DecFirstMixTablo(Message, PairKeys.first);
    Message = ReversTabloToStr(Decrypt, Border);
    
    return Message;
}

string ConversStringKeys(pair<vector<size_t>, vector<size_t>> PairKeys){
	vector<vector<size_t>> ListKeys = {PairKeys.first, PairKeys.second};
	string StrKeys;
	for(size_t p = 0; p < ListKeys.size(); p++){
		for(size_t q = 0; q < ListKeys[p].size(); q++){
			StrKeys += to_string(ListKeys[p][q]);
            StrKeys += 32; // space	
		}
		StrKeys += 95; // _
	}
	return StrKeys;
}