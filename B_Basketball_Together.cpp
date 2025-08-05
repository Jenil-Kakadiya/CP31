#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define int long long 
using namespace std;

signed main(){
    int n, d;
    cin >> n >> d;
    vector<int> power(n);

    for(int i=0; i<n; i++) cin >> power[i];
    sort(power.begin(), power.end(), greater<int>());
    int count = 0;
    int remaining = n;
    for(int x : power){
        double result_double = static_cast<double>(d) / x; // Perform floating-point division
        int result_int = static_cast<int>(ceil(result_double));
        if(remaining <= 0) break;
        if( d%x != 0 ){
            if(remaining < result_int) break;
            remaining -= result_int;
            count++;

        }
        else{
            if(remaining < (result_int+1)) break;
            remaining = remaining - result_int -1; 
            count++;
        }

    }
    cout << count << endl;
    return 0;
}