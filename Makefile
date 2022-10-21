NAME_PROGRAM   = trab1
MAIN_FILE_NAME = main
SRC            = ./src
INCLUDE        = ./include
OBJ            = ./obj
FLAGS          = -lm -pedantic -Wall 
COMPILER       = gcc   

C_FILES        = $(wildcard $(SRC)/*.c)
OBJ_PATH_FILES = $(patsubst $(SRC)%,$(OBJ)%,$(C_FILES))
OBJ_FILES      = $(patsubst %.c,%.o,$(OBJ_PATH_FILES))

all: clean create_dir $(OBJ_FILES) create_final_progam

create_final_progam: $(NAME_PROGRAM)

# rule for main file
$(OBJ)/$(MAIN_FILE_NAME).o: $(SRC)/$(MAIN_FILE_NAME).c
	@ echo "\033[1;32m"
	@ echo "Compiling main program... "
	@ $(COMPILER) -c $< -I $(INCLUDE) -o $@ $(FLAGS)
	@ echo "\033[0m"

# rule for all o files
$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	@ echo "\033[1;32m"
	@ echo "Compiling program $<..."
	@ $(COMPILER) -c $< -I $(INCLUDE) -o $@ $(FLAGS)
	@ echo "\033[0m"

# rule for create_final_progam
$(NAME_PROGRAM): 
	@ echo "\033[1;32m"
	@ echo "Creating executable..."
	@ $(COMPILER) $< $(OBJ)/*.o -I $(INCLUDE) -o $@ $(FLAGS)
	@ echo "\033[0m"

# create all needed directories
create_dir: 
	@ echo "\033[1;32m"
	@ echo "Creating $(OBJ) directory...\n"
	@ mkdir $(OBJ)
	@ echo "\033[0m"

clean:
	@ echo "\033[1;35m"
	@ echo "Removing temporary files..."
	@ rm -rf $(OBJ) $(NAME_PROGRAM) $(BIN) *.mst *.tour
	@ echo "\033[0m"
