# include <stdio.h>
# define N 10


void matrixInput(int m[N][N]);
void printMatrix(int m[N][N]);
int cMin(int v1, int v2Add, int v2Added);
void matrixFloyd(int m[N][N]);
void printIsPath(int m[N][N], int i, int j);
void printPath(int m[N][N], int i, int j);


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
	return 1;
}

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
		return v2Add;
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
