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


#define maxKind 26 //maximo numero de tipos de letras

struct Node{
    Node *fail; //puntero al nodo que representa el fallback
    Node *next[maxKind]; //punteros a los nodos que representan las letras
    int cnt; //numero de veces que aparece la palabra
    int who; //numero de la palabra
    Node() {
        fail = NULL; 
        cnt = 0; //inicializamos el contador de palabras
        who = 0; //inicializamos el numero de la palabra
        memset(next, 0, sizeof(next));
    }
};

void trie_build(const char*, Node *, int);
void build_AC_automation(Node *);
void free_AC_automation(Node *);
void query(const char*, Node *, int[]);

char buf[1048576], pattern[256][256]; //buf es el texto, pattern es un arreglo de cadenas

int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        Node *root = new Node();
        for(int i = 0; i < n; i++) {
        	scanf("%s", pattern[i]);
            trie_build(pattern[i], root, i+1);
        }
        
        build_AC_automation(root);
        
        scanf("%s", buf);
        int cnt[256] = {};
        query(buf, root, cnt);
        free_AC_automation(root);
        int maxMatch = cnt[0];
        for(int i = 0; i < n; i++) {
        	maxMatch = std::max(maxMatch, cnt[i+1]);
        }
        printf("%d\n", maxMatch);
        for(int i = 0; i < n; i++) {
        	if(cnt[i+1] == maxMatch)
        		printf("%s\n", pattern[i]);
        }
    }
    return 0;
}



void trie_build(const char* str, Node *root, int who) { 
    Node *p = root;
    int i = 0, idx;
    while(str[i]) {
        if(str[i] >= 'a' && str[i] <= 'z')
            idx = str[i] - 'a';
        if(p->next[idx] == NULL) {
            p->next[idx] = new Node();
        }
        p = p->next[idx];
        i++;
    }
    p->cnt++;
    p->who = who;
}
void build_AC_automation(Node *root) { //
    root->fail = NULL;
    std::queue<Node*> Q; 
    Q.push(root); 
    Node *tn, *p; //tn es el nodo actual, p es el nodo padre
    while(!Q.empty()) {
        tn = Q.front();
        Q.pop();
        for(int i = 0; i < maxKind; i++) {
            if(tn->next[i] == NULL) //si no hay nodo que represente la letra
                continue;
            Q.push(tn->next[i]);
            p = tn->fail;
            while(p != NULL && p->next[i] == NULL)
                p = p->fail;
            if(p == NULL)
                tn->next[i]->fail = root;
            else
                tn->next[i]->fail = p->next[i];
        }
    }
}
void free_AC_automation(Node *root) {
    std::queue<Node*> Q;
    Q.push(root);
    Node *tn, *p;
    while(!Q.empty()) {
        tn = Q.front();
        Q.pop();
        for(int i = 0; i < maxKind; i++) {
            if(tn->next[i] != NULL) {
                Q.push(tn->next[i]);
            }
        }
        free(tn);
    }
}

void query(const char* str, Node *root, int cnt[]) { //cnt es un arreglo de enteros que representa el numero de palabras que aparecen en la cadena
    int i = 0, idx;
    Node *tn, *p;
    tn = root;
    while(str[i]) {
        if(str[i] >= 'a' && str[i] <= 'z')
            idx = str[i] - 'a';
        while(tn->next[idx] == NULL && tn != root)
            tn = tn->fail;
        tn = tn->next[idx];
        tn = (tn == NULL) ? root : tn;
        p = tn;
        while(p != root) {
        	if(p->cnt > 0)
            	cnt[p->who]++; //si la palabra aparece en la cadena, sumamos 1 al contador
            p = p->fail;
        }
        i++;
    }
}