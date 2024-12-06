#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream in("input.txt");

vector<string> puzzle;

vector<string> XMAS1 = { "M.M", ".A.", "S.S" };
vector<string> XMAS2 = { "M.S", ".A.", "M.S" };
vector<string> XMAS3 = { "S.S", ".A.", "M.M" };
vector<string> XMAS4 = { "S.M", ".A.", "S.M" };


bool check1(int i, int j) {
    if (i > puzzle.size() - 3 || j > puzzle[i].size() - 3 ) {
        return false;
    }

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (puzzle[i + k][j + l] != XMAS1[k][l] && XMAS1[k][l] != '.') {
                return false;
            }
        }
    }

    return true;
}

bool check2(int i, int j) {
    if (i > puzzle.size() - 3 || j > puzzle[i].size() - 3) {
        return false;
    }

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (puzzle[i + k][j + l] != XMAS2[k][l] && XMAS2[k][l] != '.') {
                return false;
            }
        }
    }

    return true;
}

bool check3(int i, int j) {
    if (i > puzzle.size() - 3 || j > puzzle[i].size() - 3) {
        return false;
    }

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (puzzle[i + k][j + l] != XMAS3[k][l] && XMAS3[k][l] != '.') {
                return false;
            }
        }
    }

    return true;
}

bool check4(int i, int j) {
    if (i > puzzle.size() - 3 || j > puzzle[i].size() - 3) {
        return false;
    }

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (puzzle[i + k][j + l] != XMAS4[k][l] && XMAS4[k][l] != '.') {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    while (!in.eof()) {
        string line;
        getline(in, line);
        puzzle.push_back(line);
    }

    int nrWords = 0;
    for (int i = 0; i < puzzle.size(); i++) {
        for (int j = 0; j < puzzle[i].size(); j++) {
            nrWords += check1(i, j) ? 1 : 0;
            nrWords += check2(i, j) ? 1 : 0;
            nrWords += check3(i, j) ? 1 : 0;
            nrWords += check4(i, j) ? 1 : 0;
        }
    }

    cout << nrWords;

    return 0;
}