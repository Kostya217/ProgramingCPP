
3#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

// Отримання випадкового значення
int get_random_number(int start, int end);

// Вивід в консоль будь якого типу масиву
// typename T - означає будь який тип,
// t — це тип, здатний представляти розмір будь-якого об’єкта в байтах:
// size_t — це тип, який повертає оператор sizeof і широко використовується в стандартній бібліотеці
// для представлення розмірів і кількості.
// N та М - розміри масиву, які автоматично визначаються при передані інформації в функцію
// https://metanit.com/cpp/tutorial/9.2.php
template<typename T, size_t N, size_t M>
void print_array(T(&array)[N][M]);

// Заповнення двомірного масиву рандомними числами
template<size_t N, size_t M>
void fill_array(int(&array)[N][M]);

// Виконання саомго завдання, Заповнення всіх крім максимального та мінімального елемента нулями
template<size_t N, size_t M >
void fill_zeros(int(&array)[N][M]);

int main()
{
    int array[4][6];

    fill_array(array);
    print_array(array);

    fill_zeros(array);

    cout << endl
         << "New array: " << endl;
    print_array(array);

    return 0;
}

int get_random_number(int start, int end)
{
    return start + (rand() % end);
}

template< typename T, size_t N, size_t M >
void print_array(T(&array)[N][M])
{
    for(int i = 0; i < (int)N; i++)
    {
        for(int j = 0; j < (int)M; j ++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

template<size_t N, size_t M >
void fill_array(int(&array)[N][M])
{
    srand(time(NULL));
    for(int i = 0; i < (int)N; i++)
    {
        for(int j = 0; j < (int)M; j++)
        {
            array[i][j] = get_random_number(0, 1000);
        }
    }
}

template<size_t N, size_t M >
void fill_zeros(int(&array)[N][M])
{
    // Ініціалізуємо максимальний та мінімальний елемент першим елементом масива
    int max = array[0][0];
    int min = array[0][0];


    // Шукаємо мінімальний та максимальний елемент
    for(int i = 0; i < (int)N; i++)
    {
        for(int j = 0; j < (int)M; j ++)
        {
            // Пошук максимального числа
            if(max < array[i][j])
            {
                max = array[i][j];
            }
            // Пошук мінімального числа
            if(min > array[i][j])
            {
                min = array[i][j];
            }
        }
    }

    // Алгоритм заповнення всіх інших чисел на нулі
    for(int i = 0; i < (int)N; i++)
    {
        for(int j = 0; j < (int)M; j ++)
        {
            // Якщо число не дорівнює ні максимальному, ні мінімальному то заповнюємо його нулем
            if(max != array[i][j] && min != array[i][j])
            {
                array[i][j] = 0;
            }
        }
    }
}
