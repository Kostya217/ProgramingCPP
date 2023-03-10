#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;


int get_random_number(int start, int end);

template< typename T, size_t N, size_t M >
void print_array(T(&array)[N][M]);

template<size_t N, size_t M >
void fill_array(int(&array)[N][M]);

// Отримання суми чисел із верхнього та нижнього трикутника
template<size_t N, size_t M >
int get_sum_triangles(int(&array)[N][M]);

// Завдання Б варіант А
int main()
{
    int array[10][9];

    fill_array(array);
    print_array(array);

    cout << endl << "Sum: " << get_sum_triangles(array);

    return 0;

}

int get_random_number(int start, int end)
{
    return start + (rand() % end);
}

template<typename T, size_t N, size_t M>
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
            array[i][j] = get_random_number(0, 10);
        }
    }
}

template<size_t height, size_t width >
int get_sum_triangles(int(&array)[height][width])
{
    int sum = 0;
    // Цикл для отримання суми всіх чисел із верхнього трикутника
    // В якості відрізання непотрібних елементів використовується і
    // Для лівого края формула j = i, для правого width - i
    for(int i = 0; i < (int)height/2; i++) // 0 < i < 5
    {
        for(int j = i; j < (int)width - i; j ++)
        {
            sum += array[i][j];
        }
    }
    // Цикл для отримання суми всіх чисел із нижнього трикутника
    // В якості відрізання непотрібних елементів використовується і
    // Для лівого края формула j = height - i - 1, для правого width - height + i + 1
    for(int i = height/2; i < (int)height; i++) // 5 < i < 10
    {
        for(int j = height - i - 1; j < (int)width - (int)height + i + 1; j ++)
        {
            sum += array[i][j];
        }
    }

    return sum;
}



