#include"NumbersCipher.h"

map<char, uint8_t> CreateEncryptMap(string StrAlphabet){
    map<char, uint8_t> Alphabet;
    for(uint8_t p = 0; p < StrAlphabet.length(); p++){
        Alphabet[tolower(StrAlphabet[p])] = p + 1;
    }
    return Alphabet;
}

map<uint8_t, char> CreateDecryptMap(string StrAlphabet){
    map<uint8_t, char> Alphabet;
    for(uint8_t p = 0; p < StrAlphabet.length(); p++){
        Alphabet[p + 1] = tolower(StrAlphabet[p]);
    }
    return Alphabet;
}

vector<char> AddCpecialSymbols(string StrSpecialSymbs){
    vector<char> VecSpecSymbols;
    for(char SpecSymb : StrSpecialSymbs){
        VecSpecSymbols.push_back(SpecSymb);
    }
    return VecSpecSymbols;
}

bool IsInadmissSymbols(char Symb){
    string SpecialSymbols = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ\n :;*!?~`@#$%^&()[]{}_+=\\|.,<>/''""";
    vector<char> SpecSymbols = AddCpecialSymbols(SpecialSymbols);//{32, 34, 39, 44, 46, 58, 59, 63}; // {space; "; '; ,; .; :; (;); ?}
    for(char SpecSymb : SpecSymbols){
        if(Symb == SpecSymb || Symb == '\0'){
            return false;
        }
    }
    return true;
}

string ToLowerText(string OriginalText){
    string LowerText;
    for(char Symb : OriginalText){
        if(!islower(Symb)){
            LowerText += tolower(Symb);
            continue;
        }
        LowerText += Symb;
    }
    return LowerText;
}

vector<char> EncryptVec(string EncryptText, string Alphabet){
    vector<char> ResultEncrypt;
    vector<string> EncryptVec;
    string BuffString, BuffSymb;
    for(char Symb : EncryptText){
        if(isdigit(Symb)){
            BuffString += Symb;
        } 
        else if(!BuffString.empty()){
                EncryptVec.push_back(BuffString);
                BuffString.clear();
        }
        if(!IsInadmissSymbols(Symb)){
            BuffSymb += Symb;
            EncryptVec.push_back((BuffSymb));
            BuffSymb.clear();
        }
    }

    if(!BuffString.empty()){
        EncryptVec.push_back(BuffString);
    }

    map<uint8_t, char> AlphabetDecryptMap = CreateDecryptMap(Alphabet);
    size_t Element;
    for(string Val : EncryptVec){
        if(!IsInadmissSymbols(Val[0])){
            ResultEncrypt.push_back(Val[0]);
            continue;
        }
        Element = AlphabetDecryptMap[atoi(Val.c_str())];
        ResultEncrypt.push_back(Element);
    }
    return ResultEncrypt;
}

string NumbCiphEncrypt(string OriginalText, string Alphabet){
    string EncryptText;
    string ConvText = ToLowerText(OriginalText);
    
    map<char, uint8_t> AlphabetEncryptMap = CreateEncryptMap(Alphabet);
    for(size_t p = 0; p < ConvText.length(); p++){
        if(isalpha(ConvText[p])){
            EncryptText += to_string(AlphabetEncryptMap[ConvText[p]]);
            if(IsInadmissSymbols(ConvText[p + 1])){
                EncryptText += '-';
            }
        }
        else{
            EncryptText += ConvText[p];
        }
    }

    string FinalEncryptText(begin(EncryptText), end(EncryptText));
    return FinalEncryptText;
}

string NumbCiphDecrypt(string DecryptText, string Alphabet){
    vector<char> VecEncryptText = EncryptVec(DecryptText, Alphabet);
    string StringDecryptText;
    for(char Symb : VecEncryptText){
        StringDecryptText += Symb;
    }
    return StringDecryptText;
}