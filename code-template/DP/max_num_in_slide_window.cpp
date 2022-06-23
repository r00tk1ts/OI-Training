#include <iostream>
#include <chrono>
#include <deque>
#include <vector>

using namespace std;

// 用单调队列处理滑动窗口中最大值问题
// 滑动窗口从左到右取最大值，单调队列就要从大到小
vector<int> max_num_in_slide_window(const vector<int> &array, int window_size) {
    // queue存储array元素的下标，是从大到小的单调队列
    deque<int> queue;
    vector<int> res;

    // 2 6 4 [9 8 5] 5 2
    // 2 6 4 9 [8 5 5] 2       
    for(int i=0; i<array.size(); ++i) {
        // step 1: 判断一下队首元素是否过期，判断的依据就是根据下标是否越界
        if (i >= window_size && queue.front() <= i-window_size) {
            queue.pop_front();
        }
        // step 2: 判断一下待插入的当前元素array[i]是否满足单调队列的单调性
        // 我们要剔除所有小于等于array[i]元素值的队列元素
        // 因为它们比array[i]小(或等于)，且在从左到右的滑动过程中，生命期没有array[i]长，因此不再有用
        while(!queue.empty() && array[queue.back()] <= array[i]) {
            queue.pop_back();
        }
        // step 3: 插入待插入的当前元素，用插入后的queue的队首元素作为本次窗口(i-window_size~i)的最大值
        queue.push_back(i);
        if (i+1 >= window_size) {
            res.push_back(array[queue.front()]);
        }
    }
    return res;
}


int main() {
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    auto res = max_num_in_slide_window(arr, m);
    for(auto item : res) cout << item << "\t";
    cout << endl;
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<" ms"<<endl;
#endif
    return 0;
}