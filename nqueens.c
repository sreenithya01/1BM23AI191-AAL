#include<stdio.h>
#define BOARD_SIZE 5
void displayChess(int chBoard[BOARD_SIZE][BOARD_SIZE]) {
	int row,col;
   for (row = 0; row < BOARD_SIZE; row++) {
      for ( col = 0; col < BOARD_SIZE; col++)
         printf("%d ", chBoard[row][col]);
      printf("\n");
   }
}
int isQueenPlaceValid(int chBoard[BOARD_SIZE][BOARD_SIZE], int crntRow, int crntCol) { 
	int i,j;  
   for ( i = 0; i < crntCol; i++)    
      if (chBoard[crntRow][i])
         return 0;
   for ( i = crntRow, j = crntCol; i >= 0 && j >= 0; i--, j--)
      if (chBoard[i][j])       
         return 0;
   for ( i = crntRow, j = crntCol; j >= 0 && i < BOARD_SIZE; i++, j--)
      if (chBoard[i][j])      
         return 0;
   return 1;
}
int solveProblem(int chBoard[BOARD_SIZE][BOARD_SIZE], int crntCol) {
	int i;
   if (crntCol >= BOARD_SIZE)           
      return 1;
   for ( i = 0; i < BOARD_SIZE; i++) {     
      if (isQueenPlaceValid(chBoard, i, crntCol)) {
         chBoard[i][crntCol] = 1;     
         if (solveProblem(chBoard, crntCol + 1))    
            return 1;          
         chBoard[i][crntCol] = 0;        
      }
   }
   return 0;      
}
int displaySolution() {
   int chBoard[BOARD_SIZE][BOARD_SIZE],i,j;
   for( i = 0; i < BOARD_SIZE; i++)
      for( j = 0; j < BOARD_SIZE; j++)
         chBoard[i][j] = 0;      
   if (solveProblem(chBoard, 0) == 0) {     
      printf("Solution does not exist");
      return 0;
   }
   displayChess(chBoard);
   return 1;
}
int main() {
   displaySolution();
   return 0;
}

