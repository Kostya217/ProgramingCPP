#include <iostream>

using namespace std;

// Структура(наша модель даних), яка містить поля для опису системного блоку
struct SystemBlock
{
    int height = 0;
    int width = 0;
    string color = "NULL";
    float price = 0.0;
};

template<int length>
void getSystemBloks(SystemBlock (&array)[length]);

template<int length>
void printSystemBlockByPrice(SystemBlock (&array)[length], float price);

int main()
{
    SystemBlock blocks[10];
    getSystemBloks(blocks);

    printSystemBlockByPrice(blocks, 500.3);

    return 0;
}

// Заповнення даними масиву
template<int length>
void getSystemBloks(SystemBlock (&array)[length])
{
    for(int i = 0; i < 10; i++)
    {
        // Заповнення полів кожного елемента
        array[i].height = i + 5;
        array[i].width = i + 2;
        array[i].color = "yeelow";
        array[i].price = (i + 1) * 100.5;
    }
}

// Вивід в консоль кожного елемента, ціна якого більша чим вказана
template<int length>
void printSystemBlockByPrice(SystemBlock (&array)[length], float price)
{
    for(int i = 0; i < length; i++)
    {
        if(array[i].price > price)
        {
            cout << endl << "System block " << i <<  endl
                 << "Height: " << array[i].height << endl
                 << "Width: " << array[i].width << endl
                 << "Color: " << array[i].color << endl
                 << "Price: " << array[i].price << endl;
        }
    }
}


