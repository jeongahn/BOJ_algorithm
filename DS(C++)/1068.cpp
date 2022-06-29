//parent pointer implementation of trees
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// parent pointer implementation of trees에서 find사용
int find(int array[], int curr){
    if(array[curr] == -1) return true;
    else if(array[curr] == -2) return false; // 부모노드가 삭제된 노드 인 경우 false return
    else return find(array, array[curr]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Number, parentNode;
    cin >> Number;
    int array[Number];
    
    for(int i = 0; i < Number; i++){
        cin >> parentNode;
        array[i] = parentNode;
    }
    int removeNode;
    cin >> removeNode;

    vector<vector<int>> v(Number); // 2차원 동적 배열 생성 각 노드의 자식 노드를 추가 하기 위해 복잡;;..
    for(int i = 0; i < Number; i++){
        if(array[i] != -1){
            v[array[i]].push_back(i); // root 노드가 아닌 경우 각 노드에 자식 노드 추가
        }
    }
    if(array[removeNode] != -1){ // 삭제할 노드를 배열에서 찾은 후 삭제
        v[array[removeNode]].erase(find(v[array[removeNode]].begin(), v[array[removeNode]].end(), removeNode));
    }
    array[removeNode] = -2; // 삭제한 노드는 -2로 치환
    int sum = 0;

    for(int i = 0; i < Number; i++){
        if(find(array, i) && v[i].size() == 0){ //해당 노드의 자식이 없고 find함수 실행후 true인 경우에 leaf node 계산
            sum += 1; 
        }
    }
    
    cout << sum << endl;

    return 0;
}