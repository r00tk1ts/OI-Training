#include <bits/stdc++.h>

using namespace std;

struct item {
	int w;
	int num;
}g_total[20001];

int compare(const item &a, const item &b) {
	if(a.w != b.w)
		return a.w > b.w;
	return a.num < b.num;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int extra[10];
	for(int i=0;i<10;++i)
		cin >> extra[i];
	for(int i=1;i<=n;++i) {
		cin >> g_total[i].w;
		g_total[i].num = i;
	}
	sort(g_total+1, g_total+n+1, compare);

	for(int i=1,d=1;i<=n;++i) {
		g_total[i].w += extra[d-1];
		++d;
		if(d == 11)
			d = 1;
	}
	sort(g_total+1, g_total+n+1, compare);
	for(int i=1; i<=k; ++i)
		cout << g_total[i].num << " ";
	cout << endl;
	return 0;
}
