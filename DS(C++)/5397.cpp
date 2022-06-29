#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testNumber;
    string L;
    cin >> testNumber;
    for(int i = 0; i < testNumber; i++){
        cin >> L;
        int size = L.length();
        stack<char> s;
        stack<char> tmp;
        vector<char> v;
        for(int j = 0; j < size; j++){
            if(L[j] == '<' && s.empty() == true){
                continue;
            }else if(L[j] == '<'){
                tmp.push(s.top());
                s.pop();
            }else if(L[j] == '>' && tmp.empty() == true){
                continue;
            }else if(L[j] == '>'){
                s.push(tmp.top());
                tmp.pop();
            }else if(L[j] == '-' && s.empty() == true){
                continue;
            }else if(L[j] == '-'){
                s.pop();
            }else{
                s.push(L[j]);
            }
        }
        while(!tmp.empty()){
            v.push_back(tmp.top());
            tmp.pop();
        }
        reverse(v.begin(), v.end());

        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }


        auto it = v.rbegin();

        for(; it != v.rend(); ++it){
            cout << *it;
        }

        cout << '\n';

    }

    return 0;
}