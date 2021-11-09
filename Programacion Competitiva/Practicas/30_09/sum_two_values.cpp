#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

std::ostream &operator<<(std::ostream &, const std::vector<int> &);
std::vector<int> twoSum(std::vector<int>&, int);

int main(){
    std::vector<int> prueba={1,2,7,9,11,15};
    int target=11;
    std::cout<<"[ "<<twoSum(prueba,target)<<"] positions"<<std::endl;
    return 0;
}

std::vector<int> twoSum(std::vector<int>& numbers, int target){
    int left = 0, right = numbers.size() - 1; // Indices al inicio y al final
    while(left < right){
        int sum = numbers[left] + numbers[right];
        if(sum < target)
            ++left;
        else if(sum > target)
            --right;
        else
            break;
    }
    return {left, right};
}

std::ostream &operator<<(std::ostream &os, const std::vector<int> &input){
    for (auto const &i: input) {
        os << i << " ";
    }
    return os;
}
