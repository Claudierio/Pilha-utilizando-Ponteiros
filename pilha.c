// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int info;
    struct pilha* prox; 
}Pilha;

Pilha* iniciarPilha(){
    return NULL;
}


Pilha* push(Pilha* inicio, int info){
    Pilha* pilhaaux = (Pilha*)malloc(sizeof(Pilha));
    if( inicio == NULL){
        pilhaaux->info = info;
        pilhaaux->prox = NULL;
        return pilhaaux;
    }else{
        pilhaaux->info = info;
        pilhaaux->prox =inicio;
        return pilhaaux;
    }
}

Pilha* pop(Pilha* inicio){
    if(inicio==NULL){
        return NULL;
    }else{
        if(inicio->prox == NULL){
            printf("\nInformação removida: %d\n", inicio->info);
            free(inicio);
            return NULL;
        }else{
            printf("\nInformação removida: %d\n", inicio->info);
            Pilha* aux = (Pilha*)malloc(sizeof(Pilha));
            aux = inicio->prox;
            free(inicio);
            return aux;
        }
    }
}

void ver(Pilha* inicio){
    if(inicio == NULL){
        printf("Pilha vazia\n");
    }else{
        while(inicio != NULL){
        printf("Info: %d\n", inicio->info);
        inicio = inicio->prox;
        }
    }
    
}


int main() {
    Pilha* inicio = (Pilha*)malloc(sizeof(Pilha));
    inicio = iniciarPilha();
    int opc, info;
    do{
        printf("Escolha uma opcao:: \n 1- push\n 2- pop \n 3 - ver \n 9- Sair");
        scanf("%d", &opc);
        if(opc == 1){
            printf("Informe um valor.\n");
            scanf("%d", &info);
            inicio = push(inicio, info);
        }else if (opc == 2){
            inicio = pop(inicio);
        }else if (opc == 3){
            ver(inicio);
        }
        
    }while(opc!= 9);
    return 0;
}