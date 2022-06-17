#include <iostream>
#include <chrono>
#include <vector>
#include <deque>

using namespace std;

int max_seq_sum(const vector<int>& arr, int m) {
    int ans = arr[0];
    // 前缀和数组
    vector<int> s(arr.size());
    s[0] = arr[0];
    for(int i=1; i<arr.size(); ++i) {
        s[i] = s[i-1] + arr[i];
    }

    // 单调递减队列，存储s的下标
    deque<int> q;
    for(int i=0; i<s.size(); ++i) {
        if(!q.empty() && q.front() <= i - m) {
            q.pop_front();
        }
        if (i >= m) ans = max(ans, s[i] - s[q.front()]);
        while(!q.empty() && s[q.back()] >= s[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    return ans;
} 

int main() {
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.txt", "r", stdin);
#ifndef DEBUG
    freopen("out.txt", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i=0; i<arr.size(); ++i) {
        cin >> arr[i];
    }
    cout << max_seq_sum(arr, m) << endl;
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<" ms"<<endl;
#endif
    return 0;
}