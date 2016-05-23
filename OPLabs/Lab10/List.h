#include "ListItem.h"

struct List {
	ListItem* root;

	List();
	List(ListItem* root);

	void add_item(char* word);
	void delete_item(ListItem * p);
	void delete_item(char * word);
	void remove_common_items();
	void print();

	~List();
};