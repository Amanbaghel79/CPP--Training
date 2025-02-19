
#include <stdio.h>
#include <stdlib.h> 
int main(){
   int n;
  int *ptr_malloc;
  printf("Enter a number ");
  scanf("%d",&n);
//Malloc returns a 'void *' void pointer 
//Memory block assign by Malloc contains garbage value by default
//if Malloc cant allocate memory it returns a NULL pointer

  ptr_malloc=(int *) malloc(n*sizeof(int));// snytax
  for(int i=0;i<5;i++){
    ptr_malloc[i]=i+1;
  }
  for(int i=0;i<5;i++){
    printf("%d",*(ptr_malloc+i));
  }

//   free(ptr_malloc);

  //Calloc
  //it also return void pointer
  // by default all memory block is initialised with the zero
  //it take two parameters no. of block and size

  int *ptr_calloc=(int*)calloc(5,sizeof(int)); 
  if (ptr_calloc==NULL) {
      printf("Memory allocation failed \n");
      return -1;
  }
  for (int i=0;i<5;i++) {
      printf("%d",ptr_calloc[i]);
  }
  printf("\n");
  free(ptr_calloc); 

  //realloc
  // used to resize the previously allocated memory block
  // it doesnt lost the previous data 
//---realloc works behind the scenes roughly like this----
// If there is enough free space behind the current block to fulfill the request, extend the current block and return a pointer to the beginning of the block.
// Else if there is a large enough free block elsewhere, then allocate that block, copy the data from the old block over, free the old block and return a pointer to the beginning of the new block
// Else report failure by returning NULL.
  ptr_malloc = (int*)realloc(ptr_malloc, 10 * sizeof(int));
  for(int i=5;i<10;i++){
    ptr_malloc[i]=i+1;
  }
  for(int i=0;i<10;i++) {
    printf("%d",*(ptr_malloc+i));
  }
  free(ptr_malloc);
}