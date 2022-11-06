//Самые лучшие объяснения здесь: https://informatics.msk.ru/mod/book/view.php?id=579

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
    int a[N], s = 0, k = 0, n; 
    n = N;
    bool b[N];

    // Делаем рандом для рандомайзера
    srand((unsigned)time(NULL));

    ofstream file_f("d:\\1\\f.txt");
    if (!file_f) {
        cout << "20 строка файл не открыт";
    }
    else
    {
        cout << "Заполняем файл a[i]" << endl;
        for (int i = 0; i < N; i++)
        {
            a[i] = rand()%98;
            file_f << a[i] << endl;
            cout << a[i];
            if (i % 10 != 9) { cout << "\t"; }
            else { cout << "\n"; };
            b[i] = true; //Заполнили массив с логикой true - означает не повторяюшиеся элементы. На этом этапе проверки на уникальность нет, заполняем всё true
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
        while (file >> s) {//getline(file, str)) { // пока не достигнут конец файла класть очередную строку в переменную (str)
            
        a[k] = s;// atoi(str.c_str());
            cout << a[k];// и снова вывожу на экран но уже модифицированную строку (без записи ее в файл)
            //Делаем аккуратный вывод через табуляцию
            if (k % 10 != 9) { cout << "\t"; }
            else { cout << "\n"; }; 
            k++;
            for (int j = 0; j < k; j++) 
            { //Проверяем уникальность
                if (a[j] == a[k])
                { //Если не уникальные, в массив логики ставим флаг false
                    b[k] = false;
                }
            }
        }

        file.close(); // обязательно закрываем файл что бы не повредить его

    }
    else cout << " Файл не существует" << endl;

    //TODO Осталось gфиксить вывод из файла g.txt.
        
    ofstream out; // поток для записи
    out.open("d:\\1\\g.txt");
    if (out.is_open())
    {
        for (int i = 0; i < N; i++) 
            {
                //Если элемент в массиве логики = true, значит он уникальный и мы его записываем в файл g, иначе пропускаем.
               if (b[i]) out << a[i] << endl;
            }
    }
    out.close();
    k = 0;
    //открываем файл в режиме чтения
    file.open("d:\\1\\g.txt");
    //если открытие файла прошло корректно, то
    if (file)
    {
        cout << "\nВыводим только уникальные элементы массива из файла g.txt" << endl; // выводим на экран
        while (file >> s) {//getline(file, str)) { // пока не достигнут конец файла класть очередную строку в переменную (str)

            cout << s;
            //Делаем аккуратный вывод через табуляцию
            if (k % 10 != 9) { cout << "\t"; }
            else { cout << "\n"; };
            k++;
        }

        file.close(); // обязательно закрываем файл что бы не повредить его
        cout << endl << endl;
    }
    system("pause");
    return 0;

}
