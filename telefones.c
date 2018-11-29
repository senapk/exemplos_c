#include <stdio.h>
#include <string.h>

#define MAX_FONES 10

typedef struct{
    char id[10];
    char number[15];
} Fone;

typedef struct{
    char name[20];
    Fone fones[MAX_FONES];
    int  qtd_fones;
    char email[30];
} Contact;

Contact contact_create(const char * name, const char * email){
    Contact cont;
    cont.qtd_fones = 0;
    strcpy(cont.name, name);
    strcpy(cont.email, email);
    return cont;
} 
void contact_add_fone(Contact * cont, Fone fone){
    if(cont->qtd_fones < MAX_FONES){
        cont->fones[cont->qtd_fones] = fone;
        cont->qtd_fones += 1;
    }
}
void contact_show(Contact * cont){
    printf("{nome:%s}{mail:%s}", cont->name, cont->email);
        for(int i = 0; i < cont->qtd_fones; i++)
            printf("[%s:%s]", cont->fones[i].id, cont->fones[i].number);
    printf("\n");
}

int main(){
    Contact icaro = contact_create("Icaro Caminha", "caminha@gmail.com");
    contact_add_fone(&icaro, (Fone){"oi", "8888"});
    contact_add_fone(&icaro, (Fone){"tim", "9999"});
    contact_add_fone(&icaro, (Fone){"vivo", "7777"});
    contact_show(&icaro);
}