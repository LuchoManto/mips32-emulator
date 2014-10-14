#include "headers.h"
#include "environment.h"
//#include "environmentcommands.h"

/**
*@brief this function runs the environment program and allows the user to enter commands
*
* 
**/
void runenv(struct ptype *env)
{
			// env->n_arg = 1;   //initialized to 1 by default, it updates later


			 env->entry = malloc(MAXSIZE);


			printf("emul-mips>"); // prints out the prompt
			
			char *result = fgets(env->entry,MAXSIZE,stdin);  
			if (result == NULL)
			{
				printf("\n");    
				exit(0);
			}
			env = parseentry(env);													

			env = analize(env); 
			restart(env);	
}

/**
*@brief this function sets to null the values in command and in arg array
*
* it just to reset and prepare the variables for the next command
**/
void restart(struct ptype *env)
{		
	env->command = NULL;
	int i;
	for (i = 0; i<env->n_arg;i++)
		env->arg[i] = NULL;
}



struct ptype *parseentry(struct ptype *env)
{

	char *buffer;
    char *temp1;
    char *temp2 = NULL;
    env->n_arg = 1; //initialized to 1 by default, it updates later if there are any arguments

	 // printf("env->entry: '%s'\n",env->entry);

	//and now we parse	
    env->command = strtok(env->entry, " ");
    strip(env->command);

    //the rest of the string remaining in buffer are the arguments. so we continue parsing
    int i = 0;
    while ((buffer = strtok(NULL, " ")) != NULL)
    {	
        env->arg[i] = buffer;
        i++;
    }
    env->n_arg = i;

	for(i = 0; i < env->n_arg; i++)
	strip(env->arg[i]);   

	return env;
}


struct ptype *analize(struct ptype *env)
{

	if(!strcmp(env->command,"exit"))
    {
    	printf("exiting mips emulator...\n");
    	exit(0);   
    }
	else if(!strcmp(env->command,"load"))
	{
		//env = load(env);
	}
	else if(!strcmp(env->command,"disp"))
	{
		printf("disp was entered...\n");
	}
	else if(!strcmp(env->command,"disasm"))
	{
		printf("disasm was entered...\n");
	}
	else if(!strcmp(env->command,"set"))
	{
		printf("set was entered...\n");
	}
	else if(!strcmp(env->command,"assert"))
	{
		printf("assert was entered...\n");
	}
	else if(!strcmp(env->command,"debug"))
	{
		printf("debug was entered...\n");
	}
	else if(!strcmp(env->command,"resume"))
	{
		printf("resume was entered...\n");
	}
	else if(!strcmp(env->command,"run"))
	{
		printf("run was entered...\n");
	}
	else if(!strcmp(env->command,"step"))
	{
		printf("step was entered...\n");
	}
	else if(!strcmp(env->command,"break"))
	{
		printf("break was entered...\n");
	}
	else printf("command '%s' not found\n",env->command);

	return env;

}

/**this function simply discards unwanted characters in a string*/
void strip(char *s) {
    char *p2 = s;
    while(*s != '\0') {
    	if(*s != '\t' && *s != '\n') {
    		*p2++ = *s++;
    	} else {
    		++s;
    	}
    }
    *p2 = '\0';
}