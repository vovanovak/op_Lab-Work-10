#include "ListItem.h"

ListItem::ListItem(){
	word = nullptr;
	next = nullptr;
}

ListItem::ListItem(char* word, ListItem* next) {
	this->next = next;
	this->word = new char[strlen(word) + 1];
	strcpy_s(this->word, strlen(word) + 1, word);
}

ListItem::~ListItem(){
	delete word;
	if (next != nullptr)
		delete next;
}