#include <stdio.h>
#include <stdint.h>

uint32_t get_mask(uint32_t n_bits)
{
    uint32_t mask = (1 << n_bits) - 1;

    return mask;
}

uint32_t find_max_sec_bits(uint32_t num, uint32_t n_bits)
{
    uint32_t max = 0;

    uint32_t mask = get_mask(n_bits);

    for(int i = 0; i <= (sizeof(uint32_t) * 8 - n_bits); i++){
        uint32_t sec_bits = (num & (mask << i)) >> i;

        if(sec_bits > max){
            max = sec_bits;
        }
    }

    return max;
}

int main(void) {
    uint32_t num, n_bits;

    scanf("%u %u", &num, &n_bits);

    uint32_t max = find_max_sec_bits(num, n_bits);

    printf("%u", max);

    return 0;
}