#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // for(auto& x : a) cout << x << " ";
        for (int i = 0; i < n; i++)
            b[i] = {(a[i] - 1) % k, i + 1};
        // sort(b.begin(), b.end());
        sort(b.begin(), b.end(), [](const pair<int, int> &p1, const pair<int, int> &p2)
             {
            if(p1.first != p2.first) return p1.first > p2.first;
            return p1.second < p2.second; });
        // for(auto& it : b) cout << it.first << " " << it.second << endl;
        for (auto &it : b)
            cout << it.second << " ";
        cout << endl;
    }
    return 0;
}