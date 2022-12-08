#include <fstream>
#include <iostream>
#include <map>

int main()
{
    int sum = 0;
    std::ifstream inf{"input.txt"};
    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        std::cerr << "txt could not be opened for reading\n";
        return 1;
    }

    while (inf)
    {
        char c;
        std::string first, second, third;
        std::getline(inf, first);
        std::getline(inf, second);
        std::getline(inf, third);
        //Expecting that we get an input file with lines divisible by 3
        if (first.empty())
            break;

        for (int i = 0; i < first.size(); i++)
        {
            for (int j = 0; j < second.size(); j++)
            {
                if (first[i] == second[j])
                {
                    for (int k = 0; k < third.size(); k++)
                    {
                        if (second[j] == third[k])
                        {
                            c = second[j];
                            goto endloop;
                        }
                    }
                }
            }
        }

endloop:
        if (c < 91)
            c -= 38;
        else
            c -= 96;

        sum += c;
    }

    std::cout << sum;
    return 0;
}
