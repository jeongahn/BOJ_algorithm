//union-find
#include <iostream>

using namespace std;

int arr[500001];

int Find(int p){
    if(arr[p] == p){ //부모가 다른 노드가 아닐경우에는 자신을 다시 return
        return p;
    }else{
        arr[p] = Find(arr[p]); //부모가 다른 노드일 경우에 그 부모노드의 부모를 계속 탐색
        return arr[p];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;
    // 모든 노드의 부모를 자기자신으로 설정
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }

    //union find
    int p1, p2;
    int orderNum; // 몇번째에서 사이클이 만들어졌는지
    bool check;
    for(int i = 0; i < m; i++){
        cin >> p1 >> p2;
        check = false;

        if(Find(p1) == Find(p2)){ //같은 경우에 cycle 완성됨을 체크
            orderNum = i + 1;
            check = true;
            break; // 문제를 잘 못읽고... 완성한 순간 종료...를 위해서 break 추가
        }
        
        int tmp1 = Find(p1);
        int tmp2 = Find(p2);
        arr[tmp2] = tmp1;
    }
    
    //cycle이 안만들어진 경우(check == false) 0 출력
    if(check == false){
        cout << 0 << endl;
    }else{
        cout << orderNum << endl;
    }
    return 0;
}
