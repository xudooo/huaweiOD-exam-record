/* 磁盘容量排序 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int calCap(const string &str) {
    int cap = 0;
    int tmp = 0;
    int left = 0, right = 0;
    while (right < str.length()) {
        tmp = atoi(str.substr(left, right - left).c_str());
        if (str[right] == 'M') {
            left = right + 1;
        }
        else if (str[right] == 'G') {
            tmp *= 1024;
            left = right + 1;
        }
        else if (str[right] == 'T') {
            tmp *= 1024 * 1024;
            left = right + 1;
        }
        cap += tmp;
        ++right;
    }
    return cap;
}

bool compCap(const string &str1, const string &str2) {
    return calCap(str1) < calCap(str2);
}

int main() {
    int n;
    vector<string> disks;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string disk;
        cin >> disk;
        disks.emplace_back(disk);
    }

    sort(disks.begin(), disks.end(), compCap);
    for (auto &disk : disks) {
        cout << disk << endl;
    }
    return 0;
}

/* PASS 90%，不知道具体case，可能是没注意顺序问题？ */