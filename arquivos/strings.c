#include <stdio.h> //printf
#include <string.h> //strsep - se compilar na mão precisa do -std=gnu99
#include <stdlib.h> //strtol - converter string para int
int main(){
    char line[] = "david sena;33;rua joao melo;70";
    
    char fullname[30], street[30];
    int age = 0, number = 0;

    char * token;
    char * data = line;
    token = strsep(&data, ";"); //david sena
    strcpy(fullname, token);

    token = strsep(&data, ";"); //33
    age = (int) strtol(token, NULL, 10);//converte para inteiro na base 10

    token = strsep(&data, ";");//rua joao melo
    strcpy(street, token);

    token = strsep(&data, ";");//70
    number = (int) strtol(token, NULL, 10);//converte para inteiro na base 10

    printf("nome: %s\nidade: %d\nendereco: %s\nnumero: %d\n", fullname, age, street, number);
}