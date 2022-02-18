##
## EPITECH PROJECT, 2022
## Makefile for NanoTekSpice
## File description:
## Makefile
##



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

SRC_DIR := ./src
INC_DIR := -I ./inc -I ./inc/Components -I ./inc/Gates -I ./inc/ComplexComponents
OBJ_DIR := ./build

SOURCES_SUB_DIRS := $(shell find $(SRC_DIR) -type d)
OBJECTS_SUB_DIRS := $(SOURCES_SUB_DIRS:$(SRC_DIR)%=$(OBJ_DIR)%)

ifeq ($(MAKECMDGOALS), tests_run)
  SOURCES := $(shell find $(SRC_DIR) -type f -not -wholename "*/main.cpp" -name "*.cpp")
else
  SOURCES := $(shell find $(SRC_DIR) -type f -name "*.cpp")
endif

OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS    := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.d)

TEST_SRC_DIR := ./tests
TEST_OBJ_DIR := ./tests_build

TEST_SOURCES_SUB_DIRS := $(shell find $(TEST_SRC_DIR) -type d)
TEST_OBJECTS_SUB_DIRS := $(TEST_SOURCES_SUB_DIRS:$(TEST_SRC_DIR)%=$(TEST_OBJ_DIR)%)

TEST_SOURCES := $(shell find $(TEST_SRC_DIR) -type f -name "*.cpp")
TEST_OBJECTS := $(TEST_SOURCES:$(TEST_SRC_DIR)/%.cpp=$(TEST_OBJ_DIR)/%.o)

ifeq ($(MAKECMDGOALS), tests_run)
  CXX           := g++
  CXX_WARNINGS  := -Wall -Wextra -Wpedantic -Wno-unused-variable
  CXXFLAGS      := -fprofile-arcs -ftest-coverage
  LDFLAGS       := -lgcov -lcriterion
else
  CXX           := clang++
  CXX_WARNINGS  := -Wall -Wextra -Wpedantic
  CXXFLAGS      := -std=c++20
  LDFLAGS       :=
endif

CXX_DEPS      =   -MT $(OBJ_DIR)/$*.o -MP -MMD  -MF $(OBJ_DIR)/$*.d
CXX_DEBUG     :=  -g3 -ggdb3
CXX_OPTIMIZE  :=  -O2 -march=native

CXXFLAGS := $(CXXFLAGS) $(CXX_DEBUG) $(CXX_OPTIMIZE) $(CXX_WARNINGS) $(INC_DIR)

LDFLAGS := $(LDFLAGS)


WHITE	    =			\e[0m
RED		    =			\e[38;5;203m
DARK_RED	= 		\e[38;5;160m
ORANGE	  =			\e[1;33m
GREEN	    =			\e[1;32m
DARK_BLUE	= 		\e[38;5;26m
CYAN 	    =			\e[38;5;51m
BOLD	    =			\e[1m

all: intro $(NAME)

intro:
>	@ printf "$(DARK_RED)$(BOLD)+-------------------------------+\n$(WHITE)"
>	@ printf "$(DARK_RED)$(BOLD)|       NanoTekSpice V0.1       |\n$(WHITE)"
>	@ printf "$(DARK_RED)$(BOLD)+-------------------------------+\n$(WHITE)"

$(NAME): $(OBJECTS)
> @ $(CXX) $^ $(LDFLAGS) -o $@
> @ printf "$(ORANGE)$@ linking success\n$(WHITE)"

tests_run: clean $(OBJECTS) $(TEST_OBJECTS)
> @$(CXX) $(OBJECTS) $(TEST_OBJECTS) $(LDFLAGS) -o test
> @ printf "$(ORANGE)Gonna launch criterion tests\n$(WHITE)"
> ./test

tests_recap:
> @ printf "$(ORANGE)$(BOLD)Tests recap:$(WHITE)\n"
> gcovr --exclude tests --exclude inc
> gcovr --exclude tests --exclude inc --branches

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJECTS_SUB_DIRS)
> @$(CXX) $(CXXFLAGS) $(CXX_DEPS) -c $< -o $@
> @ printf "$(DARK_BLUE)Compiling [$(CYAN)$@$(WHITE)$(DARK_BLUE)]$(WHITE)\n"

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp | $(TEST_OBJECTS_SUB_DIRS)
> @$(CXX) $(CXXFLAGS) $(CXX_DEPS) -c $< -o $@
> @ printf "$(DARK_BLUE)Compiling [$(CYAN)$@$(WHITE)$(DARK_BLUE)]$(WHITE)\n"

$(OBJECTS_SUB_DIRS):
> @$(MKDIR) $(OBJECTS_SUB_DIRS)

$(TEST_OBJECTS_SUB_DIRS):
> @$(MKDIR) $(TEST_OBJECTS_SUB_DIRS)

clean:
> @$(RMDIR) $(OBJ_DIR)
> @$(RMDIR) $(TEST_OBJ_DIR)
> @ printf "$(RED)Removing object files.$(WHITE)\n"

fclean: clean
> @$(RM) $(NAME)
> @$(RM) test
> @ printf "$(RED)Removing binary file.$(WHITE)\n"

re: fclean all

-include $(DEPS)

.PHONY: all tests_run clean fclean re
