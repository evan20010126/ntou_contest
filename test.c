#include <stdio.h>

int main() {
    long long int w, x, y, t, d;
    scanf("%lld %lld %lld %lld %lld", &w, &x, &y, &t, &d);
    --d;
    int count_day = 0;
    // // 先七天七天跳
    long long int week_reduce = -(6 * y - x);

    count_day = (t - w) / week_reduce;
    if (count_day > 4) {
        count_day -= 2;
        w = w + week_reduce * count_day;
        count_day *= 7;

    } else {
        count_day = 0;
    }

    while (w > t) {
        if ((d % 7) != 6)
            w -= y;
        else
            w += x;
        ++d;
        ++count_day;
    }
    printf("%d", count_day);
    return 0;
}