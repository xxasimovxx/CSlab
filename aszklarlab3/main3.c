﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_LEN 100
#define EXAMPLE_COUNT 3

int is_separator(int c);
int is_letter(int c);
const char * match_separators(const char *src);
const char * match_word(const char *src);
int match_pattern(const char *src, const char* pattern);
void pattern_replace(char src[]);

int main(void)
{
	/***************************************Part 1*************************************************/
	
	puts("*****Part 1*****");
	printf("[%c] %s an separator\n", '.', is_separator('.') ? "is" : "is not");
	printf("[%c] %s an separator\n", ';', is_separator(';') ? "is" : "is not");
	printf("[%c] %s an separator\n", '\n', is_separator('\n') ? "is" : "is not");
	printf("[%c] %s an separator\n", ' ', is_separator(' ') ? "is" : "is not");
	printf("[%c] %s an separator\n", 'A', is_separator('A') ? "is" : "is not");
	putchar('\n');
	printf("[%c] %s a letter\n", 'Z', is_letter('Z') ? "is" : "is not");
	printf("[%c] %s a letter\n", 'f', is_letter('f') ? "is" : "is not");
	printf("[%c] %s a letter\n", '\t', is_letter('\t') ? "is" : "is not");
	printf("[%c] %s a letter\n", ' ', is_letter(' ') ? "is" : "is not");
	printf("[%c] %s a letter\n", 'g', is_letter('g') ? "is" : "is not");
	

	/***************************************Part 2*************************************************/
	puts("\n*****Part 2*****");
	char words[] = "Quick brown fox17";
	char *start;
	puts("Words: ");
	for (start = words; *start != '\0';)
	{
		//non-const char* passed, so the result can be safely cast back to non-const char *
		char * end = (char *)match_word(start);
		if (end == start)
			break;
		*end = '\0';
		printf("[%s]\n", start);
		start = end + 1;
	}

	char separators[] = "., ;\t;\n.:%";
	puts("\nSeparators:");
	for (start = separators; *start != '\0';)
	{
		//non-const char* passed, so the result can be safely cast back to non-const char *
		char * end = (char *)match_separators(start);
		if (end == start)
			break;
		*end = '\0';
		printf("[%s]\n", start);
		start = end + 1;
	}

	/***************************************Part 3*************************************************/
	puts("\n*****Part 3*****");
	const char *pattern = "/w/s/w";
	printf("Pattern: [%s]\n", pattern);
	const char *text_p1[EXAMPLE_COUNT] = { "ul. Koszykowa", "Aleje Jerozolimskie 144", "ul. 30-lecia" };
	int i;
	for (i = 0; i < EXAMPLE_COUNT; ++i)
		printf("[%s] %s a match\n", text_p1[i], match_pattern(text_p1[i], pattern) ? "is" : "is not");

	pattern = "#/w/s#/w";
	printf("\nPattern: [%s]\n", pattern);
	const char *text_p2[EXAMPLE_COUNT] = { "#programming \t #rules", "#algebra #drools_", " #p1 #ftw" };
	for (i = 0; i < EXAMPLE_COUNT; ++i)
		printf("[%s] %s a match\n", text_p2[i], match_pattern(text_p2[i], pattern) ? "is" : "is not");

	/***************************************Part 4*************************************************/
	/*
	puts("\n*****Part 4*****");
	char pbuffer[BUFF_LEN] = "", tbuffer[BUFF_LEN] = "";
	puts("Input text sample:");
	fgets(pbuffer, BUFF_LEN, stdin);
	printf("[%s]", pbuffer);
	pattern_replace(pbuffer);
	printf("Pattern: [%s]\n", pbuffer);
	for (;;)
	{
		puts("Input next text sample:");
		fgets(tbuffer, BUFF_LEN, stdin);
		if (match_pattern(tbuffer, pbuffer))
			puts("It's a match!");
		else
		{
			puts("It's not a match!");
			break;
		}
	}
	*/

	return 0;
}

int is_letter(int c){
  if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
    return 1;

  }

  return 0;

}
int is_separator(int c){

  if(
    c == ' ' || c == '\t' || c == '\n' || c == ',' || 
    c == '.' || c == '!' || 
    c == '?' || c == '-' || c == '_' || c == '/' || 
    c == '\\' || c == '|' || c == '\"' || c == '\''
  ){
    return 1;

  }

  return 0;
}

const char * match_word(const char *src){
  while(*src){
    if(!is_letter(*src)){
      return src;

    }

    src++;
  }
}
const char * match_separators(const char *src){
  while(*src){
    if(!is_separator(*src)){
      return src;

    }

    src++;
  }
}

int match_pattern(const char *src, const char* pattern){
	const char * s = src;
  char p[100];
  int i = 0;
  char last_p = 'n';
  strcpy(p, "");

 while (s[i] != '\0') {
  
  if(is_separator(s[i])){
      if(last_p != 's'){
        last_p = 's';
        strcat(p, "/s");
      }
        i++;
        continue;
  } else if(is_letter(s[i])){
      if(last_p != 'w'){
        last_p = 'w';
        strcat(p, "/w");
      }
        i++;
        continue;
    } else{
      strncat(p, &s[i], 1);
      i++; 
      continue;

    }
    }

  printf("{%s}", p);
    
    return !strcmp(p, pattern);;
} 

