#include <stdio.h>

unsigned int count_seted_bits(unsigned int num)
{
    int count = 0;

    for(unsigned int i = num; i > 0; i = i & (i - 1))
        count += 1;

    return count;
}

int main(void) {
    unsigned int num, count;

    scanf("%d", &num);

    count = count_seted_bits(num);

    printf("%d\n", count);

    return 0;
}
