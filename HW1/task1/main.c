#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int n_max;
} max_count_t;

/*

// хотел использовать этот ввод, но на последнем тесте оно отваливается, хз почему

void read_input(int* pa) {
    int n_items;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        fprintf(stderr,"Error: invalid input, expected any integer numbers\n");
        abort();
    }
}

*/

void count_max_n(max_count_t* max_count, int  num)
{
    if(num > max_count->max) {
        max_count->max = num;
        max_count->n_max = 1;
    }
    else if(num == max_count->max){
        max_count->n_max += 1;
    }
}

int main(void) {
    int n;
    int num;

    max_count_t max_count = {
        .max = -2147483648,
        .n_max = 0,
    };

    read_input(&n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        count_max_n(&max_count, num);
    }

    printf("%d\n", max_count.n_max);

    return 0;
}
