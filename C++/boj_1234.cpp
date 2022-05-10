#include <iostream>
#include <algorithm>

using namespace std;



int min_S(int n, int func_A[], int func_B[]){
  int result = 0;
  for(int i = 0; i < n; i++){
    result += func_A[i] * func_B[i];
  }

  return result;
}

bool compare(int a, int b){
  return a > b;
}

int main(void){
  int v_A[51];
  int v_B[51];
  int n;

  cin >> n;

  for(int i = 0; i <n; i++){

    cin >> v_A[i];
  }
  for(int i = 0; i<n; i++){
    cin >> v_B[i];
  }
  sort(v_A, v_A+n);
  sort(v_B, v_B+n, compare);


  cout << min_S(n, v_A, v_B) << endl;
  return 0;
}
