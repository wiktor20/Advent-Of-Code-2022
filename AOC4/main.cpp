#include <fstream>
#include <iostream>
#include <string>
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
        int fl, fu, sl, su;
        std::string first, second;
        std::getline(inf, first);
        if (first.empty())
            break;
        int i = 0;

        for(i; i < first.size(); i++){
            if(first[i] == ','){
                break;
            }
        }

        second.assign(first,i+1);
        first.assign(first,0,i);

        for(int j = 0; j < first.size(); j++){
            if(first[j] == '-'){
                std::string temp;
                temp.assign(first,0,j);
                fl = stoi(temp);
                temp.assign(first,j+1);
                fu = stoi(temp);
                break;
            }
        }
        for(int j = 0; j < second.size(); j++){
            if(second[j] == '-'){
                std::string temp;
                temp.assign(second,0,j);
                sl = stoi(temp);
                temp.assign(second,j+1);
                su = stoi(temp);
                break;
            }
        }
        if((su >= fu && sl <= fu) || (su >= fl && sl <= fl) || (fu >= sl && fl <= sl) || (fu >= su && fl <= su))
            sum++;

        // std::cout << first << std::endl;
        // std::cout << fl << " " << fu << std::endl;
        // std::cout << second << std::endl;
        // std::cout << sl << " " << su << std::endl;  
    }

    std::cout << sum;
    return 0;
}
