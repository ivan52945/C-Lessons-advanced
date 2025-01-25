#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint32_t mantissa : 23;
    uint32_t exp : 8;
    uint32_t s : 1;
}float_struct_t;

int main(void) {
    float num;
    scanf("%f", &num);

    float_struct_t* p = &num;

    printf("%d\n", p->exp);

    return 0;
}
