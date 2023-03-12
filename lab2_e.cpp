#В постфиксной записи(или обратной польской записи) операция записывается после двух операндов.

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

int main()
{
    map<char, function<int64_t(const int64_t&, const int64_t&)>> operations;// создаем контейнер
    operations['+'] = [](const int64_t& a, const int64_t& b) constexpr {return a + b;};
    operations['-'] = [](const int64_t& a, const int64_t& b) constexpr {return a - b;};
    operations['*'] = [](const int64_t& a, const int64_t& b) constexpr {return a * b;};
    string expression;
    vector<int64_t> stack_;     
    int64_t number = 0;
    bool flag = true;
    getline(cin, expression);   
    for (const auto& i : expression) {
        if (isdigit(i)) {  
            number *= 10;
            number += (i - '0');  //конвертация в строку 
            flag = true;           
        }
        else {
            if (i != ' ') {
                int64_t num2 = stack_.back();       
                stack_.pop_back();
                int64_t num1 = stack_.back();
                stack_.pop_back();             
                stack_.push_back(operations[i](num1, num2));    
                flag = false;           
            }
            else if(i == ' ' && flag) {
                stack_.push_back(number);
                number = 0;
            }               
        }
    }
    cout << stack_.back();         
    return 0;
}
