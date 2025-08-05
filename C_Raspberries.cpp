#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

int solve(vector<int> arr, int n, int k)
{
    int gap = INT_MAX; // Initialize gap to a large value
    int evenGap = 0;
    if(k == 4){
        int evens=0;
        for (int i = 0; i < n; i++) {
            if(arr[i] == 4) return 0;
            if(arr[i] % 2 == 0) evens++;
        }
        if(evens >= 2) evenGap = 0;
        else if(evens == 1) evenGap = 1;
        // cout << evens << " " <<evenGap << endl;
        else evenGap = 2;
    }
    for (int i = 0; i < n; i++){
        if(arr[i] % k == 0) return 0;
        int current_gap = k - (arr[i] % k);
        if(current_gap < gap) gap = current_gap;
    }

    // cout << evenGap << " " << gap << endl;
    // cout << "Calculated gap: " << (k == 4 ? min(gap, evenGap) : gap) << endl; // Added label for clarity

    return (k == 4 ? min(gap, evenGap) : gap); // Return the calculated gap
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << solve(arr, n, k) << endl; 
    }
    return 0;
}

