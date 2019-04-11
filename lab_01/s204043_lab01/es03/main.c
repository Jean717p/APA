#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int i=0,periodo,j,flag=0,ver=1,valid=0;
    char frase[30];
    while(strcmp(frase,"stop")!=0)
    {
        if(ver!=1 && valid==0)
        {
            printf("La stringa %s non e' periodica.\n",frase);
        }
        ver=0; valid=0;
        printf("Immettere una stringa di massimo 30 caratteri alfanumerici:\n");
        scanf("%s",frase);
        periodo=1;
        if(strlen(frase)<=30)
        {
            for(i=1 ; i<strlen(frase) ; i++)
            {
                flag=0;
                if(isalnum(frase[i])!=0)
                {

                    if(frase[0]!=frase[i])
                    {
                        periodo++;
                    }
                    if(frase[0]==frase[i] && (strlen(frase)%periodo==0))
                    {
                        for(j=periodo ; j<periodo*2 && flag==0; j++)
                        {
                            if(frase[j]!=frase[j-periodo])
                            {
                                flag=1;
                                periodo++;
                            }
                        }
                        if(flag==0)
                        {
                            ver=1;
                            printf("La stringa %s e' periodica. (periodo %d)\n",frase,periodo);
                            break;
                        }
                    }
                }

            }
        }
        else
        {
            valid=1;
            printf("La stringa e' troppo lunga o non valida.\n");
        }
    }
    return 0;
}
