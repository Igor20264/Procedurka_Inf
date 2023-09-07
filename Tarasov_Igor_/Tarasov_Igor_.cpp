// Tarasov_Igor_.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <list>
using namespace std;
// https://ru.stackoverflow.com/questions/459154/%D0%A0%D1%83%D1%81%D1%81%D0%BA%D0%B8%D0%B9-%D1%8F%D0%B7%D1%8B%D0%BA-%D0%B2-%D0%BA%D0%BE%D0%BD%D1%81%D0%BE%D0%BB%D0%B8
// Фик русского языка если не работает setlocale(LC_ALL,"rus")
#include <io.h>
#include <fcntl.h>

void fix() { // позволяет юзать русские символы. Со стак овер флов
    _setmode(_fileno(stdout), _O_U16TEXT); // обычный выход
    _setmode(_fileno(stdin), _O_U16TEXT); // обычный вход
    _setmode(_fileno(stderr), _O_U16TEXT); // При ошибке
}

double int_input(const wchar_t* text) {
    double x;
    wcout << text;
    wcin >> x;
    return x;
}

void menu(const wchar_t* name_menu,list <void*> funcs, list < const wchar_t*> texts ) {
x:
    int egg;
    wcout << L"Меню - Выбор" << name_menu << endl;
    for (int x;)
    wcin >> egg;

}

int wmain(int argc, wchar_t* argv[])
{   
    
    while (true) {

    }
    fix();
    wcout << L"Unicode -- English -- Русский -- Ελληνικά -- Español." << endl;
    s = int_input(L"Введите число:");
    wcout << s;
    return 0;
}

// Tarasov_i_a_inbo_14_23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;

void Z1() {
    cout << "TARASOV IGOR ALEKSEEVICH" << endl;
    cout << "--- END ---" << endl;
}

void Z2()
{
    double a;
    double b;
    cout << "Input A:";
    cin >> a;
    cout << "Input B:";
    cin >> b;
    cout << "+ | ";
    cout << a + b << endl;
    cout << "- | ";
    cout << a - b << endl;
    cout << "* | ";
    cout << a * b << endl;
    if (a != 0 and b != 0) {
        cout << "/ | ";
        cout << a / b << endl;
    }
    cout << "--- END ---";
}

void Z41() {
    double a;
    double b;
    cout << "Input b:";
    cin >> a;
    cout << "Input c:";
    cin >> b;
    if (b == 0) {
        cout << "delenie na 0";
    }
    else {
        b = -b;
        double x = a / b;
        if (x == -0) { cout << "Net reshenia"; }
        else { cout << x << endl; }

    }

}

void Z3() {
    double a;
    double b;
    cout << "Input A:";
    cin >> a;
    cout << "Input B:";
    cin >> b;

    b = -b;
    if (a != 0 and b != 0) {
        double x = a / b;
        cout << x << endl;
    }
    else {
        cout << "Delenie na 0" << endl;
    }
    cout << "--- END ---";
}

void Z4() {
    double a, b, c, d, x1, x2; // Объявляем переменные с плавающей точкой.

    cout << "Input a:"; // Вводим исходные данные
    cin >> a;
    if (a == 0) {

        Z41();
        goto x;

    }
    cout << "Input b:";
    cin >> b;
    cout << "Input c:";
    cin >> c;

    d = b * b - 4 * a * c; // Рассчитываем дискриминант
    if (d > 0) // Условие при дискриминанте больше нуля
    {
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
    if (d == 0) // Условие для дискриминанта равного нулю
    {
        x1 = -(b / (2 * a));
        if (x1 == -0) {
            cout << "Error x1 = -0 :(" << endl;
            goto x;
        }
        cout << "x1 = x2 = " << x1 << "\n";
    }
    if (d < 0) // Условие при дискриминанте меньше нуля
        cout << "D < 0, Sqrt not exist";
x:
    cout << "--- END ---" << endl;
}

void Z5() {
    bool a, b, c; //деньночь,шторы,лампа
    cout << "Sytki:";
    cin >> a;
    cout << "Shtori:";
    cin >> b;
    cout << "Lampa:";
    cin >> c;
    if (c == true or (a == true and b == true)) {
        cout << "Light" << endl;
    }
    else {
        cout << "Dark" << endl;
    }
    cout << "--- END ---";
}

int main()
{
    while (true)
    {
        int z;
        cout << "Spisok Zadaniy\n";
        cout << "0 - exit\n1 - Name\n2 - Arifmetica\n3 - Urovnenie\n4 - More Urovnenie\n5 - kvartira" << endl;
        cout << "Vibor zadaniya:";
        cin >> z;
        if (z == 0) { exit; }
        if (z == 1) {
            Z1();
        }
        if (z == 2) {
            Z2();
        }
        if (z == 3) {
            Z3();
        }
        if (z == 4) {
            Z4();
        }
        if (z == 5) {
            Z5();
        }
    }
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"