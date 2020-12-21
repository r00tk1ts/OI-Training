#include <iostream>

using namespace std;

int main()
{
	int reserve[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int number[2001] = {6};
	int k, n = 0;

	cin >> k;
	for(int i=1; i<=2000; ++i) {
		int temp = i;
		while(temp) {
			number[i] += reserve[temp % 10];
			temp /= 10;
		}
	}

	for(int i=0; i<=1000; ++i) {
		for(int j=0; j<=1000; ++j) {
			if(number[i] + number[j] + number[i+j] + 4 == k)
				++n;
		}
	}
	cout << n << endl;
	return 0;
}
