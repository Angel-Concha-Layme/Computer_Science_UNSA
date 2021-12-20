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


typedef long long ll;

int main(){
    while(true){
        ll A, B, C;
        std::cin >> A >> B >> C;
        if(A==0 && B==0 && C==0)
            break;
        ll Asq=A*A, Bsq=B*B, Csq=C*C;
        if(Asq+Bsq==Csq || Asq+Csq==Bsq || Csq+Bsq==Asq)
            std::cout << "right\n";
        else
            std::cout << "wrong\n";
    }
    return 0;
}