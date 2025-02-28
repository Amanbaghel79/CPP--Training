#include<stdio.h>
#include<string.h>
// int string_length(char *str) {
//     // Base case: when we reach the null terminator, return 0
//     if (*str == '\0') {
//         return 0;
//     }
//     // Recursive case: increment the length by 1 and move to the next character
//     return 1 + string_length(str + 1);
// }

int main(){
//    printf("%d \n",4);
//    printf("%f \n",4.1588888888);
//    printf("%lf \n",3.15123456789); 
//    printf("%x \n",3.123);// this will convert the no. in lowercase hexadecimal
//    printf("%X \n",3.123);// this will convert the no. in uppercase hexadecimal
//    printf("%u \n", 45);
    //   printf("%e",9.8);
    //   printf("%E",9.8); //for scientific notation
    //   printf("%g",24123);

    //  printf("abc\0xyz");



     //--------- Modifiers for Width and Precision-------------:
//1.Field Width
//Syntax: %<width>specifier
   //printf("%5d \n", 42);

// 2.Precision:
// Syntax: %.<precision>specifier
   //printf("%.4f \n", 3.14159);

// 3.Field Width with Precision
// Syntax: printf("%<width>.<precision>f", value);
//    printf("%10.2f", 3.14159); //→ 3.14 (field width 6, precision 2)
//NOTE IF WE ADD '-' SIGN THEN SPACE WILL BE ADDED ON THE RIGHT SIDE.
//    printf("%-10.2f", 3.14159);

//find length of the string without using the loops.
//  char str[]="hello world";
//  int len=string_length(str);
//  printf("Length of the string: %d\n", len);


//------------strstr-------------
  char *haystack = "Hello, World!";
  char *needle = "World";
 
 // Find the first occurrence of "World" in "Hello, World!"
 char *result = strstr(haystack, needle);
 
 if (result != NULL) {
     printf("Substring found: %s\n", result);  
 } else {
     printf("Substring not found.\n");
 }


 //--------strtok------------
 char str[] = "Hello, World! Welcome to C programming.";
 char *token;

 // Get the first token
 token = strtok(str, " ,.!");

 while(token != NULL) {
     printf("%s\n", token);  // Print each token
     token = strtok(NULL, " ,.!");  // Get the next token
 }

 //---------strcpy--------------
 char src[] = "Hello, World!";
 char dest[50];  

 strcpy(dest, src);

 printf("Source: %s\n", src);
 printf("Destination: %s\n", dest);
}


// ------FORMATE SPEIfIERS-----

// %d or %i--	Integer (decimal) --	printf("%d", 42); → 42
// %f--	Floating point number (decimal) --	printf("%f", 3.14159); → 3.141590
// %lf--	Double precision floating point number --	printf("%lf", 3.14159); → 3.141590
// %c--	Character --	printf("%c", 'A'); → A
// %s--	String (a sequence of characters) --	printf("%s", "Hello"); → Hello
// %u--	Unsigned integer --	printf("%u", 42); → 42
// %x or %X--	Hexadecimal integer (lowercase/uppercase) --	printf("%x", 255); → ff (lowercase)
// %o--	Octal number --	printf("%o", 8); → 10
// %p--	Pointer address	-- printf("%p", ptr); → 0x7ffee62dbe30
// %%--	Prints a literal percent sign % --	printf("%%"); → %

