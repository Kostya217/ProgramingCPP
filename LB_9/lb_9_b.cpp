#include <iostream>
#include<cstring>

using namespace std;


int main()
{
    // Масив із нашими словами
    string array[6]
    {
        "string_with_xyz",
        "tremble",
        "observe",
        "hel_xyz+l",
        "overl_xyz_ook"
        "hello"
    };

    // Пошук слів із суфіксом хуz
    for(int i = 0; i < 6; i++)
    {
        // якщо xyz є в слові, то вивести його
        if(array[i].find("xyz") < array[i].length())
        {
            cout << array[i] << endl;
        }
    }

    return 0;
}
