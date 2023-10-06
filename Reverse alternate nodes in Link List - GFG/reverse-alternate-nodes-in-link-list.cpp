//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    struct Node* reverse(struct Node *temp2){
        struct Node*a=temp2;
        struct Node*b=NULL;
        struct Node*c=NULL;
        while(a!=NULL){
            c=a->next;
            a->next=b;
            b=a;
            a=c;
        }
        return b;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        struct Node *temp=odd;
        struct Node *temp1=odd->next;
        struct Node *temp2=odd->next;
        // if(odd->next->next==NULL || odd->next==NULL || odd==NULL) return ;
        while(temp->next!=NULL && temp->next->next!=NULL){
           temp->next=temp->next->next;
           temp=temp->next;
           temp1->next=temp1->next->next;
           temp1=temp1->next;
        }
        struct Node *t=reverse(temp2);
        temp->next=t;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends