#include <stdio.h>
#include <ctype.h>
#include "utils.h"

int main() {

 char ch[24];
 printf("Digite o nome do cliente apenas utilizando letras\n");
 fgets(ch,sizeof(ch),stdin);
 int i = 0;
 while(ch[i] != NULL){
      if (!isalpha(ch[i]) && ch[i] != '\n' && ch[i] != '\0' && ch[i] != ' ') {
        printf("'%c' Não é uma letra\n", ch[i]);
      }
    }
 return 0;
}
