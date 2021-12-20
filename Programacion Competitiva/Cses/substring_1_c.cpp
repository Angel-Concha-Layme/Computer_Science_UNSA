#include <bits/stdc++.h>

#define ll long long int

using namespace std;

struct SuffixAuto {
    struct State {
        int len, link;
        int next[26];
        State(int _len = 0, int _link = -1) : len(_len), link(_link) {
            memset(next, -1, sizeof(next));
        }
    };
 
    vector<State> states;
    int last;
 
    SuffixAuto() {}
 
    SuffixAuto(const string &S) {
        init(S);
    }
 
    inline int state(int len = 0, int link = -1) {
        states.emplace_back(len, link);
        return states.size() - 1;
    }
 
    void init(const string &S) {
        states.reserve(2 * S.size());
        last = state();
        for (char c : S)
            extend(c);
    }
 
    void extend(char _c) {
        int c = _c - 'a'; // change for different alphabet
        int cur = state(states[last].len + 1), P = last; 
        while (P != -1 && states[P].next[c] == -1) {
            states[P].next[c] = cur;
            P = states[P].link;
        }
        if (P == -1)
            states[cur].link = 0;
        else {
            int Q = states[P].next[c];
            if (states[P].len + 1 == states[Q].len)
                states[cur].link = Q;
            else {
                int C = state(states[P].len + 1, states[Q].link);
                copy(states[Q].next, states[Q].next + 26, states[C].next);
                while (P != -1 && states[P].next[c] == Q) {
                    states[P].next[c] = C;
                    P = states[P].link;
                }
                states[Q].link = states[cur].link = C;
            }
        }
        last = cur;
    }
};
 
string S;
SuffixAuto sa;
ll N, dp[200005];
 
ll dfs_dp(int u = 0) {
    if (dp[u] > 0)
        return dp[u];
    for (int i = 0; i < 26; i++)
        if (sa.states[u].next[i] != -1) 
            dp[u] += dfs_dp(sa.states[u].next[i]);
    return dp[u] += 1;
}
 
string p = "";
 
void dfs(int u = 0) {
    if (N == 0) 
        return;
    else 
        N--;
    for (int i = 0; i < 26; i++) {
        int v = sa.states[u].next[i];
        if (v != -1) {
            if (N >= dp[v]) {
                N -= dp[v];
            }
            else {
                p += (char)(i + 'a');
                return dfs(v);
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> S >> N;
    sa.init(S);
    dfs_dp();
    dfs();
    cout << p << '\n';
}