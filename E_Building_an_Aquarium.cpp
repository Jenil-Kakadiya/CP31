#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int maxH = 0;
        int maxSum = 0;

        for(int i=0; i<n; i++) cin >> a[i];
        
        for(int i=0; i<n; i++) maxH = max(maxH, a[i]);
        for(int i=0; i<n; i++) maxSum += maxH -a[i];

        int result = 1;
        if( x >= maxSum){
            cout << maxH + ((x-maxSum)/n) << endl;
            continue;
        }else{
            int low = 1;
            int high = maxH;
            while(low <= high){
                int mid = (low+high)/2;
                int sum = 0;
                for(int i=0; i<n; i++){
                    if(mid <= a[i]) continue;
                    sum += mid - a[i];
                }
                if(sum <= x){
                    result = mid;
                    low = mid+1;
                }
                else high = mid-1;
            }
        }
        cout << result << endl;
    }
    return 0;
}