#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> restart(string& s){
    vector<int> res(s.size());
    int a = 0;
    for(int i = 1; i < s.size(); i++){
        while(a > 0 && s[a] != s[i]) a = res[a - 1]; // ex) AA
        if(s[i] == s[a]) res[i] = ++a;
    }
    return res;
}

int main(){
    string T, P; getline(cin, T); getline(cin, P);
    vector<int> res = restart(P);
    
    int b = 0;
    vector<int> result;
    
    for(int i = 0; i < T.size(); i++){
        while(b > 0 && T[i] != P[b]) b = res[b - 1];
        if(T[i] == P[b]) b++;
        if(b == P.size()){
            result.push_back(i+2-P.size());
            b = res[b - 1];
        }
    }
    cout << result.size() << '\n';
    for(int x : result) cout << x << '\n';
    return 0;
}