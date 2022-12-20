#include <iostream>
#include <windows.h>
#include <algorithm> 
#include <cstring> // Бібліотека для використання класу string

using namespace std; // string знаходиться в цьому namespace

int main()
{
    // Встановлення кодування 1251
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    string row = "";
    int last_index = 0;

    // Ввід даних через консоль
    cout << "Введіть своє речення: ";
    getline(cin, row);
    cout << row << endl;

    // символ який треба знайти та видалити
    char u = 'и';
    // символ на який треба замінити останню букву 'и'
    char e = 'е';

    // Виводимо всі індекси букви 'и'
    for(int i = 0; i < (int)row.length(); i++)
    {
        if(row[i] == u)
        {
            cout << i << " ";
            last_index = i;
        }
    }
    
    // Заміняємо останюю 'и' на 'е'
    row[last_index] = e;
    
    // Видаляємо всі букви 'и'
    // erase() - Видалення заданої кількості символів з рядка. 
    row.erase(remove(row.begin(), row.end(), u), row.end());

    cout << endl << row << endl;
    return 0;
}
