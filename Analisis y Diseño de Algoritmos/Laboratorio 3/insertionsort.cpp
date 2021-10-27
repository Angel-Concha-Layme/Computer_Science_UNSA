#include<vector>
#include<iostream>
#include<algorithm>
#include<stdlib.h>


//function to perform insertion sort
void insertionSort(std::vector<int> &vec){
   for (auto it = vec.begin(); it != vec.end(); it++){
      auto const insertion_point =
      std::upper_bound(vec.begin(), it, *it);
      std::rotate(insertion_point, it, it+1);
   }
}
//printing the array
void print(std::vector<int> vec){
   for( int x : vec)
   std::cout << x << " ";
   std::cout << '\n';
}
int main(){
   std::vector<int> arr = {2, 1, 5, 3, 7, 5, 4, 6};
   insertionSort(arr);
   print(arr);
   return 0;
}