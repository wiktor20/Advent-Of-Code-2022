#include <fstream>
#include <iostream>
#include <map>



int main()
{
    int sum = 0;
    std::string gameresult;
    std::ifstream inf{"input.txt"};
    std::map<std::string, int> my_map = {{ "AX", 3 },{ "BX", 1 },{ "CX", 2 },{ "AY", 4 },{ "BY", 5 },{ "CY", 6 },{ "AZ", 8 },{ "BZ", 9 },{ "CZ", 7 }};
    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        std::cerr << "txt could not be opened for reading\n";
        return 1;
    }

    while (inf)
    {
        //Okay I learned what a MAP is
        std::string strInput;
        inf >> strInput;
        gameresult = strInput;
        inf >> strInput;
        gameresult.append(strInput);
        sum += my_map[gameresult];
    }

    std::cout << sum;
    return 0;
}
