#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        // -1 4 -1 0 5 -4
        int maxSum = INT_MIN;
        int currSum = 0;
        int i=0, j=0;
        while(j < n){
            if(currSum < 0){
                currSum = 0;
                i=j;
            }
            if(i<j){
                if((abs(a[j])+ abs(a[j-1])) % 2 == 1){
                    currSum += a[j];
                }else{
                    currSum = a[j];
                    i=j;
                }
            }else{
                currSum = a[j];
            }
            maxSum = max(maxSum, currSum);
            j++;
        }
        cout << maxSum << endl;
    }
    return 0;
}