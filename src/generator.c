// This file is my own idea but I don't think it's good design
#include "stdio.h"

typedef enum {
	ILLEGAL,
	WHITESPACE,
	NEWLINE,
	EOF,

	//md exlcusive
	//look here if you wanna add anything new
	HASH,
	STAR,
	TXT
} token;

typedef struct {
	//A token can have two forms: e.g for encountered token "**"
	// t would just be STAR
	// s would just be "**" the string literal itself.
	token t;
	char s[];
} scanartifact;

//utility struct intended to help make lexing easier between functions
typedef struct {
	int index;
	char text[];
} scanintermediate;

//This function's ultimate job is to return a list of tokens for a single line, as well as it's accompanying text
//input "# hello *world*\n"
//output {{HASH, "#"}, {TXT, " hello "}, {STAR, "*"}, {TXT, "world"}, {STAR, "*"}, {NEWLINE, "\n"}}
void lexLine(char srctext[], int len, scanartifact artifacts[]) {
	int index = -1;
	int tokenCount = 0;
	
	while { //word level lex-loop
		scanartifact artifact;
		index++;

		if (index >= len) {
			return {EOF, ""};
		}
		
		char currentCharacter = srctext[index];
		//I don't think we need a isLetter or isSpace checker --1
		if (currentCharacter == '\0') {//EOF
			return {EOF, ""};
		}

		//Actually parse the thing as a real token now.
		index--;

		//do we really need this?
		char buf[256] = ""; //sus
		int bufIndex = 0;
		//md isnt whitespace delimited. this is a problem for separating tokens --1
		while { //intra-word character level lex-loop
			index++;

			if (index >= len) {
				return {EOF, buf};
			}
			
			currentCharacter = srctext[index];
			//I don't think we need a isLetter or isSpace checker
			if (currentCharacter == '\0') {//EOF
				return {EOF, ""};
			}
			buf[bufIndex] = currentCharacter;
			bufIndex++;
		}
		switch (currentCharacter) {
			case '#': {
				
			}
		}

	}


	return;
}


int main() {
	char example[] = "# hello *world*";
	scanartifact artifacts[64]; //sus
	parseLine(example, sizeof(example)/sizeof(char));
	return 0;
}
