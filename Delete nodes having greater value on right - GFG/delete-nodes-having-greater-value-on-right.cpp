//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        vector<int>ans;
        Node*temp=head;
        while(temp){
            ans.push_back(temp->data);
            temp=temp->next;
        }
        vector<int>val;
        val.push_back(ans[ans.size()-1]);
        int maxi=ans[ans.size()-1];
        for(int i=ans.size()-2;i>=0;i--){
            if(ans[i]>=maxi){
                val.push_back(ans[i]);
                maxi=ans[i];
            }
        }
        reverse(val.begin(),val.end());
        Node*dummy=new Node(-1);
        temp=dummy;
        for(int i=0;i<val.size();i++){
            Node* newNode=new Node(val[i]);
            temp->next=newNode;
            temp=temp->next;
        }
        return dummy->next;
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends