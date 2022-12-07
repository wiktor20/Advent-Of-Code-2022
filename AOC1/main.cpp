#include <fstream>
#include <iostream>

int main()
{
    int max = 0;
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
            if (tempsum > max)
                max = tempsum;
            tempsum = 0;
        }
    }

    std::cout << max;
    return 0;
}
