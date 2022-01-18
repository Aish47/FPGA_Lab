// Program to display truth table for given expression

#include<stdio.h>
#include<stdlib.h>

int main()
{
//Inputs
int A[]={0, 0, 0, 0, 1, 1, 1, 1};
int B[]={0, 0, 1, 1, 0, 0, 1, 1};
int C[]={0, 1, 0, 1, 0, 1, 0, 1};

int LHS[8],RHS[8];
int i;
// Loop to calculate output for different inputs
for(i=0; i<8; i++)
{
// LHS = A.(~A+B).C.(A+B)
 LHS[i] = A[i] & (~A[i] | B[i]) & C[i] & (A[i] | B[i]);
// RHS = A.B.C
 RHS[i] = A[i] & B[i] & C[i];

// Display truth table
 printf(" %d %d %d", A[i], B[i], C[i]);
 printf("\t\t%d\t%d\n", LHS[i], RHS[i]);
}
return 0;
}

/*
Output:
 A B C    A.(A'+B).C.(A+B)    A.B.C
 0 0 0          0               0
 0 0 1          0               0
 0 1 0          0               0
 0 1 1          0               0
 1 0 0          0               0
 1 0 1          0               0
 1 1 0          0               0
 1 1 1          1               1
 */
