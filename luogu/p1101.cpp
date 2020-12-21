#include <bits/stdc++.h>

using namespace std;

char mp[100][100];
bool flag[100][100] = {false};
int n;
char word[8] = "yizhong";

int main()
{
    cin >> n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> mp[i][j];
        }
    }    

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            // 行，自左向右
            if(j + 7 <= n) {
                bool tmp = true;
                for(int k=0; k<7; ++k) {
                    if(mp[i][j+k] != word[k]) {
                        tmp = false;
                        break;
                    }
                }
                if(tmp == true) {
                    for(int k=0; k<7; ++k) {
                        flag[i][j+k] = true;
                    }
                }
            }

            // 行，自右向左
            if(j - 6 >= 0) {
                bool tmp = true;
                for(int k=0; k<7; ++k) {
                    if(mp[i][j-k] != word[k]) {
                        tmp = false;
                        break;
                    }
                }
                if(tmp == true) {
                    for(int k=0; k<7; ++k) {
                        flag[i][j-k] = true;
                    }
                }
            }

            // 列，自上向下
            if(i + 7 <= n) {
                bool tmp = true;
                for(int k=0; k<7; ++k) {
                    if(mp[i+k][j] != word[k]) {
                        tmp = false;
                        break;
                    }
                }
                if(tmp == true) {
                    for(int k=0; k<7; ++k) {
                        flag[i+k][j] = true;
                    }
                }
            }

            // 列，自下向上
            if(i - 6 >= 0) {
                bool tmp = true;
                for(int k=0; k<7; ++k) {
                    if(mp[i-k][j] != word[k]) {
                        tmp = false;
                        break;
                    }
                }
                if(tmp == true) {
                    for(int k=0; k<7; ++k) {
                        flag[i-k][j] = true;
                    }
                }
            }

            // 左下到右上
            if(i - 6 >= 0 && j + 7 <= n) {
                bool tmp = true;
                for(int k=0; k<7; ++k) {
                    if(mp[i-k][j+k] != word[k]) {
                        tmp = false;
                        break;
                    }
                }
                if(tmp == true) {
                    for(int k=0; k<7; ++k) {
                        flag[i-k][j+k] = true;
                    }
                }
            }

            // 右下到左上
            if(i - 6 >= 0 && j - 6 >= 0) {
                bool tmp = true;
                for(int k=0; k<7; ++k) {
                    if(mp[i-k][j-k] != word[k]) {
                        tmp = false;
                        break;
                    }
                }
                if(tmp == true) {
                    for(int k=0; k<7; ++k) {
                        flag[i-k][j-k] = true;
                    }
                }
            }

            // 右上到左下
            if(i + 7 <= n && j - 6 >= 0) {
                bool tmp = true;
                for(int k=0; k<7; ++k) {
                    if(mp[i+k][j-k] != word[k]) {
                        tmp = false;
                        break;
                    }
                }
                if(tmp == true) {
                    for(int k=0; k<7; ++k) {
                        flag[i+k][j-k] = true;
                    }
                }
            }

            // 左上到右下
            if(i + 7 <= n && j + 7 <= n) {
                bool tmp = true;
                for(int k=0; k<7; ++k) {
                    if(mp[i+k][j+k] != word[k]) {
                        tmp = false;
                        break;
                    }
                }
                if(tmp == true) {
                    for(int k=0; k<7; ++k) {
                        flag[i+k][j+k] = true;
                    }
                }
            }
        }
    }

    for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(flag[i][j])
                    cout << mp[i][j];
                else
                    cout << "*";
            }
            cout << endl;
        }
    return 0;
}