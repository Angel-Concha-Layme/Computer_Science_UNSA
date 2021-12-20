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
#include <complex>

// N = la cantidad de personas en la cola
// T = el tiempo en minutos hasta que se cierre el banco
// ci = la cantidad de efectivo en coronas suecas que tengo
// ti = tiempo de la persona

struct Person{
    int money;
    int time;
    
    Person(int m, int w){
        money = m;
        time = w;
    }
};

bool compareMoney(const Person &, const Person &);
void queuePerson(std::vector<int> &, Person);

int main(){    
    int N, T, ci, ti;
    int sum = 0;
    int i = 0;
	
    std::cin >> N >> T;
    std::vector<int> bQueue(T);
    std::vector<Person> money;
    
    for(int i = 0; i < N; i++){
        std::cin >> ci >> ti;
        Person c(ci, ti);
		money.push_back(c); 
    }
    
    sort(money.begin(), money.end(), compareMoney);
    
    while(i < money.size()){ 
        queuePerson(bQueue, money[i]); 
        i++;
    }
    
    for(int i = 0; i < bQueue.size(); i++){
        sum += bQueue[i];
    }
    
    std::cout << sum;
    return 0; 
}

bool compareMoney(const Person &a, const Person &b){
    return a.money >= b.money;
}


void queuePerson(std::vector<int> &v, Person c){ 
    int time_ = c.time;
    while(time_ >= 0){
        if(v[time_] == 0){ 
            v[time_] = c.money; 
            return;
        }  
        time_--;
    }
}