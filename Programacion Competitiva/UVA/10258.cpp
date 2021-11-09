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

struct board{
    int ID_contestant;
    int no_problem_solution;
    int problem_list[10];
    int penalty[10];
    int total_penalty_time;
    board(int c): ID_contestant(c), no_problem_solution(0){
        total_penalty_time = 0;
        for ( int i = 0; i < 10; ++i ){
            problem_list[i] = 0;
            penalty[i] = 0;
        }
    }
};

inline void init(int []);
void judge(board &, const int &, const int &, const char &);
bool operator<(const board &, const board &);
void calc_time(std::vector<board> &);


int main(){
    int T;
    std::string s;
    int ID_contestant, problem_list, total_penalty_time;
    char L;
    std::cin >> T;
    std::getline(std::cin, s);
    std::getline(std::cin, s);
    
    for(int t = 1; t <= T; ++t){
        int index[101];
        init(index);
        std::vector<board> v;

        while(std::getline(std::cin,s)){
            if (s == "") break;

            std::istringstream iss(s);
            iss >> ID_contestant >> problem_list >> total_penalty_time >> L;

            if(index[ID_contestant]==-1){
                v.push_back(*new board(ID_contestant));
                index[ID_contestant] = (int)v.size() - 1;
                judge(v[index[ID_contestant]], problem_list, total_penalty_time, L);
            }
            else{
                if(v[index[ID_contestant]].problem_list[problem_list] == 0 ){
                    judge(v[index[ID_contestant]], problem_list, total_penalty_time, L);
                }
            }
        }

        calc_time(v);
        sort(v.begin(), v.end());

        for (std::vector<board>::iterator it = v.begin(); it != v.end(); ++it ){
            std::cout << it->ID_contestant << ' ' << it->no_problem_solution << ' ' << it->total_penalty_time << std::endl;
        }
       
        if ( t < T ) {
            std::cout << '\n';
        }     
    }
    return 0;
}



inline void init(int index[]){
    for ( int i = 0; i < 101; ++i ){
        index[i] = -1;
    }
}

void judge(board &b, const int &problem_list, const int &total_penalty_time, const char &L){
    if ( L == 'C' ){
        ++b.no_problem_solution;
        b.problem_list[problem_list] = 1;
        b.penalty[problem_list] += total_penalty_time;
    }
    else if ( L == 'I' ){
        b.penalty[problem_list] += 20;
    }
}

bool operator<(const board &b1, const board &b2){
    if ( b1.no_problem_solution > b2.no_problem_solution )   return true;
    if ( b1.no_problem_solution == b2.no_problem_solution && b1.total_penalty_time < b2.total_penalty_time )    return true;
    if ( b1.no_problem_solution == b2.no_problem_solution && b1.total_penalty_time == b2.total_penalty_time && b1.ID_contestant < b2.ID_contestant )   return true;
    return false;
}

void calc_time(std::vector<board> &v){
    for (std::vector<board>::iterator it = v.begin(); it != v.end(); ++it ){
        for ( int i = 1; i < 10; ++i ){
            if ( it->problem_list[i] == 1 ) {
                it->total_penalty_time += it->penalty[i];
            }
        }
    }
}