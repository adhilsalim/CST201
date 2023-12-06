/*
This program performs addition of two sparse matrices using tuple
Author: Advaith Manoj
*/
#include <stdio.h>

int arrin(int r, int c, int arr[][c]);
void st(int r, int c, int arr[][c], int tup[][3], int rows);
void mdisp(int r, int c, int matrix[][c]);
void trnsp(int r, int tup[][3]);
int add(int t1[][3], int t2[][3], int s[][3], int ra, int ca);

void main()
{
    while (1)
    {
        int choice;
        printf("1.Transpose 2.Sum 3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int r, c;
            printf("Enter the number of rows in the sparse matrix: ");
            scanf("%d", &r);
            printf("Enter the number of columns in the sparse matrix: ");
            scanf("%d", &c);
            int arr1[r][c];
            int trow = arrin(r, c, arr1);
            printf("The sparse matrix is: \n");
            mdisp(r, c, arr1);
            int tup[trow + 1][3];
            st(r, c, arr1, tup, trow + 1);
            printf("The tuple matrix is: \n");
            mdisp(trow + 1, 3, tup);
            trnsp(trow + 1, tup);
            mdisp(trow + 1, 3, tup);
        }
        else if (choice == 2)
        {
            int r1, c1, r2, c2;
            printf("Enter the number of rows in the first sparse matrix: ");
            scanf("%d", &r1);
            printf("Enter the number of columns in the first sparse matrix: ");
            scanf("%d", &c1);
            int sp1[r1][c1];
            int trow1 = arrin(r1, c1, sp1) + 1;

            printf("Enter the number of rows in the second sparse matrix: ");
            scanf("%d", &r2);
            printf("Enter the number of columns in the second sparse matrix: ");
            scanf("%d", &c2);
            int sp2[r1][c1];
            int trow2 = arrin(r2, c2, sp2) + 1;

            printf("The two sparse matrices are:\n");
            mdisp(r1, c1, sp1);
            mdisp(r2, c2, sp2);

            int tup1[trow1][3];
            int tup2[trow2][3];
            st(r1, c1, sp1, tup1, trow1);
            st(r2, c2, sp2, tup2, trow2);

            printf("Corresponding tuples are:\n");
            mdisp(trow1, 3, tup1);
            mdisp(trow2, 3, tup2);

            int sumtup[(trow1 + trow2)][3];
            int r3 = add(tup1, tup2, sumtup, trow1, trow2);
            mdisp(r3, 3, sumtup);
        }
        else if (choice == 3)
        {
            break
        }
    }
}

int arrin(int r, int c, int arr[][c])
{
    int nonzero = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter the element at position %d %d: ", i + 1, j + 1);
            {
                scanf("%d", &arr[i][j]);
                if (arr[i][j] != 0)
                {
                    nonzero += 1;
                }
            }
        }
    }
    return nonzero;
}

void st(int r, int c, int arr[][c], int tup[][3], int rows)
{
    tup[0][0] = r;
    tup[0][1] = c;
    tup[0][2] = rows - 1;
    int k = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] != 0)
            {

                tup[k][0] = i;
                tup[k][1] = j;
                tup[k][2] = arr[i][j];
                k += 1;
            }
        }
    }
}

void mdisp(int r, int c, int matrix[][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void trnsp(int r, int tup[][3])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            int temp1 = tup[i][j];
            tup[i][j] = tup[i][j + 1];
            tup[i][j + 1] = temp1;
        }
    }
    for (int i = 1; i < r + 1; i++)
    {
        for (int j = 1; j < (r + 1) - i - 1; j++)
        {
            if (tup[j][0] > tup[j + 1][0])
            {
                int temp2 = tup[j][0];
                tup[j][0] = tup[j + 1][0];
                tup[j + 1][0] = temp2;

                int temp3 = tup[j][1];
                tup[j][1] = tup[j + 1][1];
                tup[j + 1][1] = temp3;

                int temp4 = tup[j][2];
                tup[j][2] = tup[j + 1][2];
                tup[j + 1][2] = temp4;
            }
        }
    }
}

int add(int t1[][3], int t2[][3], int s[][3], int ra, int ca)
{
    int i = 1, j = 1, k = 1, e = 0;
    while ((i < ra) && (j < ca))
    {
        if ((t1[i][0] == t2[j][0]) && (t1[i][1] == t2[j][1]))
        {
            s[k][0] = t1[i][0];
            s[k][1] = t1[i][1];
            s[k][2] = t1[i][2] + t2[j][2];
            i++;
            j++;
            k++;
            e++;
        }
        else if ((t1[i][0] == t2[j][0]) && (t1[i][1] != t2[j][1]))
        {
            if (t1[i][1] < t2[j][1])
            {
                s[k][0] = t1[i][0];
                s[k][1] = t1[i][1];
                s[k][2] = t1[i][2];
                i++;
                k++;
                e++;
            }
            else
            {
                s[k][0] = t2[j][0];
                s[k][1] = t2[j][1];
                s[k][2] = t2[j][2];
                j++;
                k++;
                e++;
            }
        }
        else if (t1[i][0] < t2[j][0])
        {
            s[k][0] = t1[i][0];
            s[k][1] = t1[i][1];
            s[k][2] = t1[i][2];
            i++;
            k++;
            e++;
        }
        else
        {
            s[k][0] = t2[j][0];
            s[k][1] = t2[j][1];
            s[k][2] = t2[j][2];
            j++;
            k++;
            e++;
        }
    }
    while (i < ra)
    {
        s[k][0] = t1[i][0];
        s[k][1] = t1[i][1];
        s[k][2] = t1[i][2];
        i++;
        k++;
        e++;
    }
    while (j < ca)
    {
        s[k][0] = t2[j][0];
        s[k][1] = t2[j][1];
        s[k][2] = t2[j][2];
        j++;
        k++;
        e++;
    }
    s[0][0] = t1[0][0];
    s[0][1] = t1[0][1];
    s[0][2] = e;
    return e;
}