#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void changeItoB(int num){
    vector<int> v;

    while(num > 0){
        v.push_back(num % 2);
        num /= 2;
    }

    reverse(v.begin(), v.end());
    v.erase(v.begin());

    for(int i = 0; i<v.size(); i++){
        if(v[i] == 1){
            cout << 7;
        }else{
            cout << 4;
        }
    }
    cout << '\n';
    
}


int main(){
    
    int input_num;
    cin >> input_num;

    changeItoB(input_num+1);
}