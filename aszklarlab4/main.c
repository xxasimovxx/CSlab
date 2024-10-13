#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 80

enum Status{
  out = 0,
  here = 1

};

struct Book{
  char title[MAX_TITLE_LENGTH];
  int year;
  int status;

};

void printBook(struct Book * book);
int readBook(struct Book * book);
//void copyBook();
//int compareBooks();
//void sortBooks();

int main() {
	puts("**************** Part 1 ****************");
	
	struct Book a;
  readBook(&a);
  printBook(&a);
	//Test readBook, printBook on variable a
	

	puts("\n**************** Part 2 ****************");
	/*
	Book b;
	puts("Copy Book (a to b)");
	//Test function copyBook using a and b, and use printBook to demonstrate the result

	*/

	puts("\n**************** Part 3 ****************");
	/*
	//Read new data into b

	puts("\nComparing Books:");
	//Print both books and then the result of comparison between: a and b, b and a, b and b
	
	*/

	puts("\n**************** Part 4 ****************");
	/*
	Book list[] = {
			{ "The Lord of the Rings", 1955, 1 },
			{ "Tristes Tropiques", 1955, 1 },
			{ "The Great Gatsby", 1925, 1 },
			{ "Waiting for Godot", 1952, 0 },
			{ "Midnight's Children", 1981, 0 },
			{ "1984", 1949, 0 },
			{ "For Whom the Bell Tolls", 1940,1 },
			{ "Il nome della rosa", 1981, 0 }
		};
	int const size = sizeof(list) / sizeof(Book);
	puts("Unsorted list:");
	//Print the array list
	
	//Sort it using sortBooks

	puts("\nSorted list:");
	//Print the array again
	
	*/
	
	return 0;
}

int readBook(struct Book * book){
  if(book == NULL){
    return 0;

  }
  
    char input[100];
    char * piece;
    char * endptr;
    char status[4];
    char year[4];

    printf("Input: ");

    fgets(input, sizeof(input), stdin);                             

    input[strcspn(input, "\n")] = '\0';                             
    if(!strcpy(book->title,strtok(input, " "))){
      puts("Error, wrong title value");
      return 0;

    }         
    if(!strcpy(year, strtok(NULL, " "))){
      puts("Error, wrong year value");
      return 0;

    }          

    book->year = atoi(year);

    if(book->year == 0){
      puts("Error, wrong year value");
      return 0;
  }
    

    if(!strcpy(status, strtok(NULL, " "))){
      puts("Error, wrong status value");
      return 0;
    }          

    if(strcmp(status, "here")){
      book->status = 1;

    }else if(strcmp(status, "out")){
      book->status = 0;

    }else{
    puts("Error wrong value");
  }
}

void printBook(struct Book * book){

  printf("%s ", book->title);
  printf("%s ", book->year);

}











