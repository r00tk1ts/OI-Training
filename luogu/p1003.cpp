#include <iostream>
#include <vector>

using namespace std;

struct Area {
	int x1;
	int y1;
	int x2;
	int y2;
};

int main()
{
	int n;
	cin >> n;
	vector<Area> v;
	for(int i=0; i<n; ++i) {
		Area temp;
		cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
		temp.x2 += temp.x1;
		temp.y2 += temp.y1;
		v.emplace_back(std::move(temp));
	}

	int x, y;
	cin >> x >> y;
	bool cover = false;
	for(int i = v.size()-1; i>=0; --i) {
		if(v[i].x1 <= x && x <= v[i].x2 && v[i].y1 <= y && y <= v[i].y2) {
			cout << i + 1 << endl;
			cover = true;
			break;
		}
	}
	if(cover == false)
		cout << -1 << endl;
	return 0;
}
