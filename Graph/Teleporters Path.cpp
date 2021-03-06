#include <bits/stdc++.h>
using namespace std;

void open_file(){
    #ifdef INOUT
        freopen("OB.inp", "r", stdin);
        freopen("OB.out", "w", stdout);
    #endif
}

typedef pair<int, int> ii;
typedef pair<long long, int> i2;
#define X first
#define Y second 
const int maxN = 2e5 + 5;
vector<ii> a[maxN];
int indeg[maxN], outdeg[maxN], d[maxN];
vector<int> st;
int h[maxN];

void DFS(int u){
    for(int &i = h[u]; i < a[u].size(); i++){
        int v = a[u][i].X;
        int index = a[u][i].Y;
        if (d[index] == 0) {
            d[index] = 1;
            DFS(v);
        }
    }
    st.push_back(u);
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back({y, i});
        // a[y].push_back({x, i});
        outdeg[x]++;
        indeg[y]++;
    }

    for(int i = 2; i <= n - 1; i++)   
        if (indeg[i] != outdeg[i]){
            cout << "IMPOSSIBLE";
            return;
        }


    if (!(indeg[1] + 1 == outdeg[1] && indeg[n] == outdeg[n] + 1)){
        cout << "IMPOSSIBLE";
        return;
    }
    
    DFS(1);
    if (st.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return;
    }
    reverse(st.begin(), st.end());
    for(int i = 0; i < st.size(); i++)
        cout << st[i] << ' ';
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}