# include <stdio.h>
# include "my_mat.h"
# define N 10


void matrixInput(int m[N][N]){;
	for (int i=0; i < N; i++){
		for (int j=0; j < N; j++){
			scanf("%d", &m[i][j]);
		}
	}
}

void printMatrix(int m[N][N]){
	for (int i=0; i < N; i++){
		for (int j=0; j < N; j++){
			if (i != j && m[i][j] == 0){
				printf("∞	");
			}
			else{
				printf("%d	", m[i][j]);
			}
		}
		printf("\n");
	}
}

int cMin(int v1, int v2Add, int v2Added){
	/* Assuming valid input */
	if (v2Add == 0 || v2Added == 0){
		return v1;
	}	
	if (v1 == 0 || v1 >= (v2Add + v2Added)){
		return v2Add + v2Added;
	}
	return v1;
}

void printIsPath(int m[N][N], int i, int j){
	if (m[i][j]){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
}

void printPath(int m[N][N], int i, int j){
	printf("Path from %d to %d\n", i, j);
	printf("%d\n", m[i][j]); 
}

void matrixFloyd(int m[N][N]){
	for (int k=0; k < N; k ++){
		for (int i=0; i < N; i ++){
			for (int j=0; j < N; j ++){
				m[i][j] = cMin(m[i][j], m[i][k], m[k][j]);
			}
		}
	}

}
