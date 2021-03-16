#include <bits/stdc++.h>

using namespace std;

// 为了方便边界条件处理，我们将第零行和第零列、第七列置为0，它们不会被改变，也不会被按下。
int puzzle[6][8] = {0};
int press[6][8] = {0};

void dump() {
    for (int i=1; i<=5; ++i) {
        for (int j=1; j<=6; ++j) {
            cout << press[i][j] << " ";
        }
        cout << "\n";
    }
}

bool process(int number) {
    memset(press,0,30*sizeof(int));
    
    // 初始化第一行
    for (int col=1; col<=6; ++col) {
        press[1][col] = (number >> (col - 1)) % 2;
    }

    // 第一行一旦固定，下面的每一行也随之固定了
	// 下面每一行固定的策略就是必须让上一行同一列的灯处于熄灭状态
    for (int i=2; i<=5; ++i) {
        for (int j=1; j<=6; ++j) {
            press[i][j] = press[i-1][j] ^ puzzle[i-1][j] ^ press[i-1][j-1] ^ 
                press[i-2][j] ^ press[i-1][j+1];
        }
    }
    
	// 如果按照上面的递推，最后一行灯也能如愿全灭，则意味着找到了正解
    for (int j=1; j<=6; ++j) {
        if (press[5][j] != puzzle[5][j] ^ press[5][j-1] ^ press[5][j+1] ^ press[4][j])
            return false;
    }
    return true;
}

int main()
{
    // 读入所有灯状态
    for (int i=1; i<=5; ++i) {
        for (int j=1; j<=6; ++j) {
            cin >> puzzle[i][j];
        }
    }

    // 枚举第一行所有情况
    for (int num=0; num<64; ++num) {
        if(process(num)) {
            dump();
            break;
        }
    }
    return 0;
}