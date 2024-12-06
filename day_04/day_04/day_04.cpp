#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream in("input.txt");

vector<string> puzzle;

string XMAS = "XMAS";

bool checkHorizontalLR(int i, int j) {
    if (j > puzzle[i].size() - 4) {
        return false;
    }
    
    for (int k = 0; k < 4; k++) {
        if (puzzle[i][j + k] != XMAS[k]) {
            return false;
        }
    }

    return true;
}

bool checkHorizontalRL(int i, int j) {
    if (j < 3) {
        return false;
    }

    for (int k = 0; k < 4; k++) {
        if (puzzle[i][j - k] != XMAS[k]) {
            return false;
        }
    }

    return true;
}

bool checkVerticalTB(int i, int j) {
    if (i > puzzle.size() - 4) {
        return false;
    }

    for (int k = 0; k < 4; k++) {
        if (puzzle[i + k][j] != XMAS[k]) {
            return false;
        }
    }

    return true;
}

bool checkVerticalBT(int i, int j) {
    if (i < 3) {
        return false;
    }

    for (int k = 0; k < 4; k++) {
        if (puzzle[i - k][j] != XMAS[k]) {
            return false;
        }
    }

    return true;
}

bool checkDiagonalTLBR(int i, int j) {
    if (i > puzzle.size() - 4 || j > puzzle[i].size() - 4) {
        return false;
    }

    for (int k = 0; k < 4; k++) {
        if (puzzle[i + k][j + k] != XMAS[k]) {
            return false;
        }
    }

    return true;
}

bool checkDiagonalTRBL(int i, int j) {
    if (i > puzzle.size() - 4 || j < 3) {
        return false;
    }

    for (int k = 0; k < 4; k++) {
        if (puzzle[i + k][j - k] != XMAS[k]) {
            return false;
        }
    }

    return true;
}

bool checkDiagonalBLTR(int i, int j) {
    if (i < 3 || j > puzzle[i].size() - 4) {
        return false;
    }

    for (int k = 0; k < 4; k++) {
        if (puzzle[i - k][j + k] != XMAS[k]) {
            return false;
        }
    }

    return true;
}

bool checkDiagonalBRTL(int i, int j) {
    if (i < 3 || j < 3) {
        return false;
    }

    for (int k = 0; k < 4; k++) {
        if (puzzle[i - k][j - k] != XMAS[k]) {
            return false;
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
            nrWords += checkHorizontalLR(i, j) ? 1 : 0;
            nrWords += checkHorizontalRL(i, j) ? 1 : 0;
            nrWords += checkVerticalTB(i, j) ? 1 : 0;
            nrWords += checkVerticalBT(i, j) ? 1 : 0;
            nrWords += checkDiagonalTLBR(i, j) ? 1 : 0;
            nrWords += checkDiagonalTRBL(i, j) ? 1 : 0;
            nrWords += checkDiagonalBLTR(i, j) ? 1 : 0;
            nrWords += checkDiagonalBRTL(i, j) ? 1 : 0;
        }
    }

    cout << nrWords;

    return 0;
}