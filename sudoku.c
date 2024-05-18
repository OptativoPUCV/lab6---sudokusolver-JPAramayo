#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

    return 1;
}

bool first_empty(Node* n, int* pos_i, int* pos_j) {
   int i, j;
   for(i = 0 ; i < 9 ; i++) {
       for(j = 0 ; j < 9 ; j++) {
          if(n->sudo[i][j] == 0) {
             *pos_i = i;
             *pos_j = j;
             return true;
          }
       }
   }
   return false;
}

bool is_in_row_col(Node* n, int pos_i, int pos_j, int k) {
   int i;
   for(i = 0 ; i < 9 ; i++) {
      if(n->sudo[i][pos_j] == k) return true;
      if(n->sudo[pos_i][i] == k) return true;
   }
   return false;
}

bool is_in_3x3(Node* n, int pos_i, int pos_j, int k) {
   int i,j;
   int lim_inf_i = pos_i - pos_i % 3;
   int lim_inf_j = pos_j - pos_j % 3;

   for(i = lim_inf_i ; i < 3  ; i++) {
      for(j = lim_inf_j ; j < 3 ; j++) {
         if(n->sudo[i][j] == k) return true;
      }
   }
   return false;
}

List* get_adj_nodes(Node* n){
   List* list=createList();
   int i,j;
   if (first_empty(n,&i,&j)) {
      Node* adj = createNode();
      for(int k = 1 ; k <= 9 ; k++) {
         if (is_in_row_col(n,i,j,k) || is_in_3x3(n,i,j,k))
            continue;
         adj->sudo[i][j] = k;
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