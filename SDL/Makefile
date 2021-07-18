NAME=SDL
CC=gcc
DEBUG_FLAG=-ansi -pedantic-errors -Wall -Wextra -g -D_DEFAULT_SOURCE -lm
RELEASE_FLAGS=-ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3 -lm -D_DEFAULT_SOURCE
SDL_FLAG=-lSDLmain -lSDL
VLG_FLAGS=--leak-check=yes --track-origins=yes
INCLUDE=-I include/

all: debug release object 

debug: $(NAME).c 
	$(CC) $(DEBUG_FLAG) -o $(NAME)_debug.out $(SDL_FLAG) $^ 

release: $(NAME).c 
	$(CC) $(RELEASE_FLAGS) -o $(NAME)_release.out $(SDL_FLAG) $^ 

object: $(NAME).c
	$(CC) $(RELEASE_FLAGS) -c $^ -o $(NAME)_release.o $(SDL_FLAG)
	$(CC) $(DEBUG_FLAG) -c $^ -o $(NAME)_debug.o $(SDL_FLAG)

.PHONY: clean
clean:
	rm -rf obj/*.o lib/*.a
	
.PHONY2: clean2
clean2:
	rm -f obj/*.out

	

	


    
    
    
    

