#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node{
   int data;
   struct Node *pNext;//ָ����
}NODE,*PNODE;//NODE�ȼ���struct Node    PNODE�ȼ���struct Node*;
PNODE create_list(PNODE pHead);
void traverse_list(PNODE pHead);
int main(){
    PNODE pHead=NULL;//�ȼ���struct Node*pHead=NULL;
    pHead=create_list(pHead);//create_list()�Ĺ��ܣ�����һ����ѭ�������������������ͷ���ĵ�ַ����pHead;
    traverse_list(pHead);
    return 0;
}

PNODE create_list(PNODE pHead){
   int len; //���������Ч�ڵ�ĸ�����
   int i;
   int val;//������ʱ����û�����Ľ���ֵ��
   PNODE pHead=(PNODE)malloc(sizeof(NODE));
   if(NULL==pHead){
      printf("����ʧ�ܣ�������ֹ��\n");
      exit(-1);
}
   PNODE pTail=pHead;
   pTail->pNext=NULL;
   printf("����������Ҫ���ɵ�����ڵ�Ľڵ�ĸ�����len=  ");
   scanf("%d",&len);
   for(i=0;i<len;++i){
      printf("�������%d���ڵ��ֵ��",i+1);
      scanf("%d",&val);
      PNODE pNew =(PNODE)malloc(sizeof(NODE));
      if(NULL==pNew){
      printf("����ʧ�ܣ�������ֹ��\n");
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
