##Easy
**1. Two sums** 

Use hashTable

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap; 
        //create a hash table, include a key and a value
        //(in this case, key is the nums_value and, value is the nums_value index)
        for(int i = 0; i < nums.size(); i++) {
            if (myMap.count(nums[i])) return vector<int> {i, myMap[nums[i]]};//What is count used for??????
            myMap[target - nums[i]] = i; //input the index of diff=target - nums[i] into the table 
        }
        return vector<int> {};
    }
};
```

**14. Longest Common Prefix** Check the longest prefix in a array of string
Straightforward

**24. Swap Nodes in Pairs** [1,2,3,4]->[2,1,4,3]   
Be careful about last one or two digits  
1 need to connect with 4 instead of 3.

**83. Remove Duplicates from Sorted List**   
Two Pointers, Straightforward 

**107. Binary Tree Level Order Traversal II**return the bottom-up level order traversal of its nodes' values   

Remember to use ```n=queue.size()``` and loop with n (count each level) within the while loop.   

**118. Pascal's Triangle**Given numRows, generate the first numRows of Pascal's triangle   
Staightforward   
Note: Take care of the index

**219. Contains Duplicate II**find out whether there are two distinct  indice such that nums[i] = nums[j] and the difference between i and j is at most k

Use unordered_map, be careful it is at most k (which means <=k)

**257. Binary Tree Paths**Given a binary tree, return all root-to-leaf paths.  

Use iteration, use ```string s``` instead of ```string& s```.

**371. Sum of Two Integers** Without using "+" operator

```
while(carry) { // keep calculating until the carry is zero
   sum = carry ^ a; // Calculate the sum without consider the carry
   carry = (carry & a) << 1 ; // Calculate the carry by getting the AND and shifting left
   a = sum;
}
```

```383. Ransom Note```   
Use 26 length array instead of hashmap(too slow)

##Median (Mostly)

**2. Add Two Numbers**

**11. Container With Most Water**

DP, use two pointer, one starts from begin and the other starts from the end, change them as follows:

```cpp
while(height[i]<=h) i++; // In this test case, 20 keeps no change
while(height[j]<=h) j--; // change as 1->17->4
```
since the wide (j-i) decreases, the volume may increase only when the height is greater than the previous. so we shift the pointer, when the height there is small.

**15. 3Sum** Find all unique triplets in the array which gives the sum of zero.

- sort
- take one number num[i], in num[i+1] to num[end] use binary search, if sum<0 begin++, if sum>0 end--
- NOTE: Remember to jump through the equal values

**17. Letter Combinations of a Phone Number** Given a digit string, return all possible letter combinations that the number could represent.

Read string character one by one, use three loops

**22. Generate Parentheses (Basic Recursion Problem) - Review Again !**  

Use recursion. count open and close. Start from open = n and close =0; push into the vector when both open and close = 0;

//Detail explanation:  http://wiki.jikexueyuan.com/project/leetcode-book/21.html

**29. Divide Two Integers**

We subtract 3 from 15 and we get 12, which is positive. Let's try to subtract more. Well, we shift 3 to the left by 1 bit and we get 6. Subtracting 6 from 15 still gives a positive result. Well, we shift again and get 12. We subtract 12 from 15 and it is still positive. We shift again, obtaining 24 and we know we can at most subtract 12. Well, since 12 is obtained by shifting 3 to left twice, we know it is 4 times of 3. How do we obtain this 4? Well, we start from 1 and shift it to left twice at the same time. We add 4 to an answer (initialized to be 0). In fact, the above process is like 15 = 3 * 4 + 3. We now get part of the quotient (4), with a remainder 3.

Then we repeat the above process again. We subtract divisor = 3 from the remaining dividend = 3 and obtain 0. We know we are done. No shift happens, so we simply add 1 << 0 to the answer.

Now we have the full algorithm to perform division.

According to the problem statement, we need to handle some exceptions, such as overflow.

Well, two cases may cause overflow:

1. divisor = 0;
2. dividend = INT_MIN and divisor = -1 (because abs( INT_MIN ) = INT_MAX + 1).

**34. Search for a Range** Sorted array, find the range of target number

Index Problem

 - binary search, find the leftmost index of target number
 - Special Case Ex.  [8,8,8], 8 
 

**35. Search Insert Position**: use binary search

**39. Combination Sum** Similar to LC77, 78

Since the number could be repeatly used, be careful about the begin index of the loop


**49. Group Anagrams**

 - Use hash map
 - sort the string to make them have the same order
 - remember to push a vector when it is the first string ( use this string to create a one component vector)

**53. Maximum Subarray** Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

Use DP

```
temp = temp+nums[i]>nums[i]? temp+nums[i]:nums[i];
sum = max(sum,temp);
```

**54. Spiral Matrix**
Index problem.

Remember to check if colbegin>colend or rowbegin>rowend

**55. Jump Game** Element in array represents your **maximum** jump length at that position. Check if able to reach the end.

Recursion,  

**60. Two Single number** 

1. use XOR to get mixed two single number
2. temp =r&(~(r-1)), get the last bit of 1's position
3. temp&nums[i] == 0? to distinct two single numbers then XOR.

**61. Rotate List**

Use two pointers.

Be carefull some special cases: k==0; head== NULL; k >= list's size

**62. Unique path**  
Given matrix m*n robot starts from leftmost end at rightbottom, only can move right or down.

C^(n-1)_(m+n-2), totoal m+n-2 spaces, pick n-1 to go down, others are all go right. 

**64. Minimum Path Sum** : DP

```cpp
grid[i][j] += min(grid[i-1][j], grid[i][j-1]) ;
```
**69. Sqrt(x) -- Review Again** 

```cpp
int mySqrt(int x) {
    if(x <= 1) return x;
    int left = 1, right = x;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(mid <= x / mid) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - 1;
}
```


**75. Sort Colors**

 - Use two index one starts from begin and the other starts from the end.
 - if num[i]==2, swap value at i and end, then end--, i--
 - if num[i]==0, swap value at i and begin, then begin++ 

**77. Combinations -- Review again**  
Recursion, ```push_back``` and ```pop_back``` (Slow)

**78. Subsets**  
Recursion, similar to LC77

**79. Word Search** Given a 2D board and a word, find if the word exists in the grid.

 DP

Note: The end of a string is '\0'. ```s[s,size()] == '\0' ```
Since each letter can only be used once, we can change the matched character to be '\0', then go to the next character. Remember to change it back to original value if one sequence does not work.

Ex. Test case : ["CAA","AAA","BCD"] ,  "AAB"  
 
```cpp
check(vector<vector<char>>& board, int r, int c, string word, int i)
```

**80. Remove Duplicates from Sorted Array II**  
Allow duplicates at most twice, return index 

Special Case [0,0,0,0,0]

**86. Partition List**  Put node with value less than x before nodes with value equal or greater than x.

Make two new heads  
Note: Remember to link the second list's tail to NULL, otherwise may cause time limit exceeded

**91. Decode Ways** : DP

Be careful about some "0" special cases like 12001, 0, 10, 190, 110

**92. Reverse Linked List II** given m and n (1<=m<=n<=size) reverse list between m and n

Two pointer to find node at n and m-1;
Reverse one by one from m to n

**94. BT Inorder traversal** (Similar as Q144)

The way to use recursion to reach each node Inorder 

```cpp
void list(TreeNode* root, vector<int>& output) {// Do not forget '&'
     if(!root) return;
     list(root->left, output);
     output.push_back(root->val);
     list(root->right, output);
    }
