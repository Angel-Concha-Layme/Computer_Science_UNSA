#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <time.h>
#include <fstream>
#include <limits>
#include <iomanip>

int evalRPN(std::vector<std::string> &);

int main() {
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    std::cout << evalRPN(tokens) << std::endl;
    return 0;
}

int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> numbers;
    for (int i = 0; i < tokens.size(); i++) {
        std::string s = tokens[i];
        if (isdigit(s[0]) || s.size() > 1) {
             numbers.push(stoi(s));
            continue;
        }
        int number_1 = numbers.top();
        numbers.pop();
        int number_2 = numbers.top();
        numbers.pop();
        if (s == "+") {
            numbers.push(number_1+number_2);
        } else if (s == "-") {
             numbers.push(number_2-number_1);
        } else if (s == "*") {
             numbers.push(number_1*number_2);
        } else {
            numbers.push(number_2/number_1);
        }
    }
    return numbers.top();
}