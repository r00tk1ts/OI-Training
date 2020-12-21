#include <bits/stdc++.h>

using namespace std;

char str[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
					"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

int main() {
	string word;
	vector<int> v;
	int cnt = 0;
	while(cin >> word && cnt < 6) {
		if(cnt == 0) 
			word[0] = tolower(word[0]);
		if(cnt == 5 && word[word.size()-1] == '.')
			word[word.size()-1] = '\0';
		for(int i=0; i<=20; ++i) {
			if(word == str[i]) {
				v.push_back(i * i % 100);
			}
		}
		if(word == "a" || word == "first" || word == "another")
			v.push_back(1);
		if(word == "both" || word == "second")
			v.push_back(4);
		if(word == "third")
			v.push_back(9);
		cnt++;
	}

	string ret;
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); ++i) {
		if(v[i] == 0)
			continue;
		if(v[i] < 10) {
			if(ret.empty())
				ret += to_string(v[i]);
			else 
				ret += "0" + to_string(v[i]);
		} else {
			ret += to_string(v[i]);
		}	
	}
	if(ret.empty())
		ret = "0";
	cout << ret << endl;
	return 0;
}
