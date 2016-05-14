#include <iostream>
#include "List.h"
using namespace std;

char** split_string_into_words(char* str, int& words_count);
void add_word_to_array(char**& words, char* new_word, int& words_count);


void main(){
	cout << "Hello world!" << endl;

	List* lst = new List();
	
	char* str = new char[255];
	cout << "Enter string: \n";
	cin.getline(str, 255);

	int words_count = 0;

	char** words = split_string_into_words(str, words_count);

	for (int i = 0; i < words_count; i++){
		lst->add_item(words[i]);
	}

	lst->print();
}

char** split_string_into_words(char* str, int& words_count){
	char** words = new char*[words_count];
	char* word = strtok(str, ";");
	while (word != NULL){
		add_word_to_array(words, word, words_count);
		word = strtok(NULL, ";");

	}
	return words;
}


void add_word_to_array(char**& words, char* new_word, int& words_count){
	char** added_words = new char*[words_count + 1];

	for (int i = 0; i < words_count; i++){
		added_words[i] = words[i];
	}

	added_words[words_count] = new_word;

	delete words;

	words_count++;

	words = added_words;
}