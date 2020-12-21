#include <iostream>
#include <cstring>

using namespace std;

unsigned char g_use[10];

int main()
{
	int i, j, full;
	i = j = full = 0;
	bool flag = true;

	for (i=192; i<=327; ++i) {
		memset(g_use, 0, sizeof(g_use));
		full = 0;
		flag = true;

		g_use[i % 10] = g_use[i / 10 % 10] = g_use[i / 100] = 1;
		g_use[i * 2 % 10] = g_use[i * 2 / 10 % 10] = g_use[i * 2 / 100] = 1;
		g_use[i * 3 % 10] = g_use[i * 3 / 10 % 10] = g_use[i * 3 / 100] = 1;

		for(int k=1; k<=9; ++k) {
			if (!g_use[k]) {
				flag = false;
				break;
			}			
		}
		if(flag)
			cout << i << " " << i * 2 << " " << i * 3 << endl;
	}
	return 0;
}
