
#include<stdio.h>

// Program to display truth table of A.(A'+B).C.(A+B) and A.B.C and hence verify that both are equivalent
int main()
{
unsigned char num;
unsigned char A=0x00, B=0x00, C=0x00;
unsigned char LHS,RHS;
for (num = 0x00; num<0x08; num++)  
{
A = num>>2; B = num>>1; C = num>>0;
LHS= A&((~A)|B)&C&(A|B);
RHS = A&B&C;
printf("  %x %x %x", one&A, one&B, one&C);
printf("\t\t%x\t\t\t\t%x\n", one&LHS, one&RHS);
}
return 0;
}
/*
Output
  A B C    A.(A'+B).C.(A+B)   A.B.C             
  0 0 0         0               0
  0 0 1         0               0
  0 1 0         0               0
  0 1 1         0               0
  1 0 0         0               0
  1 0 1         0               0
  1 1 0         0               0
  1 1 1         1               1
  */
