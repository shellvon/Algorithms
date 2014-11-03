#encoding=utf8
#author:shellvon
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
		Sorts an array by repeatedly finding the minimum element from unsorted part and putting it at the beginning
	"""
	for i in xrange(0,len(seq)):
		iMin = i
		for j in xrange(i+1,len(seq)):
			if seq[iMin]>seq[j]:
				iMin = j
		seq[i],seq[iMin] = seq[iMin],seq[i]#if i == iMin,there are no needed to swap it!
	return seq
def bubbleSort(seq):
	"""
	See:http://en.wikipedia.org/wiki/Bubble_sort
	Time Complexity: O(n*n)
	Stable: Yes
	Description:
		The algorithm gets its name from the way smaller elements "bubble" to the top of the list. 
	Optimized:
		The above function always runs O(n^2) time even if the array is sorted.
		So,if the inner loop didn’t cause any swap then we can stop it~how do ?
		Here are the code.

	"""
	for i in xrange(0,len(seq)):
		is_swap = False
		for j in xrange(0,len(seq)-i-1):
			if seq[j]>seq[j+1]:
				seq[j],seq[j+1] = seq[j+1],seq[j]
				is_swap = True
		if not is_swap:#if there are no two elements were swapped by the inner loop, then break the loop.that's the way to optimized!!haha ~~
			break
	return seq
def mergeSort(seq):
	pass
def insertionSort(seq):
	pass
def quickSort(seq):
	pass
def heapSort(seq):
	pass
def shellSort(seq):
	pass
def buckedSort(seq):
	pass
if __name__ == '__main__':
	from random import shuffle
	lst =range(10)
	algorithm_map={
		'selectionSort':selectionSort,
		'bubbleSort':bubbleSort,
		'mergeSort':mergeSort,
		'insertionSort':insertionSort,
		'quickSort':quickSort,
		'heapSort':quickSort,
		'shellSort':shellSort,
		'buckedSort':buckedSort,
	}
	for name in algorithm_map:
		shuffle(lst)
		print 'test method:',name
		print 'before sort:',lst
		print 'after  sort:',algorithm_map[name](lst)