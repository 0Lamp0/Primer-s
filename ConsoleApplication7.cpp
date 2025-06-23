#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>

using namespace std;

// Генерация случайного числа в диапазоне [min, max]
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Генерация случайного выражения
string generateExpression() {
    vector<string> numbers = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    vector<string> ops = { "+", "-", "*", "/" };

    string expr;
    int length = randomInt(3, 6); // Длина выражения (3-6 элементов)
    bool needNumber = true;

    for (int i = 0; i < length; ++i) {
        if (needNumber) {
            expr += numbers[randomInt(0, 9)];
            // С вероятностью 30% добавляем скобки
            if (randomInt(0, 9) < 3 && i < length - 2) {
                expr = "(" + expr;
                expr += ops[randomInt(0, 3)];
                expr += numbers[randomInt(0, 9)] + ")";
                i += 2; // Пропускаем следующие шаги
            }
        }
        else {
            expr += ops[randomInt(0, 3)];
        }
        needNumber = !needNumber;
    }

    return expr;
}

// Вычисление выражения (упрощённо, лучше использовать muparser)
double evaluateExpression(const string& expr) {
    // Здесь должен быть парсер, но для примера используем "костыль"
    // В реальном коде лучше подключить muparser или другой вычислитель
    stringstream ss(expr);
    double a, b;
    char op;
    ss >> a >> op >> b;
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return 0;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    int n;
    cout << "Сколько примеров решить? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string expr = generateExpression();
        double correctAnswer = evaluateExpression(expr);
        double userAnswer;

        cout << "Пример: " << expr << endl;
        do {
            cout << "СКОЛЬКО БУДЕТ? ";
            cin >> userAnswer;
            if (abs(userAnswer - correctAnswer) < 1e-6) {
                cout << "Правильно!" << endl;
                break;
            }
            else {
                cout << "Неправильно, попробуйте ещё раз." << endl;
            }
        } while (true);
    }

    return 0;
}