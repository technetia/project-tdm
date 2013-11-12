CXX = gcc
CXXFLAGS = -g -Wall
OBJECTS = memory.o registers.o addressing_modes.o \
    memory_instructions.o register_instructions.o stack_instructions.o \
    flag_instructions.o misc_instructions.o instructions.o test.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = test

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}	# reads the .d files and reruns dependencies
