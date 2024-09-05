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
        cout << "�������� ��������, ����� ������� �������:\n1. ����������� ���������.\n2. ������������ ���������.\n";
        int FinalChoiceCrypt = UserSelect(UserChoice, 2);
        
        if(FinalChoiceCrypt != 1 && FinalChoiceCrypt != 2){
            throw "������ �����!\n������� ����� ������ ��� ��������, ����������� ��������� (1) ��� ������������ ��������� (2).\n";
        }
        return FinalChoiceCrypt;
    }

    int ChoiceCipher(string UserChoice){
        string MessageChoiceShifr = "�������� ������ ����������, ������ ������� �������:\n1. ���� A1Z26.\n2. ���� �������.\n3. ���� ������� ��������� ������������.\n";
        cout << MessageChoiceShifr;

        int FinalChoiceShifr = UserSelect(UserChoice, 3);
        if(FinalChoiceShifr != 1 && FinalChoiceShifr != 2 && FinalChoiceShifr != 3){
            throw "������ �����!\n������� ����� ������ ��� ��������, ���� A1Z26 (1), ���� ������� (2), ���� ������� ��������� ������������ (3).\n";
        }
        return FinalChoiceShifr;
    }  

    int ChoiceWork(string UserChoice){
        cout << "�������� ����� ���������� ���������, ����� ������� �������:\n1. �������.\n2. ����.\n";
        int FinalChoiceWork = UserSelect(UserChoice, 2);
        
        if (FinalChoiceWork != 1 && FinalChoiceWork != 2){
            throw "������ �����!\n������� ����� ������ ��� ��������, ���������� � ������� (1) ��� ���������� � ����� (2).\n";
        }   
        return FinalChoiceWork;
    }

    int FinalChoiceWork(string UserChoice){
        cout << "�������� ���� ����� ������� ��������� ����� ��������, ����� ������� �������:\n1. �������.\n2. ����.\n";
        int FinalChoiceWork = UserSelect(UserChoice, 2);

        if (FinalChoiceWork != 1 && FinalChoiceWork != 2){
            throw "������ �����!\n������� ����� ������ ��� ��������, ������ � ������� (1) ��� ������ � ���� (2).\n";
        }   
        return FinalChoiceWork;
    }