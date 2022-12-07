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

        // Probably some better way to do this
        if(gameresult == "AX")
            sum += 4;
        if(gameresult == "BX")
            sum += 1;
        if(gameresult == "CX")
            sum += 7;
        if(gameresult == "AY")
            sum += 8;
        if(gameresult == "BY")
            sum += 5;
        if(gameresult == "CY")
            sum += 2;
        if(gameresult == "AZ")
            sum += 3;
        if(gameresult == "BZ")
            sum += 9;
        if(gameresult == "CZ")
            sum += 6;
    }

    std::cout << sum;
    return 0;
}
