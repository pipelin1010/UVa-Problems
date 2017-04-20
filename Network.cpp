t#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;

class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N+1, 1); numSets = N; rank.assign(N+1, 0);
    p.assign(N+1, 0); for (int i = 1; i <= N; i++) p[i] = i; }
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

int tc, q, i , j, s, u, x, y, c = 1;
char k;

int main(int argc, char** argv) {
    //freopen("inp","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d", &tc);
    while (tc--){
        if (c > 1) printf("\n");
        s = u = 0;
        scanf("%d", &q);
        getchar();
        UnionFind UF(q);
        while (k = getchar(), (int)k != 10 && k != EOF){
            scanf("%d%d", &x, &y);
            getchar();
            if (k == 'c') UF.unionSet(x,y);
            else if (UF.isSameSet(x,y)) s++;
            else u++;
        }
        c++;
        printf("%d,%d\n", s, u);
    }
    return 0;
}
