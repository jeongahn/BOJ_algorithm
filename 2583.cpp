#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;

//direction 선언
int xdir[4] = {-1, 1, 0, 0};
int ydir[4] = {0, 0, -1, 1};
//모눈 종이 영역과 방문 영역 선언
int gridPaper[101][101];
int visited[101][101];


void DFS(int x, int y, int& sum){
    
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++){
        //direction의 배열을 더해줌으로써 으로 4가지 방향 이동하고 찾기
        int nextx = x + xdir[i];
        int nexty = y + ydir[i];
        
        //범위를 벗어난 경우 탐색 x
        if(nextx < 0 || nexty < 0){
            continue;
        }
        if(nextx > N || nexty > M){
            continue;
        }
        //범위를 벗어나지 않고 방문을 하지 않았던 곳만
        if(nextx >= 0 && nexty >= 0 && nextx < N && nexty < M){
            if(visited[nexty][nextx] != 1){
                sum ++;
                DFS(nextx, nexty, sum);
            }
        }
        
    }
}

int main(){

    cin >> M >> N >> K;
    int x1, x2, y1, y2;
    for(int i = 0; i < K; i++){ // 모눈 종이 1칸을 1로 표시
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2; j++){
            for(int r = x1; r < x2; r++){
                gridPaper[j][r] = 1;
                visited[j][r] = 1;
            }
        }
    }
    int sum = 0;
    vector<int> eachWidth; // DFS로 영역의 갯수와 각 영역별 크기를 저장할 벡터

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(gridPaper[i][j] == 0 && visited[i][j] != 1){
                sum = 1;
                DFS(j, i, sum);
                eachWidth.push_back(sum);
            }
        }
    }
    sort(eachWidth.begin(), eachWidth.end());

    cout << eachWidth.size() << endl;

    for(auto i : eachWidth){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}