#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void disprip(int pos,int val[],int sol[],int n,int k);
int main()
{
    int pos=0,*sol,n=4,k,num[]={5,6,7,8}; //lunghezza stabilita a priori se no era da chiedere
    printf("Inserire numero cifre da scrivere: ");
    scanf("%d",&k);
    if(k<=0||k>n)
        exit(-1);
    sol=malloc(k*sizeof(int));
    disprip(pos,num,sol,n,k);
    free(sol);
    return 0;
}
void disprip(int pos,int val[],int sol[],int n,int k){
    int temp,i,count;
    if(pos>=k){
        temp=1;
        if(k%2==0)
            temp=0;
        count=k-1;
        for(i=0;i<k;i++){
            temp+=sol[i]*pow(10,count);
            count--;
        }
        if(temp%7==0){
            printf("\t%d\n",temp);
        }
        return;
    }
    for(i=0;i<n;i++){
        sol[pos]=val[i];
        disprip(pos+1,val,sol,n,k);
    }
}
//void powerset(int pos,int val[],int sol[],int n,int k,int start)
//{
//    int j,temp,i,count;
//    if (pos>=n){
//        for(j=n-1,count=0;j>=0;j--){
//            if(sol[j]!=0){
//                count++;
//            }
//        }
//        if(count==k){
//            temp=1;
//            if(k%2==0)
//                temp=0;
//            count--;
//            for(i=0;i<n;i++){
//                if(sol[i]!=0){
//                    temp+=val[i]*pow(10,count);
//                    count--;
//                }
//            }
//            if(temp%7==0){
//                printf("%d\n",temp);
//            }
//        }
//        return;
//    }
//    sol[pos] = 0;
//    powerset(pos+1,val,sol,n,k);
//    sol[pos] = 1;
//    powerset(pos+1,val,sol,n,k);
//}
//int fattoriale(int N){
//    int i,ris;
//    for(i=ris=1;i<=N;i++){
//        ris*=i;
//    }
//    return ris;
//    }
//int comb(int pos,int val[],int sol[],int n,int k,int count) {
//    int i,temp;
//    if(pos>=k-1){
//            temp=1;
//            if(k%2==0)
//              temp=0;
//        for(i=0;i<k;i++){
//            temp+=sol[i]*pow(10,k-i);
//            }
//        if(temp%7==0){
//            printf("%d",sol[i]);
//            printf("\n");
//            return count+1;
//        }
//    }
//    for(i=0;i<n;i++){
//        sol[pos] = val[i];
//        count=comb(pos+1,val,sol,n,k,count);
//        }
//    return count;
//}


//    while(perm>0){
//            temp=1;
//            if(N%2==0)
//                temp=0;
//            for(j=rand()%(l-1),i=1;i<=N;j=rand()%(l-1),c1=0){
//                if(j==p[j]){
//                    c1=-1;
//                    }
//                if(c1!=-1){
//                    p[j]=j;
//                    temp+=num[j]*pow(10,N-i);
//                    i++;}
//            }
//            p[0]=-1;
//            for(i=1;i<l;i++){
//                p[i]=0;
//            }
//            for(i=1,j=l-1;j>0;i++,j--){
//                c1=num[j];
//                c=rand()%(l-1)+1;
//                num[j]=num[c];
//                num[c]=c1;
//            }
//            if(temp%7==0){
//                for(i=0;v[i]!=0;i++){
//                    if(v[i]==temp){
//                        c1=l+1;
//                        break;
//                    }
//                }
//                if(c1!=(l+1)){
//                    printf("%d\n",temp);
//                    v[i]=temp;}
//            }
//    perm--;
//    }
//    return 0;
//}
//    while(perm>0){
//        if(tail>head){
//            while(count<2){
//                flag=0;
//                while(flag<N-1){
//                    for(j=head,i=1,temp=1;j<=tail;i++,j++){
//                        temp+=num[j]*pow(10,N-i);
//                    }
//                    for(i=head+1,j--;j>head+1;i++,j--){
//                        t=num[j];
//                        num[j]=num[i];
//                        num[i]=t;
//                    }
//                    if(temp%7==0){
//                        printf("%d\n",temp);
//                    }
//                flag++;
//                }
//                to=num[head];
//                num[head]=num[head+1];
//                num[head+1]=to;
//                count++;
//            }
//        }
//        else{
//            while(count<2){
//                flag=0;
//                while(flag<N-1){
//                    for(j=head,i=1,temp=1;j<l;i++,j++){
//                        temp+=num[j]*pow(10,N-i);
//                    }
//                    for(j=0,temp=1,i=1;j<=tail;i++,j++){
//                        temp+=num[j]*pow(10,N-i);
//                    }
//                    for(j=l,i=head;j>head;i++,j--){
//                        t=num[j];
//                        num[j]=num[i];
//                        num[i]=t;
//                    }
//                    for(j=tail,i=0;j>0;i++,j--){
//                        t=num[j];
//                        num[j]=num[i];
//                        num[i]=t;
//                    }
//                    if(temp%7==0){
//                        printf("%d\n",temp);
//                    }
//                    flag++;
//                }
//                to=num[tail];
//                num[tail]=num[tail+1];
//                num[tail+1]=to;
//                count++;
//                }
//        }
//        head++; tail++; count=flag=0;
//        if(tail>l)
//            tail=0;
//        if(head>l)
//            head=0;
//        perm--;
//    }
//    return 0;
//}
