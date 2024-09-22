# CSE-5311-005-Hands-On-5
## Faisal Ahmad - 1002239354

The above code is an implementation of the minHeap. The following functionality is implemented:

- `build_min_heap`: Takes a vector as an input and builds a minHeap on the private vector `heap`. It does this by first pushing all the elements into the vector, then running the `heapify` function on every parent node in reverse order. This approach is faster than inserting the element one by one and "bubbling" up the elements as needed because the worst case time complexity for this approach is O(n), while the time complexity for inserting elements one by one is O(nlog(n)).
- `heapify`: Takes an integer as an argument, which is the index at which we want to heapify. It compares and swaps the smallest element with the top node, and then recursively heapifies the rest of the sub-tree.
- `pop`: Takes out the top most element of the heap (`heap[0]`), saves it in a variable `res`, and replaces it with the last element of the heap and then heapifies the entire heap using the `heapify()` function, then returns `res`
