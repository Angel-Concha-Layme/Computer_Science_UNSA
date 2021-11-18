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

void sorted_order_square(std::vector<int>);

int main(){
    std::vector<int> vector={-4, -3, 1, 2, 3};
    sorted_order_square(vector);
    
    return 0;
}

void sorted_order_square(std::vector<int> vector){
    std::multiset<int> squared_numbers;
    for(auto i = 0; i < vector.size(); i++)
        squared_numbers.insert(vector[i] * vector[i]);
    for( std::multiset<int>::iterator it = squared_numbers.begin(); it != squared_numbers.end(); it++)
        std::cout << *it << " ";
}