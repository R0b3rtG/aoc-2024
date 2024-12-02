#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream in("input.txt");

int main()
{
	vector<int> levels;
	int counter = 0;

	string line;
	while (getline(in, line)) {
		levels.clear();

		int idx = 0;
		while ((idx = line.find(' ')) && idx != -1) {
			levels.push_back(stoi(line.substr(0, idx)));
			line = line.substr(idx + 1, line.size());
		}

		levels.push_back(stoi(line));

		bool safe = true;
		for (int i = 1; i < levels.size() - 1; i++) {
			int diff1 = (levels[i] - levels[i - 1]);
			int diff2 = (levels[i + 1] - levels[i]);
			if (diff1 * diff2 <= 0 || abs(diff1) > 3 || abs(diff2) > 3) {
				safe = false;
				break;
			}
		}
		if (safe) {
			counter++;
		}
	}

	cout << counter;

	return 0;
}