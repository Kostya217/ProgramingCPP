#include <iostream>
#include <fstream>

using namespace std;


// функція для отримання тільки частини рядка
// Наприклад:
// string str = "мама – це, безумовно, найдорожча людина, яка народила мене"
// cutSrt(str, 0, 4) => мама
// cutSrt(str, 1, 3) => ам
// cutSrt(str, 0, 10) => мама – це,
string cutStr(string str, int x, int y)
{
    string row = "";

    for(int i = x; i < y; i++)
    {
        row += str[i];
    }

    return row;
}


// функція для підрахунку слів в слові
int coutWords(string str, string word)
{
    int count = 0;

    for(int i = 0; i <= (int)(str.length() - word.length()); i++)
    {
        // якщо 4 символи дорівнюють нашому слову, то плюсуємо лічильник,
        // потім зміщуємся на 1 символ, і перевіряємо наступні 4
        if(cutStr(str, i, i + word.length()) == word)
        {
            count++;
        }
    }

    return count;
}

// функція для отримання всього тексту в файлі
string getTextFormFile(string path)
{
    ifstream input(path);
    string line = "";
    string text = "";

    // Перевірка чи файл відкритий
    if(!input.is_open())
    {
        cout << "FILE IS NOT OPEN" << endl;
        return "";
    }

    // Додаємо кожний рядок в файлі до нашої зміної.
    while(getline(input, line))
    {
        text += line;
    }

    input.close();
    return text;
}

int main()
{
    cout << "Count word mama: "
         << coutWords(
                getTextFormFile("..\\work_with_file\\resource\\Mother.txt"),
                "мама"
            )
         << endl;

    return 0;
}
