#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
struct Point {
    int x, y;
};

// Function to find the orientation of three points
int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to check if a point lies on a segment
int onSegment(struct Point p, struct Point q, struct Point r) {
    if (r.x <= fmax(p.x, q.x) && r.x >= fmin(p.x, q.x) &&
        r.y <= fmax(p.y, q.y) && r.y >= fmin(p.y, q.y))
        return 1;
    return 0;
}

// Function to check if two segments intersect
int doIntersect(struct Point p1, struct Point q1, struct Point p2, struct Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return 1;

    if (o1 == 0 && onSegment(p1, q1, p2)) return 1;
    if (o2 == 0 && onSegment(p1, q1, q2)) return 1;
    if (o3 == 0 && onSegment(p2, q2, p1)) return 1;
    if (o4 == 0 && onSegment(p2, q2, q1)) return 1;

    return 0;
}

// Function to check if a point lies inside a convex polygon using ray-casting
int isInside(struct Point polygon[], int n, struct Point p) {
    if (n < 3) return 0;

    struct Point extreme = {10000, p.y};
    int count = 0, i = 0;
    do {
        int next = (i + 1) % n;
        if (doIntersect(polygon[i], polygon[next], p, extreme)) {
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], p, polygon[next]);
            count++;
        }
        i = next;
    } while (i != 0);

    return count % 2;
}

int main() {
    int n;
    printf("Enter number of points in the convex polygon: ");
    scanf("%d", &n);

    struct Point polygon[n];
    printf("Enter the points (x y) of the convex polygon:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &polygon[i].x, &polygon[i].y);
    }

    struct Point p;
    printf("Enter the point to check (x y): ");
    scanf("%d %d", &p.x, &p.y);

    if (isInside(polygon, n, p))
        printf("The point lies inside the convex polygon.\n");
    else
        printf("The point does not lie inside the convex polygon.\n");

    return 0;
}