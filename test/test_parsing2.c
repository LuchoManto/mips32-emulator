#include "../src/headers.h"
#include "../src/interpreter.h"
#include "minunit.h"

 int tests_run = 0; 
 struct ptype testdata;
 struct ptype *ptestdata;
 
 

static char * test_operation() {
     mu_assert("error, the operation is different to 'ADD'", !strcmp(testdata.operation,"ADD"));
     return 0;
 }

  static char * test_arg1() {
    mu_assert("error, the first argument is different to '$r1'", !strcmp(testdata.arg[0], "$r1"));
     return 0;
 }

  static char * test_arg2() {
    mu_assert("error, the second argument is different to '$r2'", !strcmp(testdata.arg[1], "$r2"));
     return 0;
 }
 
  static char * test_arg3() {
    mu_assert("error, the third argument is different to '$r3'", !strcmp(testdata.arg[2], "$r3"));
     return 0;
 }
 
 static char * all_tests() {
     mu_run_test(test_operation);
     mu_run_test(test_arg1);
     mu_run_test(test_arg2);
     mu_run_test(test_arg3);

     return 0;
 }
 
 int main(int argc, char **argv) {

     testdata.incoming_line = malloc(MAXSIZE);
     strcpy(testdata.incoming_line,"ADD $r1, $r2, $r3");


     ptestdata = &testdata;
     ptestdata = parseline(ptestdata);

     

     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("PARSING TEST 2 PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);
 
     return result != 0;
 }
