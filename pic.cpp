#include <string.h>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int row, cols;
    cin >> row >> cols;
    vector<vector<int>> table(row, vector<int>(cols, 0));

    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> table[i][j];
            sum += table[i][j];
        }
    }
    if (sum % (row * cols) != 0) {
        cout << "-1" << endl;
    } else {
        int average = sum / (row * cols);
        queue<pair<pair<int, int>, pair<int, int>>> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                if (table[i][j] > average) {
                    q.push({{i, j}, {i, j}});
                }
            }
        }

        int total = 0;
        while (!q.empty()) {
            pair<pair<int, int>, pair<int, int>> tmp = q.front();
            q.pop();
            // cout << i++ << endl;
            if (tmp.second.first < 0 || tmp.second.first >= row ||
                tmp.second.second < 0 || tmp.second.second >= cols) {
            } else {
                int x = tmp.second.first;
                int y = tmp.second.second;
                int orginx = tmp.first.first;
                int orginy = tmp.first.second;
                if (table[x][y] < average) {
                    int mins = average - table[x][y];
                    int plus = table[orginx][orginy] - average;
                    if (plus >= mins) {
                        table[orginx][orginy] -= mins;
                        table[x][y] += mins;
                        total += (abs(orginx - x) + abs(orginy - y)) * mins;
                    } else {
                        table[orginx][orginy] -= plus;
                        table[x][y] += plus;
                        total += (abs(orginx - x) + abs(orginy - y)) * plus;
                    }
                }
                q.push({{orginx, orginy}, {x + 1, y}});
                q.push({{orginx, orginy}, {x - 1, y}});
                q.push({{orginx, orginy}, {x, y + 1}});
                q.push({{orginx, orginy}, {x, y - 1}});

                int keep = 0;
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (table[i][j] != average)
                            keep = 1;
                    }
                }
                if (!keep)
                    break;
            }
        }
        cout << total << endl;
        /*int a;
        cin >> a;*/
    }
}