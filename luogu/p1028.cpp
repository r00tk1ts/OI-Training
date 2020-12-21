#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

/*
void addNumber(int n, int& count)
{
	int left, orig = n;
	int c = 0;
	
	while(orig / 10)
	{
		orig /= 10;
		c++;
	}

	left = orig;
	count++;

	for(int i=1; i<=left/2; ++i)
	{
		int temp = n;
		temp += i * pow(10, c + 1);
		addNumber(temp, count);
	}
}
*/

int main()
{
	int n, dp[1001];
	dp[0] = dp[1] = 1;
	cin >> n;
	assert(n <= 1000);
	for(int i=2; i<=n; ++i)
	{
		if(i % 2 == 0) 
			dp[i] = dp[i-1] + dp[i/2];
		else
			dp[i] = dp[i-1];
	}
	
	cout << dp[n] << endl; 
	return 0;
}
