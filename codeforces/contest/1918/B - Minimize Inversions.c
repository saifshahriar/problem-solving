#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair*)a)->first - ((Pair*)b)->first;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        Pair ab[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &ab[i].first);
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d", &ab[i].second);
        }

        qsort(ab, n, sizeof(Pair), compare);

        for (int i = 0; i < n; ++i) {
            printf("%d ", ab[i].first);
        }
        printf("\n");

        for (int i = 0; i < n; ++i) {
            printf("%d ", ab[i].second);
        }
        printf("\n");
    }

    return 0;
}
