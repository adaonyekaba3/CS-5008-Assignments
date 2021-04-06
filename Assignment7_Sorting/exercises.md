# Exercises

Discuss and answer the following questions (Please make sure to elaborate and justify your responses):

1. Explain what do you think the Big-Oh (worst-case) complexity of this algorithm is? Why?
2. What do you think the best-case complexity of this algorithm is?
   - Provide an example of an array of elements that fit the best-case.
3. Does insertion sort require any additional storage beyond the original array? Explain why or why not.
4. What is a 'stable sorting' algorithm? Is insertion sort a 'stable' algorithm, why or why not?

## Answers:

1. Big-Oh complexity is O(n*2) b/c at the beginning of algorithm, elements are sorted
   completely descending. In each step, all elements of the sorted sub-array must, 
   be shifted right so that the element to be sorted - which is smaller than all 
   elements sorted in each step -  can be placed at the very beginning. 

2. Best case complexity is O(n) b/c if the elements already appear in sorted order, there 
   is precisely one comparison in the inner loop and no swap operation at all. With n elements, 
   n-1 steps when we start at the second element, we come to n-1 comparison operations. 
   An example of an array is [2,3,5,7,11].

3. No it does not require additional storage 

4. A stable sorting algorithm keeps the items with the same sorting key in order. If we sort the
   list by just the first letter of each word then a stable-sort would appear in alphabetical or incrementing order. For example, [peach, straw, apple, spork] would sort to [apple, peach, straw, spork].
Yes insertion sort is a stable algorithm because it sorts in aphabetical or increase incremental order. 

