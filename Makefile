CC = gcc

GUI_SRC = source_code/gui.c source_code/grid.c source_code/solver.c source_code/validator.c source_code/cage.c source_code/cage_rules.c
TERM_SRC = source_code/f_all.c source_code/grid.c source_code/solver.c source_code/validator.c source_code/cage.c source_code/cage_rules.c source_code/parser.c

all: gui terminal launcher

gui:
	$(CC) $(GUI_SRC) -o gui_app -lraylib -lopengl32 -lgdi32 -lwinmm

terminal:
	$(CC) $(TERM_SRC) -o terminal_app

launcher:
	$(CC) launcher.c -o launcher

clean:
	del /Q gui_app.exe terminal_app.exe launcher.exe 2>nul || rm -f gui_app terminal_app launcher