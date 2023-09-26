// Tarasov_Igor_.cpp : Этот файл содержит функцию "wmain". Здесь начинается и заканчивается выполнение программы.

#include <iostream> // no com
#include <math.h> // no com
#include <vector> // Что - то типо списков
#include <io.h> // strin/out/err
#include <fcntl.h> // _O_U16TEXT
#include <fstream> // Чтение файла
#include <sstream> 
#include <string> 
#include <algorithm>
#include <iomanip>
#include <string>     // для getline
#include <fstream>// Запись чтение файлов

#include <windows.h> 
using namespace std;

const double pi = 3.14;

/*
https://metanit.com/cpp/tutorial/7.4.php
https://ru.stackoverflow.com/questions/459154/%D0%A0%D1%83%D1%81%D1%81%D0%BA%D0%B8%D0%B9-%D1%8F%D0%B7%D1%8B%D0%BA-%D0%B2-%D0%BA%D0%BE%D0%BD%D1%81%D0%BE%D0%BB%D0%B8
Фик русского языка если не работает setlocale(LC_ALL,"rus")
позволяет использовать русские символы.

Фиксит пробелму при помощи расширения вывода
*/
void fix() {
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
        wcout<<"[" << i + 1 << "] \t" << name_func[i] << endl;
    }
    wcout <<"[" << 99<<"]" << " \t" << L"Выход" << endl;
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
            cout << endl << " - - - - END - - - - " << endl;
            system("pause");
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
    cout << "Тарасов Игорь Алексеевич" << endl;
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
    0;
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
    double S = 0;
    double l = gipot((R - r), h);
    if (r == R) {
        cout << "Ошибка: Радиусы равны, Это цилиндр" << endl;
        goto end;
    }
    if ((R <= 0 or r <= 0) and (h<=0)) {
        wcout << L"Ошибка: Один из радиусов меньше или ровен 0" << endl;
        goto end;
    }

    S = pi * ((l*R)+(l*r)+(R*R)+(r*r));
    V = (pi * ((R * R) + (r * r) + (R * r)) * h)/3;
    wcout << L"Площадь - " << S << L" см2" << endl;
    wcout << L"Обьём - " << V << L" см3" << endl;
end:
    0;
}

void Z7() {
    double w, a, x;
    a = int_input(L"Введите a:");
    x = int_input(L"Введите x < 1:");
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
        cout << "Ошибка: log не принимает на вход 0, измените переменную y или b." << endl; goto err;
    }
    z = log10(b - y) * sqrt(b - x);
    cout << "z = " << z << endl;
err:
    0;
}

void Z9() {
    string x;
    bool okey = true;
    cout << "Введите x:";
    cin >> x;
    for (int i = 0; i <= x.size(); i++) {
        cout << int(x[i]) << " " << x[i] << endl;;
        if ((57 < int(x[i]) or int(x[i]) < 48) and int(x[i]) != 0) {
            cout << "Ошибка. Вы ввели число с точкой или буквой ";
            okey = false;
            break;
        }
    }
    if (okey == true) {
        int temp_x;
        temp_x = stoi(x);

        for (int i = temp_x; i <= temp_x + 10; i++) {
            wcout << i << endl;
        }
    }
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
}
// END DZ 2

// DZ 3
double get_credit(double S, double n, double p) {
    double r, m;

    if (p > 100) {
        cout << "Вы не можете взять в долг больше чем на 100 процентов! \n";
        return -1;
    }

    if (n > 40) {
        cout << "Вы не можете взять в долг больше чем на 40 лет! \n";
        return -1;
    }

    if (S <= 0) {
        cout << "Вы не можете взять меньше 0 в долг! \n";
        return -1;
    }

    else if (p == 0) {
        m = S / (12 * n);
        return m;
    }

    else {
        r = p / 100;
        double long temp = (S * r * (pow((1 + r), n)));
        double long temp1 = (12 * (pow((1 + r), n) - 1));
        m = temp / temp1;
        return m;
    }

    if (12 * (pow(1 + r, n) - 1) < 0) {
        cout << "Деление на 0! \n";
        return -1;
    }
}

