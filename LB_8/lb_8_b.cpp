#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;


int get_random_number(int start, int end);

// Task B variant A
int main()
{
    srand(time(NULL));

    int height = 10;
    int width = 9;
    int array[height][width];



    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            array[i][j] = get_random_number(0, 10);
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j ++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Sum elements variant A
    int sum = 0;
    for(int i = 0; i < height/2; i++) // 0 < i < 5
    {
        for(int j = i; j < width - i; j ++){
            sum += array[i][j];
        }
    }
    for(int i = height/2; i < height; i++) // 5 < i < 10
    {
        for(int j = height - i - 1; j < width - height + i + 1; j ++){
            sum += array[i][j];
        }
    }

    cout << endl << "Sum: " << sum;
}

int get_random_number(int start, int end)
{
    return start + (rand() % end);
}



