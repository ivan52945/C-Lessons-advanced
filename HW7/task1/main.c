#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_t {
    char word[20];
    struct  list_t* next;
} list_t;

void add_list(list_t** begin, char str[])
{
    list_t* p = calloc(1, sizeof(list_t));
    strcpy(p->word, str);
    p->next = *begin;
    *begin = p;
}

void print_list(list_t* begin)
{
    for (list_t* p = begin; p != NULL; p = p->next) {
        printf("%s ", p->word);
    }

    puts("\n");
}

void swap_elements(list_t* p1, list_t* p2)
{
    char tmp[20];
    strcpy(tmp, p1->word);
    strcpy(p1->word, p2->word);
    strcpy(p2->word, tmp);
}

void delete_list(list_t** begin)
{
    list_t* iterator = *begin;

    while (iterator != NULL) {
        list_t* delete = iterator;
        iterator = iterator->next;
        free(delete);
    }

    *begin = NULL;
}

void sort_list(list_t* begin)
{
    for (list_t* p_i = begin; p_i->next != NULL; p_i = p_i->next)
        for (list_t* p_j = p_i->next; p_j != NULL; p_j = p_j->next) {
            if (strcmp(p_i->word, p_j->word) > 0)
                swap_elements(p_i, p_j);
        }
}

int main(void)
{
    char str[20];
    list_t* begin = NULL;
    int is_not_end = 1;

    while (is_not_end) {
        scanf("%s", str);
        char* point;
        if ((point = strchr(str, '.')) != NULL) {
            is_not_end = 0;
            *point = '\0';
        }
        add_list(&begin, str);
    }

    sort_list(begin);

    print_list(begin);


    delete_list(&begin);

    return 0;
}