```
**96. Unique Binary Search Trees** 
using DP, i from 0 to n, j from 0 to i

```cpp
list[i] += list[j]*list[i-j-1];
```

**98. Validate Binary Search Tree**

use recursion

```
bool check(TreeNode* node, int min, int max) { }
```

Set ```min = INT_MIN``` for ```node->left```, and ```max = INT_MAX``` for ```node->right```

**108. Convert Sorted Array to Binary Search Tree**

Use recursion, Take the middle value as root.
The way to create a new treenode:
```c++
TreeNode* root = new TreeNode(nums[mid]);
```

**109. Convert Sorted List to Binary Search Tree** 

Recursion, Find the middle node of the linked list  

**113. Path Sum II** DFS, output all possible root to leaf values have sum equal to the given sum

DFS, Recursion
注意顺序

**114. Flatten Binary Tree to Linked List**  right side link the BT to  in preorder traversal 

Recursion, remember to list all possbile types of nodes

 - Link the rightmost node in ```root->left``` to the ```root->right```.


**116. BT, link curr->next to the node right next to the current node** 

Use two pointer, one as p represents the leftmost node p = p->left.
one as curr represents the node on the same level. curr = curr->next.

**122. Best Time to Buy and Sell Stock II**  

- Think it as sine wave, find the lowest and highest point, re-initialize when the wave decreases  
- Or There is a tricky way, see detailed code

**129. Sum Root to Leaf Numbers**   
EX. Tree [1,2,3,4] --> 124+13 return sum

The relation between two leaf is add:
```
return helper(p->left, num) + helper(p->right, num);  
```

**130. Surrounded Regions -  Review again !**

 BFS recursion

 * Go through all the boundary regions, change connected 0 to 1;
 * Go through the whole matrix, change 0 to X, and change 1 to 0
 * NOTE: Be careful on the recursion condition, not search too deeper. (Looks tricky though, expect better solution, avoid this tricky mehthod) 

**131. Palindrome Partitioning** Return matrix with all possible palindrome partitioning of s

loop i from 0 to size, check begin to i is palindrome or not, if so make begin to be i+1
Use ```push_back``` and ```pop_back```

**134. Gas Station** cycled gas station about cost, find the start index, which could finsh the cycle and return the start pos

 - Assume a mountain of cumulative gas-cost
 - index sould start from the next index of the lowest point
 - Once there comes another bottom point lower than the previous lowest point, the index need to be changed

**136. Only one Single number**: XOR 

**139. Word Break** determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 
 - Create a vector as long as the string. Once the word matches the dictionary, save 1 at the pos of the last char of word
 - if the vector's last pos has 1, return true.  

**141 - 142. Linked List Cycle I && II**

- 假设linked list有环，环长Y，环以外的长度是X, 环内走K 步相遇， 共走了t次
- 指针一  走的路是      t = X + nY + K      ①
- 指针二  走的路是     2t = X + mY+ K       ②  m,n为未知数
- 把等式一代入到等式二中, 有 2X + 2nY + 2K = X + mY + K
- =>   X+K  =  (m-2n)Y    ③ => X = (m-2n)Y
- X和K的关系是基于Y互补的。等于说，两个指针相遇以后，再往下走X步就回到Cycle的起点了。这就可以有O(n)的实现了。
- http://fisherlei.blogspot.com/2013/11/leetcode-linked-list-cycle-ii-solution.html

**143. Reorder List**

- Find the middle node (1-2-3-4-5-6)
- Reverse the second half list (1-2-3-6-5-4)
- Intersect (1-6-2-5-3-4)

**144. Binary Tree Preorder Traversal**  

If using iteration to reach every node: (Similar as Q94)

```cpp
while(p || !nodelist.empty()) {
            if (p) {
                output.push_back(p->val);
                p = p->left;
            }
            else {
                p = nodelist.top();
                nodelist.pop();
                p = p->right;
            }
        }