void ZB() {
    double S, n, p,temp;

    S = int_input(L"Введите занимаемую сумму S:");
    n = int_input(L"Введите колл-во лет n:");
    p = int_input(L"Введите % p:");
   
    temp = get_credit(S, n, p);
    if (temp == -1) {
        return;
    }
    else {
        cout << "Месячная выплата = " << temp << endl;
    }
}

void ZC() {
    int S, m=0, n;
    double p, r, mTest ,m0;
    cout << "Введите сумму кредита: ";
    cin >> S;
    cout << "Введите размер месячной выплаты: ";
    cin >> mTest;
    cout << "Введите кол-во лет: ";
    cin >> n;
 
    double rTemp = 0.0001; // временное r для вычисления

    if (n == 0 or S <= 0) { // на 0 делить нельзя!
        cout << "Неправильно введена ссумма или размер выплат! \n";
        return;
    }

    while (m < mTest) { // находим когда выплаты будут больше заданного, и выводим нужный %
        r = rTemp;
        m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1)); // подсчёт m с течением времени
        rTemp = rTemp + 0.0001;
    }

    cout << "p = " << round(r * 100) << "%" << endl;

}

string Read_File(string filePath,char separation='\n') {
    ifstream infile;
    string str;
    infile.open(filePath);
    if (infile.is_open()) {
        string str(std::istreambuf_iterator<char>{infile}, {});
        infile.close();
        return str;
    }
    else {
        cout << "Ошибка. Файл не открыт" << endl;
        goto error;
    }
    return str;
error:
    return "error";
}

bool Write_file(string filePath, string data) {
    ofstream outfile;
    outfile.open(filePath);
    if (outfile.is_open()) {
        outfile << data;
        outfile.close();
    }
    else {
        cout << "Ошибка. Файл не открыт" << endl;
        goto error;
    }
    return 1;
error:
    return 0;
}

void ZD() {
    string data;
    cout << "Введите данные:";
    cin >> data;
    Write_file("cppstudio.txt", data);
    cout << Read_File("cppstudio.txt", '\n') << endl;
}

void ZE() {
    string data = Read_File("read.txt");
    for (int i = 0; i < data.length(); i++) {
        if (48 <= data[i] and data[i] <= 57) {
            cout << data[i];
        }
    }
}

char gen_char() {
    bool run = true;
    while (run) {
        int h = rand()-100;
        if ((64 < h and h < 91) or (96 < h and h< 112) or (-1 >= h and  h >= -64)) {
            run = false;
            return char(h);
        }
    }
}

bool isSorted(string a)
{   
    int n = a.length();
    while (--n > 0)
        if (int(a[n]) < int(a[n - 1]))
            return false;
    return true;
}

// To generate permutation of the array
string shuffle(string a)
{
    for (int i = 0; i < a.length(); i++)
        swap(a[i], a[rand() % a.length()]);
    return a;
}

string bogosort(string a)
{   
    string temp;
    while (!isSorted(a))
        a = shuffle(a);
    return a;
}

void ZF() {
    int sizeArray;
    char temp;
    string alfavit;
    for (int i = 0; i < 10; i=i+1) {
        char chars = gen_char();
        alfavit += chars;
    }
    cout << endl;
    bool s=false;
    alfavit.erase(remove_if(alfavit.begin(), alfavit.end(), std::isspace), alfavit.end()); //удаление пробелов
    sizeArray = alfavit.length();
    cout << sizeArray << " Букв в сортировке." << endl;
    cout << "ДО  \t|" << alfavit << "\nПОСЛЕ\t|";
    
    alfavit = bogosort(alfavit);

    for (int i = sizeArray - 1; i >= 0; i--)
        cout << alfavit[i]; // вывод
    cout << endl;
    0;
}

// END DZ 3

// DZ 4
void ZA1() {
    ofstream out("zadanie1.txt");
    int data;
    for (int i = 0; i < 10; i++) {
        cout << "| Осталось "<< 9-i <<" |\t " << "Введите число для записи в файл:";
        cin >> data;
        out << data << endl;
    }
    // - - - - - - - - - - - - - - - - - - - - - - - -
    string line;
    ifstream in("zadanie1.txt");
    long int sum_m = 0;
    double temp;
    while (getline(in, line)) {
        temp = atof(line.c_str());
        sum_m += temp;
    }
    cout << "Сумма чисел в файле = " << sum_m << endl;
}

