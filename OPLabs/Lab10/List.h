#include "ListItem.h"

struct List {
	ListItem* root;

	List(){
		root = nullptr;
	}

	List(ListItem* root){
		this->root = root;
	}

	void add_item(char* word){
		if (root != nullptr){
			ListItem* next = root;
		
			while (next->next != nullptr){
				if (!strcmp(next->word, word))
					return;
					
				next = next->next;
			} 

			if (!strcmp(next->word, word))
				return;

			next->next = new ListItem(word, nullptr);
		}
		else{
			root = new ListItem(word, nullptr);
		}
	}

	void print(){
		cout << "List: " << endl;
		ListItem* next = root;
		cout << next->word << endl;
		while (next->next != nullptr){
			next = next->next;
			cout << next->word << endl;
		}
	}

	~List(){
		delete root;
	}
};