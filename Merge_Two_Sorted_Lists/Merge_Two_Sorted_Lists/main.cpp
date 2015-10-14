//
//  main.cpp
//  Merge_Two_Sorted_Lists
//
//  Created by 李佳 on 15/10/14.
//  Copyright © 2015年 LiJia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* first, ListNode* last)
    {
        if (first == NULL)
            return last;
        else if (last == NULL)
            return first;
        
        ListNode* result = NULL;
        ListNode* resultHead = NULL;
        while (first && last)
        {
            if (first->val < last->val)
            {
                if (resultHead)
                {
                    result->next = first;
                    result = result->next;
                }
                else
                {
                    result = first;
                    resultHead = first;
                }
                first = first->next;
                while (first && first->val < last->val)
                {
                    result = first;
                    first = first->next;
                }

            }
            else
            {
                if (resultHead)
                {
                    result->next = last;
                    result = result->next;
                }
                else
                {
                    result = last;
                    resultHead = last;
                }
                last = last->next;
                while (last && first->val >= last->val)
                {
                    result = last;
                    last = last->next;

                }
            }
        }
        
        if (first)
        {
            result->next = first;
        }
        if (last)
        {
            result->next = last;
        }
        return resultHead;
    }
};


void printList(ListNode* list)
{
    while (list)
    {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

ListNode* bulidLists(vector<int> nums)
{
    ListNode* head = new ListNode(nums[0]);
    ListNode* result = head;
    for (int i = 1; i < nums.size(); ++i)
    {
        ListNode* node = new ListNode(nums[i]);
        head->next = node;
        head = head->next;
    }
    return result;
}


int main(int argc, const char * argv[])
{
    Solution* pSol = new Solution;
    ListNode* first = bulidLists({-2,-1,0,1,3,5,7});
    ListNode* last = bulidLists({2,4,6,8});
    
    ListNode* result = pSol->mergeTwoLists(first, last);
    printList(result);
    return 0;
}
