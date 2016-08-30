// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator { 
private:
    int nextval;
public:
 	PeekingIterator(const vector<int>& nums) : Iterator(nums) { // Inheritance: Inherit the whole constructor Iterator 
 	    // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	   // iterator temp;
	   // temp = *this;
	   // return temp.next();
	    return Iterator(*this).next(); //Copy constructor, here we copy a temp Iterator *this, return the temp.next()
	    //c++ access to its own address through an important pointer called this pointer. The this pointer is an implicit parameter to all member functions.
	}



	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
//This part could be deleted, since the peekingIterator inherit the Iterator constructor which already contains the same next() and hasNext() function
// 	int next() {
// 	    return Iterator::next();
	    
// 	}

// 	bool hasNext() const {
// 	    return Iterator::hasNext();
	    
// 	}
};