//priority queue
#include <iostream>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Section; 
    priority_queue<int> present;
    int sec_num, present_price;
    cin >> Section;
    for(int i = 0; i < Section; i++){
        cin >> sec_num;
        if(sec_num == 0 && present.empty()){ // 해당 거점지가 0이고 줄 선물이 없을 경우
            cout << -1 << endl;
        }else if(sec_num > 0){ // 해당 거점지에서 선물을 충전할 수 있는 경우
            for(int j = 0; j < sec_num; j++){
                cin >> present_price;
                present.push(present_price);
            }
        }else{ // 해당 거점지에서 아이들에게 선물을 나누어 주는 경우
            cout << present.top() << endl;
            present.pop();
        }
    }

    return 0;

}