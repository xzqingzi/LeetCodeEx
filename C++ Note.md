
----------------------------

- STL: Standard template library

- Data structure: 
  * stack(first in last out), queue(first in first out)
- Search Algorithm:
 * Depth first search(DFS): visit achieved by stack and recursion, 
 * Breadth first search(BFS): acieved by queue
 
- Binary Tree
 * height balanced binary tree: log2(n) <= height <= n

- The most significant digit (?) (Ex. LC 66)

####Common Usage

- Pointer: 
  1. &val is reference, means the address of value. 
  2. *p1 is de-reference, means the value in the address p1.
  
   * EX.  
  
  ```
   int c=9;
   int *iptr=&c;//define a pointer, represents the address of int variable c.
   int **iptrptr=&iptr; 
   //define another pointer, 
   //represents the address of the address ipter (need two ** to define) 
   // EX. Leetcode.21
  ```
  *EX. 
    
 ``` c+
 root->left == (*root).left
 ```

- Create a new node: (Ex. LC 108)

 ```cpp
 TreeNode* root = new TreeNode(nums[mid]);
 ```
- Create an Limited length array
 ```
 int list[26] = {0};  // initialize an array
 ```

- Index: 
 * Ex 12345767 reverse 
 
  ```cpp
 reverse(nums.begin(),nums.end());  //7654321 
 reverse(nums.begin(),nums.begin()+3); //(567)4321
 reverse(nums.begin()+3,nums.end()); //567(1234)
 ```
- Initialize Vector
 - Static vector 
  ```cpp
  static vector<int> list({0}); //Why static here
  ```
 - Mutidimentional Vector
 ```cpp
 vector<vector<int>> result(n, vector<int>(n, 0));
 ```
 
- Queue 
 - priority_queue: The first element is always the greatest of the elements it contains 
 
  ```cpp
  priority_queue<pair<int,int>> myqueue; //initialize
  myqueue.push(make_pair(i.second,i.first)); // insert value
  ```

- Bit manipulation
 * ~0 << 2  is 1s followed by 2 0s and 1011 & (~0 << 2) is 1000 


- Convert Number to string: 
 
 ```cpp
 temp = to_string(count) + s[i]; //build_in Func

 //can also use:
 stringstream ss; // stringstream used for the conversion
 ss << count << s[i];//add the value of count and s[i] to the characters in the stream
 temp = ss.str();

 // Special Case (Ex. Leetcode 38) can also use:
 temp = '0'+count; // special case here
 temp += s[i];
 ```
- Convert string to number : ``` stoi() ```

- ```std::```  means use standard namespace
- ```auto```: means the type of value is determined by the compiler itself
- ```npos```: 
 * Maximum value for ```size_t```,  ```npos``` is a static member constant value with the greatest possible value for an element of type ```size_t```.
 ```cpp
 static const size_t npos = -1;
 ```
 * This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
 * As a return value, it is usually used to indicate no matches.
 * This constant is defined with a value of -1, which because ```size_t``` is an unsigned integral type, it is the largest possible representable value for this type.
 * **Ex**: ```pos != string::npos?```(LC.43) 
 //string::npos is the end of string, means no matches in the string 
 
- Similar as ```npos``` in string, the end of the vector is ```vector.end()```, which means no match in the vector (LC.300) EX. ```pos == vector.end()```

- ```unordered_map```: initialize ```unordered_map<int, int> myMap; ``` 
- ```this```: c++ access to its own address through an important pointer called ```this``` pointer. The ```this``` pointer is an implicit parameter to all member functions.   
eg. ```Iterator(*this).next();//conpy constructor```

- Buildin Function:

 * ```swap(x,y)```  // swap the values in x and y 
 * ```tolower()```: Convert uppercase letter to lowercase 
 * ```toupper()```: Convert lowercase letter to uppercase
 * ```isalnum()```: Check if character is alphanumeric
 * ```s.find_last_not_of()```: Searches the string for the last character that does not match any of the characters specified in its arguments. **Give the position**
 * ```labs()```: ```long int labs (long int n)```
