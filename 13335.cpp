//deque
#include<iostream>
#include<queue>
#include<vector>
#include<deque>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w, L;
    cin >> n >> w >> L;

    queue<int> before; // 건너기전
    queue<int> middle; // 다리 위
    vector<int> after; // 건넌 후
    deque<int> count; // 트럭이 건너야하는 길이를 횟수로 저장(시간이 지날수록 횟수 감소)
    int a; // 트럭 무게 및 건너기전 queue에 push
    for(int i = 0; i < n; i++){
        cin >> a;
        before.push(a);
    }

    bool over = false;
    int time = 1;

    //첫번째 트럭 부터 시작
    middle.push(before.front()); 
    before.pop();
    count.push_back(w);

    int sum = middle.front();
    while(after.size() != n){ //모든 트럭이 다 건너기 전까지
        
        for(auto i = 0; i < count.size(); i++){
            --count[i]; //다리 위 트럭이 건너야할 시간(횟수) 감소
        }
        if(count[0] == 0){ // 다리를 다 건넌 트럭은 after로 push_back
            sum -= middle.front();
            after.push_back(middle.front());
            middle.pop();
            count.erase(count.begin());
        }
        if(!before.empty() && sum + before.front() <= L){
            middle.push(before.front());
            count.push_back(w);
            sum += before.front();
            before.pop();
        }
        time++; // 매 반복마다 시간 1씩 증가
    }

    cout << time << endl;

    return 0;
}
