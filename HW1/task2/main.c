#include <stdio.h>

int main(void) {
    int div;
    scanf("%d ", &div);

    char c = 0;
    while(1){
        scanf("%c", &c);

        if(c == '.')
            break;

        if(c >= 'a' && c <= 'z')
            c = ((c - 'a' + div) % 26) + 'a';
        if(c >= 'A' && c <= 'Z')
            c = ((c - 'A' + div) % 26) + 'A';

        printf("%c", c);
    }
    printf(".\n", c);
    return 0;
}
