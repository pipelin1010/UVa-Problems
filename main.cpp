/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: invitado
 *
 * Created on 19 de abril de 2017, 07:06 PM
 */

#include <cstdio>
#include <vector>
#include <string.h>
#include <string>
#include <utility>
#include <unordered_map>

using namespace std;
typedef pair<string,string> ss;
typedef vector<int> vi;
typedef vector<ss> vss;

int tc, n, d;
char x[25], y[25];
unordered_map <string,bool> a;
unordered_map <string,int> b;
vss names;

class UnionFind {                                              
private:
  vi p ,rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 1; i <= N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(int argc, char** argv) {
    //freopen("inp","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d", &tc);
    while(tc--){
        d = 0;
        names.clear();
        a.clear(); b.clear();
        scanf("%d", &n);
        names.resize(n);
        for (int i = 0, j = 0; i < n; i++){
            scanf("%s%s", x, y);
            string aux (x), aux2 (y);
            names[i] = ss(aux,aux2);
            
            if (!a[aux]){
                b[aux] = j;
                d++;
                a[aux] = true;
                j++;
            }
            
            if (!a[aux2]){
                b[aux2] = j;
                d++;
                a[aux2] = true;
                j++;
            }
        }
        
        UnionFind UF(d+1);
        for (int i = 0; i < n; i++){
            UF.unionSet(b[names[i].first], b[names[i].second]);
            printf("%d\n",UF.sizeOfSet(b[names[i].first]));
        }
    }
    return 0;
}

