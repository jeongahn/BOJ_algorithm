//Counting Sort
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> sum(10001, 0);
    int number;
    for(int i = 1; i <= N; i++){
        cin >> number;
        sum[number]++;
    }

    for(int i = 1; i <= 10000; i++){
        if(sum[i] != 0){ // 0이 아닌경우에만 출력
            for(int j = 0; j < sum[i]; j++){
                cout << i << '\n';
            }
        }
    }
    return 0; 
}