#include <fstream>
#include <iostream>

int function(int currentchar, std::string test, int size)
{
    if (currentchar != 0)
    {
        if (function(currentchar - 1, test, size) == false)
        {
            return false;
        }
        for (int i = 0; i < currentchar; i++)
        {
            if (test[size - currentchar] == test[size - currentchar + i + 1])
            {
                return false;
            }
        }
        return true;
    }
    return true;
}


int main()
{
    std::ifstream inf{"input.txt"};
    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        std::cerr << "txt could not be opened for reading\n";
        return 1;
    }
    int i = 0;
    int size = 14;
    std::string strInput, test;
    getline(inf, strInput);

    while (1)
    {
        test.assign(strInput, i + 0, size);
        if (test.size() < size)
            break;
        if (function(size - 1, test, size - 1) == true)
            break;
        i++;
    }
    std::cout << i + size;
    return 0;
}
