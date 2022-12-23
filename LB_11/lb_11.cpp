#include <iostream>
#include <fstream>

using namespace std;


// ������� ��� ��������� ����� ������� �����
// ���������:
// string str = "���� � ��, ���������, ���������� ������, ��� �������� ����"
// cutSrt(str, 0, 4) => ����
// cutSrt(str, 1, 3) => ��
// cutSrt(str, 0, 10) => ���� � ��,
string cutStr(string str, int x, int y)
{
    string row = "";

    for(int i = x; i < y; i++)
    {
        row += str[i];
    }

    return row;
}


// ������� ��� ��������� ��� � ����
int coutWords(string str, string word)
{
    int count = 0;

    for(int i = 0; i <= (int)(str.length() - word.length()); i++)
    {
        // ���� 4 ������� ��������� ������ �����, �� ������� ��������,
        // ���� ������� �� 1 ������, � ���������� ������� 4
        if(cutStr(str, i, i + word.length()) == word)
        {
            count++;
        }
    }

    return count;
}

// ������� ��� ��������� ������ ������ � ����
string getTextFormFile(string path)
{
    ifstream input(path);
    string line = "";
    string text = "";

    // �������� �� ���� ��������
    if(!input.is_open())
    {
        cout << "FILE IS NOT OPEN" << endl;
        return "";
    }

    // ������ ������ ����� � ���� �� ���� ����.
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
                "����"
            )
         << endl;

    return 0;
}
