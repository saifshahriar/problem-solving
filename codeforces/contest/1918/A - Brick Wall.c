#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        // Calculate the maximum stability
        int max_stability = (m / 2) * n;
        printf("%d\n", max_stability);
    }

    return 0;
}
