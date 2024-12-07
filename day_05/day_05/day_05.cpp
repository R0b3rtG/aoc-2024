#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <regex>

using namespace std;

ifstream in("input.txt");

multimap<int, int> pageRelation;
regex numberReg("\\d\\d");
vector<vector<int>> updates;

void findMatches(const string& text, const regex& reg, vector<string>& matches) {
	smatch match;
	string::const_iterator searchStart(text.cbegin());

	while (regex_search(searchStart, text.cend(), match, reg)) {
		matches.push_back(match.str());
		searchStart = match.suffix().first;
	}
}

bool checkOrder(int first, int second) {
	auto range = pageRelation.equal_range(second);
	if (range.first != range.second) {
		for (auto value = range.first; value != range.second; value++) {
			if (value->second == first) {
				return false;
			}
		}
	}

	return true;
}

bool checkUpdate(vector<int>& update) {
	for (int i = 0; i < update.size() - 1; i++) {
		for (int j = i + 1; j < update.size(); j++) {
			if (!checkOrder(update[i], update[j])) {
				return false;
			}
		}
	}
	
	return true;
}

int main() {
	string line;
	vector<string> lines;

	while (!in.eof()) {
		in >> line;
		lines.push_back(line);
	}

	for (auto& line : lines) {
		vector<string> matches;
		findMatches(line, numberReg, matches);
		
		if (matches.size() == 2) {
			pageRelation.insert({ stoi(matches[0]), stoi(matches[1])});
		} else {
			vector<int> update;
			for (auto& match : matches) {
				update.push_back(stoi(match));
			}
			updates.push_back(update);
		}
	}

	int sum = 0;

	for (auto& update : updates) {
		if (checkUpdate(update)) {
			sum += update[update.size() / 2];
		}
	}

	cout << sum;

	return 0;
}