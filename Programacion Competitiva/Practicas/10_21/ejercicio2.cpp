#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> Is_there_a_loop_1(const std::vector<int>&);
std::vector<int> Is_there_a_loop_2(const std::vector<int>&);

void print_vector(const std::vector<int>&);


int main (){
    std::vector<int> IN_vector2={1,4,7,2,3,66,8,5,2,4,6,2,6,24,2,6,8,9,6,8,9,6,8,9,6,8,9,6,8,9,6,8,9};
    print_vector(Is_there_a_loop(IN_vector2));
}

std::vector<int> Is_there_a_loop (const std::vector<int> &IN_vector){
    std::vector<int> OUT_vector;

    for (int i = 0; i < IN_vector.size(); i++)
    {
        for (int j = IN_vector.size()-1; j > i; j--)
        {
            if(IN_vector[i] == IN_vector[j] && IN_vector[i+1] == IN_vector[j+1]){
                OUT_vector.push_back(IN_vector[j]);
                break;  
            }
        }            
    }
    std::sort( OUT_vector.begin(), OUT_vector.end() );
    OUT_vector.erase( unique( OUT_vector.begin(), OUT_vector.end() ), OUT_vector.end() );   
    return OUT_vector;
}
void print_vector(const std::vector<int> &IN_vector){
    for (auto i = 0; i < IN_vector.size()-1; i++){        
        std::cout<<IN_vector[i+1]<<" ";
    }    
    std::cout<<std::endl;
}