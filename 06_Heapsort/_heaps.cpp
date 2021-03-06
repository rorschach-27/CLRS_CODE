//
// Created by zy on 2021/9/1.
//

#include "_heaps.h"


void _heap::_initialized(vector<int> A) {
    this->heap = A;
    this->length = A.size();
    this->heap_size = length;
}


void _heap::_print_heap() {
    if (heap.empty())
        return;
    for (int i = 0; i < this->heap_size; ++i) {
        cout << this->heap[i] << " ";
    }
    cout << endl;
}

//different point from the book is that the heap of book's description is start by 1.
int _heap::_parent_index(int i) {
    return floor((i - 1) / 2);
}

int _heap::_left_index(int i) {
    i = (i << 1) + 1;
    return i;
}

int _heap::_right_index(int i) {
    i = (i << 1) + 2;
    return i;
}
//

void _heap::_max_heapify(int i) {
    int largest;
    int l = _left_index(i);
    int r = _right_index(i);
    if ((l <= heap_size - 1) && (heap[l] > heap[i]))
        largest = l;
    else
        largest = i;
    if ((r <= heap_size - 1) && (heap[r] > heap[largest]))
        largest = r;
    if (largest != i) {
        _swap(this->heap, i, largest);
        _max_heapify(largest);
    }
}

void _heap::_swap(vector<int> &A, int i, int j) {
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

void _heap::_min_heapify(int i) {
    int lowest;
    int l = _left_index(i);
    int r = _right_index(i);
    if ((l <= heap_size - 1) && (heap[l] > heap[i]))
        lowest = l;
    else
        lowest = i;
    if ((r <= heap_size - 1) && (heap[r] > heap[lowest]))
        lowest = r;
    if (lowest != i) {
        _swap(this->heap, i, lowest);
        _min_heapify(lowest);
    }
}

void _heap::_max_heapify_nonrecursive(int i) {
    int l, r, largest;
    while (true) {
        l = _left_index(i);
        r = _right_index(i);
        if (heap[l] > heap[i])
            largest = l;
        else
            largest = i;
        if (heap[r] > heap[largest])
            largest = r;
        if (largest == i)
            return;
        _swap(this->heap, i, largest);
        i = largest;
    }
}

void _heap::_build_max_heap() {
    for (int i = floor(length / 2) - 1; i >= 0; --i)//notice the index is not start from 1.
        _max_heapify(i);
    this->is_max_heap = true;
}

void _heap::_heapsort() {
    if (!this->is_max_heap)
        _build_max_heap();
    for (int i = length - 1; i >= 1; --i) {
        _swap(this->heap, 0, i);
        heap_size--;
        _max_heapify(0);
    }
}

