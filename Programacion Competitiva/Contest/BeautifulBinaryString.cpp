#include <bits/stdc++.h>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
int beautifulBinaryString(std::string b);

int main(){
    std::ofstream fout(getenv("OUTPUT_PATH"));
    std::string n_temp;
    std::getline(std::cin, n_temp);
    int n = std::stoi(ltrim(rtrim(n_temp)));
    std::string b;
    std::getline(std::cin, b);
    int result = beautifulBinaryString(b);
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

int beautifulBinaryString(std::string b) {
    int result = 0;
    for (int i = 0; i < b.size(); ++i){
        if (b.substr(i, 3) == "010"){
            result++;
            i += 2; 
        }
    }    
    std::cout << result << std::endl;
    return result;
}