#include <bits/stdc++.h>
using namespace std;

void open_file(){
    #ifdef INOUT
        freopen("OB.inp", "r", stdin);
        freopen("OB.out", "w", stdout);
    #endif
}

typedef pair<int, int> ii;
#define X first
#define Y second 

const int maxN = 1e3 + 5;
const int h[] = {-1, 0, 1, 0, -1};
bool Free[maxN + 5][maxN + 5];
string s[maxN];

void BFS(int u, int v){
    queue<ii> que;
    que.push(ii(u, v));
    Free[u][v] = true;
    while (!que.empty()){
        u = que.front().X;
        v = que.front().Y;
        que.pop();
        for(int i = 0; i < 4; i++){
            int x = u + h[i];
            int y = v + h[i + 1];
            if (!Free[x][y] && s[x - 1][y - 1] == '.'){
                que.push(ii(x, y));
                Free[x][y] = true;
            }
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i <= n; i++){
        Free[i][0] = Free[i][m + 1] = true;
    }
    for(int i = 0; i <= m; i++){
        Free[0][i] = Free[n + 1][i] = true;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        if (s[i - 1][j - 1] == '.' && !Free[i][j]){
            cnt++;
            BFS(i, j);
        }
    cout << cnt;
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}