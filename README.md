**Основные модули программы:**
+ `main.cpp` – ***содержит функцию main(), и весь описанный выше функционал программы.***
+ `Switch.cpp` – ***Модуль, содержащий конструкции Switch case, на которых строиться работа всей программы, можно сказать является мостом между всеми модулями и главным файлом main.***    
	+ `SwitchCryptA1Z26(int8_t ChoiceCrypt, pair<string, string> &PairKeyMess)` - **в функции содержится `Switch`, который при заданном параметре *ChoiceCrypt*,  шифрует или дешифрует сообщение методом A1Z26.**
	+ `SwitchCryptVernam(int8_t ChoiceCrypt, pair<string, string> &PairKeyMess)` -**в функции содержится `Switch`, который при заданном параметре *ChoiceCrypt*,  шифрует или дешифрует сообщение, методом Вернама.**
	+ `SwitchCryptDoubleTablPer(int8_t ChoiceCrypt, pair<string, string> &PairKeyMess)` - **в функции содержится `Switch`, который при заданном параметре *ChoiceCrypt*,  шифрует или дешифрует сообщение, методом двойной табличной перестановки.**
	+ `SwitchCipherKey(int8_t ChoiceCiphers, pair<string, string> &PairKeyMess)` - **в функции содержится `Switch`, который при заданном параметре *ChoiceCipher*, генерирует ключ для выбранного метода шифрования.
	+ `SwitchWork(int8_t ChoiceWork, int8_t ChoiceCrypt, pair<string, string> &PairKeyMess)` - **в функции содержится двойной `Switch`, который при заданных параметрах *ChoiceWork* и *ChoiceCrypt*, позволяет выбрать место считывания сообщения (консоль или файл), при шифровании сообщения запросит ключ для шифрования сообщения. 
	+ `SwitchCiphers(int8_t ChoiceCiphers, int8_t ChoiceCrypt, pair<string, string> &PairKeyMess)` -  **в функции содержится `Switch`, который при заданных параметрах *ChoiceCiphers* и *ChoiceCrypt*, запускает функцию шифра, который либо шифрует, либо дешефрует сообщение.**
	+ `OutSwitchWork(int8_t FinalChoiceWork, pair<string, string> PairKeyMess)` - **в функции содержится `Switch`, который при заданном параметре *FinalChoiceWork*, выводит результат, т.е. выводит результат программы в `Terminal` или записывает его в файл.
+ `Choices.cpp` – ***Модуль, содержащий выборы программы, такие как выбор шифровки или дешифровки, выбор считывания и записи файла.***
	+ `UserSelect(string UserChoice, size_t LimitChoice)` - **функция выбора, применяется во всех функция `Choice`, принимает выбор пользователя в виде строки номером, при не соответствии с лимитом выдаёт ошибку.** 
	+ `ChoiceCrypt(string UserChoice)` - **функция выбора действия, возможные действия: *Зашифровать / Расшифровать сообщение*.**
	+ `ChoiceCipher(string UserChoice)` - **функция выбора шифра, возможные действия: *A1Z26 / Вернам / Двойная табличная перестановка*.**
	+ `ChoiceWork(string UserChoice)` - **функция выбора места считывания информации, возможные действия: *Консоль / Файл*.**
	+ `FinalChoiceWork(string UserChoice)` - **функция выбора места записи результата, возможные действия: *Консоль / Файл*.**
+ `AuxiliaryFile.cpp` – ***Модуль, в котором находятся вспомогательные функции к программе, функции чтения, записи. Также функция аутентификации.***
	+ `InputPassword()` - **функция для входа в систему, запрашивает пароль, при успешной аутентификации, предоставляет полный функционал программы.**
	+ `ConversStrToPair(string ContentFile)` - **функция преобразует, полученную информацию из файла в виде строки, в пару ключ, сообщение.**
	+ `ReadFileToPair(string Path)` - **функция записывает информацию из файла в строку, позже при помощи функции `ConversStrToPair(string ContentFile)`, возвращает пару ключ, сообщение.**
	+ `WriteFile(string Path, pair<string, string> PairKeyMess)` - **функция записи результата в файл.**
	+ `ReadKey(string Key)` - **функция преобразования ключа в виде строки, к ключу предназначенному для двойной табличной перестановки.**

