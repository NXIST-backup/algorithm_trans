#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HASHTABLE
{
    char **elem;
    int size;
} HASHTABLE;

void init(HASHTABLE *h)
{
    h->size = 200000;
    h->elem = (char **)malloc(sizeof(char *) * h->size);
    for (int i = 0; i < h->size; i++) {
        h->elem[i] = NULL;
    }
}

int hash(HASHTABLE *h, char value[])
{
    int code = 0;
    for (size_t i = 0; i < strlen(value); i++) {
        code = (code * 256 + value[i] + 128) % h->size;
    }
    return code;
}

int search(HASHTABLE *h, int *pos, int *times, char value[])
{
    *pos = hash(h, value);
    *times = 0;
    while (h->elem[*pos] != NULL && strcmp(h->elem[*pos], value) != 0) {
        (*times)++;
        if (*times < h->size) {
            *pos = (*pos + 1) % h->size;
        } else {
            return 0;
        }
    }
    if (h->elem[*pos] != NULL && strcmp(h->elem[*pos], value) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int insert(HASHTABLE *h, char value[])
{
    int pos, times;
    if (search(h, &pos, &times, value)) {
        return 2;
    } else if (times < (h->size) / 2) {
        h->elem[pos] = (char *)malloc(strlen(value) + 1);
        strcpy(h->elem[pos], value);
        return 1;
    } else {
        return 0;
    }
}

void clear(HASHTABLE *h)
{
    for (int i = 0; i < h->size; i++) {
        if (h->elem[i] != NULL) {
            free(h->elem[i]);
        }
    }
    free(h->elem);
    free(h);
}

void low_az(char *buffer)
{
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
            buffer[i] += 32;
        }
    }
}

int main()
{
    HASHTABLE *hash = (HASHTABLE *)malloc(sizeof(HASHTABLE));
    init(hash);
    int n;
    scanf("%d", &n);
    char buffer[100000];
    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        low_az(buffer);
        int ans = insert(hash, buffer);
        if (ans == 2) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}