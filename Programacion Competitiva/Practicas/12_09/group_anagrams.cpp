#include <iostream>
#include <unordered_map>
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


std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    for (int i = 0; i < strs.size(); i++) {
        std::string temp = strs[i];
        std::sort(temp.begin(), temp.end());
        map[temp].push_back(strs[i]);
    }
    std::vector<std::vector<std::string>> result;
    for (auto iterator = map.begin(); iterator != map.end(); iterator++) {
        result.push_back(iterator->second);
    }
    return result;
}


int main(){
    std::vector<std::string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    std::vector<std::vector<std::string>> arr = groupAnagrams(strs);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}