#include<iostream>
using namespace std;
void increment(int *x){
    *x=*x+1;
}
void fun(int arr[]){
    int i=0;
    // int size=sizeof(arr)/sizeof(arr[0]);
    //this is giving error because in function argument is taken as a pointer (int *arr)
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int *ptr;
    int x=5,y=7;
    ptr= &x;
    cout<<ptr<<" ";
    cout<<*ptr<<" "<<endl;
    *ptr=y;
    cout<<ptr<<" ";
    cout<<*ptr;


// ----2---- typecasting int pointer to char pointer
  int *ptr1;
   x=1025;
  ptr1=&x;
  cout<<"size of the pointer "<<sizeof(*ptr1)<<" ";
  cout<<"value at int pointer "<<*ptr1<<endl;
  char *ptr2;
  ptr2= (char*)ptr1;
  cout<<ptr2<<" ";
  cout<<"size of the pointer "<<sizeof(*ptr2)<<" ";
  cout<<"value at char pointer"<<(ptr2+1);



// -------3------ Void pointer 
//Void Pointer (void*) is a pointer that can point to any data type.
// It is used where the type of data is unknown.
// Void pointers can’t be used with pointer arithmetic directly and cannot be dereferenced without type casting.
int a = 10;
float b = 5.5;

// Declare void pointers
void* ptr3 = &a;  // Point to int
void* ptr4 = &b;  // Point to float

// To dereference and print values, we need to cast the void pointer to the appropriate type
cout << "Value of a: " << *(int*)ptr3 << endl;
cout << "Value of b: " << *(float*)ptr4 << endl;



// ------4------ pointer as function arguments
 a=5;
// cout<<a<<endl;
cout<<&a<<endl;
increment(&a);
cout<<a;



// -----5----- pointer array
int arr[]={1,2,3,4,5};
cout<<arr<<" ";// points to the address of index first.
cout<<arr[0]<<" ";
cout<<&arr[0]<<" ";
cout<<*arr<<" ";//gives the value at index first.

for(int i=0;i<5;i++){
    cout<<*(arr+i)<<" ";
}

//  arr=arr+1; // invalid....because arr is a const pointer we can't change its value.
// arr++ inavlid operation.



// -------6------ arrays as function arguments

  fun(arr);
  int size=sizeof(arr)/sizeof(arr[0]);
  cout<<size;


//---------7--------- const pointer
//i--- point to const
a=5;
 int c=4;
const int* ptr5=&a;
// *ptr5=7 ;// invalid operation as the pointer points to the constant variable
  ptr5 = &c; //valid

//ii----const pointer
int const *ptr6;

//iii----- const pointer to const data
const int const *ptr7;


// ----ex-01-----
 x = 5 ;
 y=6;
const int *ptra = &x ;
int *const ptrb = &x ;
const int * const ptre = &x ;
// *ptra=5 // invalid
// ptra=&y; //valid
// *ptrb=7;//valid
// ptrb=&y// invalid


//--ex-02------
 x = 5 ;
const int &ref_x2 = x ;
//  int &r2 = ref_x2; //invalid we cant bind a 'int &' type with 'const int;
 const int &res=ref_x2; //valid


 //---ex-03-----
  x=5;
 const int *ptrc = &x ;
 int *const ptrd = &x ;

// int *&p_ref1 = ptrc ;// invalid as 'int *' cant bind with the 'cont int *'
// const int*&p_ref2 = ptrd ; //invalid becoz ptr2 is of type 'int * const'
}