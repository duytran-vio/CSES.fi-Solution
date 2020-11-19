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
const string DIRECT = "URDL";
bool Free[maxN + 5][maxN + 5];
string s[maxN];
int trace[maxN][maxN];
ii Start, End;

int inv(int k){
    return (k + 2) % 4;
}

void Truyvet(int x, int y, string &res){
     //cout << x << " " << y << '\n';
    if (x == Start.X && y == Start.Y) return;
    int i = trace[x][y];
    int u = x + h[inv(i)];
    int v = y + h[inv(i) + 1];
    Truyvet(u, v, res);
    res += DIRECT[i];
}

void solve(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++){
            if (s[i][j] == 'A') Start = ii(i + 1, j + 1);
            if (s[i][j] == 'B') End = ii(i + 1, j + 1);
            trace[i][j] = -1;
        }
    }

    for(int i = 0; i <= n; i++)
        Free[i][0] = Free[i][m + 1] = true;
    for(int i = 0; i <= m; i++)
        Free[0][i] = Free[n + 1][i] = true;

    queue<ii> que;
    que.push(Start);
    Free[Start.X][Start.Y] = true;
    while (!que.empty()){
        if (Free[End.X][End.Y]) break;
        int u = que.front().X;
        int v = que.front().Y;
        que.pop();
        for(int i = 0; i < 4; i++){
            int x = u + h[i];
            int y = v + h[i + 1];
            if (!Free[x][y] && s[x - 1][y - 1] != '#'){
                que.push(ii(x, y));
                Free[x][y] = true;
                trace[x][y] = i;
            }
        }
    }
    
    if (Free[End.X][End.Y]){
        cout << "YES" << '\n';
        string res = "";
        Truyvet(End.X, End.Y, res);
        cout << res.length() << '\n';
        cout << res;
    }
    else 
        cout << "NO";
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}