#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        vector<pair<int, int>> boundaries(n);

        for(int i=0; i<n ;i++) boundaries[i] = {abs(a[i]-x),abs(a[i]+x)};

        int l = boundaries[0].first;
        int r = boundaries[0].second;
        int ans = 0;
        for(int i=0; i<n; i++){
            l = max(l, boundaries[i].first);
            r = min(r, boundaries[i].second);
            if(l > r){
                ans++;
                l = boundaries[i].first;
                r = boundaries[i].second;
            }
        }

        cout << ans << endl;
    }
    return 0;
}

