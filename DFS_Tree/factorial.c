// Tuoxin Li
// 07/20/2022
//
// gcc -Wall factorial.c -o factorial
// ./factorial

#include <stdio.h>

int factorial(int n){
  int result=1;
  for(n=n;n>1;n--){
    result=result*n;
  }
  return result;
}

int factorial_rec(int n){
  if(n==1||n==0){
    return 1;
  }
  return n*factorial_rec(n-1);
}

long biggerFactorial1(int n){
  long result=1;
  for(n=n;n>1;n--){
    result=result*n;
  }
  return result;
}

long long biggerFactorial2(int n){
  long long result=1;
  for(n=n;n>1;n--){
    result=result*n;
  }
  return result;
}



int main(){

  printf("factorial(10) = %d\n",factorial(12));
  printf("factorial_rec(10) = %d\n",factorial_rec(12));
  printf("longFactorial_rec(10) = %ld\n",biggerFactorial1(39));
  printf("longLongFactoria2_rec(10) = %lld\n",biggerFactorial2(39));

  return 0;
}
