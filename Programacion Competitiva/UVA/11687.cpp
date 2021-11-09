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

int main(){
	char number[1000000];
	while(scanf("%s", number) != EOF){
		if(number[0] == 'E'){
            return 0;
        }
		int previous = atoi(number);
		int digits = strlen(number);	
		int i = 1;
		while(digits != previous){
			previous = digits;
			digits = (int)log10((double)digits) + 1;	
			++i;
		}
		printf("%d\n", i);
	}
	return 0;
}
