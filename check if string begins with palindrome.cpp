#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

const int mxn = 2e6 + 5;
int pref[mxn];

string takbir(string a){
    string x = a;
    reverse(x.begin(), x.end());
    x = a + "%" + x;    //<string> % <reverse string>

    int len = 0, n = x.size();
    for(int i = 1; i<n; i++){
        while(len && x[i]!=x[len]) len = pref[len-1];
        if(x[i]==x[len]) len++;
        pref[i] = len;
    }
    return a.substr(0, len);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //good luck kittu!
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();

        int i = 0;
        for(; i<n/2; i++) if(s[i]!=s[n-1-i]) break;
        if(i==n/2){
            cout<<s<<"\n";
            continue;
        }

        string t = s.substr(0, i);
        cout<<t;

        string x = s.substr(i, n-2*i);
        string p = takbir(x);
        reverse(x.begin(), x.end());
        string q = takbir(x);

        if(p.size() > q.size()) cout<<p;
        else cout<<q;

        reverse(t.begin(), t.end());
        cout<<t<<"\n";
    }
    return 0;
}