```
**148. Sort List**

- find middle node
- sort left and right
- merge sorted left and right

**150. Evaluate Reverse Polish Notation** Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Use stack, push number, once it is not number pop to calculate

**152. Maximum Product Subarray**

DP, each iteration, get the minval, maxval ans result;

```cpp
int temp = minres;
minres = min(min(minres*nums[i], maxres*nums[i]), nums[i]);
maxres = max(max(temp*nums[i], maxres*nums[i]), nums[i]);
result = max(result, maxres);
```

**162. Find peak Element**

 - Method 1: Run loop, if (nums[i-1] > nums[i]) return i-1;
 - Method 2: binary search, use mid1 and mid2 = mid1+1;

**179. Largest Number**

 Use sort function to compare the value of string, num i and j, compare 
 
 ```
 static bool comparefunc(string& l, string& r) {
     if (l+r > r+l) return 1;
     else return 0;
 }
 ```

**199. Binary Tree Right Side View** Use Queue, record the size of each level

**200. Number of Islands**
Recursion, if there is a '1' in the grid, set it to be zero, check the surroundings, set all the surrounding with '1' to be '0'

 - DFS, 
 - BFS, use queue, pop to clean the surrounding.  

**208. Implement Trie (Prefix Tree)** (Design)

 - trie includes pointer points to a array of 26 alphabet letters and points to the boolean value to check if it is the end of word
 - end value is initialized to be false
 - array contains 26 trieNode pointers initialized to be NULL
 
**211. Add and Search Word - Data structure design** (Design)  Design a data structure that supports the following operations: void Add(word), bool Search(word)

Use Trie, and Recursion 

**215. Kth Largest Element in an Array** Use Queue

**216. Combination Sum III**   
Add k numbers(1-9, unique), sum is n

Similar approach as LC77,778 

**225. Implement Stack using Queues**

 - use one queue, from 0 to size-2, q.push(q.front()).

**230. Kth Smallest Element in a BST**

 - The way to use iteration to reach each node (also used in Q94)

```cpp
public:
    int kthSmallest(TreeNode* root, int k) {
        int count =0;
        stack<TreeNode*> list;
        TreeNode* p = root;
        while (p||count<=k) {
            if(p) {
                list.push(p);
                p = p->left;
            }
            else {
                p = list.top();
                count++;
                if (count == k) {break;}
                list.pop();
                p = p->right;
            }
        }
        return p->val;       
    }
