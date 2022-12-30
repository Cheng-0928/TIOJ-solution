#include <bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define Cheng0928 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define size(a) signed(a.size())

using namespace std;


int gcd(int a, int b){
    a = abs(a);b = abs(b);
    if(a == 0) return b;

    return gcd(b%a, a);
}

void sol(){
    int n;
    while(cin >> n && n != 0){
        vector<pair<int,int>> a(n);
        for(int i = 0;i<n;i++){
            cin >> a[i].X >> a[i].Y;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            map<pair<int,int>, int> cnt;
            for(int j = 0;j<n;j++){
                if(i == j) continue;
                int x = a[j].X - a[i].X, y = a[j].Y - a[i].Y;
                int g = gcd(x,y);
                x/=g;y/=g;
                ans+=cnt[{-y,x}] + cnt[{y,-x}];
                cnt[{x,y}]++;
            }
        }

        cout << ans << '\n';

    }
}

signed main()
{
    Cheng0928
    /*int t;
    cin >> t;
    while(t--) */sol();
    return 0;
}
