#include <stdio.h>
#include <string.h>

#define MAX 100

int L[MAX];

int max(int num1,int num2){
  return (num1 > num2) ? num1 : num2;
}

int subsequencia(int num[],int n){
  for(int i = 0;i<n;i++)
    L[i] = 1;
  int maior = 0;
  for(int i = 1;i<n;i++){
    for(int j = 0;j<i;j++){
      if(num[j] < num[i])
        L[i] = max(L[i], L[j] + 1);
    }
    maior = max(maior,L[i]);
  }
  return maior;
}

int main() {
  memset(L,-1,sizeof(L));

  int num[] = {1,2,3,1,5,15,4,2,6},n = 10;
  int maior = subsequencia(num, n);
  printf("Maior subsequencia: %i",maior);
  
}