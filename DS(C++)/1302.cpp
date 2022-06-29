//hashing + sorting
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string,int> &a, pair<string, int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<string, int> sold;
    int number;
    string bookName;
    //hashing
    cin >> number;
    for(int i = 0; i < number; i++){
        cin >> bookName;
        if(sold.count(bookName) == 0){
            sold.insert({bookName, 1});
        }else{
            sold[bookName]++;
        }
    }
    //sorting
    vector<pair<string, int>> soldSort(sold.begin(), sold.end());
    sort(soldSort.begin(), soldSort.end(), compare);
    auto i = soldSort.begin();
    cout << i->first << endl;
    
    return 0;
}