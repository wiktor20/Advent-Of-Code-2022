#include <fstream>
#include <iostream>
#include <map>

int main()
{
    bool a = false;
    bool b = false;
    bool c = false;
    std::ifstream inf{"input.txt"};
    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        std::cerr << "txt could not be opened for reading\n";
        return 1;
    }
    std::string test;
    std::string strInput;
    getline(inf, strInput);
    int i = 0;
    int temp = 0;
    while (1)
    {
        temp = 0;
        test.assign(strInput, 0 + i, 4 + i);
        std::cout << "First:" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            std::cout << test[0] << test[i + 1];
            if (test[0] != test[i + 1]){
                std::cout << "+1";
                temp++;
            }
            if (temp == 3)
                a = true;
            std::cout << "temp: " << temp; 
            std::cout <<  std::endl;
            
        }
        temp = 0;
        std::cout << "Second:" << std::endl;
        for (int i = 0; i < 2; i++)
        {

            std::cout << test[1] << test[i + 2];
            if (test[1] != test[i + 2]){
                std::cout << "+1";
                temp++;
            }
            if (temp == 2)
                b = true;
            std::cout <<  std::endl;
        }
        if (test[2] != test[3])
        {
            c = true;
        }
        // std::cout << test;
        std::cout << a << b << c << std::endl;
        if (a && b && c)
            break;
        i++;
        a = false;
        b = false;
        c = false;
    }
    std::cout << i + 4;
    return 0;
}
