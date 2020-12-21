#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main()
{
	string word, line;

	getline(cin, word);
	getline(cin, line);

	std::transform(word.begin(), word.end(), word.begin(), 
		[](unsigned char c){ return std::tolower(c); });
	std::transform(line.begin(), line.end(), line.begin(), 
		[](unsigned char c){ return std::tolower(c); });

	word = " " + word + " ";
	line = " " + line + " ";
	if(line.find(word) == string::npos)
	{
		cout << -1 << endl;
		return 0;
	}	
	
	int first = line.find(word);
	int pos = first, s = 0;
	while(pos != string::npos) 
	{
		++s;
		pos = line.find(word, pos + 1);
	}
	cout << s << " " << first << endl;
	return 0;
}
