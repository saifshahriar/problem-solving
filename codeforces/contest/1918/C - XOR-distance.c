#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

const int maxb = 60;

int get_bit(int64_t a, int i) {
    return (a & (1ll << i)) != 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int64_t a, b, r;
        scanf("%" SCNd64 " %" SCNd64 " %" SCNd64, &a, &b, &r);
        int64_t x = 0;
        int first_bit = 1;
        if (a > b) {
            int64_t temp = a;
            a = b;
            b = temp;
        }
        for (int i = maxb - 1; i >= 0; --i) {
            int bit_a = get_bit(a, i);
            int bit_b = get_bit(b, i);
            if (bit_a != bit_b) {
                if (first_bit) {
                    first_bit = 0;
                } else {
                    if (!bit_a && x + (1ll << i) <= r) {
                        x += (1ll << i);
                        a ^= (1ll << i);
                        b ^= (1ll << i);
                    }
                }
            }
        }
        printf("%" PRId64 "\n", b - a);
    }

    return 0;
}
