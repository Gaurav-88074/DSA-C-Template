#include<stdio.h>
#include<stdlib.h>
int * seive(int n){
    int * res = (int*)calloc(n+1,sizeof(int));
    for(int i =0;i<=n;i++){
        res[i]=1;
    }
    res[0] = 0;
    res[1] = 0;
    for(int i =2;i<=n;i++){
        if(res[i]==0)continue;

        for(int j=2 * i ;j<=n;j+=i){
            res[j]=0;
        }
    }
    return res;
}
int main(){
    int * isPrime  = seive(1007);
    printf("501 -> %d\n",isPrime[229]);
    printf("589 -> %d\n",isPrime[587]);
    free(isPrime);
    return 0;
}