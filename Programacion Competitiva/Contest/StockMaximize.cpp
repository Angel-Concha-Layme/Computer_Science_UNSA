#include <iostream>
#include <vector>
#include <stack>

 
long long stockmax(std::vector<int> &input);

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        std::cin >> N;
        std::vector<int> input(N, 0);
        for (int j = 0; j < N; ++j)
            std::cin >> input[j];
        std::cout << stockmax(input) << std::endl;
    }
}


long long stockmax(std::vector<int> &input) {
    if (input.size() < 1) return -1; // invalid input
    std::stack<int> chk; 
    int actual = input.back(); 

    chk.push(input.size() - 1);
    for (int i = input.size() - 2; i >= 0;) {
        while (i >= 0 && input[i] < actual) --i;
        if (i >= 0) {
            chk.push(i);
            actual = input[i];
            --i;
        }
    }

    long long tmp = 0, max = 0, ctr = 0; 
    for (int i = 0; i < input.size(); ++i) {
        if (i < chk.top()) {
            tmp += input[i];
            ++ctr;
        } else {
            max += input[i] * ctr - tmp;
            tmp = 0;
            ctr = 0;
            chk.pop();
        }
    }
    return max;
}