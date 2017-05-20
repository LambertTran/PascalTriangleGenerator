/*
 * This program asks user to input number of lines of pascal user
 * want to print. Then, print half of pascal triangle with corressponding
 * number of lines
 */



#include <stdio.h>

void PRINT_PASCAL(int row);

void GEN_PASCAL_MATRIX(int row);



int main() {

   /*
    * Ask user to input then generate a pascal triangle
    */

   int row;

   printf("Please enter how many levels of Pascal's Triangle
           you would like to see: ");

   scanf("%d",&row);

   GEN_PASCAL_MATRIX(row);

   return 0;
}


void GEN_PASCAL_MATRIX(int row) {

   int i,j;
   int A[1000][1000];

   //Initialize the first row
   A[0][0]=1;

   for (j=1;j < row; ++j) {

      A[0][j]=0;
   }

   /*
    * Consider a square matrix [row x row]
    * Set the first and the last number in a row equal to 1
    * Calculate numbers between first and last number in a row by
    *    adding 2 numbers from previous row
    */

   for (i=1; i<row; ++i) {

   // first number in every row equal to 1
      A[i][0] = 1;

      for (j=1; j<row; ++j) {

         if (j<i) {

            A[i][j] = A[i-1][j-1] + A[i-1][j];
         }
         else if (j==i) {

            A[i][j] = 1;
         }
         else if (j>i){

            A[i][j] = 0;
         }

     }

   }

   /*
    * Print pascal triangle
    */

   for (i=0;i<row;++i) {
      for (j=0;j<row;++j) {

         if (j<=i) {

            printf("%d",A[i][j]);

            if ( j<i) {

	       printf(" ");
	    }
	 }

      }
      printf("\n");
   }
}
