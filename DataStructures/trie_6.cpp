#include<bits/stdc++.h>
using namespace std;
int n;
struct Node
{
    int cnt;
    Node* child[3];
    Node()
    {
        cnt=0;
        fill(child,child+3,nullptr);
    }
};
void addNode(Node* root,int x)
{
    Node* cur=root;
    for(int i=30;i>=0;i--)
    {
        int c = x & (1<<i);
        if(!cur->child[c])
        {
            cur->child[c]=new Node();
        }
        cur=cur->child[c];
        cur->cnt++;
    }
}
void minNode(Node* root,int x)
{
    Node* cur=root;
    for(int i=30;i>=0;i--)
    {
        int c=x & (1<<i);
		if (cur -> child[c] == nullptr) return;
        (cur->child[c])->cnt--;
        if ((cur -> child[c]) -> cnt == 0)
        {
            delete(cur -> child[c]);
            cur -> child[c] = nullptr;
            break;
        }
        cur = cur -> child[c];
    }
}
int getvalue(Node* root,int x)
{
    long long ans=0;
    Node* cur=root;
    for(int i=30;i>=0;i--)
    {
        int c = x & (1<<i);
        if(cur->child[c]!=nullptr)
        {
            cur=cur->child[c];
            ans+=(1<<i);
        }
        else
        {
            cur=cur->child[1-c];
            ans+=(1<<i);
        }
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int s;int x;
    Node* root = new Node();
    addNode(root,0);
    for(int i=0;i<n;i++)
    {
        cin>>s>>x;
        if(s==0)
        {
            addNode(root,x);
        }
        if(s==1)
        {
            minNode(root,x);
        }
        if(s==2)
        {
            cout<<getvalue(root,x)<<'\n';
        }
    }
}