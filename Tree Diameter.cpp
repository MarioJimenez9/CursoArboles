#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define pii pair<int, int>
#define fore(i, a, b) for(int i = a, to = b; i < to; i++)

const int MAXN = 2e5 + 5;

vector<int> ad[MAXN];
bool vis[MAXN];

int ans, last;

void bfs(int u){
    queue<pii> q;
    memset(vis, 0, sizeof(vis));
    q.push({u, 0});
    vis[u] = 1;
    while(!q.empty()){
        int node = q.front().fst;
        int step = q.front().snd;
        q.pop();
        fore(i, 0, ad[node].size()){
            int v = ad[node][i];
            if(vis[v])continue;
            vis[v] = 1;
            q.push({v, step + 1});
        }
        last = node;
        ans = step;
    }
}

int main(){
    
    int n, u, v;
    cin>>n;
    fore(i, 0, n - 1){
        cin>>u>>v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    bfs(1);
    bfs(last);
    cout << ans << "\n";
    return 0;
}