char sigx(long x) {
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

double S_rectangle(float x,float y) {//Прямоугольник
    return x*y;
}

double S_triangle(float x, float y) {//Треугольник
    return (x * y)/2;
}

double S_circle(float r) {//Прямоугольник
    return pi*(r*r);
}

void ZA3() {
    double x1, y1, x2, y2, r;
    int in;
    cout << "Выберите фигуру [1 - Прямоугольник | 2 - Треугольник | 3 - Круг]:"; cin >> in;
    if (in == 1) {
        x1 = int_input(L"Введите Ширину Прямоугольника:");
        y1 = int_input(L"Введите Высоту Прямоугольника:");
        if (x1 <= 0 or y1 <= 0) {
            cout << "Ошибка. Введен размер x < 0 или y < 0." << endl;
        }
        else {
            cout << "Площадь прямоугольника. S = " << S_rectangle(x1, y1) << endl;
        }
    }
    else if (in == 2) {
        y2 = int_input(L"Введите Ширину Основания Треугольника:");
        x2 = int_input(L"Введите Высоту Треугольника:");
        if (x2 <= 0 or y2 <= 0) {
            cout << "Ошибка. Введен размер x < 0 или y < 0." << endl;
        }
        else {
            cout << "Площадь Треугольника. S = " << S_triangle(x2, y2) << endl;
        }
    }
    else if (in == 3) {
        r = int_input(L"Введите Радиус круга:");


        if (r <= 0) {
            cout << "Ошибка. Введен радиус <= 0." << endl;
        }
        else {
            cout << "Площадь круга. S = " << S_circle(r) << endl;
        }
    }
    else {
        cout << "Такого варианта нету. Ошибка." << endl;
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
    int sinx[30][110] = { 0 };
    int l = 15;
    double s = -(1/l);
    for (int i = 0; i < 110; i ++) {
        sinx[int(((sin(s)) * 15+15))][i] = {9};
        s = s + (1.0/l);
    }

    for (int x = 0; x < 30 ;x++) {
        for (int y = 0; y < 110; y++) {
            if (y == 0) {
                cout << "\x1B[45m" << "|" << "\033[0m";
            }
            else {
                if (x == 15) {
                    cout << "\x1B[45m" << "-" << "\033[0m";
                }
                else {
                    int h = sinx[x][y];
                    if (h == 9) {
                        cout << "\x1B[44m" << " " << "\033[0m";
                    }
                    else {
                        cout << " ";
                    }
                }
            }
            
            
            
        }
        cout << endl;
    }
}

void ZA6() { // https://www.graecolatini.by/htm-different/num-converter-roman.htm
    string data;
    cout << "Введите число в римской системе исчесления: ";
    cin >> data;
    char err[100];
    int chetdef = 0;
    int chetchik = 0;
    for (int i = 0; i <= data.size() - 1; i++) {
            switch (data[i]) {
            case 'I':
                if (i + 1 < data.size() && (data[i + 1] == 'V' || data[i + 1] == 'X' || data[i + 1] == 'C')) {
                    chetchik = chetchik - 1;
                }
                else chetchik = chetchik + 1;
                break;

            case 'V':
                chetchik = chetchik + 5;
                break;

            case 'X':
                if (i + 1 < data.size() && (data[i + 1] == 'L' || data[i + 1] == 'C' || data[i + 1] == 'M')) {
                    chetchik = chetchik - 10;
                }
                else chetchik = chetchik + 10;
                break;

            case 'L':
                chetchik = chetchik + 50;
                break;

            case 'C':
                if (i + 1 < data.size() && (data[i + 1] == 'D' || data[i + 1] == 'M')) {
                    chetchik = chetchik - 100;
                }
                else chetchik = chetchik + 100;
                break;

            case 'D':
                chetchik = chetchik + 500;
                break;

            case 'M':
                chetchik = chetchik + 1000;
                break;

            default: err[chetdef] = data[i]; chetdef++;
                break;
            }
        }
        cout << endl;
        if (chetchik == 0) {
            cout << "Вы не ввели число для перевода" << endl;
        }
        else {
            cout << "В 10-тичной системе исчесления: " << chetchik << endl;
    }
    
}

int gen(int m, int b, int c ,long long int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s = (m * s + b) % c;
    }
    return s;
}
void ZA7 () {
    int mode;
    mode = int_input(L"Укажите вариант. [1/2]:");
    if (mode == 1) {
        for (int i = 1; i < 10; i++) {
            cout << gen(37, 3, 64, i) << endl;
        }
    }
    else {
        for (int i = 1; i < 10; i++) {
            cout << gen(25173, 13849, 65537, i) << endl;
        }
    }
}

void ZA8() {
    double A[3][4] = {{5,2,0,10},{3,5,2, 5},{20,0,0,0}};
    double B[4][2] = {{1.20,0.50},{2.80,0.40},{5,1},{2,1.5}};
    double C[3][2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 4; k++)
                C[i][j] += A[i][k] * B[k][j];   
        }
    }

    // Деньги
    int maxSeller = 0;
    int minSeller = 0;
    double maxMoney = 0;
    double minMoney = 10000000;
    for (int x = 0; x < 3; x++) {
        if (C[x][0] > maxMoney) {
            maxSeller = x + 1;
            maxMoney = C[x][0];
        }
        if (C[x][0] < minMoney) {
            minSeller = x + 1;
            minMoney = C[x][0];
        }
    }
    cout << "Продавец " << maxSeller << " С максимальной суммой:\t" << maxMoney << endl;
    cout << "Продавец " << minSeller << " С минимальной суммой:\t" << minMoney << endl;

    // Комиссионные
    maxSeller = 0;
    minSeller = 0;
    double maxComss = 0;
    double minComss = 10000000;
    for (int x = 0; x < 3; x++) {
        if (C[x][1] > maxComss) {
            maxSeller = x + 1;
            maxComss = C[x][1];
        }
        if (C[x][1] < minComss) {
            minSeller = x + 1;
            minComss = C[x][1];
        }
    }
    cout << "Продавец " << maxSeller << " С максимальной коммисией:\t" << maxComss << endl;
    cout << "Продавец " << minSeller << " С минимальной коммисией:\t" << minComss << endl;

    // Общая сумма денег
    double sumMoney = 0;
    for (int x = 0; x < 3; x++) {
        sumMoney += C[x][0];
    }
    cout << "Всего денег = " << sumMoney << endl;

    // Общая сумма комиссионных
    double sumComss = 0;
    for (int x = 0; x < 3; x++) {
        sumComss += C[x][1];
    }
    cout << "Всего комиссионных = " << sumComss << endl;

    // Общая сумма денег (+ комиссионные)
    double SumMoneyResult = 0;
    for (int x = 0; x < 3; x++) {
        SumMoneyResult += C[x][0] + C[x][1];
    }
    cout << "Общая сумма денег (+ комиссионные) = " << SumMoneyResult << endl;
}

