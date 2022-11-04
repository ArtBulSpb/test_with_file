#include <iostream>
#include <cstdlib> 
#include <string> // подключаем строки
#include <fstream> // подключаем файлы

#define N 100

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    string str; // сюда будем класть считанные строки
    int a[N], s = 0, k = 0;
    // Делаем рандом для рандомайзера
    srand((unsigned)time(NULL));

    ofstream file_f("d:\\1\\f.txt");
    if (!file_f) {
        cout << "20 строка файл не открыт";
    }
    else
    {
        cout << "28 строка заполняем файл a[i]" << endl;
        for (int i = 0; i < N; i++)
        {
            a[i] = rand();
            file_f << a[i] << endl;
            cout << a[i];
            if (i % 10 != 9) { cout << "\t"; }
            else { cout << "\n"; };
            
        }
    }
    file_f.close();


    ifstream file;

    //открываем файл в режиме чтения
    file.open("d:\\1\\f.txt");
    //если открытие файла прошло корректно, то
    if (file)
    {
        cout << "\nВыводим элементы массива после чтения их из файла и записи в массив" << endl; // выводим на экран
        while (getline(file, str)) { // пока не достигнут конец файла класть очередную строку в переменную (str)
            
            a[k] = atoi(str.c_str());
            cout << a[k];// и снова вывожу на экран но уже модифицированную строку (без записи ее в файл)
            if (k % 10 != 9) { cout << "\t"; }
            else { cout << "\n"; }; 
            k++;
        }

        file.close(); // обязательно закрываем файл что бы не повредить его

    }
    else cout << " Файл не существует" << endl;


    //TODO Осталось сделать массив исключив дубли и записать его в файл g.txt.
    ofstream out; // поток для записи
    out.open("d:\\1\\g.txt");
    if (out.is_open())
    {
        out << "Сумма нечетных чисел: " << s << endl;
        out << "Количество нечетных чисел: " << k << endl;
    }
    out.close();
    system("pause");
    return 0;

}