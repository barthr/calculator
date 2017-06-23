#define NUMBER '0'
#define IDENTIFIER '1'
#define ASSIGNMENT '2'
#define VARIABLE '3'
#define ALPHABET_SIZE 26 - 1 // -1 excluding the r for the most recent value

void push(double);

double pop(void);

int getop(char[]);

int getch(void);

void ungetch(int);

void handle_function(char[]);

double handle_variable(char[]);

double get_variable(char s[]);

void print_top_elem(void);

void clear(void);

void swap(void);
