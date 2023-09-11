﻿// Tarasov_Igor_.cpp : Этот файл содержит функцию "wmain". Здесь начинается и заканчивается выполнение программы.

#include <iostream> // no com
#include <math.h> // no com
#include <vector> // Что - то типо списков
#include <io.h> // strin/out/err
#include <fcntl.h> // _O_U16TEXT

#include <iomanip>
#include <string>     // для getline
#include <fstream>// Запись чтение файлов
using namespace std;

// https://metanit.com/cpp/tutorial/7.4.php
// https://ru.stackoverflow.com/questions/459154/%D0%A0%D1%83%D1%81%D1%81%D0%BA%D0%B8%D0%B9-%D1%8F%D0%B7%D1%8B%D0%BA-%D0%B2-%D0%BA%D0%BE%D0%BD%D1%81%D0%BE%D0%BB%D0%B8
// Фик русского языка если не работает setlocale(LC_ALL,"rus")
void fix() { // позволяет юзать русские символы. Со стак овер флов
    _setmode(_fileno(stdout), _O_U16TEXT); // обычный выход
    _setmode(_fileno(stdin), _O_U16TEXT); // обычный вход
    _setmode(_fileno(stderr), _O_U16TEXT); // При ошибке
}

// Ввод чисел как в питончике :)
double int_input(const wchar_t* text) {
    double x;
    wcout << text;
    wcin >> x;
    return x;
}


//no com
double gipot(double k1, double k2) {
    return std::sqrt(k1 * k1 + k2 * k2);
}

// Главное меню, которое само пишет список всех заданий!
void menu(vector<void(*)()> funcs, vector< const wchar_t*> name_func) {
x:
    int egg;
    wcout << L" Меню - Выбора задания " << endl;
    for (int i = 0; i < name_func.size(); i++) {
        wcout << i+1 << " - " << name_func[i] << endl;
    }
    wcout << 99 << " - " << L"Выход" << endl;
    wcout << L"Выберите задание:";
    wcin >> egg;
    if(egg == 99) {
        exit;
    }
    else {
        try
        {   
            system("cls");
            funcs.at(egg-1)();
            wcout << L" - - - END - - - " << endl;
            goto x;
        }
        catch (const exception&)
        {
            goto x;
        }
    }
}

// DZ 1
void Z1() {
    wcout << L"Тарасов Игорь Алексеевич" << endl;
}

void Z2()
{
    double a;
    double b;
    wcout << L"Input A:";
    wcin >> a;
    wcout << L"Input B:";
    wcin >> b;
    wcout << L"+ | ";
    wcout << a + b << endl;
    wcout << L"- | ";
    wcout << a - b << endl;
    wcout << L"* | ";
    wcout << a * b << endl;
    if (a != 0 and b != 0) {
        wcout << L"/ | ";
        wcout << a / b << endl;
    }
}

void Z41() {
    double a;
    double b;
    wcout << "Input b:";
    wcin >> a;
    wcout << "Input c:";
    wcin >> b;
    if (b == 0) {
        wcout << "delenie na 0";
    }
    else {
        b = -b;
        double x = a / b;
        if (x == -0) { wcout << "Net reshenia"; }
        else { wcout << x << endl; }

    }

}

void Z3() {
    double a;
    double b;
    wcout << "Input A:";
    wcin >> a;
    wcout << "Input B:";
    wcin >> b;

    b = -b;
    if (a != 0 and b != 0) {
        double x = a / b;
        wcout << x << endl;
    }
    else {
        wcout << "Delenie na 0" << endl;
    }
}

void Z4() {
    double a, b, c, d, x1, x2; // Объявляем переменные с плавающей точкой.

    wcout << "Input a:"; // Вводим исходные данные
    wcin >> a;
    if (a == 0) {

        Z41();
        goto x;

    }
    wcout << "Input b:";
    wcin >> b;
    wcout << "Input c:";
    wcin >> c;

    d = b * b - 4 * a * c; // Рассчитываем дискриминант
    if (d > 0) // Условие при дискриминанте больше нуля
    {
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        wcout << "x1 = " << x1 << "\n";
        wcout << "x2 = " << x2 << "\n";
    }
    if (d == 0) // Условие для дискриминанта равного нулю
    {
        x1 = -(b / (2 * a));
        if (x1 == -0) {
            wcout << "Error x1 = -0 :(" << endl;
            goto x;
        }
        wcout << "x1 = x2 = " << x1 << "\n";
    }
    if (d < 0) // Условие при дискриминанте меньше нуля
        wcout << "D < 0, Sqrt not exist";
x:
    int x;
}

