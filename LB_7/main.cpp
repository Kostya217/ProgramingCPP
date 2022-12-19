#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;


int get_random_number(int start, int end);

int main()
{
    srand(time(NULL));

    // Створюємо двухмірний масив
    int height = 4;
    int width = 6;
    int array[6][width];

    // Заповнюємо масив даними
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            array[i][j] = get_random_number(0, 1000);
        }
    }

    // Виводимо масив в консоль
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j ++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Шукаємо найбільший елемент в масиві
    int max = 0;
    int index_max = 0;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j ++){
            // Умова для пошуку найбільшого елемента
            if(max < array[i][j]){
                max = array[i][j];
                index_max = i;
            }
        }
    }

    // Вивід в консоль рядка з найбільшим числом
    cout << endl
         << "Row with max number: ";

    for(int j = 0; j < width; j ++){
        cout << array[index_max][j] << " ";
    }


}

int get_random_number(int start, int end)
{
    return start + (rand() % end);
}

//void print_array(int array[][6], int height, int width)
//{
//    for(int i = 0; i < height; i++)
//    {
//        for(int j = 0; j < width; j ++){
//            cout << array[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
