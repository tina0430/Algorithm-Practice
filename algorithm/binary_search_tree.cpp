#include <iostream>
using namespace std;

#define NULL 0

class TreeNode {
public :
   int value;
   TreeNode *left;
   TreeNode *right;
   TreeNode () {
      value = NULL;
      left = nullptr;
      right = nullptr;
   }
   TreeNode (int val) {
      value = val;
      left = nullptr;
      right = nullptr;
   }
};

class BinaryTree {
private :
   //arr이 오름차순으로 정렬되어있어야함
   TreeNode makeTreeR (TreeNode root, int arr[], int s_idx, int e_idx) {
      int r_idx = (s_idx + e_idx)/2;
      root.value = arr[r_idx];
//      cout << root.value << endl;
      //cout << "s_idx : " << s_idx << "  e_idx : " << e_idx << endl; 
      if (s_idx >= e_idx) {
         rootNode.left = nullptr;
         rootNode.right = nullptr;

         return root;
      }

      //root.left = new TreeNode();
      //root.right = new TreeNode();

      TreeNode leftNode, rightNode;
      
      root.left = &makeTreeR (leftNode, arr, s_idx, r_idx-1);
      root.right = &makeTreeR (rightNode, arr, r_idx+1, e_idx);

      return root;
   }

   void makeTree (int arr[], int arr_len) {
      rootNode = makeTreeR(rootNode, arr, 0, arr_len);
   }

public :   
   TreeNode rootNode;

   BinaryTree () { rootNode.value = NULL; }
   BinaryTree (int arr[], int arr_len) { makeTree(arr, arr_len-1); }
};

/*
int main () {
   int myArr[10] = {1,3,4,6,7,9,10,22,43,100};
   int arr_len = sizeof (myArr) / sizeof (myArr[0]);
   BinaryTree myTree = BinaryTree (myArr, arr_len);
   cout << "==============================" << endl;
   
   cout << "root : " << myTree.rootNode.value << endl;

   TreeNode tmp = *myTree.rootNode.left;
   cout << "root-left : " << tmp.value << endl;
   
   tmp = *myTree.rootNode.right;
   cout << "root-left : " << tmp.value << endl;
}
*/