int n_to_ten(char data) {
    string base = "0123456789ABCDFEGH";
    for (int i = 0; i < base.size(); i++) {
        if (data == base[i]) {
            return i;
        }
    }

}


int char_to_int(char symbol) {
    switch (symbol) {
    case '0': return 0; break;
    case '1': return 1; break;
    case '2': return 2; break;
    case '3': return 3; break;
    case '4': return 4; break;
    case '5': return 5; break;
    case '6': return 6; break;
    case '7': return 7; break;
    case '8': return 8; break;
    case '9': return 9; break;
    case 'A': return 10; break;
    case 'B': return 11; break;
    case 'C': return 12; break;
    case 'D': return 13; break;
    case 'E': return 14; break;
    case 'F': return 15; break;
    }
    return -1;
}


string int_to_char(int symbol) {
    switch (symbol) {
    case 0: return "0"; break;
    case 1: return "1"; break;
    case 2: return "2"; break;
    case 3: return "3"; break;
    case 4: return "4"; break;
    case 5: return "5"; break;
    case 6: return "6"; break;
    case 7: return "7"; break;
    case 8: return "8"; break;
    case 9: return "9"; break;
    case 10: return "A"; break;
    case 11: return "B"; break;
    case 12: return "C"; break;
    case 13: return "D"; break;
    case 14: return "E"; break;
    case 15: return "F"; break;
    }
    return "";
}


