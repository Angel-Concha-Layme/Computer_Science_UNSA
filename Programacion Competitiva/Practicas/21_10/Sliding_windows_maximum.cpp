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

std::vector<int> maximum_sum(std::vector<int>&, int);

int main(){
    std::vector<int> nums = { 1,3,-1,-3,5,3,6,7};
    int k;
    std::cin >> k;
    std::cout<< "ok";
    auto v = maximum_sum( nums, k);
    for (auto i : v)
        std::cout << i << " ";

    return 0;
}

std::vector<int> maximum_sum(std::vector<int>& nums, int k){
    std::deque<int> doble_ended_queue;
    std::vector<int> maximums;

    for (int p = 0; p < nums.size(); ++p) {
        while (!doble_ended_queue.empty() && nums[p] >= nums[doble_ended_queue.back()]) {
            doble_ended_queue.pop_back();}
        doble_ended_queue.emplace_back(p);
        if (p >= k && !doble_ended_queue.empty() && doble_ended_queue.front() == p - k) 
            doble_ended_queue.pop_front();
        if (p >= k - 1)
            maximums.emplace_back(nums[doble_ended_queue.front()]);
    }
    return maximums;
}