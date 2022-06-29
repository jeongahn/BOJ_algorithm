//Dijkstra
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 2147483647 // int 최대값
#define H 1001

vector<pair<int, int>> route[H]; // 벡터 열은 N으로 고정이나 열은 가변적 즉 해당 도시에서 가는 다른 모든 도시 정보와 비용 저장.
int minCost[H]; // 최소비용 저장할 배열

void Dijkstra(int sC){
    int a = sC;
    minCost[a] = 0;
    priority_queue<pair<int, int>> heap; // 최대 힙
    heap.push(make_pair(a, 0));
    // 최소 비용을 먼저 구해야 하기 때문에 적은 비용을 최대로 쓰기 위해서는 모든 비용에 -
    while(!heap.empty()){
        int curr = heap.top().first;

        int eachCost = -heap.top().second; //비용 음수화
        heap.pop();
        if(minCost[curr] < eachCost){ //더 cost가 적은 경우 pass
            continue;
        }
        for(auto i : route[curr]){ //
            int next = i.first;
            int overCost = eachCost + i.second;
            if(overCost < minCost[next]){
                minCost[next] = overCost;
                heap.push(make_pair(next, -overCost)); 
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int dpC, arC, cost;
    //각각의 코스트를 최대 비용으로 설정
    for(int i = 1; i <= N; i++){
        minCost[i] = MAX;
    }
    
    for(int i = 1; i < M+1; i++){
        cin >> dpC >> arC >> cost;
        route[dpC].push_back(make_pair(arC, cost));
    }
    int sC, eC;
    cin >> sC >> eC;

    Dijkstra(sC);
    cout << minCost[eC] << '\n'; //최소 비용 출력
    
    return 0;
}