// Created by Tailon Russell
// Homework 6
// Date: 11/23/2020.
// Source file for class Node

#include "Node.h"
Node::Node(int weight): _weight(weight), _left(nullptr), _right(nullptr) {}

Node::Node(char letter, int weight): _letter(letter), _weight(weight), _left(nullptr), _right(nullptr) {}

bool operator< (const Node & first, const Node & second){
    return first._weight > second._weight;
}
