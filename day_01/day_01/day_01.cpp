#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");

vector<long long> leftList, rightList;

int main()
{
	long long x = 0, y = 0;

	while (in >> x >> y) {
		leftList.push_back(x);
		rightList.push_back(y);
	}

	sort(leftList.begin(), leftList.end());
	sort(rightList.begin(), rightList.end());

	long long sum = 0;

	for (int i = 0; i < leftList.size(); i++) {
		sum += abs(leftList[i] - rightList[i]);
	}

	cout << sum;

	return 0;
}