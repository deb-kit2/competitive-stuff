#include<bits/stdc++.h>
#define ll long long
#define loop(n) for(ll i = 0; i<n; i++)
#define sort(a) sort(a.begin(), a.end())
using namespace std;

string s;
int dp[105][105];
int takbir(){
    int n = s.size();
    if(!n) return 0;

    memset(dp,0, sizeof(dp));
    for(int i = 0; i<n; i++) dp[i][i] = 1;

    for(int length = 2; length<=n; length++){
        for(int i = 0; i<n-length+1; i++){
            int j = i+length-1;
            if(s[i]==s[j] && length == 2) dp[i][j] = 2;
            else if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    while(t--){
        cin>>s;
        cout<<takbir()<<"\n";
    }
    return 0;       
}