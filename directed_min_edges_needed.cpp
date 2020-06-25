#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxn = 5005;
vector<int> adj[mxn];
bool vis[mxn];
bool reach[mxn];
int p = 0;

void dfs(int node){
    reach[node] = 1;
    for(int x : adj[node]){
        if(!reach[x]) dfs(x);
    }
}

void dfsx(int node){
    vis[node] = 1;
    p++;
    for(int x : adj[node]){
        if(!vis[x] && !reach[x]) dfsx(x);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s; cin>>n>>m>>s;
    for(int i = 0, x, y; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
    }

    dfs(s);

    vector<pair<int, int>> res;
    for(int i = 1; i<=n; i++){
        if(!reach[i]){
            p = 0;
            for(int i = 1; i<=n; i++) vis[i] = false;
            dfsx(i);
            res.push_back({p, i});
        }
    }
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());

    int ans = 0;
    for(pair<int, int> q : res){
        if(!reach[q.second]){
            ans++;
            dfs(q.second);
        }
    }
    cout<<ans<<"\n";
    return 0;
}