#include <iostream>
#include <map>
#include <string>

using namespace std;

int g_table[21][21][21] = {0};


long func(long a, long b, long c) 
{
	if(a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if(a > 20 || b > 20 || c > 20)
		return func(20, 20, 20);
	else if(a < b && b < c)
		return func(a, b, c-1) + func(a, b-1, c-1) - func(a, b-1, c);
	else
		return func(a-1, b, c) + func(a-1, b-1, c) + func(a-1, b, c-1) - func(a-1, b-1, c-1);
}

int main()
{
	long a, b, c;
	for(int i=0; i<21; ++i){
		for(int j=0; j<21; ++j) {
			g_table[0][i][j] = 1;
			g_table[i][0][j] = 1;
			g_table[i][j][0] = 1;
		}
	}

	for(int i=1; i<=20; ++i){
		for(int j=1; j<=20; ++j) {
			for(int k=1; k<=20; ++k) {
				if(i < j && j < k) 
					g_table[i][j][k] = g_table[i][j][k-1] + g_table[i][j-1][k-1] - g_table[i][j-1][k];
				else 
					g_table[i][j][k] = g_table[i-1][j][k] + g_table[i-1][j-1][k] + g_table[i-1][j][k-1] - g_table[i-1][j-1][k-1];
			}
		}
	}
	
	while(cin >> a >> b >> c) {
		if(a == -1 && b == -1 && c == -1)
			break;
		if (a <= 0 || b <= 0 || c <= 0)
			cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << endl;
		else if(a > 20 || b > 20 || c > 20)
			cout << "w(" << a << ", " << b << ", " << c << ") = " << g_table[20][20][20] << endl;
		else
			cout << "w(" << a << ", " << b << ", " << c << ") = " << g_table[a][b][c] << endl;
	}
	return 0;
}
