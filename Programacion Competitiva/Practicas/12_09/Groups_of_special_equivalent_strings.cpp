#include <vector>
#include <list>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>


class Solution {
public:
    int numSpecialEquivGroups(std::vector<std::string>& A) {
        std::unordered_set<std::string> set;

        for (const std::string& s : A) {
            std::string even;
            std::string odd;
                for (int i = 0; i < s.length(); ++i)
                    if (i % 2 == 0)
                        even += s[i];
                    else
                        odd += s[i];
            sort(begin(even), end(even));
            sort(begin(odd), end(odd));
            set.insert(even + odd);
        }
    return set.size();
  }
};