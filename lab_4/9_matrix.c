#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int rows;
    int cols;
    int **data;
};

int main()
{
    struct Matrix m;
    int i, j;

    printf("Enter number of rows: ");
    scanf("%d", &m.rows);
    printf("Enter number of columns: ");
    scanf("%d", &m.cols);

    // Allocate memory for rows
    m.data = (int **)malloc(m.rows * sizeof(int *));

    // Allocate memory for each row
    for (i = 0; i < m.rows; i++)
    {
        m.data[i] = (int *)malloc(m.cols * sizeof(int));
    }

    // Input elements
    printf("\nEnter elements of the matrix:\n");
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m.data[i][j]);
        }
    }

    // Display matrix
    printf("\n--- Matrix ---\n");
    for (i = 0; i < m.rows; i++)
    {
        for (j = 0; j < m.cols; j++)
        {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < m.rows; i++)
    {
        free(m.data[i]);
    }
    free(m.data);

    return 0;
}
