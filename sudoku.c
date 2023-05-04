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
  for(int i = 0; i < 9; i ++)
    {
      if (n->sudo[0][i]==n->sudo[0][0])
      {
        return 0;
      }
    }
  for(int j = 0; j < 9; j++)
    {
      if(n->sudo[j][0]==n->sudo[0][0])
        return 0;
    }
   int k=4,p; 
    for(p=0;p<9;p++){
        int i=3*(k/3) + (p/3) ;
        int j=3*(k%3) + (p%3) ;
        //printf("%d ",nodo->sudo[i][j]);
        //if(p%3 == 2) printf("\n");
        if(n->sudo[i][j]==n->sudo[0][0])
          return 0;
    }
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int i, j, num;
    for(i=0; i < 9; i++)
      {for(j=0;j<9;j++)
        {
          if(n->sudo[i][j] ==0){
            for(num = 1; num <= 9; num++)
              {
                Node *adyacente=copy(n);
                adyacente->sudo[i][j]=num;
                pushBack(list, adyacente);
              }
            return list;
          }
        }
        
      }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
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