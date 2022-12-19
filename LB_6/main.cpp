#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

struct MinAndMax
{
    int index_min = 0;
    int index_max = 0;
};

int get_random_number(int start, int end);
void get_array(int *array, int length);
void print_array(int array[], int lenght);
MinAndMax get_min_and_max(int array[], int length);
void change_array(int *array, int start, int end);

int main()
{

    int length = 20;
    int array[length];
    MinAndMax minAndMax;
    srand(time(NULL));

    get_array(array, length);

    print_array(array, length);
    minAndMax = get_min_and_max(array, length);

    cout << endl <<  "Min index: " << minAndMax.index_min << endl;
    cout << "Max index: " << minAndMax.index_max << endl;
    if(minAndMax.index_min > minAndMax.index_max)
    {
        change_array(array, minAndMax.index_max, minAndMax.index_min);
    }
    else
    {
        change_array(array, minAndMax.index_min, minAndMax.index_max);
    }


    print_array(array, length);


}

int get_random_number(int start, int end)
{
    return start + (rand() % end);
}

void get_array(int *array, int length)
{
    for(int i = 0; i < length; i++)
    {
        array[i] = get_random_number(0, 100);
    }
}

void print_array(int array[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
}

MinAndMax get_min_and_max(int array[], int length){
    MinAndMax minAndMax;
    for(int i = 1; i < length; i++)
    {
        if(array[minAndMax.index_min] > array[i])
        {
            minAndMax.index_min = i;
        }
        if(array[minAndMax.index_max] < array[i])
        {
            minAndMax.index_max = i;
        }
    }

    return minAndMax;
}

void change_array(int *array, int start, int end)
{
    end -= 1;
    int new_array[(end - start)];
    for(int i = 0; i < (end - start); i++)
    {
        new_array[i] = array[end - i];
    }
    for(int i = start + 1, j = 0; i < end + 1; i++, j++){
        array[i] = new_array[j];
    }
}

