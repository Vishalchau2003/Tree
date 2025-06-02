# 145. Binary Tree Postorder Traversal

**Difficulty:** Easy  
**Link:** [LeetCode Problem](https://leetcode.com/problems/binary-tree-postorder-traversal/)

## Description

Given the `root` of a binary tree, return the postorder traversal of its nodes' values.

### Postorder Traversal:
- Traverse the left subtree
- Traverse the right subtree
- Visit the node

## Example 1:

**Input:**  
`root = [1,null,2,3]`  
**Output:**  
`[3,2,1]`  

## Example 2:

**Input:**  
`root = [1,2,3,4,5,null,8,null,null,6,7,9]`  
**Output:**  
`[4,6,7,5,2,9,8,3,1]`  

## Example 3:

**Input:**  
`root = []`  
**Output:**  
`[]`  

## Example 4:

**Input:**  
`root = [1]`  
**Output:**  
`[1]`  

## Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## Follow-Up

Can you solve it **iteratively** instead of recursively?
