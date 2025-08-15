#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, k , a, b;
        cin >> n >> k >> a >> b;
        vector<int> x(n+1), y(n+1);
        for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];

        int minA = 1e17;
        int minB = 1e17;
        int ans = abs(x[a] - x[b]) + abs(y[a] - y[b]);
        for(int i=1; i<=k; i++){
            minA = min(minA, abs(x[i] - x[a]) + abs(y[i] - y[a]));
            minB = min(minB, abs(x[i] - x[b]) + abs(y[i] - y[b]));
            ans = min(ans, minA + minB);
        }
        cout << ans << endl;
    }
    return 0;
}