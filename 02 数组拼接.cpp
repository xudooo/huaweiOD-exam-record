/* 数组拼接 */

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

bool checkEmpty(vector<queue<int>> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (!vec[i].empty()) {
            return false;
        }
    }
    return true;
}

int main() {
    int len;
    int numsOfQueues;
    vector<queue<int>> vec;
    vector<int> res;

    cin >> len >> numsOfQueues;
    for (int i = 0; i < numsOfQueues; ++i) {
        string str;
        string tmp;
        queue<int> q;
        cin >> str;
        stringstream ss(str);
        while (getline(ss, tmp, ',')) {
            q.push(atoi(tmp.c_str()));
        }
        vec.emplace_back(q);
        while (!q.empty()) {
            q.pop();
        }
    }

    while (!checkEmpty(vec)) {
        for (int i = 0; i < numsOfQueues; ++i) {
            for (int j = 0; j < len; ++j) {
                if (!vec[i].empty()) {
                    res.emplace_back(vec[i].front());
                    vec[i].pop();
                }
            }
        }
    }

    for (int i = 0; i < res.size() - 1; ++i) {
        cout << res[i] << ",";
    }
    cout << res[res.size() - 1] << endl;
}