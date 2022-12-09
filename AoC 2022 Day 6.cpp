#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <algorithm>

bool checkRepeat(std::string buffer)    //takes a sorted string
{
    for (int i = 0; i < buffer.length(); i++)
    {
        if (buffer[i] == buffer[i + 1])
            return true;                //there is a repeat character
    }
    return false;                       //no repeats
}

int countCharacters()
{
    std::ifstream file{ "input.txt" };
    std::string line{};
    int count{4};                       //includes the four processed characters of the marker
    std::getline(file, line);
    for (int i = 0; i < line.length()-4; i++)
    {
        std::string buffer{};
        buffer.append(line.begin() + i, line.begin() + i + 4);
        std::sort(buffer.begin(), buffer.end());
        if (checkRepeat(buffer))
            ++count;
        else
            return count;
    }
}

int countCharactersP2() //part two
{
    std::ifstream file{ "input.txt" };
    std::string line{};
    int count{ 14 };                       //includes the fourteen processed characters of the marker
    std::getline(file, line);
    for (int i = 0; i < line.length() - 14; i++)
    {
        std::string buffer{};
        buffer.append(line.begin() + i, line.begin() + i + 14);
        std::sort(buffer.begin(), buffer.end());
        if (checkRepeat(buffer))
            ++count;
        else
            return count;
    }
}


int main()
{
    std::cout << countCharactersP2();
    return 0;
}
