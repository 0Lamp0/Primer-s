#include <iostream>     
#include <string>       
#include <ctime>        
#include <cmath>        
#include <muParser.h>   

using namespace std;

// Генератор случайного целого числа от min до max включительно
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Генератор случайного арифметического знака
char ops() {
    char oper[] = { '+', '-', '*', '/' };
    return oper[randomInt(0, 3)];
}

// Настройка кол-ва опеоаций 
int min_terms = 2; 
int max_terms = 4; 

string AddOneBracket(string expr) {

    if (rand() % 10 >3) // 70% случаев — не вставляем скобки
        return expr;

    vector<int> opPositions;
    for (int i = 1; i < expr.length() - 1; i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
            opPositions.push_back(i);
    }

    if (opPositions.empty()) return expr;

    int opIndex = opPositions[randomInt(0, opPositions.size() - 1)];

    expr.insert(opIndex - 1, "(");
    expr.insert(opIndex + 3, ")");

    return expr;
}

//Генератор строки-примера
string GenExpr() {
    
    string expr;
    int LenExpr = 2*randomInt(min_terms, max_terms)+1;
    char chekdel = 0;
    bool needop = 1; 
    for (int i = 0; i < LenExpr;i++)
    {
        if (needop)
        {

            if (chekdel != '/')
            {
                expr += to_string(randomInt(0, 9));

            }
            else
                expr += to_string(randomInt(1, 9));
        }
        else 
        {
            chekdel = ops();
            expr += chekdel;
        
        }
        needop= !needop;

        
        
    }
    return AddOneBracket(expr);
}








int main() {
    setlocale (LC_ALL, "ru");
    srand(time(0));

    for (int i=0; i < 10;i++)
    cout << GenExpr() <<endl;
    /*int numExamples;
    

    cout << "Сколько примеров хотите решить? ";
    cin >> numExamples; 
    cout << "\n-------------------------------------------------\n- Используй (.) а не (,)\n- Точность выражения 6 символов после запятой\n------------------------------------------------";


    cout << "Все примеры решены. Молодец!" << endl;*/
    return 0;
}