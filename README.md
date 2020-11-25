# Solution to Homework6 CS411 UAF
This solution implements Huffman Coding

This project was developed in Clion.
The solution consists of four files huffcode.cpp, huffcode.hpp, Node.cpp, and Node.h.
The test file is huffcode_test.cpp.

# The Problem
As stated in the Assignment_Instructions, the goal was to implement huffman coding, with efficient encoding 
and decoding algorithms.  

# Key Highlights
A few of the big issues that I had to resolve was knowing how to represent a Huffman tree, how to encode 
and decode. After doing some research I came across a geeksforgeeks article on Huffman coding 
<https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/> The way the algorithm was described in this 
article helped me a ton in creating my own Huffman tree. (The code they provided though I personally 
didn't think it helped). The other part to this that I needed to figure out was that I needed to create
the tree and the table in the setWeights function (meaning call a helper function to do it).

The next big issue was encoding. It took me a while to figure out that I needed to create a table for the 
encodings. This required me to write a helper function to create the table (in the actual code it's an
ordered map). Then once I did that I just had to traverse the string of letters and find them in the table 
and add the codeword to the result. 

The final issue I had to tackle was decoding. For this I found another geeks for geeks article 
<https://www.geeksforgeeks.org/huffman-decoding/>. This was very helpful in figuring out the algorithm. 
When I first thought of the solution I had, like the createTabe code, asked if we are on a child first and
then moved to that child, which caused the result to not move at the last step when it should, so all the 
tests on decoding a single letter, resulted in an empty string. After looking over the geeks for geeks 
article I realized that I needed to ask if we were on a node after I moved to it. 
 
# License
[MIT](https://choosealicense.com/licenses/mit/)
