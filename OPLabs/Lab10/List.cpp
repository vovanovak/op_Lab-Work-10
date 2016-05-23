#include "List.h"

List::List(){
	root = nullptr;
}

List::List(ListItem* root){
	this->root = root;
}


void List::add_item(char* word){
	if (root != nullptr){
		ListItem* next = root;

		while (next->next != nullptr){
			next = next->next;
		}

		next->next = new ListItem(word, nullptr);
	}
	else{
		root = new ListItem(word, nullptr);
	}
}

void List::delete_item(ListItem * p){
	ListItem* next = root;

	if (next == p)
	{
		root = root->next;
		next = root;
	}
	else {
		ListItem* prev = nullptr;

		while (next != nullptr){
			if (p == next){
				prev->next = next->next;
				break;
			}
			else{
				prev = next;
				next = next->next;
			}
		}
	}
}


void List::delete_item(char * word){
	ListItem* next = root;

	if (!strcmp(next->word, word))
	{
		root = root->next;
		next = root;
	}

	ListItem* prev = NULL;

	while (next != nullptr){
		if (!strcmp(next->word, word)){
			prev->next = next->next;
		}
		else{
			prev = next;
			next = next->next;
		}
	}
}

void List::remove_common_items(){
	ListItem* next = root;

	while (next != nullptr){
		ListItem* next1 = next->next;
		while (next1 != nullptr){
			if (!strcmp(next->word, next1->word)){
				ListItem* prev = next1;
				next1 = next->next;
				delete_item(prev);
			}
			else {
				next1 = next1->next;
			}
		}

		next = next->next;
	}
}

void List::print(){
	cout << "List: " << endl;
	ListItem* next = root;
	cout << next->word << endl;
	while (next->next != nullptr){
		next = next->next;
		cout << next->word << endl;
	}
}

List::~List(){
	delete root;
}