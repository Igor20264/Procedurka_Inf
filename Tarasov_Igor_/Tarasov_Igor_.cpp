﻿// Tarasov_Igor_.cpp : Этот файл содержит функцию "wmain". Здесь начинается и заканчивается выполнение программы.

#include <iostream> // no com
#include <math.h> // no com
#include <vector> // Что - то типо списков
#include <io.h> // strin/out/err
#include <fcntl.h> // _O_U16TEXT
#include <fstream> // Чтение файла
#include <sstream> 
#include <string> 
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
    double R = 0.0, r = 0.0, V = 0.0, h = 0.0;
    R = int_input(L"Введите 1-ый радиус:");
    r = int_input(L"Введите 2-ой радиус:");
    h = int_input(L"Введите Высоту:");
    float S = 0, Pi = 3.14;
    float l = gipot((R - r), h);

    if ((R <= 0 or r <= 0) and (h<=0)) {
        wcout << L"Ошибка: Один из радиусов меньше или ровен 0" << endl;
        goto end;
    }

    S = Pi * ((l*R)+(l*r)+(R*R)+(r*r));
    V = (Pi * ((R * R) + (r * r) + (R * r)) * h)/3;
    wcout << L"Площадь - " << S << L" см2" << endl;
    wcout << L"Обьём - " << V << L" см3" << endl;
end:
    0;
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
    0;
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
    0;
}

void Z9() {
    int x;
    x = int_input(L"Введите x:");
    for (int i = x; i <= x + 10; i++) {
        wcout << i << endl;
    }
err:
    0;
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
    0;
}

// END DZ 2


// DZ 3

void ZB() {
    double S, n, p, r, m;
    S = int_input(L"Введите занимаемую сумму S:");
    n = int_input(L"Введите колл-во лет n:");
    p = int_input(L"Введите % p:");
    

    if (p > 0 and S > 0 and n > 0) {
        r = p / 100;
        m = (S * r*(pow((1+r),n)))/(12*(pow((1+r),n)-1));
        wcout << m << L"Руб. Месячная выплата" << endl;
    }
    else{
        wcout << L"Ошибка ..<0";
    }
    0;
}

double func(double sum, double month, int year)
{
    double percent;

    percent = ((12 * month - 1) / sum) * 100;

    if (percent > 100)
    {
        cout << "Процент не может быть более 100 %" << endl;
        exit(0);
    }
    else
        return percent;
}

void ZC() {
    int S, m, n;
    double p, r, m1;
    m1 = 0;
    cout << "Введите сумму кредита: ";
    cin >> S;
    cout << "Введите размер месячной выплаты: ";
    cin >> m;
    cout << "Введите кол-во лет: ";
    cin >> n;
 
    for (p = 1; m1 < m; p++)
    {
        r = p / 1200;
        m1 = S * (r + (r / (pow((1 + r), n) - 1)));
        if (m1 > m) {
            cout << "Кредит давался под " << p << "%" << endl;
        }
    }

}

void ZD() {
    ifstream fin;
    fin.open("C:\\Users\\Admin\\source\\repos\\Igor20264\\Tarasov_Igor\\Tarasov_Igor_\\read.txt");
    if (fin.is_open()) {
        char buff[1024];
        x:
        fin >> buff;
        cout << buff << endl; // напечатали слово
        if (strlen(buff) != 0) {
            goto x;
        }
        fin.close();
    }
    else {
        cout << "Error" << endl;
    }
    0;
}

void ZE() {
    ifstream fin;
    fin.open("C:\\Users\\Admin\\source\\repos\\Igor20264\\Tarasov_Igor\\Tarasov_Igor_\\read.txt");
    if (fin.is_open()) {
        char buff[1024];
    x:
        fin >> buff;
        for (int i = 0; i < strlen(buff); i++) {
            cout << int(buff[i]) << " " << buff[i] << endl;
            if (48 <= buff[i] and buff[i] <= 57) {
                cout << buff[i] << endl;
            }
        }
        if (strlen(buff) != 0) {
            goto x;
        }
        fin.close();
    }
    else {
        cout << "Error" << endl;
    }
    0;
}

void ZF() {
    int sizeArray;
    char temp;
    string alfavit = "wpMQqlLXoSWgVijBHDzkeOusYICtEK";//30
    //string alfavit = "wpMQqlXoSWgVijGfmZUcbvryTaRPFdAnJLBHDzkeOuhNsxYICtEK";//52
    bool s=false;
    //wcout << "Введите Строку: " << endl; cin >> alfavit;
    alfavit.erase(remove_if(alfavit.begin(), alfavit.end(), std::isspace), alfavit.end());
    sizeArray = alfavit.length();
    cout << sizeArray << " Букв в сортировке." << endl;
    cout << "ДО  \t|" << alfavit << "\nПОСЛЕ\t|";
    for (int i = 1; i < sizeArray; i++)
        for (int j = 0; j < sizeArray - i; j++)
        {
            if (alfavit[j + 1] > alfavit[j])
            {
                temp = alfavit[j];
                alfavit[j] = alfavit[j + 1];
                alfavit[j + 1] = temp;
            }
        }

    for (int i = sizeArray - 1; i >= 0; i--)
        wcout << alfavit[i]; // вывод
    cout << endl;
    0;
}

// END DZ 3
int wmain(int argc, wchar_t* argv[])
{   
    //fix();
    setlocale(LC_ALL, "RUSSIAN");

    vector<void(*)()> funcs {Z1,Z2,Z3,Z4,Z5,Z6,Z7,Z8,Z9,ZA,ZB,ZC,ZD,ZE,ZF};
    vector< const wchar_t*> name_func{L"Имя",L"Арифметика",L"Уравнение",L"Еще уравнение",L"Лампа со шторой",L"Конус",L"Разветвление",L"Функция",L"Порядок",L"Табуляция",L"Заем",L"Ссуда",L"Копирование файла",L"Фильтр",L"Сортировка букв"};
    menu(funcs, name_func);
    
    return 0;
}