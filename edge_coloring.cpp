#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, x, y;
const int mxn = 1e5 + 5;
vector<pair<int, int>> adj[mxn];
int col[mxn];

void dfs(int node, int parent, int pcol){
    int c = 1;
    for(pair<int, int> x : adj[node]){
        if(x.first == parent) continue;
        if(c == pcol) c++;
        col[x.second] = c;
        dfs(x.first, node, c);
        c++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //good luck, kittu
    cin>>n;
    for(int i = 0; i<n-1; i++){
        cin>>x>>y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
    }

    int k = -1;
    for(int i = 1; i<=n; i++) k = max(k, int(adj[i].size()));
    cout<<k<<"\n";

    dfs(1, -5, -5);
    for(int i = 0; i<n-1; i++) cout<<col[i]<<"\n";
    return 0;
}
