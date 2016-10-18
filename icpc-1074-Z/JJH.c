#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define log2(x) log(x)/log(2)

int position(int length,int r, int c, int result);

int main(){
  int n,r,c,t;
  int length,result;
  
  scanf("%d",&t);
  
  while(t--){
      scanf("%d %d %d",&n,&r,&c);
      result=0;
      
      length = pow(2,n);
      position(length,r,c,result);
  
  }
  
  return 0;
}
int position(int length,int r, int c, int result){
  if(length>2){
    if((r+1)<=length/2 && (c+1)<=length/2){
      position(length/2,r,c,result);
    }
    else if((r+1)<=length/2 && (c+1)>length/2){
      result += 4*pow(2,2*(log(length)-2))*1;
      position(length/2,r,c,result);
    }
    else if((r+1)>length/2 && (c+1)<=length/2){
      result += 4*pow(2,2*(log(length)-2))*2;
      position(length/2,r,c,result);
    }
    else if((r+1)>length/2 && (c+1)>length/2){
      result += 4*pow(2,2*(log(length)-2))*3;
      position(length/2,r,c,result);
    }
  }
}
