//Code derived (translated) from https://github.com/fisik-yum/ucge/blob/main/cengine/llex.go
//wip. unusable
typedef enum {
	ILLEGAL,
	WHITESPACE,
	NEWLINE,
	EOF,

	//md exlcusive
	HASH,
	STAR,
	TXT
} token_t;

//why do we need this?
typedef struct {
	char[] data;
	int index;
} scanner_t;

typedef struct {
	//A token can have two forms:
	// tokenForm would just be STAR
	// stringForm would just be "**" the string literal itself.
	token_t tokenForm;
	char stringForm[];
} scanartifact_t;

//This section parses a string as input.

scanartifact_t Scan(scanner_t* s) {
	s.index++;
	if (s.index >= sizeof(s.data)) {
		return {EOF, ""};
	}
	curChar = s.data[s.index];

	switch (curChar) {
		case '#': {return break;}
		case '*': {return break;}
		case '\0': {return {EOF, ""} break;}
		default: { return {TXT, }}
	}
}