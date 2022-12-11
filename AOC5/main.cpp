#include <fstream>
#include <iostream>
#include <map>
#include <stack>

int main()
{
    int sum = 0;
    std::stack<char> stack[9];
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
        if(strInput.empty()){
            break;
            }
        for(int i = 0; i < strInput.size(); i++)
        {
            char temp = strInput[i];
            // std::cout << temp << std::endl;
            if(i % 4 == 1 && temp > 64) // 64 to handle 
                stack[i/4].push(temp);
        }
    }

    for(int i = 0; i < 9; i++){
        std::stack<char> temp;
        int size = stack[i].size();
        for(int j = 0; j < size; j++){
            temp.push(stack[i].top());
            stack[i].pop();
        }
        // std::cout << temp.top() << std::endl;
        temp.swap(stack[i]);
    }


 while (inf)
    {
        int quantity, fromstack, tostack;
        std::string strInput;
        inf >> strInput;
        inf >> strInput;
        if(strInput.empty()){
            break;
            }
        quantity = stoi(strInput);
        inf >> strInput;
        inf >> strInput;
        fromstack = stoi(strInput) - 1;
        inf >> strInput;
        inf >> strInput;
        tostack = stoi(strInput) - 1;

        for(int i = 0; i < quantity; i++){
            std::cout << quantity << fromstack << tostack << std::endl;
            char temp = stack[fromstack].top();
            stack[tostack].push(temp);
            stack[fromstack].pop();
        }
    }



    for(int i = 0; i < 9; i++){
        int size = stack[i].size();
        for(int j = 0; j < size; j++){
            std::cout << stack[i].top();
            stack[i].pop();
        }
        std::cout << std::endl;
    }

    return 0;
}
