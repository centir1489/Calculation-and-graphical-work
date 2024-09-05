#include"Switchs.h"

int main(){
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    
    InputPassword();
    Sleep(2000);
	system("cls");

    vector<int8_t> ControlProcessVec(4, 0), FinalControlVec = ControlProcessVec;
    string Message, Key, ReadLine;
    pair<string, string> PairKeyMess;
    int8_t SelectCrypt, SelectWork, SelectCipher, SelectOutWork;
    while(true){
        try{

            if(!(ControlProcessVec[0] == 1 || ControlProcessVec[0] == 2)){
                SelectCrypt = ChoiceCrypt(ReadLine);
                ControlProcessVec[0] = SelectCrypt;
            }

            if(!(ControlProcessVec[1] == 1 || ControlProcessVec[1] == 2)){
                SelectWork = ChoiceWork(ReadLine);
                SwitchWork(SelectWork, SelectCrypt, PairKeyMess);
                ControlProcessVec[1] = SelectWork;
            }

            if(!(ControlProcessVec[2] == 1 || ControlProcessVec[2] == 2 || ControlProcessVec[2] == 3)){
                SelectCipher = ChoiceCipher(ReadLine);
                if(SelectWork == 1 && SelectCrypt == 1){ // Генерируем ключ, если шифруем и работаем в консоле.
                    SwitchCipherKey(SelectCipher, PairKeyMess);
                }
                SwitchCiphers(SelectCipher, SelectCrypt, PairKeyMess);
                ControlProcessVec[2] = SelectCipher;
            }
            if(!(ControlProcessVec[3] == 1 || ControlProcessVec[3] == 2)){
                SelectOutWork = FinalChoiceWork(ReadLine);
                OutSwitchWork(SelectOutWork, PairKeyMess);
                ControlProcessVec[3] = SelectOutWork;
            }
            
            
    
            ControlProcessVec = FinalControlVec; // Все действия выполнены, возвращаемся в начало.
        }
        catch(const char *ErrorMessage){
			cout << ErrorMessage;
			Sleep(3000);
			system("cls");
			continue;
            
        }
    }
    return 0;
}