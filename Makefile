SHELL := bash
.ONESHELL:
.SHELLFLAGS := -eu -o pipefail -c
.DELETE_ON_ERROR:


MAKEFLAGS := $(MAKEFLAGS)
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables


ifeq ($(origin .RECIPEPREFIX), undefined)
  $(error This Make does not support .RECIPEPREFIX. Please use GNU Make 4.0 or later)
else
  .RECIPEPREFIX = >
endif


NAME  := nanotekspice


MKDIR := mkdir -p
RM    := rm -f
RMDIR := rm -fr
TOUCH := touch -a


SOURCES_DIR := ./src
INCLUDE_DIR := ./inc
OBJECTS_DIR := ./build


SOURCES_SUB_DIRS := $(shell find $(SOURCES_DIR) -type d)
OBJECTS_SUB_DIRS := $(SOURCES_SUB_DIRS:$(SOURCES_DIR)%=$(OBJECTS_DIR)%)


ifeq ($(MAKECMDGOALS), tests_run)
  SOURCES := $(shell find $(SOURCES_DIR) -type f -not -wholename "*/main.cpp" -name "*.cpp")
else
  SOURCES := $(shell find $(SOURCES_DIR) -type f -name "*.cpp")
endif

OBJECTS := $(SOURCES:$(SOURCES_DIR)/%.cpp=$(OBJECTS_DIR)/%.o)
DEPS    := $(SOURCES:$(SOURCES_DIR)/%.cpp=$(OBJECTS_DIR)/%.d)


TEST_SOURCES_DIR := ./tests
TEST_OBJECTS_DIR := ./tests_objects


TEST_SOURCES_SUB_DIRS := $(shell find $(TEST_SOURCES_DIR) -type d)
TEST_OBJECTS_SUB_DIRS := $(TEST_SOURCES_SUB_DIRS:$(TEST_SOURCES_DIR)%=$(TEST_OBJECTS_DIR)%)


TEST_SOURCES := $(shell find $(TEST_SOURCES_DIR) -type f -name "*.cpp")
TEST_OBJECTS := $(TEST_SOURCES:$(TEST_SOURCES_DIR)/%.cpp=$(TEST_OBJECTS_DIR)/%.o)


ifeq ($(MAKECMDGOALS), tests_run)
  CXX           := g++
  CXX_WARNINGS  := -Wall -Wextra
  CXXFLAGS      := -fprofile-arcs -ftest-coverage
  LDFLAGS       := -lgcov -lcriterion
else
  CXX           := clang++
  CXX_WARNINGS  := -Wall -Wextra -Wno-unused-parameter -Wpedantic
  CXXFLAGS      :=
  LDFLAGS       :=
endif


CXX_DEPS      =   -MT $(OBJECTS_DIR)/$*.o -MMD -MP -MF $(OBJECTS_DIR)/$*.d
CXX_DEBUG     :=  -g3 -ggdb3
CXX_OPTIMIZE  :=  -O2 -march=native


CXXFLAGS := $(CXXFLAGS) $(CXX_DEBUG) $(CXX_OPTIMIZE) $(CXX_WARNINGS) -I $(INCLUDE_DIR)


LDFLAGS := $(LDFLAGS)


.PHONY: all
all: $(NAME)


$(NAME): $(OBJECTS)
> @$(CXX) $^ $(LDFLAGS) -o $@
> @echo CXX $@


.PHONY: tests_run
tests_run: fclean $(OBJECTS) $(TEST_OBJECTS)
> @$(CXX) $(OBJECTS) $(TEST_OBJECTS) $(LDFLAGS) -o test
> @echo CXX $@
> ./test


$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp | $(OBJECTS_SUB_DIRS)
> @$(CXX) $(CXXFLAGS) $(CXX_DEPS) -c $< -o $@
> @echo CXX $@


$(TEST_OBJECTS_DIR)/%.o: $(TEST_SOURCES_DIR)/%.cpp | $(TEST_OBJECTS_SUB_DIRS)
> @$(CXX) $(CXXFLAGS) $(CXX_DEPS) -c $< -o $@
> @echo CXX $@


$(OBJECTS_SUB_DIRS):
> @$(MKDIR) $(OBJECTS_SUB_DIRS)
> @echo MKDIR $(OBJECTS_SUB_DIRS)


$(TEST_OBJECTS_SUB_DIRS):
> @$(MKDIR) $(TEST_OBJECTS_SUB_DIRS)
> @echo MKDIR $(TEST_OBJECTS_SUB_DIRS)


.PHONY: clean
clean:
> @$(RMDIR) $(OBJECTS_DIR)
> @echo RMDIR $(OBJECTS_DIR)
> @$(RMDIR) $(TEST_OBJECTS_DIR)
> @echo RMDIR $(TEST_OBJECTS_DIR)


.PHONY: fclean
fclean: clean
> @$(RM) $(NAME)
> @echo RM $(NAME)
> @$(RM) test
> @echo RM test


.PHONY: re
re: fclean all

-include $(DEPS)
