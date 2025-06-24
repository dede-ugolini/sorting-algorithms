#include <stdio.h>
#include <stdilib.h>
#include <string.h>

typedef struct {

  char nome
}

void removerQuebraLinha(char *str) {
    size_t len = strlen(str);
    if(len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
