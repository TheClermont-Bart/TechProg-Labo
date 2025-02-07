#include <stdio.h>
#include <string.h>

size_t strlen(char* str){
    size_t i = 0;
    while(str[i] != '\0'){
        ++i;
    }
    return i;
}

//Main fourni à titre d'exemple
int main()
{
   char* str = "Hello this is a test";
   char* find = "test";
   static char sub[128] = {0};
    size_t len = strlen(str);
   while(1){
       int i = 0;
       while(str[i] != ' '){
           sub[i] = str[i];
           if(strlen(sub) >= len){
               break;
           }
           ++i;
       }
       str = &str[i];
       if(strcmp(sub,find) == 0){
           printf("Found\n");
       }
       if(i > len || str[1] == '\0'){
           break;
       }
   }
    return 0;
}
