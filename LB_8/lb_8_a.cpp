#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int get_random_number(int start, int end);

template< typename T, size_t N, size_t M >
void print_array(T(&array)[N][M]);

template<size_t N, size_t M >
void fill_array(int(&array)[N][M]);

template<size_t N, size_t M >
void fill_zeros(int(&array)[N][M]);

int main()
{
    srand(time(NULL));
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
    int max = array[0][0];
    int min = array[0][0];

    for(int i = 0; i < (int)N; i++)
    {
        for(int j = 0; j < (int)M; j ++)
        {
            if(max < array[i][j])
            {
                max = array[i][j];
            }
            if(min > array[i][j])
            {
                min = array[i][j];
            }
        }
    }

    for(int i = 0; i < (int)N; i++)
    {
        for(int j = 0; j < (int)M; j ++)
        {
            if(max != array[i][j] && min != array[i][j])
            {
                array[i][j] = 0;
            }
        }
    }
}
