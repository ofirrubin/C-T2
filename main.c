# include <stdio.h>
# include "my_mat.h"
# define N 10



int main(){
	/* Create a matrix */
	int matrix[N][N];
	int c, t1, t2;
	/* While not exit: */
	while((c=getchar()) != 'D'){
		if (c == 'A'){
			matrixInput(matrix);
			matrixFloyd(matrix);
		}
		else{
			scanf("%d", &t1);
			scanf("%d", &t2);
			if (c == 'B'){
				printIsPath(matrix, t1, t2);
			}
			else if (c == 'C'){
				printPath(matrix, t1, t2);
			}
		}
		
		
	}
	return 0;
}
