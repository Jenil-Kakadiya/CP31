#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> s(n);
        for(int i=0; i<n ;i++) cin >> s[i];

        int low = 1;
        int high = 1e9;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int sum = 0;
            for(int i=0; i<n; i++){
                sum += (s[i] + 2*mid) * (s[i] + 2*mid);
                if(sum > c) break;
            }
            if(sum <= c) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid-1;
        }
        cout << ans << endl;
    }
    return 0;
}