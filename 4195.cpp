//union find + hashing
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

//hash - unordered_map 사용
unordered_map<int,int> tmp; // 각 친구의 node
unordered_map<int,int> cnt; // 관계 수 count

//union find 필요 함수 구현
int Find(int Num){
    if(tmp[Num] == Num){
        return Num;
    }else{
        tmp[Num] = Find(tmp[Num]);
        return tmp[Num];
    }
}

int Union(int nameNum1, int nameNum2){
    int tmp1 = Find(nameNum1);
    int tmp2 = Find(nameNum2);

    if(tmp1 != tmp2){
        tmp[tmp2] = tmp1;
        cnt[tmp1] += cnt[tmp2]; // 친구의 count를 더해줌으로써 연결된 관계수를 return
    }

    return cnt[tmp1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        int F;
        cin >> F;
    
        string name1, name2;

        unordered_map<string,int> Friend; 
        
        int num = 0;

        for(int j = 0; j < F; j++){
            cin >> name1 >> name2;
            if(Friend.find(name1) == Friend.end()){
                Friend[name1] = num;
                tmp[num] = num;
                cnt[num] = 1;
                num++;
            }
            if(Friend.find(name2) == Friend.end()){
                Friend[name2] = num;
                tmp[num] = num;
                cnt[num] = 1;
                num++;
            }
            int nameNum1 = tmp[Friend[name1]];
            int nameNum2 = tmp[Friend[name2]];
            cout << Union(nameNum1, nameNum2) << '\n';
        }
    }
    return 0;
}