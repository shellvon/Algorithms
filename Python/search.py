# encoding=utf8
# author:shellvon
"""
Search Algorithms
Search Method:
    binarySearch
    DFS/BFS
"""


def isSortted(elements):
    return all(elements[i - 1] <= elements[i] for i in xrange(1, len(elements)))


def binarySearch(elements, key):
    """
    See:http://en.wikipedia.org/wiki/Binary_search_algorithm
    Time Complexity:O(Logn)
    Description:
        It can be ignore half of the elements after one comparison.
        1) Compare x with the middle element.
        2) If x matches with middle element, we return the mid index.
        3) Else if x is greater than the mid element, then x can only
           lie in right half subarray after the mid element.
        So we find for right half.
        4) Else (x is smaller) find for the left half.
    You can use Recursive/Iterative to implement it.
    Here is the Iterative python implementation of Binary Search.

    find the key from the elements.
    the elements should be a sorted list,if not,would be return None
    """
    if not isSortted(elements):
        return None
    low, high = 0, len(elements) - 1    # sum(1 for i xrange(1,len(elements)))
    while high >= low:
        # print 'find from lst:',elements[low:high+1]
        mid = low + (high - low) // 2
        if elements[mid] > key:
            high = mid - 1
        elif elements[mid] == key:
            return mid
        else:
            low = mid + 1
    return None    # if goes here it means not found in the elements


def findMin(elements):
    """
    See:https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    Time Complexity:O(Logn)
    Description:
        Find the minimum element in a sorted and rotated array use the
        binarySearch
        The solution assumes that all elements are distinct.
    """
    low, high = 0, len(elements)-1
    if low >= high:
        return elements[0]
    mid = low + (high - low) // 2
    if mid > low and elements[mid] < elements[mid-1]:
        return elements[mid]
    if mid < high and elements[mid+1] < elements[mid]:
        return elements[mid+1]
    if elements[high] > elements[mid]:
        return findMin(elements[low:mid])
    else:
        return findMin(elements[mid:])


def findMaxSub(elements):
    """
    Find The maximum sum in the subset
    return the sum and start,end as bounds.
    """
    sub_sum, tmp_sum = elements[0], 0
    bounds = (0, 0)
    start = 0
    for i in xrange(len(elements)):
        tmp_sum += elements[i]
        if tmp_sum > sub_sum:
            sub_sum = tmp_sum
            bounds = (start, i)
        elif tmp_sum < 0:
            tmp_sum = 0
            start += 1
    return bounds, sub_sum


def findMaze(grid):
    """
    visited maze
    """
    pass


def dfs(graph, start, path=[]):
    """
    See:https://en.wikipedia.org/wiki/Depth-first_search
    Description:
         Depth First Search~
    """
    if start not in graph or graph[start] is None or graph[start] == []:
        return None
    path = path + [start]    # append/extend
    for edge in graph[start]:
        if edge not in path:
            path = dfs(graph, edge, path)
    return path


def bfs(graph, start):
    """
    See:https://en.wikipedia.org/wiki/Breadth-first_search
    Description:
        Breadth First Search~
    Queue is import for this.
    """
    """
    pass
    """


if __name__ == '__main__':
    l0 = range(1)
    l1 = range(10)
    l2 = [2, -4]
    l3 = [5, 6, 7, 10, 2, 3, 4]
    l4 = [1, 2, 3, 4, 5, 6, 7, 8, 0]
    lst = [l0, l1, l2, l3, l4]
    print binarySearch(l1, 3)
    for i in lst:
        print findMin(i),