long long funTenCC(string line, int base_num = 2) { // перевод в 10 с.с.
    long long new_x = 0; // полученное число в 10 с.с.

    for (int i = 0; i < line.length(); i++) { // пробегание по всем цифрам
        int symbol = char_to_int(line[i]); // конвертированный символ в цифру
        cout << symbol << endl;
        new_x += symbol * pow(base_num, line.length() - i - 1); // запись в число цифры line[i]
    }
    cout << new_x << endl;
    return new_x;
}


string funNewCC(int num, int base_num = 2) { // перевод в нужную с.с.
    string new_x = int_to_char(num % base_num);
    cout << new_x << endl;
    if (num > 0) {
        return funNewCC(num / base_num) + new_x;
    }
    return new_x;
}


void ZA9() {
    string data;
    int osnov_old=16,osnov_nev=10;

    cout << "Введите исходное число: ";
    cin >> data;
    cout << "Введите исходное основание (число): ";
    cin >> osnov_old;
    cout << "Введите новое основание (число): ";
    cin >> osnov_nev;

    int num = funTenCC(data, osnov_old);
    if (osnov_nev == 10) {
        cout << "Число в 10 системе: " << num << endl;
    }
    else {
        cout << "Число в 10 системе:" << num << endl;
        cout << "Число в n ричной" << funNewCC(num, osnov_nev) << endl;
    }
    
}
// END DZ 4

// DZ 5 Доп функции

// Через рекурсию и деление
int gcn(int a, int b) {
    if (b == 0)
        return a;
    return gcn(b, a % b);
}

// Через Цикл Вычитанием
int gcd(int x, int y) {
    while (x != y) {
        if (x > y) {
            x = x - y;
        }
        else {
            y = y - x;
        }
    }
    return x;
}

