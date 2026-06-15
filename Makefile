CC = gcc
RAYLIB_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -lm

step5: step5_color_draw.c
	$(CC) step5_color_draw.c -o step5 $(RAYLIB_FLAGS)

run-step5: step5
	./step5

clean:
	rm -f step5
