#include<iostream>
#include<vector>

std::vector<std::string> &read_table(std::string);
void read_table(std::string , std::vector<std::string> &);

int main(){
    auto customers = read_table("customers");
    return 0;
}


std::vector<std::string> &read_table(std::string table){
    std::vector<std::string> result;
    return result;
}

void read_table(std::string table, std::vector<std::string> &result){
}






