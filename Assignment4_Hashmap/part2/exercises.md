# Exercises

Discuss and answer the following questions (Make sure to elaborate and justify your responses):

1. How good is the provided hash function--are we really getting constant time operations with our hashmap?
2. What is one other way you could implement the hash function? Anything creative is acceptable in this answer.
3. If I have to resize the hashmap to add more buckets, what is th Big-O complexity?
4. What is 'open addressing' in regards to hash maps and hash tables?

## Answers:

1. the provided hash function is efficient enough. We are getting constant time operations using O(n) time. 
2. The mid-square method is another numerical technique to implement the hash function. 
3. The Big-O complexity is O(n) or O(1) for insert, delete, etc. 
4. Open addressing is a method for handling collisions, where elements are stored in the hash table and the size of the table must be greater than or equal to the number of buckets. 


