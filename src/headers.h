#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 512

typedef int bool;
#define true 1
#define false 0

struct ptype /// it's a structure that has all elements that are involved in the interpretation of a file
{   
	char *full_script;     
	char *parsed_script;    
	char *incoming_line;
	char *label;
	char *tag;
	char *operation;
	char *arg[4]; /// four is the maximum amount of arguments that a command can have
};

