#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;
    int input_length, dir;
    vector<int> dir_four;
    vector<int> length_six;
    int dir_list[4] = {0,};
    int small_width = 1;
    int large_width = 1;
    for(int i = 0; i < 6; i++){
        cin >> dir >> input_length;
        dir_four.push_back(dir);
        length_six.push_back(input_length);
    }
    for(int i = 0; i < 6; i++){
        dir_list[dir_four[i] - 1] += 1;
    }
    
    for(int i = 0; i < 2; i++){
        dir_four.push_back(0);
        length_six.push_back(0);
    }

    for(int i = 0; i < 6; i++){
        if(dir_list[dir_four[i]-1] == 1){
            large_width *= length_six[i];
            continue;
        }
        if(dir_four[i] == dir_four[(i+2) % 6]){
                small_width *= length_six[(i+1) % 6];
        }
    }
    int answer;
    answer = num * (large_width - small_width);
    cout << answer << endl;

    return 0;    
}