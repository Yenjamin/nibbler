EXE = nibbler

#folders
SRC_DIR = src
OBJ_DIR = obj

#list the source files at some point
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


#compiler to use
CC = clang++

#header includes
CPPFLAGS += -Ihdr $(shell sdl2-config --cflags) 
CPPFLAGS += -I$(HOME)/.brew/Cellar/sfml/2.4.2_1/include #for macos
#compiling flags
CFLAGS += -Wall -Wextra -pedantic -std=c++0x #-Werror
#LDFLAGS += -Llib
LDLIBS += $(shell sdl2-config --libs) -ldl -lncurses

LIBFLAGS = -shared -fPIC $(CPPFLAGS) $(CFLAGS) $(LDLIBS)
LIB1 = sdl2/SDL2.so
LIB2 = ncurses/ncurses.so
LIB3 = sfml/sfml.so
LIBS = $(LIB1) $(LIB2) $(LIB3)

INS = libsInstalled.true

TEST = test.out

MAKE += --no-print-directory

.PHONY: clean re fclean all

all: $(INS) $(EXE) $(LIBS)
	
$(INS):
	$(shell sh install.sh)
	touch $(INS)

$(EXE): $(OBJ)
	$(CC) $^ -o $@ $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIB1): sdl2/SDL2.cpp
	$(CC) $(LIBFLAGS) -o $(LIB1) sdl2/SDL2.cpp

$(LIB2): ncurses/ncurses.cpp
	$(CC) $(LIBFLAGS) -o $(LIB2) ncurses/ncurses.cpp

$(LIB3): sfml/sfml.cpp
	$(CC) -o $(LIB3) sfml/sfml.cpp -rpath $(HOME)/.brew/lib -L$(HOME)/.brew/lib -lsfml-graphics -lsfml-window -lsfml-system $(LIBFLAGS)


clean:
	$(RM) $(OBJ)
	$(RM) $(LIBS)

fclean:
	@$(MAKE) clean
	$(RM) $(EXE)
	$(RM) -r $(TEST) $(TEST).dSYM
	#$(RM) $(INS)

re:
	@$(MAKE) fclean
	@$(MAKE) all

$(TEST):
	$(CC) -o $(TEST) $(SRC) -g3 $(CPPFLAGS)

t:
	$(CC) $(SRC) ncurses/ncurses.cpp $(CPPFLAGS) $(CFLAGS) $(LDLIBS)

