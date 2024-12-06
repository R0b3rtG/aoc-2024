#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

ifstream in("input.txt");

void findMatches(const string& text, const regex& reg, vector<string>& matches) {
    smatch match;

    string::const_iterator searchStart(text.cbegin());

    while (regex_search(searchStart, text.cend(), match, reg)) {
        matches.push_back(match.str());
        searchStart = match.suffix().first;
    }
}

regex mulReg("mul\\(\\d+,\\d+\\)");
regex numReg("\\d+");

int main()
{
    string text;
    vector<string> matches;

    while (!in.eof()) {
        getline(in, text);
        findMatches(text, mulReg, matches);
    }

    vector<string> numbers;

    for (auto& match : matches) {
        findMatches(match, numReg, numbers);
    }

    long long sum = 0;

    for (int i = 0; i < numbers.size(); i+= 2) {
        sum += (long long)stoi(numbers[i]) * (long long)stoi(numbers[i + 1]);
    }

    cout << sum;
	
    return 0;
}
