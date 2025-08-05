#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int func(int n, int x, vector<int> vec)
{
    if (n == 1){
        return max(vec[0], (x - vec[0]) * 2);
    }
    int minVolume = vec[0];
    for (int i = 1; i < n; i++){
        minVolume = max(minVolume, vec[i]-vec[i-1]);
    }
    minVolume = max(minVolume, (x - vec[n-1])*2);
    return minVolume;
}
int main()
{
    int t;
    int func(int n, int x, vector<int> vec);
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            arr.push_back(ele);
        }
        cout << func(n, x, arr) << endl;
    }
    return 0;
}
