/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* root) {
    queue<TreeLinkNode*> Q;
	map<int,vector<TreeLinkNode*>> m;
	Q.push(root);
	m[0].push_back(root);
	int level=1;
	TreeLinkNode* dummy = new TreeLinkNode(-1);
	Q.push(dummy);

	while(Q.size()>1){
		while(Q.front()!=dummy){
				TreeLinkNode* popedEle=Q.front();
				Q.pop();
				if(popedEle->left){

					Q.push(popedEle->left);
					m[level].push_back(popedEle->left);
				}
				if(popedEle->right){
					Q.push(popedEle->right);
					m[level].push_back(popedEle->right);
				}
		}
		Q.pop();
		Q.push(dummy);
		level++; 
	}
	for(auto it = m.begin();it!=m.end();it++){
		vector<TreeLinkNode*> v = it->second;
		for(int i=1;i<v.size();i++){
			v[i-1]->next=v[i];
		} 
	}
}
