#include<stdio.h>
#include<math.h>
#define PI 3.14596;
int main(void){
   int a = 0;
   float b = 2*PI;
   int n = 100;
   float x = a;
   float h = (b-a)/n;
   
   printf("   \"x\"   ,  \"sin(x)\" ");
   printf("\n");
   for(int i=1; i<= n; i++){
   	printf("%lf , %lf", x, sin(x));
   	 printf("\n");
   	 x = x+h;
   	
   }
   
   return 0;
}
