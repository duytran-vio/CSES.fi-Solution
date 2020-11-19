#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;

const int maxN = 1e3 + 5;
const int h[] = {-1, 0, 1, 0, -1};
const int INF = 1e9;
const string DIRECT = "URDL";
string s[maxN];
int trace[maxN][maxN], n, m;
ii Start;

bool inside(int x, int y){
    return ((0 < x) && (x <= n) && (0 < y) && (y <= m));
}

void BFS(vector<ii> a, vector<vector<int>> &d){
    queue<ii> que;
    for(int i = 0; i < a.size(); i++){
        que.push(a[i]);
        d[a[i].X][a[i].Y] = 1;
    }

    while (!que.empty()){
        int u = que.front().X;
        int v = que.front().Y;
        que.pop();
        for(int i = 0; i < 4; i++){
            int x = u + h[i];
            int y = v + h[i + 1];
            if (inside(x, y) && d[x][y] == INF && s[x - 1][y - 1] != '#'){

                que.push(ii(x, y));
                d[x][y] = d[u][v] + 1;
                trace[x][y] = i;
            }
        }
    }

}

void Truyxuat(int u, int v, string &res){
    if (u == Start.X && v == Start.Y) return;
    int i = trace[u][v];
    int x = u - h[i];
    int y = v - h[i + 1];
    Truyxuat(x, y, res);
    res += DIRECT[i];
}

void Print(int u, int v){
    cout << "YES" << '\n';
    string res;
    Truyxuat(u, v, res);
    cout << res.size() << '\n' << res;
}

void solve(){

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    vector<ii> mons;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        if (s[i][j] == 'M')
            mons.push_back(ii(i + 1, j + 1));
        if (s[i][j] == 'A') Start = ii(i + 1, j + 1);
    }

    vector<vector<int>> dM(n + 1, vector<int>(m + 1, INF));
    vector<vector<int>> dA(n + 1, vector<int>(m + 1, INF));

//    cout << inside(1, 1);
    BFS(mons, dM);
    BFS({Start}, dA);
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= m; j++)
//            cout << dA[i][j] << ' ';
//        cout << '\n';
//    }
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= m; j++)
//            cout << dM[i][j] << ' ';
//        cout << '\n';
//    }
    for(int i = 1; i <= n; i++){
        if (dA[i][1] < dM[i][1]) {
            Print(i, 1);
            return;
        }
        if (dA[i][m] < dM[i][m]){
            Print(i, m);
            return;
        }
        if (i == 1 || i == n){
            for(int j = 1; j <= m; j++)
                if(dA[i][j] < dM[i][j]){
                    Print(i, j);
                    return;
                }
        }
    }
    cout << "NO";
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}


