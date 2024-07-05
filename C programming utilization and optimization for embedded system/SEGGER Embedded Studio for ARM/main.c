/*main.c*/


///*** Assemvly TestFunc test*******************************/
//#include <stdio.h>
//#include <stdlib.h>

//extern void AssemTestFunc(void);

//int main(void) {
  
//  AssemTestFunc();

//  while (1)
//  {
  
//  }
//}


///*** Check assembly code depending on C code ******************************/
//#include <stdio.h>
//#include <stdlib.h>

//extern void AssemTestFunc(void);

//int gVar;

//int main(void)
//{
//  if (gVar ==0)
//  {
//    gVar = gVar + 1;
//  }
//  else
//  {
//    gVar = gVar - 1;
//  }
//}


//int main(void) {
  
//  AssemTestFunc();

//  while (1)
//  {
  
//  }
//}


///****Addr copy test******************************/
//#include <stdio.h>
//#include <stdlib.h>

//extern void AssemTestFunc(void);

//int main(void) {

//  AssemTestFunc();

//  while (1)
//  {
  
//  }
//}


///****Addr copy test******************************/
//#include <stdio.h>
//#include <stdlib.h>

//extern void AssemTestFunc(void);

//int gVar = 0x100;

//int main(void) {

//  AssemTestFunc();
//  printf("gVar : %#010xc",gVar);

//  while (1)
//  {
  
//  }
//}


/**** DoSum test ******************************/
//#include <stdio.h>
//#include <stdlib.h>

//extern void AssemTestFunc(void);
//extern int DoSum(int);

//int gVar = 0x100;

////int DoSum(int n)
////{
////  int sum = 0;
////  for (int k=0; k<=n; k++)
////  {
////    sum = sum +k;
////  }
////  return sum;
////}

//int main(void) 
//{
//  printf("program starts \r\n");

//  int a = DoSum(10);
//  printf("%d \r\n", a);

//  //AssemTestFunc();
//  printf("gVar : %#010xc \r\n",gVar);

//  while (1)
//  {
  
//  }
//}



///*** Assembly Code Test QUIZ 3 test *******************************/
//#include <stdio.h>
//#include <stdlib.h>

//extern void AssemTestFunc(void);
//extern int DoDist(int, int);

//int gVar = 0x100;

//int GetDist(int a, int b)
//{
//  int d;
//  d = a-b;
//  if (d<0)
//  {
//    d = -d;
//  }
//  return d;
//}


//int main(void) 
//{
//  printf("program starts \r\n");

//  int d = DoDist(-4, 3);
//  printf("DoDist d : %d \r\n", d);

//  int d2 = GetDist(-4, 3);
//  printf("GetDist d2 : %d \r\n", d2);

//  //AssemTestFunc();
//  //printf("gVar : %#010xc \r\n",gVar);

//  while (1)
//  {
  
//  }
//}


/*** Assembly Code Test QUIZ 3 *******************************/
#include <stdio.h>
#include <stdlib.h>

extern void AssemTestFunc(void);
extern int memory_copy(int, int, int);

int gVar = 0x100;

int buf0[8]={0,1,2,3,4,5,6,7};
int buf1[8];

//void memory_copy(int*pdst, int * psrc, int len)
//{
//  for (int k=0; k<len; k++)
//  {
//    pdst[k] = psrc[k];
//  }
//}

int main(void) 
{
  printf("program starts \r\n");

  memory_copy(*buf1, *buf0, 8);

  //AssemTestFunc();
  //printf("gVar : %#010xc \r\n",gVar);

  while (1)
  {
  
  }
}
