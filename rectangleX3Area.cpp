// 三個矩形，找交集面積
#include <cmath>
#include <iostream>
using namespace std;

struct point {
    long long int x;
    long long int y;
};

int main() {
    point tri1[2];
    point tri2[2];
    point tri3[2];
    cin >> tri1[0].x >> tri1[0].y >> tri1[1].x >> tri1[1].y;
    cin >> tri2[0].x >> tri2[0].y >> tri2[1].x >> tri2[1].y;
    cin >> tri3[0].x >> tri3[0].y >> tri3[1].x >> tri3[1].y;
    long long int left_max = max(tri1[0].x, max(tri2[0].x, tri3[0].x));
    long long int right_min = min(tri1[1].x, min(tri2[1].x, tri3[1].x));
    long long int bottom_max = max(tri1[0].y, max(tri2[0].y, tri3[0].y));
    long long int top_min = min(tri1[1].y, min(tri2[1].y, tri3[1].y));
    if ((right_min - left_max <= 0) || (top_min - bottom_max <= 0)) {
        cout << "0";
    } else {
        cout << (right_min - left_max) * (top_min - bottom_max);
    }

    return 0;
}