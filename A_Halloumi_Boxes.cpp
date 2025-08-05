#include <iostream>
#include <vector>
#include<algorithm>
#include <functional>
using namespace std;


string func(int boxes,int maxLen,vector<int> vec){
    if(maxLen > 1){
        return "YES";
    }
    else{
        vector<int> sorted(vec.begin(), vec.end());
        sort(sorted.begin(), sorted.end());
        for(int i=0; i< vec.size(); i++){
            // cout << vec[i] << " "<< sorted[i] << endl;
            if(vec[i] != sorted[i]){
                return "NO";
            }
        }
        return "YES";
    }
}
int main(){
    int n;
    string func(int boxes,int maxLen,vector<int> vec);
    // cout << "enter"<<endl;
    cin >> n;

    for(int i=0; i< n; i++){
        int boxes;
        int maxLen;
        cin >> boxes;
        cin >> maxLen;
        vector<int> arr;
        for(int i=0; i< boxes; i++){
            int ele;
            cin >> ele;
            arr.push_back(ele);
        }
        cout << func(boxes,maxLen,arr) << endl;
    }
    return 0;
}
