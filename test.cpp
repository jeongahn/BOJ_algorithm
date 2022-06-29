#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

string Solve() {
	string text;
	stack <int> stk, temp;

	cin >> text;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == '<') {
			if (stk.empty()) continue;
			else {
				temp.push(stk.top());
				stk.pop();
			}
		}
		else if (text[i] == '>') {
			if (temp.empty()) continue;
			else {
				stk.push(temp.top());
				temp.pop();
			}
		}
		else if (text[i] == '-') {
			if (stk.empty()) continue;
			else stk.pop();
		}
		else
			stk.push(text[i]);
	}

	string result;
	while (!temp.empty()) {
		stk.push(temp.top());
		temp.pop();
	}
	while (!stk.empty()) {
		result += stk.top();
		stk.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int testcase; cin >> testcase;

	while (testcase--) {
		cout << Solve() << endl;
	}
	return 0;
}