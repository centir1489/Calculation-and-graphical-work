#include"Switchs.h"

void SwitchWork(int8_t ChoiceWork, int8_t ChoiceCrypt, pair<string, string> &PairKeyMess){
    string ReadLine;
    switch(ChoiceWork){
        case EnumChoiceWork::Terminal:{
            cout << "������� ��������� ��� �������� ��� �����������: ";
            getline(cin, ReadLine);
            if(ReadLine.empty()){
                throw "�� �� ����� ���������, ������� ��������� ��� �������� ��� �����������.";
            }
            PairKeyMess.second = ReadLine;
            if(ChoiceCrypt == 2){
                cout << "������� ���� ��� ����������� ��������� (���� ����������� A1Z26, �� ������� ���� ���-��): ";
                getline(cin, ReadLine);
                if(ReadLine.empty()){
                    throw "�� �� ����� ���� ��� ����������� ���������, ������� ���� ��� �����������.";
                }
                PairKeyMess.first = ReadLine;
            }
            break;
        }
        case EnumChoiceWork::File:{
            cout << "������� ���� � �����: ";
            getline(cin, ReadLine);
            if(ReadLine.empty()){
                throw "�� ������ �� �����, ���� ���� � ����� ��������� ��������: C:\\Users\\User\\Desktop\\RGR\\TestTxt\\DoublePer\\TestFile.txt";
            }
            string Path = ReadLine;
            PairKeyMess = ReadFileToPair(Path);
            break;
        }
        default:
            break;
    }
}

void OutSwitchWork(int8_t FinalChoiceWork, pair<string, string> PairKeyMess){
    switch(FinalChoiceWork){
        case EnumChoiceWork::Terminal:{
            if(!PairKeyMess.first.empty()){
                cout << "\t\t\t��������� ������ ���������.\n����: " << PairKeyMess.first << "\n���� ����� ���������: " << PairKeyMess.second << '\n';
            }
            else{
                cout << "\t\t\t��������� ������ ���������.\n" << "\n���� ����� ���������: " << PairKeyMess.second << '\n';
            }
            break;
        }
        case EnumChoiceWork::File:{
            cout << "������� ���� � �����: ";
            string ReadLine;
            getline(cin, ReadLine);
             if(ReadLine.empty()){
                throw "�� ������ �� �����, ���� ���� � ����� ��������� ��������: C:\\Users\\User\\Desktop\\RGR\\TestTxt\\DoublePer\\TestFile.txt";
            }
            string Path = ReadLine;
            WriteFile(Path, PairKeyMess);
            break;
        }
        default:
            break;
    }
}

void SwitchCryptA1Z26(int8_t ChoiceCrypt, pair<string, string> &PairKeyMess){ // Key ~~ Alhpabet
    switch(ChoiceCrypt){
        case EnumChoiceCrypt::Encrypt:{
            PairKeyMess.first = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            PairKeyMess.second = NumbCiphEncrypt(PairKeyMess.second, PairKeyMess.first);
            PairKeyMess.first = "";
            break;
        }

        case EnumChoiceCrypt::Decrypt:{
            PairKeyMess.first = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            PairKeyMess.second = NumbCiphDecrypt(PairKeyMess.second, PairKeyMess.first);
            PairKeyMess.first = "";
            break;
        }
    default:
        break;
    }
}

void SwitchCryptVernam(int8_t ChoiceCrypt, pair<string, string> &PairKeyMess){
    switch(ChoiceCrypt){
        case EnumChoiceCrypt::Encrypt:{
            vector<size_t> VecKey = SpecialGenerateKey(PairKeyMess.second);
            PairKeyMess.first = KeyVecSizetToStr(VecKey);
            string EncryptMess = VernamXorText(PairKeyMess.second, PairKeyMess.first);
            PairKeyMess.second = EncryptMess;
            break;
        }

        case EnumChoiceCrypt::Decrypt:{
            string DecryptMess = VernamXorText(PairKeyMess.second, PairKeyMess.first);
            PairKeyMess.second = DecryptMess;
            PairKeyMess.first = "";
            break;
        }
    default:
        break;
    }
}

void SwitchCryptDoubleTablPer(int8_t ChoiceCrypt, pair<string, string> &PairKeyMess){
    switch(ChoiceCrypt){
        case EnumChoiceCrypt::Encrypt:{
            pair<vector<size_t>, vector<size_t>> StartKeys = InitKeys(PairKeyMess.second);
            PairKeyMess.first = ConversStringKeys(StartKeys);
            PairKeyMess.second = FillinMessage(PairKeyMess.second, size_t(sqrt(PairKeyMess.second.length())));

            string EncryptMess = EncryptMessageDP(PairKeyMess.second, StartKeys);
            PairKeyMess.second = EncryptMess;
            break;
        }

        case EnumChoiceCrypt::Decrypt:{
            pair<vector<size_t>, vector<size_t>> Keys = ReadKey(PairKeyMess.first);
            string DecryptMess = DecryptMessageDP(PairKeyMess.second, Keys);
            PairKeyMess.second = DecryptMess;
            PairKeyMess.first = "";
            break;
        }
    default:
        break;
    }
}

void SwitchCipherKey(int8_t ChoiceCiphers, pair<string, string> &PairKeyMess){
    switch(ChoiceCiphers){
        case EnumChoiceShifr::A1Z26:{
            break;
        }
        case EnumChoiceShifr::Vernam:{
            vector<size_t> VecKey = SpecialGenerateKey(PairKeyMess.second);
            PairKeyMess.first = KeyVecSizetToStr(VecKey);
            break;
        }
        case EnumChoiceShifr::DoubleTabloPerm:{
            pair<vector<size_t>, vector<size_t>> StartKeys = InitKeys(PairKeyMess.second);
            PairKeyMess.first = ConversStringKeys(StartKeys);
            break;
        }
    
        default:
            break;
    }
}

void SwitchCiphers(int8_t ChoiceCiphers, int8_t ChoiceCrypt, pair<string, string> &PairKeyMess){
    switch(ChoiceCiphers){
        case EnumChoiceShifr::A1Z26:{
            SwitchCryptA1Z26(ChoiceCrypt, PairKeyMess);
            break;
        }
        case EnumChoiceShifr::Vernam:{
            SwitchCryptVernam(ChoiceCrypt, PairKeyMess);
            break;
        }
        case EnumChoiceShifr::DoubleTabloPerm:{
            SwitchCryptDoubleTablPer(ChoiceCrypt, PairKeyMess);
            break;
        }
    
    default:
        break;
    }
}