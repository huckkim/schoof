CXX = g++-10
CXXFLAGS = -std=c++20 -Wall -MMD
EXEC = myprogram
OBJECTS = main.o integer_ring.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -I$(COMMON_DIR)/structures/RINGS -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
