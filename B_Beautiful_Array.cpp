#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, b, sum;
        cin >> n >> k >> b >> sum;
        int minimum_sum = (b * k) ;
        int maximum_sum = (b * k)  + (n * (k-1));

        // cout << minimum_sum << maximum_sum << endl;
        if (sum < minimum_sum || sum > maximum_sum){
            cout << "-1" << endl;
        }else{
            vector<int> ans(n, 0);
            ans[0] = minimum_sum;
            sum -= minimum_sum;
            for (int i = 0; i < n; i++){ 
                int add = min(k - 1, sum);
                ans[i] += add;
                sum -= add;
            }
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
