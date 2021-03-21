#include <stdio.h>
#include <stdlib.h>
#define COLOR_CODE 2

struct structure_point
{
    int columns;
    int rows;
    int pos_column;
    int pos_row;
};
typedef struct structure_point typed_point;
int** create_array(typed_point);
void print_array(int**, int, int);
void free_array(int**, int);
void flood_fill(int**, typed_point);

int main()
{
    typed_point A;
    scanf("Enter two integers that represent the the dimension of the array: %d\n", &A.columns);
    scanf("%d", &A.rows);
    printf("The dimension of the array is :(%d, %d) ", A.rows, A.columns);
    int** array = create_array(A);
    for(int i = 0; i<A.rows; i++)
    {
        for(int j = 0; j<A.columns; j++)
        {
            scanf("[%d][%d] = %d", i, j, &array[i][j]);
        }
    } 
    print_array(array, A.rows, A.columns);
    printf("Type the position where you want to apply the flood fill: ");
    scanf("[%d][%d]", &A.pos_row,&A.pos_column);
    flood_fill(array, A);
    print_array(array, A.rows, A.columns);
    free_array(array, A.rows);
    return 0;
}

int** create_array(typed_point A)
{
    int** array_pointer= NULL;
    array_pointer = malloc(A.rows*sizeof(int*));
    for(int i = 0; i<A.rows; i++)
    {
        array_pointer[i] = malloc(A.columns*sizeof(int));
    }
    return array_pointer;
}
void print_array(int** array, int rows, int columns)
{
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<columns; j++)
        {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
}
void free_array(int** array, int rows)
{
    for(int i = 0; i<rows; i++)
    {
        free(array[i]);
    }
    free(array);
}
void flood_fill(int** array, typed_point A)
{
    array[A.pos_row][A.pos_column] = COLOR_CODE;
    flood_fill(array[A.pos_row+1][A.pos_column], A);
    flood_fill(array[A.pos_row-1][A.pos_column], A);
    flood_fill(array[A.pos_row][A.pos_column+1], A);
    flood_fill(array[A.pos_row+1][A.pos_column-1], A);
}
