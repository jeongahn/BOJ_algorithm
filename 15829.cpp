//hash function
#include <iostream>
#include <unordered_map>
#include <cmath>
#define M 1234567891 //모듈러 M
using namespace std;

long long power(unsigned long a, unsigned long b){ 
    long long sum = 1;

    for(int i = 0; i < b; i ++){
        sum *= a;
        if(sum > M){ // sum이 M보다 커지는 경우 모듈러로 나눠주기
            sum %= M;
        }
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int number;
    char alphabet;
    unordered_map<long long, int> Stringlist;

    cin >> number;
    
    for(int i = 0; i < number; i++){
        cin >> alphabet;
        Stringlist.insert(make_pair(power(31, i), ((int)alphabet - 96))); //Stringlist에 추가
    }
    unsigned long sum = 0;
    for(auto i : Stringlist){
        sum += i.first * i.second;
        if(sum > M){ // 여기에서도 sum이 M보다 커지게 되는 경우가 있다 50점이 나온 이유.. 예외 코드 추가
            sum %= M;
        }
    }
    cout << sum << endl;

    return 0;
}