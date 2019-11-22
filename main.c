// authors Davide Merli, Ryan Perrina, Giulia Tedeschi, Manuel Luizietti
//20191122
//Exercise 02 week  04
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<time.h>
void checkpointer (int*);
int main()
{
    bool prime;
    int count=0;
    int value;
    printf("Insert a start value:");
    scanf("%d",&value);
    int *ptrDin;

    while(value!=1)
    {
        prime=true;
        for(int i=value-1;i>1;i--)
        {
            if(value%i==0)prime=false;
        }
        if(prime==true)
        {
            ++count;

            if(count==1)
            {
                ptrDin=(int *) malloc(sizeof(int));
                checkpointer(ptrDin);
                *ptrDin=value;
            }
            else
            {
                ptrDin=(int *) realloc(ptrDin,sizeof(int)*count);
                checkpointer(ptrDin);
                ptrDin[count-1]=value;
            }

        }
        value--;
    }
    free(ptrDin);
    printf("prime number until your number:\n");
    for(int j=count-1;j>=0;j--)
    {
        printf("%d\n",ptrDin[j]);
    }

    free(ptrDin);
    return 0;
}

void checkpointer (int* ptr)
{
    if(ptr==NULL)                               //check if there is enough space to contain the dim number
    {
        printf("Sorry, not enough space!\n\n");
        exit(1);                                //if not, end program
    }
}
