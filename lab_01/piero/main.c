#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[30],fine[5]={"stop"};
    int i=0,n,j,f=0,k=1,l=0;
    while(strcmp(str,fine)!=0)
    {
        if(k!=1 && l==0)
        {
            printf("la stringa %s non e' periodica \n",str);
        }
        l=0;
        k=0;
      printf("Stringa? ");
      scanf("%s",str);
      n=1;
      if(strlen(str)<=30)
      {
          for(i=1 ; i<strlen(str) ; i++)
          {
              f=0;
              if(isalnum(str[i])!=0)
              {

                      if(str[0]!=str[i])
                      {
                          n++;
                      }
                      if(str[0]==str[i] && (strlen(str)%n==0))
                      {
                         for(j=n ; j<2*n && f==0; j++)
                         {
                           if(str[j]!=str[j-n])
                           {
                               f=1;
                               n++;
                           }

                         }
                         if(f==0)
                         {
                             k=1;
                         printf("la stringa %s e' periodica di %d volte\n",str,n);
                         break;
                         }
                      }
              }

          }
      }
      else
      {
          l=1;
          printf("stringa troppo lunga, non valida\n");
      }
    }
    return 0;
}
