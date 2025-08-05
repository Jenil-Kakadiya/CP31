#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        unordered_map<int, int> maxA, maxB;

        // Find max streaks in array a
        int count = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && a[i] == a[i - 1]) {
                count++;
            } else {
                maxA[a[i - 1]] = max(maxA[a[i - 1]], count);
                count = 1;
            }
        }

        // Find max streaks in array b
        count = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && b[i] == b[i - 1]) {
                count++;
            } else {
                maxB[b[i - 1]] = max(maxB[b[i - 1]], count);
                count = 1;
            }
        }

        int maxResult = 0;

        // Combine streaks from both arrays
        for (auto& p : maxA) {
            int val = p.first;
            int lenA = p.second;
            int lenB = maxB[val];
            maxResult = max(maxResult, lenA + lenB);
        }

        // Check values only in b
        for (auto& p : maxB) {
            int val = p.first;
            int lenB = p.second;
            if (maxA.find(val) == maxA.end()) {
                maxResult = max(maxResult, lenB);
            }
        }

        cout << maxResult << endl;
    }
    return 0;
}
