#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
#include <limits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>


using namespace std;

template<class T>
void print(vector<T>& arr){
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void print2d(vector<vector<T>> & matrix){
    for(int i=0;i<matrix.size();++i){
        print(matrix[i]);
    }
}

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void printList(ListNode* head){
    while(head){
        cout << head->val<<"->";
        head=head->next;
    }
    cout <<"NULL"<<endl;
}


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 