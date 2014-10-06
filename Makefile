#executable files go in bin folder, includes test executables
#.o files go in build folder
# .c and .h files go in scr folder

#make test compiles the tests
#make clear deletes unnecesary files


###############################--MAIN FILES COMPILATION--################################
#########################################################################################


all: bin/emul-mips

bin/emul-mips: build/main.o build/reader.o build/environment.o build/assembler.o 
	gcc -pg build/main.o build/reader.o build/environment.o build/assembler.o -o bin/emul-mips

build/reader.o: src/reader.c src/reader.h src/headers.h
	gcc -pg -c src/reader.c -o build/reader.o

build/environment.o: src/environment.c src/environment.h src/headers.h
	gcc -pg -c src/environment.c -o build/environment.o

build/assembler.o: src/assembler.c src/assembler.h src/reader.h src/headers.h 
	gcc -pg -c src/assembler.c -o build/assembler.o

build/main.o: src/main.c src/headers.h
	gcc -pg -c src/main.c -o build/main.o

###############################--INSTALL--################################
##########################################################################

install: bin/emul-mips
	chmod 755 bin/emul-mips
	sudo cp bin/emul-mips /usr/local/bin


###############################--TESTS--################################
########################################################################


###########################--ALL TESTS--################################

#environment testing is not included in general testing

test: testparser testreader testautoload testenviroment

###########################--PARSING TESTS--################################
#tests parsing functions of source file reader.c

testparser: bin/test_parsing bin/test_parsing2 bin/test_parsing3
	./bin/test_parsing 
	./bin/test_parsing2
	./bin/test_parsing3

bin/test_parsing: build/test_parsing.o build/assembler.o build/reader.o
	gcc -pg build/test_parsing.o build/assembler.o build/reader.o -o bin/test_parsing

bin/test_parsing2: build/test_parsing2.o build/assembler.o build/reader.o
	gcc -pg build/test_parsing2.o build/assembler.o build/reader.o -o bin/test_parsing2

bin/test_parsing3: build/test_parsing3.o build/assembler.o build/reader.o
	gcc -pg build/test_parsing3.o build/assembler.o build/reader.o -o bin/test_parsing3

build/test_parsing.o: test/test_parsing.c src/assembler.h src/headers.h
	gcc -c test/test_parsing.c -o build/test_parsing.o

build/test_parsing2.o: test/test_parsing2.c src/assembler.h src/headers.h
	gcc -c test/test_parsing2.c -o build/test_parsing2.o

build/test_parsing3.o: test/test_parsing3.c src/assembler.h src/headers.h
	gcc -c test/test_parsing3.c -o build/test_parsing3.o

###########################--READER TESTS--################################
#tests reading functions of source file reader.c

testreader: bin/test_reader
	./bin/test_reader

bin/test_reader: build/test_reader.o build/reader.o
	gcc build/test_reader.o build/reader.o -o bin/test_reader

build/test_reader.o: test/test_reader.c src/reader.h src/headers.h
	gcc -pg -c test/test_reader.c -o build/test_reader.o

###########################--environment TESTS--################################
#tests functions of source file environment.c

testenviroment: bin/emul-mips bin/test_enviroment
	./bin/emul-mips < test/commandfiles/test_enviroment_commands.txt > test/resultfiles/test_enviroment_result.txt
	./bin/test_enviroment

bin/test_enviroment: build/test_enviroment.o build/environment.o
	gcc build/test_enviroment.o build/environment.o -o bin/test_enviroment

build/test_enviroment.o: test/test_enviroment.c src/reader.h src/headers.h
	gcc -pg -c test/test_enviroment.c -o build/test_enviroment.o

###########################--AUTOLOAD TESTS--################################
#tests the autoloading function of the environment, passing a file argument when initiating the emulator
testautoload: bin/emul-mips bin/test_autoloader
	./bin/emul-mips ./test/testscript.elf < test/commandfiles/test_autoloader_commands.txt > test/resultfiles/test_autoloader_result.txt
	./bin/test_autoloader

bin/test_autoloader: build/test_autoloader.o
	gcc build/test_autoloader.o -o bin/test_autoloader

build/test_autoloader.o: test/test_autoloader.c src/headers.h
	gcc -pg -c test/test_autoloader.c -o build/test_autoloader.o

clear: 
	find . -name *.o -delete
	rm -f *~