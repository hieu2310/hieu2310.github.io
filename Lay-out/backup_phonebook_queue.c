#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct Address
{
char name[30];
char phone[15];
char email[30];
}Address;


typedef struct AddressList
{
Address data;
struct AddressList *next;
}AddressList;




void push(struct AddressList** head_ref, Address new_data) 
{ 
    struct AddressList* new_node = (struct AddressList*) malloc(sizeof(struct AddressList)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 

} 
  
void insertAfter(struct AddressList* prev_node, Address new_data) 
{ 
    if (prev_node == NULL) 
    { 
      printf("the given previous node cannot be NULL"); 
      return; 
    } 
  
    struct AddressList* new_node =(struct AddressList*) malloc(sizeof(struct AddressList)); 
    new_node->data  = new_data; 
    new_node->next = prev_node->next; 
  
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node; 
} 
  
/* Given a reference (pointer to pointer) to the head 
   of a list and an int, appends a new node at the end  */
void append(struct AddressList** head_ref, Address new_data) 
{ 
    /* 1. allocate node */
    struct AddressList* new_node = (struct AddressList*) malloc(sizeof(struct AddressList)); 
  
    struct AddressList *last = *head_ref;  /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->data  = new_data; 
  
    /* 3. This new node is going to be the last node, so make next of 
          it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
  
    /* 6. Change the next of last node */
    last->next = new_node; 
    return; 
} 
  
// // This function prints contents of linked list starting from head 
void printList(struct AddressList *node) 
{ 
  while (node != NULL) 
  { 
    printf(" %s\n ", node->data.name);
    printf(" %s\n ", node->data.phone);
    printf(" %s\n ", node->data.email);
     node = node->next; 
  } 
} 

struct QNode { 
    Address new_data; 
    struct QNode* next; 
}; 
  
// The queue, front stores the front node of LL and rear stores the 
// last node of LL 
struct Queue { 
    struct QNode *front, *rear; 
}; 
  
// A utility function to create a new linked list node. 
struct QNode* newNode(Address new_data) 
{ 
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    temp->new_data = new_data; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function to create an empty queue 
struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  
// The function to add a key k to q 
void enQueue(struct Queue* q, Address new_data) 
{ 
    // Create a new LL node 
    struct QNode* temp = newNode(new_data); 
  
    // If queue is empty, then new node is front and rear both 
    if (q->rear == NULL) { 
        q->front = q->rear = temp; 
        return; 
    } 
  
    // Add the new node at the end of queue and change rear 
    q->rear->next = temp; 
    q->rear = temp; 
} 
  
// Function to remove a key from given queue q 
struct QNode* deQueue(struct Queue* q) 
{ 

    FILE *fp;
    fp = fopen("phonebook_queue.txt","w+");
    // If queue is empty, return NULL. 
    if (q->front == NULL) 
        return NULL; 
  
    // Store previous front and move front one node ahead 
    struct QNode* temp = q->front; 

    fputs(temp, fp);
    
    free(temp); 
  
    q->front = q->front->next; 
    
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL) 
        q->rear = NULL; 
    
    return temp; 
} 



  
/* Driver program to test above functions*/
int main() 
{ 
  /* Start with the empty list */
  AddressList* root = NULL; 
  AddressList *cur = NULL;
  Address data;

  struct Queue* q = createQueue(); 
  int n;
  printf("Nhap so luong du lieu: ");
  scanf("%d",&n); __fpurge(stdin);
  for (int i=0;i<n;i++)
  {
  	printf("Name %d:\n",i+1);
  	scanf("%30[^\n]s",data.name);
  	__fpurge(stdin);
  	printf("Phone %d:\n",i+1);
  	scanf("%15[^\n]s",data.phone);
  	__fpurge(stdin);
  	
  	printf("mail %d:\n",i+1);
  	scanf("%25[^\n]s",data.email);
  	__fpurge(stdin);
  

  	//push(&root,data);

  	//append(&root,data);
    enQueue(&root,data);
    //deQueue(&root);
    // printList(root); 
  }
  

  // struct QNode* n = deQueue(q); 
  //   if (n != NULL) 
  //       printf("Dequeued item is %d", n->key); 
  //   return 0; 
  //append(&root,data);
  printList(root); 
  
  return 0; 
} 
