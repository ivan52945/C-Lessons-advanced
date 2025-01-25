#include <stdio.h>

int main(void) {
    int n, in;
    scanf("%d", &n);
    int res = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &in);
        res ^= in;
    }

    printf("%d", res);
    return 0;
}
