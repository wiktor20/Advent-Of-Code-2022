#include <fstream>
#include <iostream>

int main()
{
    int sum = 0;
    std::string gameresult;
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
        inf >> strInput;
        gameresult = strInput;
        inf >> strInput;
        gameresult.append(strInput);

        // Probably some better way to do this. Suprisingly made part 2 easy
        if(gameresult == "AX")
            sum += 3;
        if(gameresult == "BX")
            sum += 1;
        if(gameresult == "CX")
            sum += 2;
        if(gameresult == "AY")
            sum += 4;
        if(gameresult == "BY")
            sum += 5;
        if(gameresult == "CY")
            sum += 6;
        if(gameresult == "AZ")
            sum += 8;
        if(gameresult == "BZ")
            sum += 9;
        if(gameresult == "CZ")
            sum += 7;
    }

    std::cout << sum;
    return 0;
}
