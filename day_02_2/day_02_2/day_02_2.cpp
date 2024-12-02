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

		for (int index1 = 0; index1 < levels.size(); index1++) {
			vector<int> copyLevels;

			for (int index2 = 0; index2 < levels.size(); index2++) {
				if (index1 != index2) {
					copyLevels.push_back(levels[index2]);
				}
			}

			bool safe = true;
			for (int i = 1; i < copyLevels.size() - 1; i++) {
				int diff1 = (copyLevels[i] - copyLevels[i - 1]);
				int diff2 = (copyLevels[i + 1] - copyLevels[i]);
				if (diff1 * diff2 <= 0 || abs(diff1) > 3 || abs(diff2) > 3) {
					safe = false;
					break;
				}
			}
			if (safe) {
				counter++;
				break;
			}
		}
	}

	cout << counter;

	return 0;
}