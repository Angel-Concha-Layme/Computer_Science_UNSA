#include <bits/stdc++.h>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

int pairs(int k, std::vector<int> arr) {
    std::sort (arr.begin(), arr.end());  

    size_t init = 0, end_ = 1;
    int cnt = 0;
    int diff;

    while (end_ < arr.size()) {
        diff = arr[end_] - arr[init];
        if (diff < k)end_++;
        else if (diff > k) init++;
        else if (diff == k){
            cnt++;
            end_++;
        }   
    }
    return cnt;

}

int main(){
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string first_multiple_input_temp;
    std::getline(std::cin, first_multiple_input_temp);

    std::vector<std::string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    std::string arr_temp_temp;
    std::getline(std::cin, arr_temp_temp);

    std::vector<std::string> arr_temp = split(rtrim(arr_temp_temp));

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

std::string ltrim(const std::string &str) {
    std::string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(std::ptr_fun<int, int>(isspace)))
    );

    return s;
}

std::string rtrim(const std::string &str) {
    std::string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(std::ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

std::vector<std::string> split(const std::string &str) {
    std::vector<std::string> tokens;

    std::string::size_type start = 0;
    std::string::size_type end = 0;

    while ((end = str.find(" ", start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
