#include <bits/stdc++.h>
#define lli long long int
#define p 1000000007

using namespace std;

lli arr[100010];
lli n, q;

struct node{
	lli odd;
	lli even;

	node(lli o=0, lli e=0){
		odd = o;
		even = e;
	}
};
node tree[400010];
node merge(node A, node B){
	node C;
	C.odd = A.odd+B.odd;
	C.even = A.even+B.even;
	return C;
}

void build(lli index, lli l, lli r){
	// leaf nodes
	if (l==r)
	{
		tree[index]=node(arr[l]%2, 1-arr[l]%2);
		//cout<<"index = "<<index<<" val = "<<l<<endl;
		return;
	}

	lli mid = (l+r)/2;
	build(2*index, l, mid);
	build(2*index+1, mid+1, r);
	tree[index] = merge(tree[2*index], tree[2*index+1]);
	//cout<<"index = "<<index<<" val = "<<tree[index]<<endl;
}

void update(lli index, lli l, lli r, lli x, lli v){
	if (x<l || x>r)
	{
		return;
	}
	if (l==r)
	{
		arr[l] = v;
		tree[index] = node(arr[l]%2, 1-arr[l]%2);
		return;
	}
	

	lli mid = (l+r)/2;
	update(2*index, l, mid, x, v);
	update(2*index+1, mid+1, r, x, v);
	tree[index] = merge(tree[2*index], tree[2*index+1]);

}

node query(lli index, lli l, lli r, lli ql, lli qr){
	if (r<ql || l>qr)
	{
		return node(0,0);
	}

	if (ql<=l && qr>=r)
	{
		return tree[index];
	}
	lli mid = (l+r)/2;
	return merge(query(2*index, l, mid, ql, qr), query(2*index+1, mid+1, r, ql, qr));

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;

    for (int i = 0; i < n; ++i)
    {
    	cin>>arr[i];
    }
    //cout<<"starting??"<<endl;
    build(1,0,n-1);
    //cout<<"hua ki nahi??"<<endl;
    cin>>q;
    while(q--){
    	lli ch;
    	cin>>ch;
    	//cout<<"going on "<<ch<<endl;
    	if (ch==0)
    	{
    		lli i,x;
    		cin>>i>>x;
    		update(1,0,n-1,i-1,x);
    	}else{
    		lli ql, qr;
    		cin>>ql>>qr;
    		node ans = query(1,0,n-1,ql-1,qr-1);
    		if (ch==2)
    		{
    			cout<<ans.odd<<"\n";
    		}else{
    			cout<<ans.even<<"\n";
    		}
    		
    	}
    
    }

}