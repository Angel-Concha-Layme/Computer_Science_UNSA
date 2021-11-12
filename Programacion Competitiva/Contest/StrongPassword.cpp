#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
int minimumNumber(int n, string password);

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}



int minimumNumber(int n, string password) {
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";

    bool isNum,isLow,isUpp,isSpecial;
    isNum = false;
    isLow = false;
    isUpp = false;
    isSpecial = false;
    int cnt = 4;

    int pass = 6 - password.size();
    
    for (int i = 0; i < n; i++){
        size_t foundN = numbers.find(password[i]);
        size_t foundL = lower_case.find(password[i]);
        size_t foundU = upper_case.find(password[i]);
        size_t foundS = special_characters.find(password[i]);
        
        if (foundN != -1 && isNum == false){
            isNum = true;
            cnt--;
        }else if (foundL != -1 && isLow == false){
            isLow = true;
            cnt--;
        }else if (foundU != -1 && isUpp == false){
            isUpp = true;
            cnt--;
        }else if (foundS != -1 && isSpecial == false){
            isSpecial = true;
            cnt--;
        }
    }
    return max(pass,cnt);

}