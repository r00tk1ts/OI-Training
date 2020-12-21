#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	int item = 1;
	while(sum <= n)
	{
		sum += item;
		item++;
	}
	item--;
	sum -= item;
	int left = n - sum;
	//cout << "sum: " << sum << endl;
	//cout << "left: " << left << endl;
	//cout << "item: " << item << endl;
	if(left == 0)
	{
		if((item-1) % 2 == 0)
			cout << item-1 << "/" << 1 << endl;
		else
			cout << 1 << "/" << item-1 << endl;
	} 
	else
	{
		if(item % 2 == 0)
			cout << left << "/" << item - left + 1<< endl;
		else
			cout << item - left + 1 << "/" << left << endl;
	}
	return 0;
}
