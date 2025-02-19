#include<iostream>
using namespace std;
int main(){
char str[20];
int arr[5]={1,2,3,4,5};
int arr2[10];
int size=sizeof(arr);
int num;
 FILE *fptr;
 FILE *fbptr;
 fptr= fopen("sample.txt","w");
  fptr= fopen("sample.txt","r");
 fbptr=fopen("sample2.bin","wb");
 if(fbptr==NULL){
    printf("error");
    return 1;
 }

  int res=fwrite(arr,sizeof(int),size,fbptr);

 if(res!=size) printf("error");
 else printf("sucess");
 res=fread(arr2,sizeof(int),size,fbptr);

 if (res != size) {
    printf("Error reading from the file.\n");
} else {
    printf("Data read from binary file:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}



 if(fptr==NULL) {
    printf("error");
 }
    printf("enter a number");
    if (fscanf(fptr, "%s", str) != EOF) {
        // Output the string read from the file
        printf("String read from file: %s\n", str);
    } else {
        printf("Error reading from file.\n");
    }
    fprintf(fptr, "%s", str);
    printf("String read from file: %s\n", str);
    fclose(fptr);
    return 0;
 
   //Another way
//     // const char *s="aman baghel";
//     char s[10]={"aman"};
//     FILE *fptr;

//     // Open the file in write mode
//     fptr = fopen("sample.txt", "w");

//     if (fptr == NULL) {
//         printf("Error opening file.\n");
//         return 1; // return with error code if file cannot be opened
//     }
    
//     // Prompt the user for input
//     printf("Enter a string: ");
//     // cin >> s; // Use cin for reading input into a string

//     // Write the string to the file
//     fprintf(fptr, "%s", s); // Use .c_str() to get a C-style string

//     // Close the file after writing
//     fclose(fptr);

//     printf("String written to file successfully.\n");

//-----------fseek()----------//
fseek(fptr, 5, SEEK_SET);

  // Move the file pointer 10 bytes before the end of the file
  fseek(fptr, -10, SEEK_END);

    // Read an integer from the current file position
    fread(&num, sizeof(int), 1, fptr);

    printf("The number read from file: %d\n", num);


}