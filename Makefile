CC=gcc
CFLAGS=-g -Wall -Werror -Wextra -std=c++17
BUILDDIR=build
SRCEXT=cpp
SOURCES=$(wildcard *.$(SRCEXT))
OBJECTS=$(patsubst %,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TEST_FLAGS=-lgtest -lgmock -pthread
LIB=s21_matrix_oop.a

all: clean $(LIB)

test: $(LIB)
	@g++ $(CFLAGS) tests/*.cpp $(LIB) -o test $(TEST_FLAGS)
	@./test

debug: $(LIB) $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -lstdc++ -o debug
	@./debug

coverage: test
	@gcovr -r . --html --html-details -o coverage_report.html
	@open coverage_report.html

$(LIB): $(OBJECTS)
	@ar rc $(LIB) $(OBJECTS)
	@ranlib $(LIB)

$(BUILDDIR)/%.o: %.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@$(CC) -c $(CFLAGS) $< -lstdc++ -o $@ 

clean:
	@rm -rf $(OBJECTS) \
	$(LIB) \
	debug \
	test \
	$(BUILDDIR) \
	*.gc* \
	*.html \
	*.css

rebuild: clean all

.PHONY: all test clean debug


