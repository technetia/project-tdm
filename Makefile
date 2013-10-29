CXX = gcc
CXXFLAGS = -g -Wall
OBJECTS = memory.o registers.o flag_instructions.o register_instructions.o \
    stack_instructions.o misc_instructions.o test.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = test

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}	# reads the .d files and reruns dependencies
