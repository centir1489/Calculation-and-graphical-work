#include"ChiferVernam.h"

size_t RandomValues(size_t LeftBorder, size_t RightBorder){
    ranlux24 generator(random_device{}());
    uniform_int_distribution<size_t> distribution(LeftBorder, RightBorder);
    size_t RdValue = distribution(generator);
    return RdValue;
}

size_t ChangSymb(size_t TextSymb, size_t &KeySymb){
    size_t CorrectSymb = TextSymb ^ KeySymb;
    while(CorrectSymb < 32 || CorrectSymb > 125){
        KeySymb = RandomValues(32, 125);
        CorrectSymb = TextSymb ^ KeySymb;
    }
    return CorrectSymb;
}

vector<size_t> SpecialGenerateKey(string OriginalText){
    vector<size_t> Key;
    size_t CiphSymb;
    for(size_t p = 0; p < OriginalText.length(); p++){
        Key.push_back(RandomValues(32, 125));
        CiphSymb = OriginalText[p] ^ Key[p];
        if(CiphSymb < 32){
            CiphSymb = ChangSymb(OriginalText[p], Key[p]);
        }
    }
    return Key;
}

vector<size_t> GenerateKey(size_t KeyLength){
    vector<size_t> Key;
    for(size_t p = 0; p < KeyLength; p++){
        Key.push_back(RandomValues(32, 125));
    }
    return Key;
}

vector<size_t> KeyStrToVecSizet(string Key){
    vector<size_t> VecKey;
    for(size_t Symb : Key){
        VecKey.push_back(Symb);
    }
    return VecKey;
}

string KeyVecSizetToStr(vector<size_t> VecKey){
    string Key;
    for(char Symb : VecKey){
        Key += Symb;
    }
    return Key;
}

string VernamXorText(string OriginalText, string Key){
    string DecryptText;
    vector<size_t> VecKey = KeyStrToVecSizet(Key);
    for(size_t p = 0; p < OriginalText.length(); p++){
        DecryptText += OriginalText[p] ^ VecKey[p];
    }
    return DecryptText;
}