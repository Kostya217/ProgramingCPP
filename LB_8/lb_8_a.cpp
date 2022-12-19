#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;


int get_random_number(int start, int end);
void print_array(int array[][6], int height, int width);

int main()
{
    srand(time(NULL));

    int height = 4;
    int width = 6;
    int array[height][width];



    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            array[i][j] = get_random_number(0, 1000);
        }
    }

    int max = array[0][0];
    int min = array[0][0];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j ++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j ++){
            if(max < array[i][j]){
                max = array[i][j];
            }
            if(min > array[i][j]){
                min = array[i][j];
            }
        }
    }
    cout << endl
         << "New array: " << endl;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j ++){
            if(max != array[i][j] && min != array[i][j]){
                array[i][j] = 0;
            }

        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j ++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }


}

int get_random_number(int start, int end)
{
    return start + (rand() % end);
}


