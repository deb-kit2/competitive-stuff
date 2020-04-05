#include<bits/stdc++.h>
#define ll long long
#define loop(n) for(ll i = 0; i<n; i++)
#define sort(a) sort(a.begin(), a.end())
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s, t; cin>>s>>t;
    int n = s.size(), m = t.size();
    int lcs[n+1][m+1];

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(i==0 || j==0) lcs[i][j] = 0;
            else if(s[i-1]==t[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    if(lcs[n][m]==0) return cout<<"\n", 0;

    string res = "";
    for(int i = n, j = m; i>0 && j>0;){
        if(lcs[i][j]!=lcs[i-1][j] && lcs[i][j]!=lcs[i][j-1]){
            res.push_back(s[i-1]);
            i--; j--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1]) i--;
        else j--;
    }

    reverse(res.begin(),res.end());
    cout<<res<<"\n";
    return 0;
}