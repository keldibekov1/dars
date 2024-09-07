#include <stdio.h>
#include <stdlib.h>



int main() {
    system("cls");

    FILE *fayl = fopen("royxat.txt", "w");

    char name[64]="";
    scanf("%[^\n]", name);
    fprintf(fayl, name);


    return 0;
}