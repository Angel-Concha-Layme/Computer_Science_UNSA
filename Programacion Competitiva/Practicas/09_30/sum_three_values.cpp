#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

std::ostream &operator<<(std::ostream &, const std::vector<int> &);
std::vector<int> threeSum(std::vector<int>& , int);

int main(){
    std::vector<int> prueba={1,2,4,5,12};
    int target=19;
    std::cout<<"[ "<<threeSum(prueba,target)<<"] positions"<<std::endl;
    return 0;
}


std::ostream &operator<<(std::ostream &os, const std::vector<int> &input){
    for (auto const &i: input) {
        os << i << " ";
    }
    return os;
}

std::vector<int> threeSum(std::vector<int>& numbers, int target){
    int left = 0, right = numbers.size() - 1; 
    for (int i = 0; i < numbers.size()- 2; i++) {    
        left = i + 1; 
        right = numbers.size() - 1; 
        while (left < right) {
            if (numbers[i] + numbers[left] + numbers[right] == target) {
                return {i, left, right};
            }
            else if (numbers[i] + numbers[left] + numbers[right] < target)
                left++;
            else 
                right--;
        }
    }        
}

