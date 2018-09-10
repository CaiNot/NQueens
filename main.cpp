#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int n;
    vector<vector<string>> result;
    vector<string> ans;
    int count = 0;
    int *a;
public:
    vector<vector<string>> solveNQueens(int n) {
        int ansVec[n];
        this->a = ansVec;
        this->n = n;
        queens(0);
        return result;
    }

    int totalQueens(int n) {
        this->n = n;
        int ansVec[n];
        this->a = ansVec;
        this->countTotalQueens(0);
        return this->count;
    }

private:
    void countTotalQueens(int start) {
        if (start < this->n) {
            for (int i = 0; i < this->n; i++) {
                this->a[start] = i;
                if (!isConflic(start))
                    countTotalQueens(start + 1);
            }
        } else {
            this->count++;
        }
    }

    void queens(int k) {
        if (k < this->n) {
            for (int i = 0; i < n; i++) {
                this->a[k] = i;
                if (!isConflic(k)) {
                    queens(k + 1);
                }
            }
        } else {
            string temp = "";
            for (int i = 0; i < this->n; i++) {
                for (int j = 0; j < this->n; j++) {
                    if (this->a[i] == j) {
                        temp += "Q";
                    } else {
                        temp += ".";
                    }
                }
                ans.push_back(temp);
                temp = "";

            }
            result.push_back(ans);
            ans.clear();
        }
    }

    bool isConflic(int k) {
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < i; j++)
                if (a[i] == a[j] || (abs(a[i] - a[j]) == i - j)) {
                    return true;
                }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    cout << s.totalQueens(4) << endl;
//    auto result = s.solveNQueens(8);
//
//    for (int i = 0; i < result.size(); i++) {
//        cout << "[";
//        for (int j = 0; j < result[i].size(); j++) {
//            cout << result[i][j] << ",\n";
//        }
//        cout << "]\n";
//    }
    return 0;
}