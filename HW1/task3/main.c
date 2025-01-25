#include <stdio.h>
#include <stdint.h>


uint32_t cyclic_shift_right(uint32_t num, uint32_t shift)
{
    uint32_t copy = num;

    uint32_t right_part = num >> shift;

    uint32_t left_part = copy << (sizeof(uint32_t) * 8 - shift);

    return left_part + right_part;
}

int main(void) {
    uint32_t num, shift;

    scanf("%u %u", &num, &shift);

    uint32_t res = cyclic_shift_right(num, shift);

    printf("%u", res);

    return 0;
}
