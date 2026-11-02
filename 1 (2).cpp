//задача 1
#include <iostrem>
#include <fstream> // чтение файла
#include <string> //запись файла
using namespace std;

int main() {
    ifstream fin("input.txt"); //переменная для чтения файла
    ofstream fout("output.txt"); //переменная для записи в файл

    string s; //переменная, куда положим все из файла
    getline(fin, s); //читаем из fin целую строку до /n и записываем в s

    string bad = "usergntm"; //строка запрещенных букв. буквы не повторяются. дальще будет проверка на наличие символа, а не позиция
    string result = ""; // пустая строка для ответа. все, что осталось после удаления

    for (int i = 0; i < s.size(); i++) { //цикл по всем символам s. s.size возвр количество символов. s[i] - доступ к i-му символу (нум с 0)
        char c = s[i]; //копируем тек символ в переменную с. чтобы дальше менять его, а не s
        if (c >= 'A' && c <= 'Z') c = c -'A' + 'a'; //приводим к нижнему регистру, если это заглавная латинская буква
        if (bad.find(c) == string::npos) { //проверяем встречается ли символ в строке bad. если  есть, то возвр его позицию первого вхождения, если нет, то возвр спец занч 
            result += s[i]; //символ хороший, добавляем в оригинал
        }
    }
    fout << result; //записываем строку в файл
    fin.close();
    fout.close();
    return 0;
}
//задача 2 способ 1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream f1("input1.txt");
    ifstream f2("input2.txt");

    string x, y;
    getline(f1, x);
    getline(f2, y);

    if (x.find(y) != string::npoos) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    f1.close();
    f2.close();
    return 0;
}
// задача 2 способ 2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream f1("input1.txt");
    ifstream f2("input2.txt");

    string x, y;
    getline(f1, x);
    getline(f2, y);

    bool found = false;

    for (int i = 0; i + y.size() <= x.size(); i++) {
        bool match = true;
        for (int j =0; j < y.size(); j++) {
            if (x[i + j] != y[j]) {
            match = false;
            break;
            }
        }
        if (match) {
        found = true;
        break;
        }
    }
    if (found) cout << "yes";
    else cout << "no";
}
//задача 3
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// перевод числа в двоичную систему
string toBinary(long long n) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res = char('0' + n % 2) + res;
        n /= 2;
    }
    return res;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    string s;
    getline(fin, s);
    
    string result = "";
    int i = 0;
    while (i < s.size()) {
        if (s[i] >= '0' && s[i] <= '9') {
            // собираем всё число
            long long num = 0;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            result += toBinary(num);
        } else {
            result += s[i];
            i++;
        }
    }
    
    fout << result;
    fin.close();
    fout.close();
    return 0;
}