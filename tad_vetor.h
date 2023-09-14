#include <iostream>
#include <string.h>
typedef struct vetor {
	int* array;
	int qtde;
	int tam;
} Vetor;

Vetor* vet_criar(){
 Vetor* v = (Vetor*) malloc(sizeof(Vetor));
    v->qtde = 0;
    v->tam = 5;
    v->array = (int*) calloc(v->tam,sizeof(int));
      return v;
}

void vet_desalocar(Vetor* endVetor){
   free(endVetor);
    endVetor = NULL;
}   
bool vet_anexar(Vetor* v, int elemento){
if(v == NULL)return false;
    v->array[v->qtde] = elemento;
    if(v->qtde == v->tam){
        v->tam++;
    }
     v->qtde++;
     return true;
}
bool vet_inserir(Vetor* v, int elemento, int posicao){
   if(posicao > v->tam) return false;
     v->array[posicao-1] = elemento;
     v->qtde++;
       return true;
}
bool vet_substituir(Vetor* v, int posicao, int novoElemento){
    if(posicao > v->tam) return false;
     v->array[posicao] = novoElemento;
       return true;
}
bool vet_removerPosicao(Vetor* v, int posicao, int* endereco){
    if(posicao > v->tam) return false;
       endereco = &(v->array[posicao]);
        for(int i = posicao; i < v->qtde;i++){
              v->array[i] = v->array[i+1];
        }
        v->qtde--;
        return true;
}
int vet_removerElemento(Vetor* v, int elemento){
    int guardar = -1;
    int* pos = NULL;
     for(int i = 0; i < v->qtde; i++){
         if(v->array[i] == elemento ){
            guardar = i;
         }
     }
       if(guardar == -1){
          return -1;
       }else{
         vet_removerPosicao(v, guardar, pos);
       }
}
int vet_tamanho(Vetor* v){
    return v->qtde;  
}
bool vet_elemento(Vetor* v, int posicao, int* saida){
   if(posicao > v->tam) return false;
      for(int i = 0; i < v-> qtde; i++){
        if(i == posicao ){
           *saida = v->array[i];
            return true;
        }
      }
}
int vet_posicao(Vetor* v, int elemento){
  for(int i = 0; i < v->qtde; i++){
         if(v->array[i] == elemento ){
            return i;
         }
     }
     return -1;
}
void vet_imprimir(Vetor* v){
  for(int i = 0; i < v->qtde; i++){
      printf("%d", v->array[i]);
       if(i < v->qtde-1){
        printf(",");
       }
  }
}
bool vet_toString(Vetor* v, char* enderecoString){
  if(v == NULL)return false;
  char str[100];
   strcat(str,"[");
      for(int i = 0; i < v->qtde; i++){
            char temp[10];
            sprintf(temp,"%d",v->array[i]);
            strcat(str,temp);
            if(i+1<v->qtde){
              strcat(str,",");
            }
      }
      strcat(str,"]");
      strcpy(enderecoString,str);
      return true;
}
