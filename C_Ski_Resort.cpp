#include <iostream>
#include <vector>
using namespace std;
#define int long long

long long factorial_recursive(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial_recursive(n - 1);
    }
}

int solve(vector<int> a, int n, int k, int q){
    vector<int> ans;
    int count = 0;
    for (int i = 0; i < n; i++){
        if (a[i] <= q)
            count++;
        else{
            if (count > 0 && count >= k){
                int num_subarrays = (count - k + 1) * (count - k + 2) / 2; // sum of arithmetic progression
                ans.push_back(num_subarrays);
            }
            count = 0;
        }
    }
    if (count > 0 && count >= k){

        int num_subarrays = (count - k + 1) * (count - k + 2) / 2; // sum of arithmetic progression
        ans.push_back(num_subarrays);
    }

    if (!ans.size()){
        return 0;
    }

    int sum = 0;
    for (int x : ans)
    {
        sum += x; // Each x now represents the number of valid subarrays
    }
    return sum;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(a, n, k, q) << endl;
    }
    return 0;
}
