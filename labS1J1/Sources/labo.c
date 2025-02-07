#include "labo.h"

char* sousTexte(char* texte, int from, int to)
{
    static char sousTab[64] = { 0 };

    for (int i = from; i < to; i++) {
        sousTab[i - from] = texte[i];
    }
    return sousTab;
}

void set_String(char* text, String* s)
{
    for (int i = 0; text[i] != 0; i++) {
        s->characters[i] = text[i];
    }
    s->length = strlen(text);
}

int String_is_palindrome(String* s)
{
    int palindrome = 0;

    for (int i = 0; i < s->length; i++) {
        if (s->characters[i] != s->characters[s->length]) {
            palindrome++;
        }
    }

    if (palindrome == s->length) {
        return 1;
    }
    else {
        return 0;
    }
}

void bubbleSort(int elements[], int n)
{
    int temp = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
             if (elements[j] > elements[j+1]) {
                temp = elements[j];
                elements[j] = elements[j+1];
                elements[j+1] = temp;
            }
        }
    }
}
