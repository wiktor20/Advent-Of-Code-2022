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
        bool flag = false;
        std::string firsthalf, secondhalf;
        std::getline(inf, firsthalf);

        if (firsthalf.empty())
            break;

        int size = firsthalf.size() / 2;
        secondhalf.assign(firsthalf, size);
        firsthalf.assign(firsthalf, 0, size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (firsthalf[i] == secondhalf[j])
                {
                    c = firsthalf[i];
                    flag = true;
                    break;
                }
            }
            if (flag == true)
                break;
        }

        // std::cout << firsthalf << std::endl << secondhalf << std::endl << c << std::endl;

        if (c < 91)
        {
            c -= 38;
            sum += c;
        }
        else
        {
            c -= 96;
            sum += c;
        }
    }

    std::cout << sum;
    return 0;
}
