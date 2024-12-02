#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ifstream in("input.txt");

vector<long long> leftList;
map<long long, int> freq;

int main()
{
	long long x = 0, y = 0;

	while (in >> x >> y) {
		leftList.push_back(x);
		freq[y]++;
	}

	long long sum = 0;



	for (int i = 0; i < leftList.size(); i++) {
		sum += leftList[i] * freq[leftList[i]];
	}

	cout << sum;

	return 0;
}