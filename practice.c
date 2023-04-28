#include <stdio.h>
#include <stdlib.h>

//this is a code for linked list

//creating node
struct node{
  int data;
  struct node *next;
}*head;




void createList(int n){

   struct node *newNode, *temp;
   int i,data;

   head = (struct node *)malloc(sizeof(struct node));
    if(head==NULL){
      printf("memory is not allocated");
      exit(0);
     }

  printf("Enter the data in node 1: ");
  scanf("%d", &data);

  head-> data = data;
  head->next = NULL;


  temp = head;


    for(i=2;i<=n;i++){
        newNode = (struct node *)malloc(sizeof(struct node));

         if(newNode==NULL){
          printf("memory is not allocated");
          break;
         }

        printf("Enter the data in node : ", i);
        scanf("%d", &data);

         newNode->data = data;
         newNode->next = NULL;

         temp->next = newNode;
         temp = temp->next;
    }

}

void traverseList(){
    if(head==NULL){
        printf("List is empty");
    }
struct node *temp;
temp = head;

printf("\n[");
while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
}
printf("]");


}

void insertAtBegin(int data){
struct node *lk = (struct node *)malloc(sizeof(struct node));

lk->data = data;
lk->next = head;

head =lk;

}

void insertAfterNode(struct node *list, int data){
  struct node *lk = (struct node *)malloc(sizeof(struct node));
  lk->data = data;
  lk->next = list->next;
  list->next = lk;


}

void deleteAtBegin(){
  head = head->next;
}

void deleteAtEnd(){

  struct node *ptr, *ptr1;

  if(head==NULL){
    printf("\n list is empty");
  }else if(head->next == NULL){
      head = NULL;
      free(head);
      printf("only one node is deleted\n");
  }else{
  ptr = head;
  while(ptr->next!=NULL){
    ptr1 = ptr;
    ptr = ptr->next;
  }
  ptr1->next = NULL;
  free(ptr);
  printf("\n deleted from the last");


  }

}


int main(){
int n,data;
printf("No of nodes: ");
scanf("%d", &n);
//creating list
createList(n);
printf("List is created");

 traverseList();
 printf("list is traversed");

printf("\nEnter the data in node 1: ");
scanf("%d", &data);
insertAtBegin(data);
 printf("new list is traversed: ");
 traverseList();

 printf("adding new nodes in list\n");
 insertAfterNode(head->next->next, 33);

  printf("after adding new nodes in list\n");
  traverseList();


  deleteAtEnd();
    printf("after deleting  node from the last in list\n");
  traverseList();
}
