#include <iostream>
using namespace std;

struct ListItem {
	char* word;
	ListItem* next;

	ListItem(){
		word = nullptr;
		next = nullptr;
	}

	ListItem(char* word, ListItem* next) {
		this->next = next;
		this->word = new char[strlen(word) + 1];
		strcpy_s(this->word, strlen(word) + 1, word);
	}

	~ListItem(){
		delete word;
		if (next != nullptr)
			delete next;
	}
};