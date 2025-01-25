#include <stdio.h>
#include <stdint.h>

uint32_t get_mask(uint32_t num, uint32_t n_jun_bits)
{
    uint32_t mask = (1 << n_jun_bits) - 1;

    return num & mask;
}

uint32_t main(void) {
    uint32_t num, n_jun_bits;

    scanf("%u %u", &num, &n_jun_bits);

    uint32_t res = get_mask( num,  n_jun_bits);

    printf("%u", res);

    return 0;
}
