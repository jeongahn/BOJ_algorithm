#include <iostream>
#include <vector>
using namespace std;


void fibonacci(int n){
    vector<int> dp_zero;
    vector<int> dp_one;
    dp_zero.push_back(1);
    dp_one.push_back(0);
    dp_zero.push_back(0);
    dp_one.push_back(1);
    
    for(int i=2; i < n+1; i++){
        dp_zero.push_back(dp_zero[i-1] + dp_zero[i-2]);
        dp_one.push_back(dp_one[i-1] + dp_one[i-2]);
    }
    cout << dp_zero[n] << " ";
    cout << dp_one[n] << endl;
    // if(n == 0) {
    //     return dp[0];
    // }else if(n == 1){
    //     return dp[1];
    // }else{
    //     return fibonacci(n-1) + fibonacci(n-2);
    // }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int testCase;
    cin >> testCase;
    int num;
    for(int i = 0; i < testCase; i++){
        cin >> num;
        // count_zero = 0;
        // count_one = 0;
        fibonacci(num);
        //cout << count_zero << " " << count_one << "\n";
    }
    return 0;
}