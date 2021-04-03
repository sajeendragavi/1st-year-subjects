#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct ElementNode {
    int index;
    struct ElementNode *next;
};

struct SparseMatrix {
    int *A;
    int *IA;
    struct ElementNode *JA;
    int size; //get size to the  A and IA
    int rows;
    int columns;
};


void addNode(struct SparseMatrix *m, struct ElementNode *node);
void printMatrixDetails(struct SparseMatrix *m);
void printMatrixDetails(struct SparseMatrix *m);
void printMatrix(struct SparseMatrix *m);
struct SparseMatrix *sumOfMatrix(struct SparseMatrix *m1, struct SparseMatrix *m2, int rows, int columns);
struct SparseMatrix *manual(int rows, int columns);
void addNode(struct SparseMatrix *m, struct ElementNode *node) {
    if (m->JA == NULL) {
        m->JA = node;
    } else {
        struct ElementNode *n = m->JA;
        while (n->next) {
            n = n->next;
        }
        
        n->next = node;
    }
}

int getElemet(struct SparseMatrix *m, int i, int j) {
    struct ElementNode *jNode = m->JA;
    
    for (int k = 0; k < j; k++) {jNode = jNode->next;}
    
    if (jNode->index < 0) {return 0;}
    
    int startIndex = jNode->index;
    int stopIndex = m->size;
    
    if (jNode->next != NULL) {
        struct ElementNode *n = jNode->next;
        while ((n->index == -1) && (n->next != NULL)) {
            n = n->next;
        }
        if (n->index >= 0) {stopIndex = n->index;}
    }
    
    
    for (int a = startIndex; a < stopIndex; a++) { if (m->IA[a] == i) {return m->A[a];} } return 0;
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
    
    struct ElementNode *n = m->JA;
    
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
            printf("%5d", getElemet(m, i, j));
            //printf("%5d", getElemet(m, i, j));

        }
        printf("\n");
    }
}



struct SparseMatrix *sumOfMatrix(struct SparseMatrix *m1, struct SparseMatrix *m2, int rows, int columns)
{
    int matrix[rows][columns];
    
    int elements = 0;
    int count = 0;
    
    int matrix1[rows][columns];
    int matrix2[rows][columns];
    int mj1[m1->size];
    int mj2[m2->size];	
    
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) matrix[i][j] = 0;
    
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++){
            matrix1[i][j] = getElemet(m1, i, j);
            if (matrix1[i][j] != 0) {mj1[count] = j;count++;}
        }
    count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++){
            matrix2[i][j] = getElemet(m2, i, j);
            if (matrix2[i][j] != 0){
                mj2[count] = j;
                count++;
            }
        }
    count = 0;
    
    
    
    for (int i = 0; i < m1->size; i++){
        int k = mj1[elements];
        int l = m1->IA[elements];
        matrix[l][k] = m1->A[elements];
        elements++;
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

struct SparseMatrix *manual(int rows, int columns) {
    struct SparseMatrix *matrix = malloc(sizeof(struct SparseMatrix));
    
    matrix->A = malloc(columns * rows * sizeof(int));
    matrix->IA = malloc(columns * rows * sizeof(int));
    matrix->JA = NULL;
    
    matrix->columns = columns;
    matrix->rows = rows;
    
    int quantity = 0;
    printf("Input quantity of nonzero elements: ");
    scanf("%d", &quantity);
    
    int matrix_result[rows][columns];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) matrix_result[i][j] = 0;
    for (int i = 0; i < quantity; i++)
    {
        int element = 0;
        int x;
        int y;
        printf("\nInput element: ");
        scanf("%d", &element);
        printf("\nInput i: ");
        scanf("%d", &x);
        printf("\nInput j: ");
        scanf("%d", &y);
        matrix_result[y][x] = element;
    }
    
    int index = 0;
    for (int j = 0; j < columns; j++) {
        // create node for column j
        struct ElementNode *jNode = malloc(sizeof(struct ElementNode));
        jNode->index = -1;
        jNode->next = NULL;
        
        for (int i = 0; i < rows; i++) {
            if (matrix_result[i][j] != 0) {
                int element = matrix_result[i][j];
                if (jNode->index < 0) {
                    jNode->index = index;
                }
                
                matrix->A[index] = element;
                matrix->IA[index] = i;
                 
                // increase index
                index++;
            }
        }
        addNode(matrix, jNode);
    }
    
    matrix->size = index;
    
    matrix->A = realloc(matrix->A, index * sizeof(int));
    matrix->IA = realloc(matrix->IA, index * sizeof(int));
    
    return matrix;
}

int main() 
{
    printf("Input matrix size\n");
    int columns = 0, rows = 0;
    scanf("%d", &columns);
    scanf("%d", &rows);
    struct SparseMatrix *m1 = manual(rows, columns);
    struct SparseMatrix *m2 = manual(rows, columns);
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
    struct SparseMatrix *res = sumOfMatrix(m1, m2, rows, columns);
    printMatrixDetails(res);
       
    getch();
    return 0;
    
}