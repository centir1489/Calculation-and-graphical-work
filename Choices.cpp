#include"Choices.h"

    int UserSelect(string UserChoice, size_t LimitChoice){
        getline(cin, UserChoice);
        int FinalChoice = atoi(UserChoice.c_str());
        for(size_t p = 0; p <= LimitChoice; p++){
            if(p == FinalChoice){
                return FinalChoice;
            }
        }
        return -1;
    }
    

    int ChoiceCrypt(string UserChoice){ 
        cout << "Выберите действие, ответ введите номером:\n1. Зашифровать сообщение.\n2. Расшифровать сообщение.\n";
        int FinalChoiceCrypt = UserSelect(UserChoice, 2);
        
        if(FinalChoiceCrypt != 1 && FinalChoiceCrypt != 2){
            throw "ОШИБКА ВВОДА!\nВыбарть можно только два действия, зашифровать сообщение (1) или расшифровать сообщение (2).\n";
        }
        return FinalChoiceCrypt;
    }

    int ChoiceCipher(string UserChoice){
        string MessageChoiceShifr = "Выберите способ шифрования, отвтет введите номером:\n1. Шифр A1Z26.\n2. Шифр Вернома.\n3. Шифр двойная табличная перестановка.\n";
        cout << MessageChoiceShifr;

        int FinalChoiceShifr = UserSelect(UserChoice, 3);
        if(FinalChoiceShifr != 1 && FinalChoiceShifr != 2 && FinalChoiceShifr != 3){
            throw "ОШИБКА ВВОДА!\nВыбрать можно только три варианта, Шифр A1Z26 (1), Шифр Вернама (2), Шифр двойная табличная перестановка (3).\n";
        }
        return FinalChoiceShifr;
    }  

    int ChoiceWork(string UserChoice){
        cout << "Выберите место считывания сообщения, ответ введите номером:\n1. Консоль.\n2. Файл.\n";
        int FinalChoiceWork = UserSelect(UserChoice, 2);
        
        if (FinalChoiceWork != 1 && FinalChoiceWork != 2){
            throw "ОШИБКА ВВОДА!\nВыбарть можно только два действия, считывание с консоли (1) или считывание с файла (2).\n";
        }   
        return FinalChoiceWork;
    }

    int FinalChoiceWork(string UserChoice){
        cout << "Выберите куда будет записан результат ваших действий, ответ введите номером:\n1. Консоль.\n2. Файл.\n";
        int FinalChoiceWork = UserSelect(UserChoice, 2);

        if (FinalChoiceWork != 1 && FinalChoiceWork != 2){
            throw "ОШИБКА ВВОДА!\nВыбарть можно только два действия, запись в консоль (1) или запись в файл (2).\n";
        }   
        return FinalChoiceWork;
    }