#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int s)
{
    int count = 0;
    for(int i=0; i<n; i++){
        int vx, vy, x, y;
        cin >> vx >> vy >> x >> y;
        if(x == y){
            if((vx == -1 && vy == -1) || (vx == 1 && vy == 1)){
                count++;
            }
        }
        if(x + y == s){
            if((vx == 1 && vy == -1) || (vx == -1 && vy == 1)){
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n;
        cin >> s;
        cout << solve(n, s) << endl;
    }
    return 0;
}
