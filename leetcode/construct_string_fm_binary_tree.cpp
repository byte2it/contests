// b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/**
* Definition for a binary tree node.  */

#include <string>
using std::string;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void rec_helper(TreeNode* n, string& s) {
		if (n == nullptr) return;

		char szV[32] = { 0 };
		sprintf_s(szV, "%d", n->val);
		s.append(szV);
		if (n->left != nullptr) {
			s.push_back('(');
			rec_helper(n->left, s);
			s.push_back(')');
		}

		if (n->right != nullptr) {
			if (n->left == nullptr) {
				s.push_back('(');
				s.push_back(')');
			}

			s.push_back('(');
			rec_helper(n->right, s);
			s.push_back(')');
		}
	}

	string tree2str(TreeNode* t) {
		string res = "";
		TreeNode* node = t;
		rec_helper(t, res);
		return res;
	}
};

int main()
{
    return 0;
}