```

**232. Implement Queue using Stacks**

 - using two stack, one use to save the order as queue, one use to flip the order to queue. 

**238. Product of Array Except Self**  

- O(2n) is also O(n)
- two loops one from beginning and the other from the end

**241. Different Ways to Add Parentheses** compute results for all the different possible ways to group numbers and operators.

Use Recursion. For detail, see the actual code explanation
  
 - loop from 0 to size, once it is operator do the following
 - Take substring before the operator, do recursion, loop the result
 - Take substring after the operator, do recusion, loop the result

**260. Single Number III** Given an array, two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.  

 - first XOR to get r 
 - Then ```temp = r&(~(r-1))```;    
   Ex. temp = 0010, shows the pos of the last bit of 1 in r, which means, the two single number have the last different bit at 1's position.
 - ```temp&nums[i] //AND```   
    Separate two different numbers


**268. Missing Number** Find the one that is missing from the array 0-n.

Note: it can be unsorted.  
Use XOR.

**284. Peeking Iterator** (Design)

Two Approachs:  
1. copy constructor when the peek() is called, output the next() of the temp copied value   
2. copy constructor when the next() is called. Set a currentvalue, each time next() is called, make temp=currentvalue, pointer move to the next, then copy constructor and check peek value and make currentvalue = peek value, and return temp value (NOT SURE) 

**288. Unique Word Abbreviation** Check A word's abbreviation is unique if no other word from the dictionary has the same abbreviation (Design)

Use one unordered map and one unordered set


**300. Longest Increasing Subsequence**

 - Special approach see: http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 - use low_bound()
 - the end of the vector is vector.end(), which represents NULL pointer
 
**319. bulb switcher**
 
 1. start from off, toggle odd times make the bulb on, and even times off.
 2. bulb n is toggled when i is equal to its factor
 3. list all the factors of n, ONLY when n is the square of a integer, n has odd number factors. 
  
```cpp
return sqrt(n)
```
**328. OddevenLinkedlist**, put odd nodes first follewed by even nodes

Two pointer move together, one connect odd, the other connect even, then connect the odd pointer tail to the even head.

**334. Increasing Triplet Subsequence** Given an unsorted array return whether an increasing subsequence of length 3 exists or not

runtime O(n), complexity O(1), set variables min and mid, if one number is greater than mid, return true.

**343. Integer Break** break a number into at least two positive integers and maximize the product of those integers. Return the maximum product.

Can only be product of 2 or 3, more 3 is better than 2.


**347. Top K Frequent Elements** Given a non-empty array of integers, return the k most frequent elements.

- use map, key as number, value as count
- Either usepriority_queue, set pair, first as count and second as number, output the first K number
- Or use matrix, set each row as count, pushback number into rows, thenloop from end to begin and output first K number 


