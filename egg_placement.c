#include <stdio.h>
#include <math.h>
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));}
int can_place_eggs(int blue[][2], int red[][2], int N, double dist) {
    int i = 0, j = 0, count = 0;
    while (i < N && j < N) {
        if (distance(blue[i][0], blue[i][1], red[j][0], red[j][1]) >= dist) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }    }
    return count >= N;}
int main() {
    int N, B, R;
    scanf("%d %d %d", &N, &B, &R);
    int blue[B][2], red[R][2];
    for (int i = 0; i < B; i++) {
        scanf("%d %d", &blue[i][0], &blue[i][1]);
    }
    for (int i = 0; i < R; i++) {
        scanf("%d %d", &red[i][0], &red[i][1]);    }
    double low = 0, high = 10000;
    while (high - low > 1e-6) {
        double mid = (low + high) / 2;
        if (can_place_eggs(blue, red, N, mid)) {
            low = mid;
        } else {
            high = mid;
        }    }
    printf("%.6f\n", low);
    return 0;}