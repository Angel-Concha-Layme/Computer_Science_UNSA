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

void Fill(int x, int y, const int size, const std::vector<std::string>& image, std::vector<std::vector<bool> >& checked);

int main(){
    int d;
    int imageCount(1);
    while (std::cin >> d && d){
        std::vector<std::string> image(d);
        for (int i = 0; i < d; ++i){
            std::cin >> image[i];
        }
        std::vector<std::vector<bool> > checked(d, std::vector<bool> (d, false));
        int count(0);
        for (int x = 0; x < d; ++x){
            for (int y = 0; y < d; ++y){
                if (image[x][y] == '1' && !checked[x][y]){
                    ++count;
                    checked[x][y] = true;
                    Fill(x, y, d, image, checked);
                }
            }
        }
        std::cout << "Image number " << imageCount << " contains " << count << " war eagles.\n";
        ++imageCount;
    }
}

void Fill(int x, int y, const int size, const std::vector<std::string>& image, std::vector<std::vector<bool> >& checked){
    for (int xc = x - 1; xc < x + 2; ++xc){
        for (int yc = y - 1; yc < y + 2; ++yc){
            if (yc >= 0 && yc < size && xc >= 0 && xc < size
                && image[xc][yc] == '1' && !checked[xc][yc]){
                checked[xc][yc] = true;
                Fill(xc, yc, size, image, checked);
            }
        }
    }
}