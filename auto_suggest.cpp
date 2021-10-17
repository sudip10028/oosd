#include <bits/stdc++.h>
#define lli long long int
#define p 1000000007

using namespace std;

struct node{
	int cnt;
	int curcnt;
	node* child[26];
	vector<string> strs;

	node(){
		cnt=0;
		curcnt=0;
		strs.clear();
		for (int i = 0; i < 26; ++i)
		{
			child[i]=NULL;
		}
	}
};


struct trie{
	node* head;
	int k;

	trie(){
		head = new node();
	}

	void print(node* cur){
		if(cur==NULL){
			cout<<"null node"<<endl;
			return;
		}
		cout<<"count is = "<<cur->curcnt<<endl;
		cout<<"under count = "<<cur->cnt<<endl;
		if(cur->curcnt>0){
			cout<<"string is = "<<cur->strs[0]<<endl;
		}
		
	}
	void insert(string s){
		int n = s.size();
		node* cur = head;
		for (int i = 0; i < n; ++i)
		{
			cur->cnt++;
			int t = (s[i]-'a');
			if(cur->child[t]==NULL){
				cur->child[t] = new node();
			}
			cur = cur->child[t];
		}
		cur->curcnt++;
		cur->strs.push_back(s);
		//print(cur);
	}

	void dfs(node* cur){
		if(k<=0) return;

		if(cur==NULL) return;

		for (int i = 0; i < cur->strs.size(); ++i)
		{
			cout<<cur->strs[i]<<" ";
			k--;
			if(k<=0) return;
		}

		for (int i = 0; i < 26; ++i)
		{
			dfs(cur->child[i]);
		}
	}
	void query(string q, int k1){
		k = k1;
		int n = q.size();
		node* cur = head;
		vector<string> ans;
		for (int i = 0; i < n; ++i)
		{
			if(cur==NULL){
				cout<<"\n";
				return;
			}
			int t = (q[i]-'a');
			cur = cur->child[t];
		}
		if (cur==NULL || (cur->cnt==0 && cur->curcnt==0))
		{
			cout<<"\n";
			return;
		}
		dfs(cur);
		cout<<"\n";
	}
};
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    lli n, maxlen, q;

    cin>>n>>maxlen>>q;

    trie tr;

    while(n--){
    	int size;
    	string s;
    	cin>>size>>s;
    	tr.insert(s);
    }

    while(q--){
    	int si,k;
    	string s;
    	cin>>si>>s>>k;
    	//tr.query(s.substr(0,si),k);
    	for (int i = 1; i <= si; ++i)
    	{
    		tr.query(s.substr(0,i),k);
    	}
    	//break;
    	
    }

}