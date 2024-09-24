run:
	gcc -g -Wall -Wextra -I include -L lib -o bin/main src/main.c -lglad -lglfw3 -lgdi32 -lopengl32 -lglm
	bin/main

build-deps:
	gcc -Wall -Wextra  -I include -c lib/glad.c -o bin/glad.o
	ar rv lib/libglad.a bin/glad.o
	ranlib lib/libglad.a
	 