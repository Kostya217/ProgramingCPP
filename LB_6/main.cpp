#include <iostream>
// Бібліотека для часу
#include <time.h>
// Бібліотека для рандому
#include <cstdlib>

using namespace std;

struct MinAndMax
{
    int index_min = 0;
    int index_max = 0;
};

// Декларуємо прототипи функцій для додання їх в область видимості
int get_random_number(int start, int end);
void get_array(int *array, int length);
void print_array(int array[], int lenght);
MinAndMax get_min_and_max(int array[], int length);
void change_array(int *array, int start, int end);

int main()
{
    // Створюємо наш масив
    int length = 20;
    int array[length];

    //Структура в якій зберігається максимальний та мінімальний індекс
    MinAndMax minAndMax;

    // Встановлення початкової точки, з якої відбувається генерування випадкових чисел
    srand(time(NULL));

    // Заповнення масиву випадковими числами
    get_array(array, length);

    // Виведення в консоль масиву
    print_array(array, length);

    // Отримання мінімального та максимального індексу
    minAndMax = get_min_and_max(array, length);

    cout << endl <<  "Min index: " << minAndMax.index_min << endl;
    cout << "Max index: " << minAndMax.index_max << endl;

    // Перевірка щоб правильно підставити стартові та кінцеві значення, звідки потрібно змінити масив
    if(minAndMax.index_min > minAndMax.index_max)
    {
        change_array(array, minAndMax.index_max, minAndMax.index_min - 1);
    }
    else
    {
        change_array(array, minAndMax.index_min, minAndMax.index_max - 1);
    }


    print_array(array, length);


}

int get_random_number(int start, int end)
{
    // Вертає випадкове число від початкового до кінцевого => (3, 10) => 3 + 9057 % 10 = 3 + 7 = 10
    return start + (rand() % end);
}

void get_array(int *array, int length)
{
    // Через цикл присвоюємо випадкові значення елементам
    for(int i = 0; i < length; i++)
    {
        array[i] = get_random_number(0, 100);
    }
}

void print_array(int array[], int length)
{
    // Через цикл виводимо елементи масиву
    for(int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
}

MinAndMax get_min_and_max(int array[], int length){
    // Через цикл знаходим мінімальний та максимальний елементи, та вертаємо їх
    MinAndMax minAndMax;
    for(int i = 1; i < length; i++)
    {
        // Перевірка на мінімальний елемент
        if(array[minAndMax.index_min] > array[i])
        {
            // Визначення мінімального індексу
            minAndMax.index_min = i;
        }
        // Перевірка на максимальний елемент
        if(array[minAndMax.index_max] < array[i])
        {
            // Визначення максимального індексу
            minAndMax.index_max = i;
        }
    }

    return minAndMax;
}

void change_array(int *array, int start, int end)
{
    // створюємо новий масив та заповнюємо його із кінця в початок
    int new_array[(end - start)];
    for(int i = 0; i < (end - start); i++)
    {
        new_array[i] = array[end - i];
    }
    // Заміняємо елементи в масиві на потрібні
    for(int i = start + 1, j = 0; i < end + 1; i++, j++)
    {
        array[i] = new_array[j];
    }
}

