// Created by Tailon Russell
// Homework 6
// Date: 11/23/2020.
// Header file for class Node

#ifndef HOMEWORK6_NODE_H
#define HOMEWORK6_NODE_H
#include <memory>
class Node {
public:
    Node(int);
    Node(char, int);
    std::shared_ptr<Node> _left;
    std::shared_ptr<Node> _right;
    char _letter{};
    int _weight;
};
bool operator< (const Node & first, const Node & second);
#endif //HOMEWORK6_NODE_H
