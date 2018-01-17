#include <iostream>
#include <fstream>
#include <queue>
#include "string_smooze.h"

int main()
{
    std::ifstream fin("strings.txt");
    if (!fin.is_open()) return 1;
    std::queue<std::string> lines; //очередь для хранения k строк
    std::string str; //хранит считанную строку
    size_t k = 5; //количество строк
    //считывание строк
    while (std::getline(fin, str))
    {
        if (lines.size() == k)
        {
            lines.pop();
        }
        lines.push(str);
    }
    fin.close();
    //вывод строк
    std::ofstream out("out.txt");
    while (!lines.empty())
    {
        out << lines.front() << std::endl;
        lines.pop();
    }

    //проверка для сжимания строк
    std::string string = "aaaaaavvvvvvvfffsgggggggggggggggggggggg";
    std::string string2 = smooze_copy(string);
    smooze(string);
    out << string2 << std::endl;
    out << string << std::endl;
    return 0;
}
