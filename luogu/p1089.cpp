#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> cost(12);
	for(auto &elem : cost) 
		cin >> elem;

	const int money = 300;
	int left = 0;
	int total = 0;
	for(int i=0; i<cost.size(); ++i) {
		if(left + money < cost[i]) {
			cout << -(i+1);
			return 0;
		}
		if(left >= cost[i]) {
			left -= cost[i];
			total += money;
		} else { 
			if((cost[i] - left) % 100 == 0) {
				total += money - (cost[i] - left) / 100 * 100;
				left += (cost[i] - left) / 100 * 100 - cost[i];
			} else {
				total += money - ((cost[i] - left) / 100 + 1) * 100;
				left += ((cost[i] - left) / 100 + 1) * 100 - cost[i];
			}
		}
	}	
	total = total * 1.2 + left;
	cout << total;
	return 0;
}
