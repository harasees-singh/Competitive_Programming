#include<stdio.h>
#include<string.h>
void main(){
    int itemlist[] = {8,2,3,1,6};
    int a = 2, b = 5, item1=4;
    int x,y;

    itemlist[a-1]=item1;
    printf("the el is\n");
    for(x=0;x<b;x++){
        printf("itemlist[%d]=%d\n",x,itemlist[x]);z
    }
}