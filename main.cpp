#include<bits/stdc++.h>

using namespace std;

#define Fast1 ios_base::sync_with_stdio(0)
#define Fast2 cin.tie(0)
#define Fast3 cout.tie(0)
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef short int SI;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

class treeNode
{
public:
	int data;
	treeNode* left;
	treeNode* right;
	treeNode(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~treeNode(){
		delete left;
		delete right;
	}
	
};

treeNode* builtTree(){

	// cout<<"\n Enter root :";
	int rootData;
	cin>>rootData;
	treeNode* root = new treeNode(rootData);

	queue<treeNode*> node;
	node.push(root);

	while(!node.empty()){

		treeNode* ptr = node.front();
		node.pop();

		int val;
		// cout<<"\n Enter Left of "<<ptr->data<<" :";
		cin>>val;

		if( val != -1){
			ptr->left = new treeNode(val);
			node.push(ptr->left);
		}

		// cout<<"\n Enter right of "<<ptr->data<<" :";
		cin>>val;

		if(val != -1){
			ptr->right = new treeNode(val);
			node.push(ptr->right);
		}

	}

	return root;
}

pair<int,int> getDiameter(treeNode* root){

	pair<int,int> res;
	if(!root){
		res = make_pair(0,0);
		return res;
	}

	pair<int,int> left = getDiameter(root->left);
	pair<int,int> right = getDiameter(root->right);

	int lh = left.F;
	int ld = left.S;
	int rh = right.F;
	int rd = right.S;

	int height = 1 + max(lh,rh);
	int diameter = max(lh + rh,max(rd,ld));
	res.F = height;
	res.S = diameter;

	return res;
}


int main(){

	treeNode* root = builtTree();

	pair<int,int> res= getDiameter(root);
	cout<<"\n Diameter of Tree :"<< res.F;
	cout<<"\n Height of Tree : "<< res.S;
	return 0;
}
//1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 10 -1 -1 -1 -1 -1
