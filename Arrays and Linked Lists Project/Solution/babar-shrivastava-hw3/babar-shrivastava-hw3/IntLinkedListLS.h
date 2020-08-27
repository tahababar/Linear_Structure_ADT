#include "IntNode.h"

#ifndef INTLINKEDLISTLS_H
#define INTLINKEDLISTLS_H

class IntLinkedListLS
{public:
	IntLinkedListLS();
	~IntLinkedListLS();

	void addToStart(int value);
	void addToIndex(int value, int index);

	int removeFromStart();
	int removeFromIndex(int index);

	int getSize();

	int get(int index);

	void printAll();

private:
	IntNode* head;
	int size;
};
#endif