**Модули, содержащие логику шифрования:**
+ `NumbersCipher.cpp` – ***Модуль содержащий функции шифрования и дешифрования для шифра A1Z26.***
	+ `CreateEncryptMap(string StrAlphabet)` - **функция для создания таблицы для шифрования сообщения.**
	+ `CreateDecryptMap(string StrAlphabet)` - **функция для создания таблицы для дешифрования сообщения.**
	+ `AddCpecialSymbols(string StrSpecialSymbs)` - **Добавление специальных символов в алфавит, которые не будут шифроваться, но и не будут удаляться при шифровании.**
	+ `IsInadmissSymbols(char Symbol)` - **функция пропуска символа, при не обнаружении его в алфавите или специальных символах.**
	+ `ToLowerText(string OriginalText)` - **функция преобразования текста, при обнаружении прописных букв преобразует их в печатные, которые используются для шифрования.**
	+ `EncryptVec(string EncryptText, string Alphabet)` - **промежуточная функция для шифрования сообщения, функция возвращает вектор номеров букв по алфавиту, используется в функции `NumbCiphEncrypt(string OriginalText, string Alphabet)`.**
	+ `NumbCiphEncrypt(string OriginalText, string Alphabet)` - **функция шифрования текста, преобразует символьный текст алфавита, в номерной текст.**
	+ `NumbCiphDecrypt(string DecryptText, string Alphabet)` - **функция дешифрования текста, преобразует номерной текст, в изначальное символьное сообщение.**
+ `ChiferVernam.cpp` – ***Модуль содержащий функции шифрования и дешифрования для шифра Вернама.***
	+ `RandomValues(size_t LeftBorder, size_t RightBorder)` - **функция случайной генерации целого числа, с помощью  атрибута `ranlux24`, в диапазоне [`LeftBorder`, `RightBorder`].**
	+ `ChangSymb(size_t TextSymb, size_t &KeySymb)` - **функция проверки и замены символа, на допустимый символ при шифровании методом Вернама.**
	+ `SpecialGenerateKey(string OriginalText)` - **функция генерации ключа, при котором при операции *XOR* не будут допускаться не дешифруемые символы.**
	+ `GenerateKey(size_t KeyLength)` - **функция генерации случайного ключа.**
	+ `KeyStrToVecSizet(string Key)` - **функция преобразования ключа в виде строки, в ключ в виде вектора.**
	+ `KeyVecSizetToStr(vector<size_t> VecKey)` - **функция преобразования ключа вектора в ключ в виде строки.**
	+ `VernamXorText(string OriginalText, string Key)`- **функция шифрования и дешифрования методом Вернама.**
+ `DoubleTablPer.cpp` – ***Модуль содержащий функции шифрования и дешифрования для шифра двойной табличной перестановки.***
	+ `ConversStringKeys(pair<vector<size_t>, vector<size_t>> PairKeys)` - **функция преобразования ключей для двойной табличной перестановки в виде пары из векторов, содержащих места перестановки, в ключ в виде строки.**
	+ `FillinMessage(string Message, size_t SizeRowTable)` - **функция дополнения сообщения символами, для корректной записи в таблицу.**
	+ `RandomValues(size_t Border)` - ** **функция случайной генерации целого числа, с помощью  атрибута `ranlux24`, в диапазоне [`LeftBorder`, `RightBorder`].**.**
	+ `DefineBorders(string Message)` - **функция для определения количества рядов и колонн, для записи в таблицу, функция используется в `InitKeys(string Message)`.**
	+ `InitKeys(string Message)` - **функция для создания случайных ключей, для перестановки по таблице.**
	+ `TabloToStr(vector<vector<char>> Tablo, size_t Border)` - **функция преобразования текста в таблице в строку (считывание происходит по рядам).**
	+ `ReversTabloToStr(vector<vector<char>> Tablo, size_t Border)` - **функция преобразования текста в таблице в строку (считывание происходит по колоннам).**
	+ `CreateTabloRow(string Message)` - **функция создания таблицы по рядам, запись сообщения в таблицу с лева на право.**
	+ `CreateTabloColumn(string Message)` - **функция создания таблицы по колоннам, запись сообщения в таблицу с верху вниз.**
	+ `EncFirstMixTablo(string Message, vector<size_t> FirstKey)` - **функция перестановки рядов таблицы по первому ключу, используется при шифровании сообщения, в функции `EncryptMessageDP(...).**
	+ `EncSecondMixTablo(string Message, vector<size_t> SecondKey)` - **функция перестановки колонн таблицы по второму ключу, используется при шифровании сообщения, в функции `EncryptMessageDP(...).**
	+ `DecFirstMixTablo(string Message, vector<size_t> FirstKey)` - **функция перестановки рядов в таблице по первому ключу, используется при дешифровании сообщения, в функции `DecryptMessageDP(...)`.**
	+ `DecSecondMixTablo(string Message, vector<size_t> SecondKey)` - **функция перестановки колонн в таблице по первому ключу, используется при дешифровании сообщения, в функции `DecryptMessageDP(...)`.**
	+ `EncryptMessageDP(string Message, pair<vector<size_t>, vector<size_t>> PairKeys)` - **функция шифрования сообщения методом двойной табличной перестановки, в функции происходит процесс записи сообщения в таблицу по рядам, перестановки рядов по первому ключу, перезапись сообщения в таблицу по колоннам перестановка колонн по второму ключу и считывание зашифрованного сообщения.**
	+ `DecryptMessageDP(string Message, pair<vector<size_t>, vector<size_t>> PairKeys)` - **функция дешифрования сообщения методом двойной табличной перестановки, процесс дешифрования происходит как в процессе шифрования, только в другом порядке.**
