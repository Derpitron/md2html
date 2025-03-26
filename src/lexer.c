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
    IDENT
} token_t;

//why do we need this?
typedef struct {
    char[] data;
    int index;
} scanner_t;

typedef struct {
    token_t tokenForm;
    char stringForm[];
} scanartifact_t;

int isHash(char c) {
    return c == '#';
}

int isStar(char c) {
    return c == '*';
}

//This section parses a string as input.

scanartifact_t Scan(scanner_t* s) {
    s.index++;
    if (s.index >= sizeof(s.data)) {
        return {EOF, ""};
    }
    curChar = s.data[s.index];
    switch (c) {
         case '#': {break;}
         case '*': {break;}
        case '\0': {return {EOF, ""} break;}
        default: { return {ILLEGAL, ""}}
    }
}