void Z5() {
    bool a, b, c; //деньночь,шторы,лампа
    wcout << L"Сутки:";
    wcin >> a;
    wcout << L"Шторы:";
    wcin >> b;
    wcout << L"Лампа:";
    wcin >> c;
    if (c == true or (a == true and b == true)) {
        wcout << L"Светло" << endl;
    }
    else {
        wcout << L"Темно" << endl;
    }
    wcout << "--- END ---";
}
// END DZ 1

// DZ 2

void Z6() {
    bool inv = false;
    double R = 0.0, r = 0.0, V = 0.0, h = 0.0;
    R = int_input(L"Введите 1-ый радиус:");
    r = int_input(L"Введите 2-ой радиус:");
    h = int_input(L"Введите Высоту:");
    float S = 0, Pi = 3.14;
    float l = gipot((R - r), h);
    if ((R <= 0 or r <= 0) and inv == true) {
        wcout << L"Ошибка: Один из радиусов меньше или ровен 0" << endl;
        goto end;
    }

    S = Pi * ((l*R)+(l*r)+(R*R)+(r*r));
    V = (Pi * ((R * R) + (r * r) + (R * r)) * h)/3;
    wcout << L"Площадь - " << S << L" см2" << endl;
    wcout << L"Обьём - " << V << L" см3" << endl;
end:
    int s;
}

void Z7() {
    double w, a, x;
    a = int_input(L"Введите a:");
    x = int_input(L"Введите x:");
    if (a == 0 or x == 0) {
        wcout << L"Ошибка: Одна из переменных ровна 0" << endl;
        goto err;
    }
    if (abs(x) >= 1) {
        if ((x * x) >= a) {
            wcout << L"Ошибка: x слишком большой, или a слишком маленькая." << endl; goto err;
        }
        w = sqrt(a - (x * x));
    }
    else {
        w = a * log10(abs(x));
    }
    wcout << L"w = " << w << endl;
err:
    int s;
}

void Z8() {
    double x, y, b, z=0;
    x = int_input(L"Введите x:");
    y = int_input(L"Введите y:");
    b = int_input(L"Введите b:");
    if ((b - y<=0)) {
        wcout << L"Ошибка: log не принимает на вход 0, измените переменную y или b." << endl; goto err;
    }
    z = log10(b - y) * sqrt(b - x);
    wcout << L"z = " << z << endl;
err:
    int s;
}

void Z9() {
    int x;
    x = int_input(L"Введите x:");
    for (int i = x; i <= x + 10; i++) {
        wcout << i << endl;
    }
err:
    int s;
}
// А потому что в 16 ричной системе исчесления это 10, а Z - задание, я знаю что считаю не с нуля...
void ZA() {
    double y;
    wcout.width(10);
    wcout << "x" << " | " << "y" << endl;
    for (float x = -4; x <= 4; x += 0.5) {
        if (x == 1) {
            wcout.width(10);
            wcout << x << " | " << L"Деление на 0" << endl;
        }
        else{
            y = ((x * x) - (2 * x) + 2) / (x - 1);
            wcout.width(10);
            wcout << x << " | " << y << endl;
        }
       
        //wcout << L"x = " << x << L" \t| y = " << y << endl;
    }
err:
    int s;
}

// END DZ 2


// DZ 3

void ZB() {
    double S, n, p, r, m;
    S = int_input(L"Введите занимаемую сумму S:");
    p = int_input(L"Введите % p:");
    n = int_input(L"Введите колл-во лет n:");

    if (p > 0 and S > 0 and n > 0) {
        r = p / 100;
        m = (S * r*(pow((1+r),n)))/(12*(pow((1+r),n)-1));
        wcout << m;
    }
    else{
        wcout << L"Ошибка ..<0";
    }

}

// END DZ 3

// DZ 4

void ZA1() {
    ofstream out;
    out.open("zadanie1.txt");

    if (out.is_open()) {
        int data;
        for (int i = 0; i < 10; i++) {
            cout << "| Осталось "<< 9-i <<" |\t " << "Введите число для записи в файл:";
            cin >> data;
            out << data << endl;
        }
    }
    else {
        cout << "ERROR WRITE FILE" << endl;
    }
    out.close();

    string line;
    ifstream in;
    long int sum_m = 0;
    double temp;
    in.open("zadanie1.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            temp = atof(line.c_str());
            sum_m += temp;
        }
        cout << "Сумма чисел в файле = " << sum_m << endl;
    }
}

