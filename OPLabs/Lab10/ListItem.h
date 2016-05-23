#include <iostream>
using namespace std;

struct ListItem {
	char* word;
	ListItem* next;

	ListItem();

	ListItem(char* word, ListItem* next);

	~ListItem(); 
};