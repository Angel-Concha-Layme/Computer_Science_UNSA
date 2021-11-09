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

const int NONE = 0;
const int TO_BARB = 1;
const int TO_BUCK = 2;
const int REVERSE = 3;
const int MAX_N = 1024000;


struct Node{
    int numBucc;
    int action;
};

int N;
int buckCountMain[MAX_N];
Node allNodes[5 * MAX_N];   


int GenerateSegmentTree(int, int, int);
void SetUpGraph();
int GetNewBucCount(int, int, int, int);
void AddLazyUpdateAction(int, int);
void ApplyAndPushLazyUpdate(int, int, int);
int ApplyLazyChange(int, int, int, int, int, int);
int Query(int, int, int, int, int);

int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; ++t){
        SetUpGraph();
        int q;
        std::cin >> q;
        std::cout << "Case " << t << ":\n";
        int qCount = 1;
        while (q--){
            char cmd;
            int start, end;
            std::cin >> cmd >> start >> end;
            if (cmd == 'S'){
                std::cout << "Q" << qCount++ << ": " << Query(1, 0, N - 1, start, end ) << '\n';
            }
            else{
                int update;
                if (cmd == 'F')
                    update = TO_BUCK;
                else if (cmd == 'E')
                    update = TO_BARB;
                else if (cmd == 'I')
                    update = REVERSE;
                
                ApplyLazyChange(1, 0, N - 1, start, end, update);
            }
        }
    }
}


int GenerateSegmentTree(int index, int nodeLeft, int nodeRight){
    allNodes[index].action = NONE;
    if (nodeLeft == nodeRight)
        return allNodes[index].numBucc = buckCountMain[nodeLeft];
    int mid = (nodeLeft + nodeRight) / 2;
    allNodes[index].numBucc = GenerateSegmentTree(index * 2, nodeLeft, mid) + GenerateSegmentTree(index * 2 + 1, mid + 1, nodeRight);
    return allNodes[index].numBucc;
}

void SetUpGraph(){
    int numInputs;
    std::cin >> numInputs;
    std::vector<std::string> allInputs(numInputs);
    std::vector<int> numRepetitions(numInputs);
    N = 0;
    for (int i = 0; i < numInputs; ++i){
        std::cin >> numRepetitions[i] >> allInputs[i];
        N += numRepetitions[i] * allInputs[i].size();
    }
    int current = 0;
    for (int i = 0; i < numInputs; ++i){
        while ((numRepetitions[i])--){
            for (std::string::const_iterator iter = allInputs[i].begin(); iter != allInputs[i].end(); ++iter, ++current){
                if (*iter == '1')
                    buckCountMain[current] = 1;
                else
                    buckCountMain[current] = 0;
            }
        }
    }
    GenerateSegmentTree(1, 0, N - 1);
}

int GetNewBucCount(int origCount, int start, int end, int action){
    if (action == NONE)
        return origCount;
    else if (action == TO_BARB)
        return 0;
    else if (action == TO_BUCK)
        return end - start + 1;
    else if (action == REVERSE)
        return end - start + 1 - origCount;
    else
        while (true) {}
}

void AddLazyUpdateAction(int index, int action){
    if (action == REVERSE)
        allNodes[index].action = REVERSE - allNodes[index].action;
    else if (action != NONE) 
        allNodes[index].action = action;
}

void ApplyAndPushLazyUpdate(int index, int nodeStart, int nodeEnd){
    if (allNodes[index].action == NONE)
        return;
    allNodes[index].numBucc = GetNewBucCount(allNodes[index].numBucc, nodeStart, nodeEnd, allNodes[index].action);
    if (nodeStart != nodeEnd){
        int middle = (nodeStart + nodeEnd) / 2;
        AddLazyUpdateAction(index * 2, allNodes[index].action);
        AddLazyUpdateAction(index * 2 + 1, allNodes[index].action);
    }
    allNodes[index].action = NONE;
}


int ApplyLazyChange(int index, int nodeStart, int nodeEnd, int changeStart, int changeEnd, int action){  
    ApplyAndPushLazyUpdate(index, nodeStart, nodeEnd);
    if (nodeEnd < changeStart || nodeStart > changeEnd){
        return allNodes[index].numBucc;
    }
    if (nodeStart >= changeStart && nodeEnd <= changeEnd){
        AddLazyUpdateAction(index, action);
        ApplyAndPushLazyUpdate(index, nodeStart, nodeEnd);
        return allNodes[index].numBucc;
    }
    int middle = (nodeStart + nodeEnd) / 2;
    return allNodes[index].numBucc = ApplyLazyChange(index * 2, nodeStart, middle, changeStart, changeEnd, action) + ApplyLazyChange(index * 2 + 1, middle + 1, nodeEnd, changeStart, changeEnd, action);
}

int Query(int index, int nodeStart, int nodeEnd, int queryStart, int queryEnd){
    if (nodeEnd < queryStart || nodeStart > queryEnd)
        return 0;
    ApplyAndPushLazyUpdate(index, nodeStart, nodeEnd);
    if (nodeStart >= queryStart && nodeEnd <= queryEnd){
        return allNodes[index].numBucc;
    }
    int middle = (nodeStart + nodeEnd) / 2;
    int count = Query(index * 2, nodeStart, middle, queryStart, queryEnd) + Query(index * 2 + 1, middle + 1, nodeEnd, queryStart, queryEnd);
    return count;
}