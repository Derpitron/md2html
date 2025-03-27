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
} artifact;

//utility struct intended to help make lexing easier between functions
typedef struct {
	int index;
	char text[];
} scanintermediate;

//This function's ultimate job is to return a list of tokens for a single line, as well as it's accompanying text
//input "# hello *world*\n"
//output {{HASH, "#"}, {TXT, " hello "}, {STAR, "*"}, {TXT, "world"}, {STAR, "*"}, {NEWLINE, "\n"}}
void lexLine(char srctext[], int len, artifact artifacts[]) {
	//TODO: replace artifact list with a stack for easy use?
	int index = -1;
	int tokenIndex = 0;
	
	while { //word level lex-loop
		artifact artifact;
		index++;

		if (index >= len) {
				artifact = {EOF, ""}; //TODO: what does the break; statement do here
				break;
		}
		
		char currentCharacter = srctext[index];
		//I don't think we need a isLetter or isSpace checker --1
		if (currentCharacter == '\0') {//EOF
			artifact = {EOF, ""}; //TODO: what does the break; statement do here
			break;
		}

		//Actually parse the thing as a real token now.
		index--;

		char buf[256] = ""; //sus
		int bufIndex = 0;
		//md isnt whitespace delimited. this is a problem for separating tokens --1
		while { //intra-word character level lex-loop
			index++;

			if (index >= len) {
				artifact = {EOF, buf}; //TODO: what does the break; statement do here
				break;
			}
			
			currentCharacter = srctext[index];
			//I don't think we need a isLetter or isSpace checker
			if (currentCharacter == '\0') {//EOF
				artifact = {EOF, ""}; //TODO: what does the break; statement do here
				break;
			} else if (currentCharacter == '#') {
				while (currentCharacter == '#') { //for header levels h1, h2, etc
					buf[bufIndex] = currentCharacter;
					index++;
					currentCharacter = srctext[index];
				} //finished parsing header, now we ignore any more header characters in the rest of the line
				artifact = {HASH, buf}; //TODO: buf is still {'#', '#', '#', '\0', '',...,''} etc etc for 250 something more bytes. this is too big
			}
			buf[bufIndex] = currentCharacter;
			bufIndex++;
		}

		artifacts[tokenIndex] = artifact; //Append the artifact to the artifact list
		tokenIndex++;
	}


	return;
}


int main() {
	char example[] = "# hello *world*";
	artifact artifacts[64]; //sus
	parseLine(example, sizeof(example)/sizeof(char));
	return 0;
}
