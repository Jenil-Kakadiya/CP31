#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, r, b;
        cin >> n >> r >> b;

        int maxRs = r / (b+1);
        int remainingRs = r %(b+1);

        // cout << maxRs << remainingRs << endl;

        for(int i=1; i <= (b+1); i++){
            for(int j=1; j <= maxRs; j++) cout << "R";
            if(remainingRs){
                cout<< 'R';
                remainingRs--;
            }
            if( i != b+1) cout << "B";
        }
        cout << endl;
    }
    return 0;
}