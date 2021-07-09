#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double randn (double mu, double sigma)
{
	
  double U1, U2, W;
  double  mult, X1, X2;
  ///////////////////////////////////////

  U1 = -1 + ((double) rand () / RAND_MAX) * 2;
  U2 = -1 + ((double) rand () / RAND_MAX) * 2;
  W = pow (U1, 2) + pow (U2, 2);;
  while (W>=1 || W == 0)
  {
	  U1 = -1 + ((double) rand () / RAND_MAX) * 2;
	  U2 = -1 + ((double) rand () / RAND_MAX) * 2;
	  W = pow (U1, 2) + pow (U2, 2);;
  }
      
  ////////////////////////////////////////

  mult = sqrt((-2 * log (W)) / W);
  X1 = U1 * mult;
  X2 = U2 * mult;
  
  ///////////////////////////////////////////
 
  return (mu + sigma * (double) X1);
  
  ///////////////////////////////////////////////
}


int main()
{
  int n,i;
  FILE *fptr1, *fptr2, *fptr3, *fptr4;
  double mu=0.0, sigma=1.0;
  //////////////////////////////////////////
  
  printf("enter the number of paricles\n");
  scanf("%u",&n);
  //////////////////////////////
  
  struct particle
   {
	   double X[3];
	   double h;
   };
   ////////////////////////////
   printf("sizeof particle array: %ld bytes\n", n*sizeof(struct particle)); 
   //////////////////////////////////////////
   struct particle *ptr;
   ptr = (struct particle*) calloc(n , sizeof(struct particle));
   if (ptr == NULL) 
    { 
		printf("Memory not allocated.\n"); 
		exit(0); 
	} 
    ///////////////////////////////////////////////////
	printf("Memory successfully allocated using calloc.\n"); 
	for(i = 0; i < n; i++)
        {
       (ptr+i)->X[0]=randn (mu,sigma);
       (ptr+i)->X[1]=randn (mu,sigma);
       (ptr+i)->X[2]=randn (mu,sigma);
       (ptr+i)->h=(double)rand()/RAND_MAX;
        }
     ////////////////////////////////////////////////
     
    //////////////////////////////////
    fptr1 = fopen("X1.dat", "w");
	if (fptr1 == NULL) 
	{
	printf("Error!");
	exit(1);
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			fprintf(fptr1,"%lf\n",(ptr+i)->X[0]);	
		}
    }
    fclose(fptr1);
    ////////////////////////////
    
    //////////////////////////////////
    fptr2 = fopen("X2.dat", "w");
	if (fptr2 == NULL) 
	{
	printf("Error!");
	exit(1);
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			fprintf(fptr2,"%lf\n",(ptr+i)->X[1]);	
		}
    }
    fclose(fptr2);
    ////////////////////////////
    
    //////////////////////////////////
    fptr3 = fopen("X3.dat", "w");
	if (fptr3 == NULL) 
	{
	printf("Error!");
	exit(1);
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			fprintf(fptr3,"%lf\n",(ptr+i)->X[2]);	
		}
    }
    fclose(fptr3);
    ////////////////////////////
    
    //////////////////////////////////
    fptr4 = fopen("h.dat", "w");
	if (fptr4 == NULL) 
	{
	printf("Error!");
	exit(1);
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			fprintf(fptr4,"%lf\n",(ptr+i)->h);	
		}
    }
    fclose(fptr4);
    //////////////////////////// 
    
return 0;
}