Returns the absolute value of parameter n ( /n/ ).
This is the long int version of abs.

 * ```substr(pos)```: output the string from pos to the end;  
 * ```ispunct(int c )```: Check whether c is a punctuation character.


- INT max and min 
 ```
 abs(INT_MIN) = INT_MAX + 1
 ```


------
- **Heap:**   

**Theory:**  
How to implement priority_queue    
The inside is a Binary tree, it is almost completed, every level is completed except the last level   
For every level, root is smaller than the smaller children

- pop(): Runtime O(logn) 
 - exchange the position of root and last element     
root <--> last element  
 - pop last element (actually is pop the initial root)    
 - change the root with children's smaller element, switch it down until it is larger than root, and smaller than children 

- push(): Runtime O(logn)   
 - put the new element to the last element position (Maybe the rightmost element position of the binary tree)   
 - Compare with its root and next value, swith it up until it is larger than root, and smaller than children  


- front(). Runtime O(1)   
 - output the root value


- Make a heap O(nlogn): 
 - Initially k elements, push value one by one to make a binary tree 

**Heap in Practice:**   
Implementation heap in practice, Use vector is the most popular way to implement    
L level complete tree has 2^L-1 elements    

- Make a heap /push()   
 - Create a vector, if want to push a value, we need to switch it with the root
 - set the index of the new element position is i, compare and switch it with the element at position at (i-1)/2 (The root's position)
 - compare until the index is 0 or the parent value is less than the new element


- Pop()
 - Switch the begin and back element, pop the last element use pop_back() in vectors
 - from the begin i=0 (root position), switch the root with its chilren at position 2\*i+1 and 2\*i+2
 - switch until there is no chilren or both cildren is greater than root 


- front() is just ouput this front value of vector


If given the vector, we can directly sort it O(nlogn), the priority queue is implemented. But sort maybe a little bit slower than push the element one by one (uplimit O(nlogn)) 

**Heap Ex.**    
priority queue has **three arguments**   
If pass TreeNode into priority queue,
  
- first argument TreeNode  //tell what type of element is used   
- second argument vector<TreeNode> //underline instructor   
//what do you expect to succeed this structure, usually use vector   
//can also pass linked list     
- third pass function // how to compare two values 

Exercise:   
How to implement the priority_queue (Heap)  
have four functions  
make heap  
push  
pop  
top  
 
-------- 
 
 

###Leetcode 
    * Majority element Special Algorithm

```cpp
 class Solution { // majorrity count > n/2, not equal 
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int maj = nums[0];
        for (int i = 1; i<nums.size(); i++) { 
            if (nums[i] == maj) {
                count++;
            }
            else if (count == 0) { // only the digit with more # than previous majority could make count = 0
                maj = nums[i];
                count++;
            }
            else { 
                count--;
            } 
        }
        return maj;
    }
};
```


----------------------------
----------------------------


**Slide Notes**

### Slide 1
 - A data structure is the data that’s operated on by an algorithm to solve a problem.
 - An Abstract Data Type or ADT is:“A coordinated group of(a) data structures, 
(b) algorithms and 
(c) interface functions
that is used to solve a particular problem.”
 - Structure type
 
```cpp
struct Nerd {
    string name;
    int IQ;
}; 
```

### Silde 2
- constructor
 - Constructor is a special member function that **automatically initializes** every new variable you create of a class.
  - The constructor has the same name as the func
  - No return type and No return value
  - ** To **define a constructor outside the class declaration**:use the class name, followed by ::, followed by the class name.
  -  If a constructor requires parameters, You **must provide values for those parameters** when you create a new variable   
  
 ```
  Class CSNerd {
  Public:
     CSNerd(int PCs, bool usesMac){
     ...
     }
  }
  //In the main function, provide the value
  int main() {     CSNerd ed(1,true); // OK     CSNerd alan; // invalid! 
   }
  ```

  -  Your class can have many different constructors. This is called **overloading constructors**.
  -  If you don’t define any constructors, C++ generates an **implicit, default constructor** for you. This default constructor won’t initialize your object’s **scalar member variables**!
(*scalar variables*: int, float, doule, bool etc. *Non scalar*: string, CSNerd etc.)
 - Your class **must** have a constructor that **requires no arguments**! 
 ```cpp
 CSNerd() 
 }
 ```
  - The constructor is **not called** when you just define **a pointer variable**!
 ```c++
 CSNerd* Ptr
 ```
 - Create a array of ayour class   
 ```
 CSNerd arr[4] // create a array of 4 CSNerd value, constructor is called 4 times 
 ```
- Destructor
 - The job of the destructor is to de-initialize or destructa class variable when it goes away.
 - To define a destructor, place a tilde in front of the name of the class

 ```cpp
 ~SomeClass() {}
```
 - Define a destructor outside your class definition 

 ```cpp
class someclass {
public: 
      ~ someclass(); //define a function header inside the class
};
someclass:: ~someclass() {
}
```
 - Destructor must has No input parameters, No return values 
 - If you don’t define your own destructor for a class, Then C++ will define an implicit one for you
 - The destructor is called when the **block finishes**, OR if dynamically allocated variables (e.g . allocated using the ```new```command) are destructed **when ```delete``` is called**, before the memory is actually freed by the OS. 

- Class composition 
 - It is when a class contains one or more member variables that are objects (```string``` is also this kind of class)   

 ```cpp
 class Gastank{
 }
 private:
 Gastank myTank; //class composition
 int power;
 string modelname; //class compsotion
 ``` - Construct and destruct order    
 In the case below,    
 myBelly and myBrains construct first and HungryNerd construct (outer constructor) later;   
 HungryNerd destruct (outer destructor) first, and myBelly and myBrains destruct (destructors of the inner objects) later
 
 ```
class HungryNerd {
public:        HungryNerd()      {         myBelly.eat();         myBrain.think();
      }private:      Stomach myBelly;
      Brain myBrain;
      int age; // The auto added default constructor WON’T initialize the scalar member variables!
      //you should define your own constructor and initialize them!
};
```
 
 - Advanced class composition, if the constructor is defined that required to pass a value
 
 ```cpp
 Stomach(int startGas) { 
      myGas = startGas; } 
class HungryNerd {
public:        HungryNerd()
        :mybelly(10), myBrain(150),age(19) //Add a initializer list      {         myBelly.eat();         myBrain.think();
      }private:      Stomach myBelly;
      Brain myBrain;
      int age;
};
``` 
 - **initializer list**: It sits between the constructor’sprototype and its body. It starts with a colon, followed by one or more member variables, and their parameters in parentheses.
 - you may also use the initializer list to **initialize your scalar member variables** too

- Some Rule
 - Never include a CPP file in another .CPP or .H file.
 - Never put a “using namespace” command in a header file.
 - Never assume that a header file will include some other header file for you.
- Preprocessor Directives
 - ```#define```: could use to define new constants  
 ```#define FOOBAR```
 
 - ```#ifdef```: to check if a constant has been defined already
 - ** The compiler only compiles the codebetween the```#ifdef``` and the ```#endif```if the constant was defined.

 ```
 #ifdef FOOBARvoid someFunc(void) {cout << PI; }#endif
```
 - ```#ifndef``` command to check if a constant has **NOT** been defined already 
 - ** The compiler only compiles the code between the ```#ifndef``` and the ```#endif``` if the constant was NOT defined
 
 ```
#ifdef FOOBARvoid someFunc(void) {cout << PI; }#endif
 ```
 
- Include h.file
- You Must include h file, when:
 1. You define a regular variable of that class’s type, OR 2. You use the variable in any way (call a method on it, return it, etc).
- DON’T need to include the class’s .H file.
 1. Use the class to define a parameter to a function, OR
 2. Use the class as the return type for a func, OR
 3. Use the class to define a pointer or reference variable
 
### Slide 3 





