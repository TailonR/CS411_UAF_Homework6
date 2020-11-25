// huffcode.hpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Header for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017
//
// Modified 11/23/20
// Tailon Russell
// For CS411 Fall 2020
// Header file for class Huffcode

#ifndef FILE_HUFFCODE_H_INCLUDED
#define FILE_HUFFCODE_H_INCLUDED

#include <string>
#include <unordered_map>
#include <map>
#include "Node.h"
#include <queue>

// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {

// ***** HuffCode: ctors, dctor, op= *****
public:

    // Compiler-generated default ctor, copy ctor, copy =, dctor used

// ***** HuffCode: general public functions *****
public:

    void setWeights(const std::unordered_map<char, int> & theweights);

    std::string encode(const std::string & text) const;

    std::string decode(const std::string & codestr) const;

    void createHuffmanTree();

    void createTable(const std::shared_ptr<Node>&, std::string);


// ***** HuffCode: data members *****
private:
    std::priority_queue<Node> _minHeap;
    std::map<std::string, char> _encodings;

};  // End class HuffCode


#endif //#ifndef FILE_HUFFCODE_H_INCLUDED