// Проверяет простая ли функция
bool is_es(long long n) {
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

//перевод из 10 в 3-ичную систему
int ten_to_x3(int Number, int Base) {
    int chislo = Number;
    int ostatok;
    string data;
    while (chislo > 0)
    {
        ostatok = chislo % 3;
        chislo /= 3;
        data.append(to_string(ostatok));
    }
    return stoi(data);
}

//перевод из N-ой системы в 10-ичную систему
int cc_to_ten(int Number, int Base) {
    int n = Number, a = Base;
    int result = 0;
    int cnt = 0;
    while (n > 0)
    {
        result += n % 10 * pow(a, cnt++);
        n /= 10;
    }
    return result;
}

// разделение по символу
vector<string> split(string arr, char separator = ' ') {
    int i = 0;
    vector<string> ret;
    string s;
    while (arr[i] != '\0') {
        if (arr[i] != separator) {
            s += arr[i];
        }
        else {
            ret.push_back(s);
            s.clear();
        }
        i++;

    }
    if (arr.length() > 0) {
        ret.push_back(s);
    }
    return ret;
}

// DZ 5

void ZAA() {
    double x, y;
    x = int_input(L"Введите первое число:");
    y = int_input(L"Введите второе число:");
    cout << gcd(x, y) << " или " << gcn(x, y) << endl;  
}

void ZAB() {
    int gg[100];
    int data;
    data = int_input(L"Введите число >2: ");
    if (data <= 2) {
        cout << "Ошибка. Вы ввели число меньше 2-вух.";
    }
    else {
        for (int i = 2; i < data; i++) {
            if (is_es(i)) {
                cout << i << endl;
            }
        }
    }
    
}

void ZAC(){ //24 Статическая обработка файла: поиск наименее часто встречающейся согласной буквы.
    string data;
    int l[9999] = {0};
    int min_int = 10000;
    char min_char = '.';
    data = Read_File("read.txt");
    for (int i = 0; i < data.length(); i++) {
        l[int(data[i]) + 1000]++;
    }
    for (int i = 0; i < 9999; i++) {
        char c = char(i - 1000);
        if (0 < l[i]) {
            if (0 < l[i] < min_int and

                ((('a' <= c && c <= 'z') || ('а' <= c && c <= 'я') || ('A' <= c && c <= 'Z') || ('А' <= c && c <= 'Я'))
                    and (!strchr("аоэиуыеёюяaeiouАОЭИУЫЕЁЮЯAEIOU", c)))) {
                min_int = l[i];
                min_char = c;
            }
        }
        
        
    }
    cout << "Меньше всего:" << min_char << " Повторяется:" << min_int << endl;

}

void ZAD() {//Задан массив F[1:n] из чисел в семеричной системе счисления. 
    //В другом массиве организовать перевод исходного массива в троичную систему счисления
    cout << "Введите числа в 7-ичной системе исчесления через пробел:";
    string temp,temp1;
    cin >> temp1;
    getline(cin,temp);
    temp = temp1 + temp;
    vector<string> l = split(temp);
    vector<int> data;
    int n = l.size();
    int *array = new int[n];
    for (int i = 0; i < l.size(); i++) {
        for (int x = 0; x < l[i].length(); x++) {
            if (6 < (int(l[i][x]) - 48)) {
                cout << "Ошбика. Вы ввели не 7-ричную систему исчесления." << endl;
                return;
            }
        }
        array[i] = stoi(l[i]);
    }
    int* array_to_f = new int[n];
    for (int i = 0; i < l.size(); i++) {
        array_to_f[i] = ten_to_x3(cc_to_ten(array[i], 7),3);
    }
    for (int i = 0; i < l.size(); i++) {
        cout << array_to_f[i] << " ";
    }
    cout << "[3]" << endl;
}

vector<string> input(string text,string text1) {
    cout << text << text1;
    string temp, temp1;
    cin >> temp1;
    getline(cin, temp);
    temp = temp1 + temp;
    vector<string> l = split(temp);
    return l;
}

void ZAE(){
    string medals[10][3];
    vector<string> country = {"Германия","Новергия","Россия","Австрия","Канада","США","Финлядия","Япония","Китай","Корея"};
    cout << "Страна | Медали (через пробел)" << endl;
    for (int i = 0; i < 10; i++) {
        vector<string> data = input(country[i], ":");
        //ошбика ниже
        for (int x = 0; x < 3; x++) {
            medals[i][x].append(data[x]);
            cout << medals[i];
            cout << medals[i] ->size() << " ";
        }   
        if (medals[i]->length() != 3) {
            cout << "Ошибка. Вы ввели не 3 типа медалей";
            return;
        }
    }
    int array[10][3];
    for (int i = 0; i < 10; i++) {
        for (int x = 0; x < 3; x++) {
            array[i][x] = stoi(medals[i][x]);
            cout << array[i][x];
        }
        cout << endl;
    }

}
// END DZ 5

int main(int argc, wchar_t* argv[])
{

    /*
    5-3 / 2 штуки
    5-4 / 2 штуки
    5-5
    */
    //fix()
    setlocale(LC_ALL, "RUSSIAN");

    ZA9();
    //system("pause");
    vector<void(*)()> funcs {Z1,Z2,Z3,Z4,Z5,Z6,Z7,Z8,Z9,ZA,ZB,ZC,ZD,ZE,ZF,ZA1,ZA2,ZA3,ZA4,ZA5,ZA6,ZA7,ZA8,ZA9,ZAA,ZAB,ZAC,ZAD};
    vector< const wchar_t*> name_func{L"1-1 Имя",L"1-2 Арифметика",L"1-3 Уравнение",L"1-4 Еще уравнение",L"1-5 Лампа со шторой",L"2-1 Конус",L"2-2 Разветвление",L"2-3 Функция",L"2-4 Порядок",L"2-5 Табуляция",L"3-1 Заем",L"3-2 Ссуда",L"3-3 Копирование файла",L"3-4 Фильтр",L"3-5 Сортировка букв",L"4-1 Файл",L"4-2 Знак числа",L"4-3 Геометрические фигуры",L"4-4 Былая слава (Осуждаю !!!)",L"4-5 Синусоида",L"4-6 Автоматный распознаватель",L"4-7 Генератор псевдослучайных чисел",L"4-8 Умножение матриц",L"4-9 Системы счисления",L"5-1 Алгоритм Евклида",L"5-2 Решето Эратосфена",L"5-3 Обработка текстовых файлов",L"5-4 Ряды"};
    //menu(funcs, name_func);
    return 0;
}