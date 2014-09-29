#include "../src/headers.h"
#include "../src/interpreter.h"
#include "minunit.h"

 int tests_run = 0; 
 struct ptype testdata;
 struct ptype *ptestdata;
 
 static char * test_tag() {
     mu_assert("error, the tag is different to '.text'", testdata.tag == ".text");
     return 0;
 }
 
 static char * test_operation() {
     mu_assert("error, the operation is different to 'ADD'", testdata.operation == "ADD");
     return 0;
 }

  static char * test_arg1() {
    mu_assert("error, the first argument is different to '$r1'", testdata.arg[0] == "$r1");
     return 0;
 }

  static char * test_arg2() {
    mu_assert("error, the second argument is different to '$r2'", testdata.arg[1] == "$r2");
     return 0;
 }
 
  static char * test_arg3() {
    mu_assert("error, the third argument is different to '$r3'", testdata.arg[2] == "$r3");
     return 0;
 }
 
  static char * test_arg4() {
    mu_assert("error, the fourth argument is different to '$r4'", testdata.arg[3] == "$r4");
     return 0;
 }
 
 static char * all_tests() {
     mu_run_test(test_tag);
     mu_run_test(test_operation);
     mu_run_test(test_arg1);
     mu_run_test(test_arg2);
     mu_run_test(test_arg3);
     mu_run_test(test_arg4);
     return 0;
 }
 
 int main(int argc, char **argv) {


     testdata.incoming_line = ".text ADD $r1, $r2, $r3, $r4  # r2 + r3 ---> r1";

     ptestdata = &testdata;
     ptestdata = parse(ptestdata);



     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);
 
     return result != 0;
 }
