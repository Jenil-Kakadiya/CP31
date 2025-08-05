#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n>>k;
        string s;
        cin >> s;

        int l = s.length();
        if(n == 0 || k == 0 || k > n){
            cout << 0 << endl;
            continue;
        } 
        int currCount = 0;
        for(int i=0; i<k; i++){
            if(s[i] == 'W') currCount++;
        }

        int maxCount = currCount;
        
        for(int i=0; i <= n-k-1 ; i++){
            if(s[i] == 'W') currCount--;
            if(s[i+k] == 'W') currCount++;
            maxCount = min(maxCount, currCount);
        }
        // cout << endl;
        cout << maxCount << endl;
    }
    return 0;
}


// #include <iostream>
// #include <string> // Required for string manipulation
// #include <algorithm> // Required for min/max functions

// using namespace std;

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n, k;
//         cin >> n >> k;
//         string s;
//         cin >> s;

//         // Handle edge cases
//         if (n == 0 || k == 0 || k > n) {
//             cout << 0 << endl;
//             continue;
//         }

//         // Calculate initial window count
//         int currCount = 0;
//         for(int p = 0; p < k; p++){
//             if(s[p] == 'W') currCount++;
//         }
//         int minCount = currCount;

//         // Slide the window
//         for(int i = 1; i <= n - k; i++){ // loop until n - k
//             if(s[i-1] == 'W') currCount--; // Character leaving the window
//             if(s[i + k - 1] == 'W') currCount++; // Character entering the window
//             minCount = min(minCount, currCount);
//         }
//         cout << minCount << endl;
//     }
//     return 0;
// }
