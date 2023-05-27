//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* middleNode(struct Node* head)
    {
        if(head->next==NULL)
        {
            return head;
        }
        struct Node* slow = head;
        struct Node* fast = head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
                slow = slow->next;
                fast = fast->next->next;
        }
        return slow;
    }
    struct Node* reverse(struct Node* head)
    {
        struct Node* b = NULL;
        struct Node* a = head;
        struct Node* c=NULL;
        while(a!=NULL)
        {
            c = a->next;
            a->next = b;
            b= a;
            a = c;
        }
        return b;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        struct Node *middle = middleNode(head);
        middle->next = reverse(middle->next);
        struct Node *temp = middle->next;
        struct Node *start_temp = head;
        while(temp!=NULL)
        {
            int val = start_temp->data;
            start_temp->data = temp->data - val;
            temp->data = val;
            start_temp = start_temp->next;
            temp = temp->next;
        }
        middle->next = reverse(middle->next);
        
        return head;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends