#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct NodeEle
{
	int index;
	struct NodeEle *next;	
};

struct sparse_matrix
{
	int *A;
	int *IA;
	struct NodeEle *JA;
	int size;
	int rows;
	int coloumns;
	
};


void printMatrix(struct Sparse_matrix *m);
void printMatrixDetails(struct Sparse_matrix *m);
int getelement(struct sparse_matrix *m,int i,int j);
struct sparse_matrix *sum_matrices(struct sparse_matrix *m1,struct sparse_matrix *m2,int coloumns,int rows);
void addNode(struct sparse_matrix* matrix,struct NodeEle *node);
struct sparse_matrix create(int coloumns,int rows);


int main()
{
	printf("input size of matrix:");
	int coloumns = 0,rows = 0;
	scanf("%d",&coloumns);
	scanf("%d",&rows);
	struct sparse_matrix *m1 = create(coloumns,rows);
	struct sparse_matrix *m2 = create(coloumns,rows);
	struct sparse_matrix *result = sum_matrices(m1,m2,coloumns,rows)
	
	if (rows*columns < 400)
	{
        printf("Matrix: \n");
        printMatrix(m1);
        printf("\n");
        printMatrix(m2);
        printf("\n");
    }
    else
	{
        printMatrixDetails(m1);
        printMatrixDetails(m2);
    }
    unsigned sum = sumOfMatrixStandart(m1, m2, rows, columns);
    struct SparseMatrix *res = sumOfMatrix(m1, m2, rows, columns, sum);
    printMatrixDetails(res);
	
	getch();
	return 0;
}

struct sparse_matrix create(int coloumns,int rows)
{
	
	
	struct sparse_matrix *matrix = malloc(sizeof(struct sparse_matrix)) ;
	
	matrix->A = malloc(coloumns*rows*sizeof(int));// for numbers of non zero values
	matrix->IA = malloc(coloumns*rows*sizeof(int));// numbers of non zero values before rows
	matrix->JA =NULL;//index column

	matrix->coloumns = coloumns;
	matrix->rows = rows;
	
	int amount = 0;   // 
	printf("enter the amount of non zero values:");
	scanf("%d",&amont);
	int matrix_final[rows][coloumns];
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0 ; j < coloumns ;j++)
		{
			matrix_final[i][j] = 0;
			
		}
	}
	for(int k = 0;k < amount ;amount++)
	{
		int element = 0;
		int ro_i;
		int col_j;
		
		printf("\ninput the non zero element:");
		scanf("%d",&element);
		printf("row index:");
		scanf("%d",&ro_i);
		printf("coloumn index:");
		scanf("%d",&col_j);
		matrix_final[ro_i][col_j] = element;
		
	}
	int index = 0;
	for(int j = 0;j < coloumns ; j++)
	{
		// creating node for coloumns
		struct NodeEle *node_col = malloc(sizeof(struct NodeEle));
		node_col->index = -1; // indexing coloumn of input element
		node_col->next = NULL;
		for(int i =0; i < rows ;i++ )
		{
			if(matrix[i][j] != 0)
			{
				int element = matrix[i][j];
				if(node_col->index < 0) // check only one coloumn and there is a only one value 
				{
					node_col->index = index;
					
				}
				matrix->A[index] = element;
				matrix->IA[index] = i;
				index++;
				
			}
			
			
		}
		addNode(matrix,node_col); 
	}
	matrix->size = index;
	matrix->A =realloc(matrix->A,index,sizeof(int))
	matrix->IA =realloc(matrix->IA,index,sizeof(int))
	
	return matrix;
}

void addNode(struct sparse_matrix* matrix,struct NodeEle *node)
{
	if(m->JA == NULL)
	{
		m->JA = node;
		
		
	}
	else
	{
		struct NodeEle *new = m->JA;
		while(new->next != NULL)
		{
			new = new->next;
			
		}
		new->next = node;//create node 
	}
	
}
struct sparse_matrix *sum_matrices(struct sparse_matrix *m1,struct sparse_matrix *m2,int coloumns,int rows)
{
	int matrix[rows][coloumns];
	 
	int element = 0;
	
	int matrix1[rows][coloumns];
	int matrix2[rows][coloumns];
	int mj1[m1->size];
    int mj2[m2->size];
	
	for(int i =0;i < rows;i++)
	{
		for(int j = 0;j < coloumns;j++)
		{	
			matrix[i][j] = 0;     ///to continue 3 lab sashith	
		}	
	}
	for(int i = 0;i < rows ;i++)
	{
		for(int j = 0;j < coloumns;j++)
		{
			
			matrix1[i][j] = getelement(m1,i,j);
			if(matrix1[i][j] != 0)
			{mj1[count] = j;
		    count ++;
				
			}
		}
		count = 0;
		
		for(int j = 0;j < coloumns;j++)
		{
			
			matrix2[i][j] = getelement(m1,i,j);
			if(matrix1[i][j] != 0)
			{mj1[count] = j;
		    count ++;
				
			}
		}
		count = 0;
		
		for (int i = 0; i < m1->size; i++)
		{
			int k = mj1[elements];
			int l = m1->IA[elements];
			matrix[l][k] = m1->A[elements];
			elements++;
		}
	}
    elements = 0;
    for (int i = 0; i < m2->size; i++){
        int k = mj2[elements];
        int l = m2->IA[elements];
        matrix[l][k] = matrix[l][k] + m2->A[elements];
        elements++;
    }
	
	struct SparseMatrix *res = malloc(sizeof(struct SparseMatrix));
    
    res->A = malloc(columns * rows * sizeof(int));
    res->IA = malloc(columns * rows * sizeof(int));
    res->JA = NULL;
    
    res->columns = columns;
    res->rows = rows;

    
    int index = 0;
    for (int j = 0; j < columns; j++) {
        // create node for column j
        struct ElementNode *jNode = malloc(sizeof(struct ElementNode));
        jNode->index = -1;
        jNode->next = NULL;
        
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] != 0) {
                int element = matrix[i][j];
                if (jNode->index < 0) {
                    jNode->index = index;
                }
                
                res->A[index] = element;
                res->IA[index] = i;
                
                // increase index
                index++;
            }
        }
        addNode(res, jNode);
    }
    
    res->size = index;
    
    res->A = realloc(res->A, index * sizeof(int));
    res->IA = realloc(res->IA, index * sizeof(int));
    
    return res;
	
	
	
}
int getelement(struct sparse_matrix *m,int i,int j)
{
	struct NodeEle *Jnode = m->JA;
	for(int k = 0; k < j ;j++)
	{
		Jnode = Jnode->next;
		
	}
	if(Jnode->index <0 )
	{
		return 0;
	}
	int start_index = Jnode->index;
	int stop_index = m->size;
	
	if(Jnode->next != NULL)
	{
		struct NodeEle *n = Jnode->next;
		while((n->index == -1)&&(n->next != NULL))
		{
			n=n->next;
			
		}
		if(n->index > 0 )
		{
			stop_index = n->next;
			
		}
	}
	
	for(int st = start_index;st < stop_index ; st++)
	{
		if(m->IA[st] == i)
		{
			return m->A[a];
			
		}
		
	}
	return 0;
}

void printMatrixDetails(struct SparseMatrix *m) {
    printf("A, IA, JA:\n\n");
    
    printf("A: ");
    for (int i = 0; i < m->size; i++) {
        printf("%d ", m->A[i]);
    }
    
    printf("\n\nIA: ");
    for (int i = 0; i < m->size; i++) {
        printf("%d ", m->IA[i]);
    }
    
    printf("\n\nJA: ");
    
    struct NodeEle *n = m->JA;
    
    while (n) {
        if (n->index != -1)
            printf("%d ", n->index);
        n = n->next;
    }
    
    printf("\n\n");
}

void printMatrix(struct SparseMatrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->columns; j++) {
            printf("%5d", getelement(m, i, j));
            //printf("%5d", getElemet(m, i, j));

        }
        printf("\n");
    }
}