/*
Атбаш — простой шифр подстановки для алфавитного письма. 
Правило шифрования состоит в замене i-й буквы алфавита буквой с номером n − i + 1, 
где n — число букв в алфавите
*/

#include <iostream>
#include <string>
#include <cctype>

const int lettersAmount = 33;

char alphabetLetters[lettersAmount] = {'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж',
                                              'з', 'и', 'й','к', 'л', 'м', 'н', 'о',
                                              'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц',
                                              'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я'};

std::string toLowerCase(std::string str)
{
    using namespace std;

    int N = str.length();

    for (int i = 0; i < N; i++) {
        if (str[i] >= -64 && str[i] <= -33) 
            str[i] = str[i] + 32; // в ASCII коды русских прописных букв находятся в диапозоне -32..-1

        if (str[i] == -88) 
            str[i] = -72; // Буква "ё"
    }

    return str;
}

std::string scrambler(std::string baseString)
{
    using namespace std;
   
    int N = baseString.length(), letterNumInAlphabet = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < lettersAmount; j++)
            if (baseString[i] == alphabetLetters[j]) {
                baseString[i] = alphabetLetters[lettersAmount - j - 1];
                break;
            }

    return baseString;

}

int main()
{
    system("chcp 1251 > nul");

    using namespace std;
    
    string baseString, cipheredString;

    cout << "Программа шифрует введеную строку на русском языке Шифром Атбаша.\n" <<
        "Атбаш — простой шифр подстановки для алфавитного письма. Правило шифрования состоит в замене i-й буквы алфавита буквой с номером n - i + 1," <<
        "где n — число букв в алфавите." << endl;

    cout << "\nВведите исходную строку: ";

    getline(cin, baseString);

    cipheredString = scrambler(toLowerCase(baseString));

    cout << "Зашифрованная строка: " << cipheredString << endl;


    system("pause");

    return 0;
}

