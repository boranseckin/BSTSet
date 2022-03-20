#include "BSTSet.h"
#include "Stack.h"
#include "Stack.cpp"

#include <iostream>
#include <vector>

BSTSet::BSTSet()
{
	root = NULL;
}

BSTSet::BSTSet(const std::vector<int>& input)
{
    for (int i = 0; i < input.size(); i++) add(input[i]);
}

BSTSet::~BSTSet()
{
    destroy(root);
}

void BSTSet::destroy(TNode* t)
{
    if (t == NULL) return;
    destroy(t->left);
    destroy(t->right);
    delete t;
}

bool BSTSet::isIn(int v) const
{
	if (root == NULL) return false;
    
    TNode *curr = root;
    while (curr != NULL)
    {
        if (curr->element == v) return true;
        else if (curr->element > v) curr = curr->left;
        else curr = curr->right;
    }

    return false;
}

void BSTSet::replaceWithRightMin(TNode *curr) {
    TNode *minPrev = curr;
    TNode *min = curr->right;

    if (!min) return replaceWithLeftMax(curr);

    while (min->left) {
        minPrev = min;
        min = min->left;
    }

    if (min->right) {
        if (minPrev->element > min->element) {
            minPrev->left = min->right;
        } else {
            minPrev->right = min->right;
        }
    } else {
        if (minPrev->element > min->element) {
            minPrev->left = NULL;
        } else {
            minPrev->right = NULL;
        }
    }

    curr->element = min->element;
    delete min;
}

void BSTSet::replaceWithLeftMax(TNode *curr) {
    TNode *maxPrev = curr;
    TNode *max = curr->left;

    if (!max) return replaceWithRightMin(curr);

    while (max->right) {
        maxPrev = max;
        max = max->right;
    }

    if (max->left) {
        if (maxPrev->element > max->element) {
            maxPrev->left = max->left;
        } else {
            maxPrev->right = max->left;
        }
    } else {
        if (maxPrev->element > max->element) {
            maxPrev->left = NULL;
        } else {
            maxPrev->right = NULL;
        }
    }

    curr->element = max->element;
    delete max;
}

void BSTSet::add(int v)
{
    if (isIn(v)) return;

    if (root == NULL) {
        root = new TNode(v, NULL, NULL);
    } else {
        TNode* curr = root;

        while (curr != NULL) {
            if (curr->element > v) {
                if (curr->left == NULL) {
                    curr->left = new TNode(v, NULL, NULL);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right == NULL) {
                    curr->right = new TNode(v, NULL, NULL);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
    }
}

bool BSTSet::remove(int v)
{
	if (root == NULL) return false;

    TNode *prev = NULL;
    TNode *curr = root;

    while (curr != NULL) {
        if (curr->element == v) break;

        prev = curr;
        if (curr->element > v) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (curr == NULL) return false;

    if (curr->left == NULL && curr->right == NULL) {
        if (prev == NULL) {
            root = NULL;
        } else {
            if (prev->right && prev->right->element == v) {
                prev->right = NULL;
            } else {
                prev->left = NULL;
            }
        }
        delete curr;
        return true;
    } else if (curr->left == NULL) {
        replaceWithRightMin(curr);
        return true;
    } else if (curr->right == NULL) {
        replaceWithLeftMax(curr);
        return true;
    } else {
        replaceWithRightMin(curr);
        return true;
    }
}

void BSTSet::Union(const BSTSet& s)
{
	Stack<TNode *> stack;
    stack.push(s.root);

    TNode *curr;
    while (!stack.isEmpty()) {
        curr = stack.pop();
        stack.push(curr->left);
        stack.push(curr->right);

        add(curr->element);
    }
}

void BSTSet::intersection(const BSTSet& s)
{
    if (root == NULL) return;

    std::vector<int> toBeDeleted;

    if (s.size() == 0) {
        destroy(root);
        root = NULL;
        return;
    }

    Stack<TNode *> stack;
    stack.push(root);

    TNode *curr;
    while (!stack.isEmpty()) {
        curr = stack.pop();

        stack.push(curr->left);
        stack.push(curr->right);

        if (!s.isIn(curr->element)) {
            toBeDeleted.push_back(curr->element);
        }
    }

    for (int i = 0; i < toBeDeleted.size(); i++) {
        remove(toBeDeleted[i]);
    }
}

void BSTSet::difference(const BSTSet& s)
{
	if (root == NULL || s.size() == 0) return;

    std::vector<int> toBeDeleted;

    Stack<TNode *> stack;
    stack.push(root);

    TNode *curr;
    while (!stack.isEmpty()) {
        curr = stack.pop();

        stack.push(curr->left);
        stack.push(curr->right);

        if (s.isIn(curr->element)) {
            toBeDeleted.push_back(curr->element);
        }
    }

    for (int i = 0; i < toBeDeleted.size(); i++) {
        remove(toBeDeleted[i]);
    }
}

int BSTSet::size() const
{
    if (root == NULL) return 0;

    std::vector<TNode *> queue;
    queue.push_back(root);

    int size = 1, count = 0;

    while(!queue.empty()) {
        count = queue.size();

        while(count > 0) {
            TNode *curr = queue.front();
            queue.erase(queue.begin());

            if (curr->left != NULL) {
                queue.push_back(curr->left);
                size++;
            }
            if (curr->right != NULL){
                queue.push_back(curr->right);
                size++;
            }

            count--;
        }
    }

    return size;
}

int BSTSet::height()
{
    if (root == NULL) return -1;

    std::vector<TNode *> queue;
    queue.push_back(root);

    int height = -1, count = 0;

    while(!queue.empty()) {
        count = queue.size();
        height++;

        while(count > 0) {
            TNode *curr = queue.front();
            queue.erase(queue.begin());

            if (curr->left != NULL) queue.push_back(curr->left);
            if (curr->right != NULL) queue.push_back(curr->right);

            count--;
        }
    }

    return height;
}

// create and use class MyStack
void BSTSet::printNonRec()
{
    // TODO
}

void BSTSet::printNice(TNode *t, int indent)
{
    if (t == NULL) return;

    printNice(t->right, indent + 1);

    for (int i = 0; i < indent; i++)
        std::cout << "    ";

    std::cout << t->element << std::endl;

    printNice(t->left, indent + 1);
}

// Do not modify following provided methods

void BSTSet::printBSTSet()
{
    if (root == NULL)
        std::cout << "";
    else {
        printBSTSet(root);
    }
}

void BSTSet::printBSTSet(TNode* t)
{
    if (t != NULL) {
        printBSTSet(t->left);
        std::cout << t->element << ",";
        printBSTSet(t->right);
    }
}

// int main() {
//     const std::vector<int> input = {1,4,2,5,3};
//     const std::vector<int> input2 = {9,7,8,4,5,3,6};
//     //4 5 3
//     BSTSet set = BSTSet(input);
//     BSTSet set2 = BSTSet(input2);
//     set.printNice(set.getRoot());
//     std::cout << "-------" << std::endl;
//     set.intersection(set2);
//     set.printNice(set.getRoot());
// }
