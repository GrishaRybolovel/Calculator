#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
int opcode;
double rega = 0, regb = 0, regc = 0, regd = 0;

double power(double b, unsigned long long e) {
    double v = 1.0;
    while(e != 0) {
        if((e & 1) != 0) {
            v *= b;
        }
        b *= b;
        e >>= 1;
    }
    return v;
}

int factorial(int n){
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i;
    }
    return res;
}


int main()
{
    cout << "Что умеет калькулятор:\n"
            "1)Он может выполнять арифметические операции(+-/*),\n"
            "2)тригонометрические вычисления(sin, cos, tg, ctg),\n"
            "3)Считать степень числа (a ** b),\n"
            "4)Считать факториал (!a),\n"
            "5)Вычислять натуральный логарифм(ln a),\n"
            "6)Находить НОК и НОД числа(lcm a/ gcd a),\n"
            "7)Конвертирует число из одной системы счисления в другую(a b c){Число a в системе счисления b в систему счисления c},\n"
            "8)Находит площадь правильного n-угольника по заданной стороне(n len),\n"
            "9)Находит корни квадратного уравнения по заданных коэффицентам(a b c),\n"
            "10)Генерирует псевдослучайные числа в заданном диапазоне(a b),\n"
            "11)Сохраняет результат в одну из четерых ячеек(a)."
            "12)Чтобы выйти, введите '12',\n";


    while (true){
        cout << "Чтобы произвести вычисления, введите типа операции, которую хотите произвести(1-11).\n";
        cin >> opcode;


        if(opcode == 1){
            cout << "Введите число а, число b и оператор(7 8 *){операторы: +-*/}\n"
                    "Если вы хотите использовать значения из ячеек памяти, вместо чисел вводите a/b/c/d\n"
                    "Текущие значения в ячейках: " << rega << " " << regb << " " << regc << " " << regc << "\n";
            string a, b, op;
            cin >> a >> b >> op;

            int c, d;

            if(a == "a") c = rega;
            else if(a == "b") c = regb;
            else if(a == "c") c = regc;
            else if(a == "d") c = regd;
            else c = atoi(a.c_str());

            if(b == "a") d = rega;
            else if(b == "b") d = regb;
            else if(b == "c") d = regc;
            else if(b == "d") d = regd;
            else d = atoi(b.c_str());

            double res;

            if(op == "+") res = c + d;
            else if(op == "-") res = c - d;
            else if(op == "*") res = c * d;
            else if(op == "/") res = c / d;

            cout << c << " " << op << " " << d << " = " << res << "\n";
            cout << "Если вы хотите записать полученный результат в ячейку, то введите ее код(a/b/c/d)), иначе введите 'No'\n";
            string cell;
            cin >> cell;

            if(cell == "a") rega = res;
            else if(cell == "b") regb = res;
            else if(cell == "c") regc = res;
            else if(cell == "d") regd = res;
            else if(cell == "No") continue;
        }


        else if(opcode == 12){
            break;
        }

        else if(opcode == 2){
            cout << "Введите число а и оператор(0 sin){операторы: sin, cos, tg, ctg}\n"
                    "Если вы хотите использовать значения из ячеек памяти, вместо числа вводите a/b/c/d\n"
                    "Текущие значения в ячейках: " << rega << " " << regb << " " << regc << " " << regc << "\n";
            string a, op;
            cin >> a >> op;

            int c;

            if(a == "a") c = rega;
            else if(a == "b") c = regb;
            else if(a == "c") c = regc;
            else if(a == "d") c = regd;
            else c = atoi(a.c_str());

            double res;

            if(op == "sin") res = sin(c);
            else if(op == "cos") res = cos(c);
            else if(op == "tg") res = tan(c);
            else if(op == "ctg") res = 1 / tan(c);

            cout << op << "(" << c << ")" << " = " << res << "\n";
            cout << "Если вы хотите записать полученный результат в ячейку, то введите ее код(a/b/c/d)), иначе введите 'No'\n";
            string cell;
            cin >> cell;

            if(cell == "a") rega = res;
            else if(cell == "b") regb = res;
            else if(cell == "c") regc = res;
            else if(cell == "d") regd = res;
            else if(cell == "No") continue;
        }

        else if(opcode == 3){
            cout << "Введите число а, число b и оператор(7 8 &){операторы: &, |, ^(xor), >>/<<(сдвиг)}\n"
                    "Если вы хотите использовать значения из ячеек памяти, вместо чисел вводите a/b/c/d\n"
                    "Текущие значения в ячейках: " << rega << " " << regb << " " << regc << " " << regc << "\n";
            string a, b, op;
            cin >> a >> b >> op;

            int c, d;

            if(a == "a") c = rega;
            else if(a == "b") c = regb;
            else if(a == "c") c = regc;
            else if(a == "d") c = regd;
            else c = atoi(a.c_str());

            if(b == "a") d = rega;
            else if(b == "b") d = regb;
            else if(b == "c") d = regc;
            else if(b == "d") d = regd;
            else d = atoi(b.c_str());

            double res;

            if(op == "&") res = c & d;
            else if(op == "|") res = c | d;
            else if(op == "^") res = c ^ d;
            else if(op == "<<") res = c << d;
            else if(op == ">>") res = c >> d;

            cout << c << " " << op << " " << d << " = " << res << "\n";
            cout << "Если вы хотите записать полученный результат в ячейку, то введите ее код(a/b/c/d)), иначе введите 'No'\n";
            string cell;
            cin >> cell;

            if(cell == "a") rega = res;
            else if(cell == "b") regb = res;
            else if(cell == "c") regc = res;
            else if(cell == "d") regd = res;
            else if(cell == "No") continue;
        }

        else if(opcode == 4){
            cout << "Введите число а, число b и оператор(7 8 **){операторы: **}\n"
                   "Если вы хотите использовать значения из ячеек памяти, вместо чисел вводите a/b/c/d\n"
                   "Текущие значения в ячейках: " << rega << " " << regb << " " << regc << " " << regc << "\n";
            string a, b, op;
            cin >> a >> b >> op;

            int c, d;

            if(a == "a") c = rega;
            else if(a == "b") c = regb;
            else if(a == "c") c = regc;
            else if(a == "d") c = regd;
            else c = atoi(a.c_str());

            if(b == "a") d = rega;
            else if(b == "b") d = regb;
            else if(b == "c") d = regc;
            else if(b == "d") d = regd;
            else d = atoi(b.c_str());

            double res;

            if(op == "**") res = power(c, d);

            cout << c << " " << op << " " << d << " = " << res << "\n";
            cout << "Если вы хотите записать полученный результат в ячейку, то введите ее код(a/b/c/d)), иначе введите 'No'\n";
            string cell;
            cin >> cell;

            if(cell == "a") rega = res;
            else if(cell == "b") regb = res;
            else if(cell == "c") regc = res;
            else if(cell == "d") regd = res;
            else if(cell == "No") continue;
        }

        else if(opcode == 5){
            cout << "Введите число а и оператор(0 !){операторы: !}\n"
                    "Если вы хотите использовать значения из ячеек памяти, вместо числа вводите a/b/c/d\n"
                    "Текущие значения в ячейках: " << rega << " " << regb << " " << regc << " " << regc << "\n";
            string a, op;
            cin >> a >> op;

            int c;

            if(a == "a") c = rega;
            else if(a == "b") c = regb;
            else if(a == "c") c = regc;
            else if(a == "d") c = regd;
            else c = atoi(a.c_str());

            double res;

            if(op == "!") res = factorial(c);

            cout << c << op << " = " << res << "\n";
            cout << "Если вы хотите записать полученный результат в ячейку, то введите ее код(a/b/c/d)), иначе введите 'No'\n";
            string cell;
            cin >> cell;

            if(cell == "a") rega = res;
            else if(cell == "b") regb = res;
            else if(cell == "c") regc = res;
            else if(cell == "d") regd = res;
            else if(cell == "No") continue;
        }

        else if(opcode == 6){
            continue;
        }
    }
}
