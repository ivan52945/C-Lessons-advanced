#include <stdio.h>
#include <stdint.h>

struct pack_array {
    uint32_t array;
    uint32_t count0 : 8;
    uint32_t count1 : 8;
};

void array2struct(int arr[], struct pack_array* pack_array_s)
{
    pack_array_s->array = 0;
    pack_array_s->count1 = 0;

    int n = sizeof(pack_array_s->array) * 8;

    for(int i = 0; i < n; ++i){
        pack_array_s->array += arr[i] << (n - i - 1);
        pack_array_s->count1 += arr[i];
    }

    pack_array_s->count0 = n - pack_array_s->count1;
}

int main(void) {
    int arr[32];

    struct pack_array pack_array_s = {0};

    for(int i = 0; i < (sizeof(arr) / sizeof(arr[0])); ++i)
        scanf("%d", (int*)(arr) + i);

    array2struct(arr, &pack_array_s);

    printf("%u %u %u", pack_array_s.array, pack_array_s.count0, pack_array_s.count1);

    return 0;
}
