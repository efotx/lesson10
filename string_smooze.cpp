#include "string_smooze.h"

//сжимание строки в новую строку
std::string smooze_copy(std::string s)
{
    std::string out;
    out.reserve(s.size());
    auto runner = s.begin();
    while (runner != s.end())
    {
        size_t counter = 1;
        out.push_back(*runner);
        ++runner;
        while (*runner == *(runner - 1))
        {
            ++counter;
            ++runner;
        }
        if (counter > 1)
        {
        out.append(std::to_string(counter));
        }
    }
    return out;
}

//сжимание в исходную строку
void smooze(std::string &s)
{
    auto runner = s.begin();
    auto src = s.begin();
    while (runner != s.end())
    {
        size_t counter = 1;
        *src++ = *runner++;
        while (*runner == *(runner - 1))
        {
            ++counter;
            ++runner;
        }
        if (counter > 1)
        {
            std::string strCounter = std::to_string(counter);
            auto counterIt = strCounter.begin();
            while (counterIt != strCounter.end())
            {
                *src++ = *counterIt++;
            }
        }
        //std::cout << s << std::endl;
    }
    s.resize(std::distance(s.begin(), src));
}
