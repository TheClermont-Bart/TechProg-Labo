#include <stdio.h>
#include <string.h>

size_t strlen(char* str){ // O(n)
    size_t i = 0; // O(1)
    while(str[i] != '\0'){ // O(n)
        ++i;
    }
    return i;
}

//Main fourni à titre d'exemple
int main()
{
   char* str = "Hello this is a test"; // O(1)
   char* find = "test"; // O(1)
   static char sub[128] = {0}; // O(1)
    size_t len = strlen(str); // O(n)
   while(1){ // O(1)
       int i = 0;
       while(str[i] != ' '){ // O(n)
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
} // O(n)
