#include"AuxiliaryFile.h"
 
pair<string, string> ConversStrToPair(string ContentFile){
	string Key, Text;
	size_t Pos = ContentFile.find('\n');
    if(Pos != string::npos){
        Key = ContentFile.substr(0, Pos);
        Text = ContentFile.substr(Pos + 1);
    } 
    else{
        Text = ContentFile;
        Key.clear();
    }
	if(Text.empty()){
		Text = Key;
		Key.clear();
	}
	return {Key, Text};
}

pair<string, string> ReadFileToPair(string Path){
    ifstream ReadedFile;
    ReadedFile.open(Path);
    if(!ReadedFile.is_open()){
        throw "Ошибка открытия файла! Ошибка в названии файла или пути к нему!\n";
        return {"", ""};
    }
	string ContentFile;
	
    string LineText;
    while(getline(ReadedFile, LineText)){
        ContentFile += LineText + '\n';
    }
    ReadedFile.close();
    pair<string, string> PairKeyMess = ConversStrToPair(ContentFile);
    return PairKeyMess;
}

void WriteFile(string Path, pair<string, string> PairKeyMess){
	ofstream ReadedFile;
    ReadedFile.open(Path);
    if(!ReadedFile.is_open()){
        throw "Ошибка открытия файла! Ошибка в названии файла или пути к нему!\n";
    }
	
	if(!PairKeyMess.first.empty()){
		ReadedFile << PairKeyMess.first << '\n' << PairKeyMess.second;
	}
	else{
		ReadedFile << '\n' << PairKeyMess.second;
	}

	ReadedFile.close();
}

pair<vector<size_t>, vector<size_t>> ReadKey(string Key){
	string BuffStr;
	vector<vector<size_t>> ListKeys(2);
	size_t NumbKey = 0;
	for(size_t p = 0; p < Key.length(); p++){
		if(isdigit(Key[p])){
			BuffStr += Key[p];
		}
		else{
			ListKeys[NumbKey].push_back(size_t(atoi(BuffStr.c_str())));
			BuffStr.clear();
		}
        if(Key[p] == 95){ // _
			NumbKey = 1;
		}
	}
    ListKeys[0].pop_back(); 
    ListKeys[1].pop_back();
	return {ListKeys[0], ListKeys[1]};
}

void InputPassword(){
	string Password;
	size_t CorrectPassword = 1575563705396792991;
	while(true){
		cout << "\t\tВы вошли в приложение Мои Шфиры\nВведите пароль:  ";
		
		getline(cin, Password);
		size_t HashPass = hash<string>()(Password);
		if (CorrectPassword == HashPass){
			cout << "\nДобро пожаловать! Приятной работы!";
			break;
		}
		else{
			cout << "Неверный пароль!\n";
			Password.clear();
		}
	}
}
