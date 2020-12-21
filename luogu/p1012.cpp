#include <bits/stdc++.h>

using namespace std;

bool compare(const string &a, const string &b) {
	return a + b > b + a;
}

int main() {
	vector<string> v;
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) {
		string temp;
		cin >> temp;
		v.emplace_back(move(temp));
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); ++i) 
		cout << v[i];
	cout << endl;
	return 0;
}
