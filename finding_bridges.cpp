#include<bits/stdc++.h>
#define ll long long
#define loop(n) for(ll i = 0; i<n; i++)
#define sort(a) sort(a.begin(), a.end())
using namespace std;

//change size as needed
vector<int> adj[101];
bool vis[101];
int low[101], in[101], timer;
void dfs(int node, int parent){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    for(int x : adj[node]){
        if(x==parent) continue;
        if(vis[x]) low[node] = min(low[node], in[x]);//back edge
        else{
            dfs(x, node);
            if(low[x] > in[node]) cout<<"Bridge between "<<node<<" "<<x<<"\n";
            low[node] = min(low[node], low[x]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y;
    cin>>n>>m;
    loop(m){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1); //dfs(root, any-num);
    return 0;
}