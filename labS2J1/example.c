
int main(int argc, char** argv){

    int n = 100; // O(1)

    for(int i=0; i < n; ++i){ // O(n)
        printf("This is something");

        for(int y =0; y < n; ++y){ // O(n)
            printf("Ahhhh something constant");
        }
    }
} 
// O(1)+[O(n)+O(n)]= O(n^2) ( Le O(1) s'annule et etant donne que l'ont retrouve O(n) dans une boucle O(n) celle si devient O(n^2)