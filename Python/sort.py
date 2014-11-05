# encoding=utf8
# author:shellvon
"""
Sort Algorithms
Sort Method:
    Selection Sort
    Bubble Sort
    Merge Sort
    Insertion Sort
    QuickSort
    Heap Sort
    Shell Sort
    Bucket Sort
"""


def selectionSort(seq):
    """
    See:https://en.wikipedia.org/wiki/Selection_sort
    Time Complexity: O(n*n)
    Stable: Yes 
    Description:
        Sorts an array by repeatedly finding the minimum element from unsorted
        part and putting it at the beginning
    """
    for i in xrange(0, len(seq)):
        iMin = i
        for j in xrange(i+1, len(seq)):
            if seq[iMin] > seq[j]:
                iMin = j
        seq[i], seq[iMin] = seq[iMin], seq[i]    # if i == iMin,there are no needed to swap it!
    return seq


def bubbleSort(seq):
    """
    See:http://en.wikipedia.org/wiki/Bubble_sort
    Time Complexity: O(n*n)
    Stable: Yes
    Description:
        The algorithm gets its name from the way smaller elements "bubble" to
        the top of the list. 
    Optimized:
        The above function always runs O(n^2) time even if the array is sorted.
        So,if the inner loop didn’t cause any swap then we can stop it~how do ?
        Here are the code.
    """
    for i in xrange(0, len(seq)):
        is_swap = False
        for j in xrange(0, len(seq)-i-1):
            if seq[j] > seq[j+1]:
                seq[j], seq[j+1] = seq[j+1], seq[j]
                is_swap = True
        if not is_swap:    # if there are no two elements were swapped by the inner loop, then break the loop.that's the way to optimized!!haha ~~
            break
    return seq


def merge(left, right):
    """
    Call by mergeSort,the last step
    """
    left_len, right_len = len(left), len(right)
    result_seq, i, j = [], 0, 0
    while i < left_len and j < right_len:
        if left[i] <= right[j]:
            result_seq.append(left[i])
            i += 1
        else:
            result_seq.append(right[j])
            j += 1
    # Copy the remaining elements of left/right sequence, if there are have.
    # You need to know why you should not use .append method. Instead,you can use:
    # result_seq += lst or result_seq.extend
    result_seq.extend(left[i:])  
    result_seq.extend(right[j:])
    return result_seq

def mergeSort(seq):
    """
    See:http://en.wikipedia.org/wiki/Merge_sort
    Time Complexity: O(nLogn)
    Stable: Yes
    Description:
        Divide and Conquer!!!
        1).Divide the seq in two halfs.
        2).mergeSort for first half.
        3).mergeSort for second half.
        4).merge the two half.
    This's solution code are the C++ Style:
        mid = start + (end - start)//2  # Step 1,in python,it same as (end+start)/2.
                                        # but in C++,it can be avoid the overflow when end and start are too big.
        mergeSort(seq,start,mid)        # Step 2
        mergeSort(seq,mid+1,end)        # Step 3
        merge(seq,start,mid,end)        # Step 4
    I use the Python Style for this method:
    """
    if len(seq) <= 1:
        return seq
    mid = len(seq) / 2
    left = mergeSort(seq[:mid])
    right = mergeSort(seq[mid:])
    return merge(left, right)


def insertionSort(seq):
    """
    See:http://en.wikipedia.org/wiki/Insertion_sort
    Time Complexity: O(n*n)
    Stable: Yes
    Description:
        Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands. 
    """
    for i in xrange(1, len(seq)):
        key = seq[i]
        j = i - 1
        while j >= 0 and seq[j] > key:
            seq[j+1] = seq[j]
            j = j - 1
        seq[j+1] = key
    return seq


def quickSort(seq):
    """
    See:http://en.wikipedia.org/wiki/Quicksort
    Time Complexity: O(n*n) if worst case
    Stable: No
    Description:
        Divide and Conquer!!!Same as mergeSort
        1).Pick an element,call a pivot,from the seq.
        2).Partition.
        3).Recursively.
    The pivot,there are many way to pick it:
        1).Always pick first element[implemented below]
        2).The last
        3).Random
        4).Median
    The key process in the quickSort is `how to partition` 

    More Details See:http://www.cnblogs.com/figure9/archive/2010/12/10/1902711.html
    """
    q_sort= lambda l: l if len(l)<=1 else q_sort([x for x in l[1:] if x<l[0]])+[l[0]]+q_sort([x for x in l[1:] if x>=l[0]])
    return q_sort(seq)


def heapSort(seq):
    """
    See:http://en.wikipedia.org/wiki/Heapsort
    Time Complexity: O(nLogn)
    Description:
        make heap~
    """
    pass

def shellSort(seq):
    """
    See:http://en.wikipedia.org/wiki/Shell_sort
    Time Complexity: O(n*n)
    Stable: No
    """
    pass


def buckedSort(seq):
    """
    """
    pass

if __name__ == '__main__':
    from random import shuffle
    lst = range(10)
    algorithm_map = {
        'selectionSort': selectionSort,
        'bubbleSort': bubbleSort,
        'mergeSort': mergeSort,
        'insertionSort': insertionSort,
        'quickSort': quickSort,
        'heapSort': quickSort,
        'shellSort': shellSort,
        'buckedSort': buckedSort,
    }
    for name in algorithm_map:
        shuffle(lst)
        print 'test method:', name
        print 'before sort:', lst
        print 'after  sort:', algorithm_map[name](lst)
