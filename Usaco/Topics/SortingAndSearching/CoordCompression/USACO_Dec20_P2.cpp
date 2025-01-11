#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const int maxn = 2501;

set<int> xCoordinates, yCoordinates;
map<int, int> xCoordMapping, yCoordMapping;
vector<pair<int,int>> allCoordinates;
vector<vector<int>> prefSum(maxn, vector<int>(maxn, 0));

int count(pair<int,int> firstCorner, pair<int, int> secondCorner) {
	pair<int, int> bottomLeft = {min(firstCorner.first, secondCorner.first), min(firstCorner.second, secondCorner.second)};
	pair<int, int> topRight = {max(firstCorner.first, secondCorner.first), max(firstCorner.second, secondCorner.second)};

	return (prefSum[topRight.first][topRight.second] - prefSum[bottomLeft.first - 1][topRight.second] - prefSum[topRight.first][bottomLeft.second - 1] + prefSum[bottomLeft.first - 1][bottomLeft.second - 1]);
}
int main() {
	long long n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		allCoordinates.push_back({x, y});
	}
	sort(allCoordinates.begin(), allCoordinates.end(), 
		[](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first;});
	for (auto p : allCoordinates) {
		// cout << p.first << " " << p.second << endl;
		xCoordinates.insert(p.first);
		yCoordinates.insert(p.second);
	}

	int xOrder = 1, yOrder = 1;
	for (int coord : xCoordinates) {
		xCoordMapping[coord] = xOrder;
		xOrder += 1;
	}

	for (int coord : yCoordinates) {
		yCoordMapping[coord] = yOrder;
		yOrder += 1;
	}

	for (int i = 0; i < allCoordinates.size(); ++i) {
		auto p = allCoordinates[i];
		allCoordinates[i] = {xCoordMapping[p.first], yCoordMapping[p.second]};
		prefSum[allCoordinates[i].first][allCoordinates[i].second] = 1; 
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			prefSum[i][j] += prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1];
		}
	}

	long long ans = 0;
	for (int i = 0; i < allCoordinates.size(); ++i) {
		// long long blockedCount = 0;
		for (int j = i + 1; j < allCoordinates.size(); ++j) {
			auto firstCorner = allCoordinates[i];
			auto secondCorner = allCoordinates[j];
			pair<int, int> bottomLeft = {min(firstCorner.first, secondCorner.first), min(firstCorner.second, secondCorner.second)};
			pair<int, int> topRight = {max(firstCorner.first, secondCorner.first), max(firstCorner.second, secondCorner.second)};

			long long upper = 0, lower = 0;
			if (bottomLeft.second != 1) {
				lower += count({bottomLeft.first, bottomLeft.second - 1}, {topRight.first, 1});
			}
			if (topRight.second != n) {
				upper += count({topRight.first, topRight.second + 1}, {bottomLeft.first, n});
			}
            // cout << i << " " << j << "; added = " << (upper + 1) * (lower + 1) << endl;
			ans += (upper + 1) * (lower + 1);
		}
	}
	cout << ans + n + 1 << endl;
}
