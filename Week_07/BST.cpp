#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  // If the root is NULL, create new node and return it
  if (node == NULL) {
    struct node *newNode = new struct node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  // If key < root's key, insert it into the left subtree
  if (key <= node->key) {
    node->left = insertNode(node->left, key);
  }
  // If root's key < key, insert it into the right subtree
  else if (node->key < key) {
    node->right = insertNode(node->right, key);
  }
  // Return the unchanged root pointer
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Base case => if the root is NULL, return it
  if (root == NULL) {
    return root;
  }

  // If the key < root's key, search in the left subtree
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  }
  // If the root's key < key, search in the right subtree
  else if (root->key < key) {
    root->right = deleteNode(root->right, key);
  }
  // If the key == root's key, this is the node to be deleted
  else {
    // Case 1: If node has no children
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }
    // Case 2: If node has one child
    else if (root->left == NULL) {
      struct node *temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root;
      root = root->left;
      delete temp;
    }
    // Case 3: If node has two children
    else {
      // Find the inorder successor of the node
      struct node *temp = root->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      // Copy the successor's key value to the root's key value
      root->key = temp->key;
      // Delete the successor from the right subtree
      root->right = deleteNode(root->right, temp->key);
    }
  }

  // Return the modified root pointer
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;

  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}