/**
 * @file BSTSet.h
 * @author Boran Seckin (seckinb@mcmaster.ca)
 */

#ifndef BSTSET_H_
#define BSTSET_H_

#include "TNode.h"
#include <vector>
#include <iostream>

class BSTSet
{
private:
	// must contain only one private field
	TNode* root = NULL;

public:
	// required constructors/destructor
	BSTSet();
	BSTSet(const std::vector<int>& input);
	~BSTSet();

	// required methods
	bool isIn(int v) const;
	void add(int v);
	bool remove(int v);
	void Union(const BSTSet& s);
	void intersection(const BSTSet& s);
	void difference(const BSTSet& s);
	int size() const;
	int height();
	void printNonRec(); // create and use class MyStack

	// provided recursive print method
	void printBSTSet();

	// Used for testing
	TNode* getRoot()
	{
		return root;
	}

private:
	// provided helper methods
	void printBSTSet(TNode* t);

	void destroy(TNode* t);
	void replaceWithRightMin(TNode *curr);
	void replaceWithLeftMax(TNode *curr);
	void printNice(TNode *t, int indent = 0);
};

#endif /* BSTSET_H_ */
