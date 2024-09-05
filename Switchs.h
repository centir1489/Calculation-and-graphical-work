#pragma once
#include"Choices.h"
#include"NumbersCipher.h" //A1Z26
#include"ChiferVernam.h"
#include"DoubleTablPer.h"
#include"AuxiliaryFile.h"

using namespace std;

enum EnumChoiceCrypt {
        Encrypt = 1,
        Decrypt = 2
    };

    enum EnumChoiceShifr {
        A1Z26 = 1,
        Vernam = 2,
        DoubleTabloPerm = 3
    };

    enum EnumChoiceWork {
        Terminal = 1,
        File = 2
    };

void SwitchCryptA1Z26(int8_t ChoiceCrypt, pair<string, string> &PairKeyMess);
void SwitchCryptVernam(int8_t ChoiceCrypt, pair<string, string> &PairKeyMess);
void SwitchCryptDoubleTablPer(int8_t ChoiceCrypt, pair<string, string> &PairKeyMess);

void SwitchCipherKey(int8_t ChoiceCiphers, pair<string, string> &PairKeyMess);

void SwitchWork(int8_t ChoiceWork, int8_t ChoiceCrypt, pair<string, string> &PairKeyMess);
void SwitchCiphers(int8_t ChoiceCiphers, int8_t ChoiceCrypt, pair<string, string> &PairKeyMess);
void OutSwitchWork(int8_t FinalChoiceWork, pair<string, string> PairKeyMess);


