#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void GenerateFunnyWords(const string* words, int size)
{
    cout << "Смешные слова:\n";

    for (int i = 0; i < size; i++)
    {
        if (words[i].length() >= 3)
        {
            string suffix = words[i].substr(words[i].length() - 3);

            for (int j = 0; j < size; j++)
            {
                if (j != i && words[j].length() >= 3 && words[j].substr(0, 3) == suffix)
                {
                    cout << words[i] << words[j].substr(3) << "\n";
                   
                }
            }
        }
    }
}

int main()
{
    setlocale(0, "");
    const string filename = "D:\\russian.txt";
    ifstream inFile(filename);

    if (!inFile.is_open())
    {
        cerr << "Не получилось открыть словарь.\n";
        return 1;
    }

    string* words = new string[10000];
    int size = 0;
    string word;

    while (inFile >> word)
    {
        words[size++] = word;
    }

    inFile.close();

    GenerateFunnyWords(words, size);

    delete[] words;
}
