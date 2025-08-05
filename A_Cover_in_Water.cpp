#include <iostream>
using namespace std;

int solve(string s, int n){

    if(n == 1){
        if( s == ".") return 1;
        else return 0;
    }
    int req = 0;
    int count = 0;
    for(int i=0; i<n ; i++){
        if(s[i] == '.'){
            count++;
            // cout << "Count" << count<< endl;
            if(i == (n-1) && count >= 3){
                // cout << "Req at last " << req << endl;
                req = 2;
            }else if(i == (n-1)){
                req += count;
            } 
        }else{
            if(count >= 3){
                // cout << "Req" << req << endl;
                return req = 2;
                // break;
            }else{
                req += count;
                // cout << "Req" << req << endl;
                // cout<< count << "set to 0"<< endl;
                count = 0;
            }
        }
    }
    return req;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        cout << solve(s, n) << endl;
    }
    return 0;
}