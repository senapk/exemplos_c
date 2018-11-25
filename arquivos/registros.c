#include <stdio.h>
#include <stdlib.h> //strtol
#include <string.h> //strsep

typedef struct{
    char fullname[30];
    int age;
} Person;

void load_vector(Person * vet, int *size){
    char line[100];
    FILE * file = fopen("pessoas.txt", "r");
    fgets(line, sizeof(line), file);
    *size = (int) strtol(line, NULL, 10);//pegando primeira linha : qtd de pessoas
    for(int i = 0; i < (*size); i++){
        fgets(line, sizeof(line), file);
        char * token = NULL, * data = line;
        token = strsep(&data, ";");//pegando o nome
        strcpy(vet[i].fullname, token);
        token = strsep(&data, "\n");//apontando para a idade
        vet[i].age = (int) strtol(token, NULL, 10); //transformando em int e salvando
    }
    fclose(file);
}
void save_vector(Person * vet, int size){
    FILE * file = fopen("pessoas.txt", "w");
    fprintf(file, "%d\n", size);
    for(int i = 0; i < size; i++)
        fprintf(file, "%s;%d\n", vet[i].fullname, vet[i].age);
    fclose(file);
}

int main(){
    Person vet[100];
    int size = 0;
    char temp[100];
    load_vector(vet, &size);
    for(int i = 0; i < size; i++)
        printf("%d nome: %s, idade: %d\n", i, vet[i].fullname, vet[i].age);
    Person p;
    printf("Digite nome:");
    fgets(p.fullname, sizeof(p.fullname), stdin);
    p.fullname[strlen(p.fullname) - 1] = '\0';//jogar o enter fora
    printf("Digite idade:");
    fgets(temp, sizeof(temp), stdin);
    p.age = (int) strtol(temp, NULL, 10);
    vet[size] = p;
    size += 1;
    save_vector(vet, size);
}