char sigx(double x) {
    if (x == 0) {
        return '0';
    }
    else {
        if (x > 0) {
            return '+';
        }
        else {
            return '-';
        }
    }
}

void ZA2() {
    double x = int_input(L"Введите число:");
    cout << "Знак числа = " << sigx(x) << endl;
}

float S_rectangle(float x,float y) {//Прямоугольник
    float Pi = 3.14;
    return x*y;
}

float S_triangle(float x, float y) {//Треугольник
    float Pi = 3.14;
    return (x * y)/2;
}

float S_circle(float r) {//Прямоугольник
    float Pi = 3.14;
    return Pi*(r*r);
}

void ZA3() {
    double x1, y1, x2, y2, r;
    x1 = int_input(L"Введите Ширину Прямоугольника:");
    y1 = int_input(L"Введите Высоту Прямоугольника:");
    y2 = int_input(L"Введите Ширину Основания Треугольника:");
    x2 = int_input(L"Введите Высоту Треугольника:");
    r = int_input(L"Введите Радиус круга:");
    if (x1 <= 0 or y1 <= 0) {
        cout << "Ошибка. Введен размер x < 0 или y < 0." << endl;
    }
    else {
        cout << "Площадь прямоугольника. S = " << S_rectangle(x1, x2)<<endl;
    }
    if (x2 <= 0 or y2 <= 0) {
        cout << "Ошибка. Введен размер x < 0 или y < 0." << endl;
    }
    else {
        cout << "Площадь Треугольника. S = " << S_triangle(x1, x2) << endl;
    }
    if (r <= 0) {
        cout << "Ошибка. Введен радиус <= 0." << endl;
    }
    else {
        cout << "Площадь круга. S = " << S_circle(r) << endl;
    }
}

void ZA4() {
    string data;
    cout << "RU/US:";
    cin >> data;
    if (data == "US") {
        for (int i = 0; i < 13; ++i)
        {
            if (i < 7) {
                if (0 == i % 2) {
                    for (int j = 0; j < 7; ++j)
                    {
                        cout << "\x1B[44m" << "  *" << "\033[0m";
                    }
                    cout << "\x1B[41m\x1B[31m" <<  setw(51) << "\033[0m";
                }
                else {
                    cout << "\x1B[44m" << " " << "\033[0m";
                    for (int j = 0; j < 7; ++j)
                        if (j == 6) {
                            cout << "\x1B[44m" << "* " << "\033[0m";
                        }
                        else {
                            cout << "\x1B[44m" << "*  " << "\033[0m";
                        }
                    cout << "\x1B[47m\x1B[37m" << setw(51) << "\033[0m";
                        
                }
                
                std::cout << '\n';
            }

        }

        for (int i = 0; i < 18; ++i)
            if (0 == i % 2)
                cout << "\x1B[47m\x1B[37m" << setw(72) << setfill(' ') << "\033[0m" << '\n';
            else
                cout <<  "\x1B[41m\x1B[31m"  << setw(72) << setfill('/') << "\033[0m" << '\n';

    }
    else {
        for (int i=0; i < 3; i++) {
            cout <<"\x1B[47m\x1B[37m" << setw(72) << setfill('_') << "\033[0m" << '\n';
        }
        for (int i=0; i < 3; i++) {
            cout << "\x1B[44m\x1B[34m" << setw(72) << setfill('_') << "\033[0m" << '\n';
        }
        for (int i=0; i < 3; i++) {
            cout << "\x1B[41m\x1B[31m" << setw(72) << setfill('_') <<"\033[0m" << '\n';
        }
    }

    
}

void ZA5() {
    0;
}
// END DZ 4
int wmain(int argc, wchar_t* argv[])
{   
    setlocale(LC_ALL, "");
    //fix();
    ZA4();
    vector<void(*)()> funcs {Z1,Z2,Z3,Z4,Z5,Z6,Z7,Z8,Z9,ZA};
    vector< const wchar_t*> name_func{L"Имя",L"Арифметика",L"Уравнение",L"Еще уравнение",L"Лампа со шторой",L"Конус",L"Разветвление",L"Функция",L"Порядок",L"Табуляция"};
    menu(funcs, name_func);
    
    return 0;
}