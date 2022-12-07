#include <fstream>
#include <iostream>

int main()
{
    int first = 0;
    int second = 0;
    int third = 0;
    int tempsum = 0;
    std::ifstream inf{"input.txt"};

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        std::cerr << "txt could not be opened for reading\n";
        return 1;
    }

    while (inf)
    {
        std::string strInput;
        std::getline(inf, strInput);

        if (!strInput.empty())
            tempsum += std::stoi(strInput);

        else
        {
            if (tempsum >= first)
            {
                third = second;
                second = first;
                first = tempsum;
                tempsum = 0;
            }

            else if (tempsum >= second)
            {
                third = second;
                second = tempsum;
                tempsum = 0;
            }

            else if (tempsum >= third)
                third = tempsum;
            tempsum = 0;
        }
    }

    std::cout << first + second + third;
    return 0;
}
