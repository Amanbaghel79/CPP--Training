//structure as pointer memebers

#include <stdio.h>
#include <stdlib.h>  

struct Student {
    int *id;        
    char *name;     
    float *marks;  
};
union abc{
    int a;
    int b;
};
int main() {
   struct Student student1;
    student1.id = (int*)malloc(sizeof(int));         
    student1.name = (char*)malloc(50 * sizeof(char)); 
    student1.marks = (float*)malloc(sizeof(float));   

    *student1.id = 101;               
    student1.name = "John Doe";        
    *student1.marks = 89.5;       


    printf("Student ID: %d\n", *student1.id);
    printf("Student Name: %s\n", student1.name);
    printf("Student Marks: %.2f\n", *student1.marks);

    free(student1.id);
    free(student1.marks);

   //Size of the union is the size of the largest data type
   
    union abc var;
    var.a=5;
    var.b=4;
    union abc *ptr=&var;
    printf("union a: %d\n", ptr->a);
    printf("unoin b: %d\n", ptr->b);
    return 0;
}
