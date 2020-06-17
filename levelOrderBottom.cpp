vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> ret;
	if (nullptr == root)
		return ret;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		size_t levelSize = q.size();
		vector<int> vLevel;

		for (size_t i = 0; i < levelSize; i++)
		{
			TreeNode* cur = q.front();
			q.pop();

			vLevel.push_back(cur->val);

			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}

		ret.push_back(vLevel);
	}
	return ret;
}