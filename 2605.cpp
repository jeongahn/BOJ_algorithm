//arrayList
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int studentNumber;
    cin >> studentNumber;
    vector<int> v; //arrayList
    int num;

    for(int i = 0;i < studentNumber; i++){
        cin >> num;
        int a = (i + 1) - num - 1;
        v.insert(v.begin() + a, i + 1);
    }
    for(int i = 0; i < studentNumber; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}