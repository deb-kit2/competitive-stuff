#include<bits/stdc++.h>
#define ll long long
#define loop(n) for(ll i = 0; i<n; i++)
#define sort(a) sort(a.begin(), a.end())
using namespace std;

const int mxn = 55;
int n, m, result[mxn];
bool nx[mxn];
vector<int> adj[mxn];
void color(){
    memset(result, -1, sizeof(result));
    memset(nx, 0, sizeof(nx));
    result[1] = 1;

    for(int node = 2; node<=n; node++){
        //mark neighbor's colors as unavailable
        for(int x : adj[node]){
            if(result[x] != -1) nx[result[x]] = 1;
        }

        //find next available color asd assign to node
        for(int cr = 1; cr<=n; cr++){
            if(!nx[cr]){
                result[node] = cr;
                break;
            }
        }

        for(int x : adj[node]){
            if(result[x] != -1) nx[result[x]] = 0;
        }
    }
    
    for(int i = 1; i<=n; i++) cout<<result[i]<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x, y;
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    color();
    return 0;
}