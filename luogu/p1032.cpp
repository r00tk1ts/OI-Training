#include <bits/stdc++.h>

using namespace std;

string a, b;
string sa[6], sb[6];
int n = 0;
queue<string> q;
queue<int> step;
map<string, bool> mp;

int bfs() {
    while(!q.empty() && q.front() != b && step.front() <= 10) {
        if(mp[q.front()]) {
            q.pop();
            step.pop();
            continue;
        }
        mp[q.front()] = true;
        for(int i=0; i<n; ++i) {
            string s = q.front();
            while(true) {
                size_t pos = s.find(sa[i]);
                if(pos == -1) 
                    break;
                string temp = q.front();
                temp.replace(pos, sa[i].size(), sb[i]);
                q.push(temp);
                step.push(step.front()+1);
                s[pos] = '*';
            }
        }
        q.pop();
        step.pop();
    }
    if(q.empty() || step.front() > 10)
        return -1;
    else
        return step.front();
}

int main()
{
    cin >> a >> b;

    while(cin >> sa[n] >> sb[n])
        ++n;
        
    q.push(a);
    step.push(0);
    int result = bfs();
    if(result == -1)
        cout << "NO ANSWER!";
    else
        cout << result << endl;
    return 0;
}