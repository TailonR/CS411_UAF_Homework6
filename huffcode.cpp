// huffcode.cpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Source for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017
//
// Modified 11/23/20
// Tailon Russell
// For CS411 Fall 2020
// Source file for class Huffcode

#include "huffcode.hpp"  // for class HuffCode declaration
#include <string>
#include <unordered_map>
#include <utility>

//  HuffCode::setWeights
//  given an unordered map create a heap and call helper functions to create a Huffman tree and an ordered map
//  Pre: theweights needs to be a valid unordered_map
void HuffCode::setWeights(const std::unordered_map<char, int> & theweights) {
    for (auto pair: theweights) {
        Node newNode(std::get<0>(pair), std::get<1>(pair));
        _minHeap.push(newNode);
    }
    if(!_minHeap.empty()) {
        createHuffmanTree();
        createTable(std::make_shared<Node>(_minHeap.top()), "");
    }
}

//  HuffCode::createHuffmanTree
//  A helper function to create a Huffman tree
//  Pre: None
void HuffCode::createHuffmanTree() {
    while (_minHeap.size() > 1) {
        auto lowestWeightNode1 = _minHeap.top();
        _minHeap.pop();
        auto lowestWeightNode2 = _minHeap.top();
        _minHeap.pop();
        Node newNode(lowestWeightNode1._weight+lowestWeightNode2._weight);
        newNode._left = std::make_shared<Node>(lowestWeightNode1);
        newNode._right = std::make_shared<Node>(lowestWeightNode2);
        _minHeap.push(newNode);
    }
}

//  HuffCode::createTable
//  A helper function to create a table of encodings for each letter
//  Pre: root has to be a valid shared_ptr
void HuffCode::createTable(const std::shared_ptr<Node>& root, std::string codeword){
    if (root == nullptr) {
        return;
    }
    if (root->_left == nullptr) {
        if (codeword.empty())
            codeword += "0";
        _encodings[codeword] = root->_letter;
        return;
    }
    codeword += "0";
    createTable(root->_left, codeword);
    codeword = codeword.substr(0, codeword.size()-1);
    codeword += "1";
    createTable(root->_right, codeword);
}

//  HuffCode::encode
//  Given a text, encode the text, with each letter being encoded as the key in the table
//  Pre: None
std::string HuffCode::encode(const std::string & text) const {
    std::string codeword;
    for (const auto &letter: text){
        for (const auto& it: _encodings) {
            if (it.second == letter) {
                codeword.append(it.first);
                break;
            }
        }
    }
    return codeword;
}

//  HuffCode::decode
//  Given a string, decode it as described in the Huffman Tree
//  Pre: None
std::string HuffCode::decode(const std::string & codestr) const
{
    std::string decoded;
    std::shared_ptr<Node> node;
    if (!codestr.empty())
        node = std::make_shared<Node>(_minHeap.top());

    for (auto digit: codestr) {
        if (digit == '0')
            node = node->_left;
        if (digit == '1')
            node = node->_right;

        if (node->_left == nullptr) {
            decoded += node->_letter;
            node = std::make_shared<Node>(_minHeap.top());
        }
    }
    return decoded;
}
