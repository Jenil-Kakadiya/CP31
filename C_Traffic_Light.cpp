#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        char c;
        string s;
        cin >> n >> c;
        cin >> s;
        string copy = s+s;
        int maxDiff = 0;
        int lastG = -1;
        for(int i=2*n-1; i >-1; i--){
            // cout << copy[i] << " ";
            if(copy[i] == c && lastG == -1) continue;
            if(copy[i] == 'g') lastG = i;
            if(lastG != -1 && copy[i] == c) maxDiff = max(maxDiff, lastG-i);
        }

        cout << maxDiff << endl; 
    }
    return 0;
}