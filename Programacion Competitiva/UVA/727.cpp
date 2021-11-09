#include <iostream>
#include <stack>
#include <cstring>



int Priority(char c) {
    switch (c) {
        case '(': return 1; break;
        case '+': return 2; break;
        case '-': return 2; break;
        case '*': return 3; break;
        case '/': return 3; break;
    }
}

main() {
    int kase, i;
    char s[10], c;
    std::cin >> kase; gets(s); gets(s);
    while (kase--) {
        std::stack <char> st;
        while (gets(s) && strlen(s)) {
            c = s[0];
            if (c==' ') break;
            if (c=='(') {
                st.push(c);
            }
            else if (c=='+' || c=='-' || c=='*' || c=='/') {
                while (!st.empty() && Priority(c) <= Priority(st.top())) {
                    printf("%c", st.top());
                    st.pop();
                }
                st.push(c);
            }
            else if (c==')') {
                while (st.top()!='(') {
                    printf("%c", st.top());
                    st.pop();
                }
                st.pop();
            }
            else printf("%c", c);
        }
        while (!st.empty()) {
            printf("%c", st.top()); st.pop();
        }
        std::cout << std::endl;
        if (kase) std::cout << std::endl;
    }
}