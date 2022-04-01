#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node{
   int data;
   struct Node *pNext;//指针域
}NODE,*PNODE;//NODE等价于struct Node    PNODE等价于struct Node*;
PNODE create_list(PNODE pHead);
void traverse_list(PNODE pHead);
int main(){
    PNODE pHead=NULL;//等价于struct Node*pHead=NULL;
    pHead=create_list(pHead);//create_list()的功能：创建一个非循环单链表，并将该链表的头结点的地址赋给pHead;
    traverse_list(pHead);
    return 0;
}

PNODE create_list(PNODE pHead){
   int len; //用来存放有效节点的个数。
   int i;
   int val;//用来临时存放用户输入的结点的值。
   PNODE pHead=(PNODE)malloc(sizeof(NODE));
   if(NULL==pHead){
      printf("分配失败，程序终止！\n");
      exit(-1);
}
   PNODE pTail=pHead;
   pTail->pNext=NULL;
   printf("请输入您需要生成的链表节点的节点的个数：len=  ");
   scanf("%d",&len);
   for(i=0;i<len;++i){
      printf("请输入第%d个节点的值：",i+1);
      scanf("%d",&val);
      PNODE pNew =(PNODE)malloc(sizeof(NODE));
      if(NULL==pNew){
      printf("分配失败，程序终止！\n");
      exit(-1);
}
      pNew->data=val;
      pHead->pNext=pNew;
      pNew->pNext=NULL;
      pTail=pNew;
}
      return pHead;
}

void traverse_list(PNODE pHead){
    PNODE p=pHead->pNext;
    while(NULL!=p){
      printf("%d ",p->data);
      p=p->pNext;
    }
    printf("\n");
}
