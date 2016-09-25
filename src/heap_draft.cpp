class minheap {
private:
	vector<int> heaplist;

public:
	minheap(vector<int> list) {
		for (int i=0; i<list.size(); i++) {
			heappush(list[i]);
		}
	}

	minheap() {
	}

 void heappush(int x) {
 	heaplist.push_back(x);
 	shiftup(heaplist.size()-1);
 }

 void shiftup(int i) { //input index 
 	if (i == 0) return;
 	int k = (i-1)/2;
 	if (heaplist[i] >= heaplist[k]) return;
 	swap(heaplist[i], heaplist[k]);
 	shiftup[k];
 	return;
 }

 int heappop() {
 	//if (heaplist.size() == 0)  
 	swap(heaplist.front(), heaplist.back());
 	int result = heaplist.pop_back();
 	shiftdown(0);
 	return result;
 }

 void shiftdown(int i) {
 	int cl = i*2+1;
 	int cr = cl+1;
 	if (cl >= heaplist.size()) return;
 	int minIndex;
 	if (cr < heaplist.size()) {
 		minIndex = heaplist[cl] > heaplist[cr]? cl : cr;
 	}
 	else {
 		minIndex = cl;
 	}

 	if (heaplist[i] <= heaplist[minIndex]) return;
 	swap(heaplist[i], heaplist[minIndex]);
 	shiftdown(minIndex);
 	return;
 }

 int heaptop() {
 	return heaplist.front();
 } 

｝


// http://www.cplusplus.com/reference/algorithm/make_heap/
// http://www.codeproject.com/Tips/816934/Min-Binary-Heap-Implementation-in-Cplusplus
// http://www.sanfoundry.com/cpp-program-implement-binary-heap/
// http://codereview.stackexchange.com/questions/42999/implementation-of-binary-heap-in-c
// http://www.cs.uah.edu/~rcoleman/Common/CodeVault/Code/Code211_Heap.html



