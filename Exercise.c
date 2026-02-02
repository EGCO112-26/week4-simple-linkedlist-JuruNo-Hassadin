//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    
    struct node e,a,b,c,G,*head,*temp ;
    a.value = 5;
    a.next=&b;
    head=&a;
    printf("%d\n",head ->value ); //what value for 5
    b.value=a.value+3;
    b.next=&c;
    c.value=b.value+3;
    e.value=2;
    e.next=&a;
    head=&e;
    printf("Before\n");
    printf("%d\n",head ->value);
    printf("%d\n",head ->next->value ); 
    printf("%d\n",head->next->next->value);
    printf("%d\n",head->next->next->next->value);
   
    



    

    
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
     a.next=&G;
    G.value=7;
    G.next=&b;
    printf("After\n");
    
    printf("%d\n",head ->value);
    printf("%d\n",head ->next->value ); 
    printf("%d\n",head->next->next->value);
    printf("%d\n",head->next->next->next->value);
    printf("%d\n",head->next->next->next->next->value);



   
        
    /*  Exercise III Use loop to print everything */
        typedef struct node* NodePtr;
        NodePtr tmp=head; //add temp value to faciliate
        printf("Exercise III\n");
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d\n", tmp->value);
            tmp=tmp->next;
          // What is missing???
        }
    
    
   /*  Exercise IV change to while loop!! (you can use NULL to help) */
        printf("Exercise IV\n");
        tmp=head;
         while(tmp){
            printf("%3d\n", tmp->value);
            tmp=tmp->next;
           // What is missing???
        }
   
    
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
*/
        /* แบบ MANUAL
        printf("Exercise V\n");
        head=(NodePtr) malloc(sizeof(struct node));
        temp=head;
        head->value=7;
        head->next=(NodePtr) malloc(sizeof(struct node));
        head->next->value=10;
        head->next->next=NULL;
        printf("%3d\n",head->value);
        printf("%3d\n",head->next->value);
    */
        
        printf("Exercise V\n");
        head=(NodePtr) malloc(sizeof(struct node));
        temp=head;
        int count=5;
        for(int i=0;i<count;i++){
            temp->value=7+i*2;
            if(i<count-1){
                temp->next=(NodePtr) malloc(sizeof(struct node));
                temp=temp->next;
            }
            else{
                temp->next=NULL;
            }
        }
        /* print using iterator so we don't lose `head` */
        NodePtr it = head;
        while(it){
        
            printf("%3d\n", it->value);
            it=it->next;
        }
        
        
        


    /*  Exercise VI Free all node !!
         //use a loop to help
    */
    printf("\n");
    printf("Exercise VI\n");
    void free_all_nodes(NodePtr head) {
        NodePtr current = head;
        NodePtr next_node;

        while (current != NULL) {
        next_node = current->next; 
        free(current);             
        current = next_node;
        printf("free โหนดปัจจุบันเสร็จแล้วเรียบร้อย");     
        }
    }
    
   
}
/*จดบันทึก*/
/*int *a=(int*)malloc sizeof(int);
free(a);
NODE *a=(NodePtr)malloc sizeof(NODE);
NODE *b=(struct NODE*)malloc sizeof(struct Node);
NODE *c=(struct Node*),malloc sizeof(struct Node);
free(a);
*/

/*
struct node {
    int value;
    node *next;
};
typedef node* nodePtr;
nodePtr head,temp;
head=(nodePtr) malloc sizeof(node);
temp=head;
head->value=7
head->next=(nodePtr)malloc sizeof(node);
*/



