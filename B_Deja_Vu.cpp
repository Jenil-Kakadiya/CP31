#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<int> x(q);

        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<q; i++) cin >> x[i];

        int prev = 31;
        for(int i=0; i<q; i++){
            if(prev <= x[i]) continue;
            int val = pow(2, x[i]);
            for(int j=0; j<n; j++){
                if(a[j] % val == 0)
                    a[j] += (val/2);
            }
            prev = x[i];
        }

        for(int i=0; i<n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}