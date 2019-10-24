#include <stdio.h>
#include <malloc.h>
struct dl_list{
	int data;
	struct dl_list *next;
	struct dl_list *prev;
};

typedef struct dl_list *node;

node creat(node head){
	head = (node)malloc(sizeof(struct dl_list));
	printf("nhap  gia tri : ");
	scanf("%d",&head.data);
	head -> prev = NULL;
	head -> next = NULL;
	return head;
}

node add_h(node head){
	node p = NULL;
	 p = creat(p);
	 if(head == NULL){
	 	head = p;
         
	 }
	 else{
	 	p -> next = head;
         head -> prev = p;
	 }
     return p;
}
node Input(){
    int i, n;
    node head = NULL;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("so thu %d: \n", i + 1);
        head = add_h(head);
    }
}

node Oput(node head){
    node p = NULL;
    for(p = head; p != NULL; p = p ->next){
        printf("%d", head->data);
    }
}
node add(node head){
    node p = NULL, temp = NULL;
    int n, k = 0;
    printf("nhap vi tri can chen: ");
    scanf("%d", &n);
    if(n == 0){
        p = creat(p);
        p ->next = head;
        head ->prev = p;
    }
    else{
        p = head;
        while(p != NULL && k != n - 1){
            p = p ->next;
            k = k + 1;
        }
        if(k != n - 1){
            printf("ko co vi tri chen \n");
        }
        else{
            temp = creat(temp);
            temp ->next = p ->next;
            temp ->prev = p;
            p -> next ->prev = temp;
            p ->next = temp;
        }
    return head;
    }

}
int main(){
    node head = NULL;
    head = Input();
    Oput(head);
    head = add(head);
    Oput(head);
}