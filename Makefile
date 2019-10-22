NAME = avm

CFLAGS = -Wall -Wextra -Werror -std=c++11
CC = clang++
OBJDIR = obj/

INCLUDES = -I execution/ -I input/ -I parsing/

_COR_SRC = main.cpp AbstractVM.cpp parsing/Lexer.cpp  \
        parsing/Parser.cpp input/FileReader.cpp  \
         execution/OperandFactory.cpp  execution/Instruction.cpp  input/CinReader.cpp \
          execution/exceptions.cpp

COR_SRC = $(_COR_SRC)

COR_INC = execution/IOperand.h AbstractVM.h parsing/Lexer.h parsing/Parser.h input/FileReader.h input/IInputReader.h \
parsing/Token.h execution/OperandFactory.h execution/Instruction.h input/CinReader.h consts.h execution/Operand.h execution/exceptions.h

COR_INCLUDES = $(INCLUDES)

COR_OBJ = $(addprefix $(OBJDIR),$(notdir $(COR_SRC:.cpp=.o)))





all: $(NAME) $(ASM) $(DISASM)

$(NAME): $(LIBFT) $(OBJDIR) $(COR_OBJ) $(COR_INC)
	@$(CC) $(CFLAGS) $(COR_OBJ) -o $(NAME) $(LIB) $(CURSES)
	@echo "\033[32m[avm is done]\033[00m"


$(OBJDIR)%.o: */%.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)


$(OBJDIR)%.o: %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME) $(ASM) $(DISASM)

re: fclean all

.PHONY: clean all fclean re
