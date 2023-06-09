#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int num1;
  int num2;
  int num3;
  for(int i = 0; i < 9; i++){
    int filas[10]={0,0,0,0,0,0,0,0,0,0};
    int colum[10]={0,0,0,0,0,0,0,0,0,0};
    for(int j = 0; j< 9; j++)
      {
        num1 = n -> sudo[i][j];
        if(num1!= 0){
          if(filas[num1]==0)
          {
            filas[num1] = 1;
          }
          else{
            return 0;
          }
        }
      num2 = n->sudo[j][i];
      if(num2!=0){
        if(colum[num2]==0){
          colum[num2]=1;
        }
        else{
          return 0;
          }
        }
     }
  }
  for(int i = 0; i < 9; i += 3) {
    for(int j = 0; j < 9; j += 3) {
      int valores[10] = {0,0,0,0,0,0,0,0,0,0};
      for(int l = i; l < i + 3; l++) {
        for(int k = j; k < j + 3; k++) {
          num3 = n->sudo[l][k];
          if(num3 != 0){
            if(valores[num3] == 1){
              return 0;
            }
            else{
              valores[num3] = 1;
            }
          }
        }
      }
    }
  }
  return 1;
}


List* get_adj_nodes(Node* n) {
    List* list = createList();
    int i, j, num;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (n->sudo[i][j] == 0) {
                for (num = 1; num <= 9; num++) {
                    Node* adyacente = copy(n);
                    adyacente->sudo[i][j] = num;
                    if (is_valid(adyacente)) {  
                        pushBack(list, adyacente);
                    } else {
                        pushBack(list,adyacente);
                        popBack(list);  
                    }
                }
                return list;
            }
        }
    }
    return list;
}


int is_final(Node* n){
  for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
        {
          if(n->sudo[i][j]==0)
          {
            return 0;
          }
        }
    }
    return 1;
}

Node* DFS(Node* initial, int* cont){
  Stack * S = createStack();
  push(S, initial);
  
  while (!is_empty(S))
  {
    Node *n = top(S);
    
    pop(S);
    (*cont)++;
      
    if(is_final(n))
    {
      return n;
    }
    
    List *lista = get_adj_nodes(n);
    Node *aux = first(lista);
    
    while(aux)
    {
      push(S, aux);
      aux = next(lista);
    }
    free(n);
  }
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/