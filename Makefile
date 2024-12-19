##
## EPITECH PROJECT, 2024
## DAMIEN
## File description:
## Makefile
##

SRC =	src/test.c \
		src/load_config/load.c \
		src/load_config/actors.c \
		src/load_config/check.c \
		src/kronkerizer/check_extension.c \
		src/kronkerizer/kronkerize.c

OBJ = $(SRC:.c=.o)

OUT ?= .blue.out

CFLAGS = -Wall -g -lcsfml-graphics -lcsfml-window -lcsfml-audio \
	-lcsfml-system

all: $(OUT)

$(OUT): $(OBj)
	@rm -f include/my.h
	@rm -f include/my_printf.h
	@make -C lib/my > /dev/null
	@cp lib/libmy.a libmy.a
	@gcc -o $(OUT) $(SRC) $(CFLAGS) -lm  -L./lib/ -lmy > /dev/null
	@echo MAKED
	
.PHONY: run
run: re
	@echo "RUNNING $(OUT)"
	@./$(OUT)
	@echo "SUCCESFULLY RUNNED $(OUT)"

debug:	eliott
	valgrind ./$(OUT)

.PHONY: clean
clean:
	@find . -name "*~" -delete -o -name "#*#" -delete -o -name "*.out" -delete
	@find . -name "*.o" -delete -o -name "unit_tests"  -delete > /dev/null
	@find . -name "*.a" -delete -o -name "*.log" -o -name "'#*#'" -delete
	@find . -name "*.gcda" -delete -o -name "*.gcno" -delete > /dev/null
	@find . -name "unit_test" -delete > /dev/null
	@echo "CLEAN"

.PHONY: fclean
fclean: clean
	@rm -f $(OUT)

.PHONY: code
code: fclean
	@coding-style . . > /dev/null
	@cat coding-style-reports.log
	@rm -f coding-style-reports.log
	@echo "CODING-STYLE CHECKED"

.PHONY: push
push: fclean
	@git add .
	@echo "What did you change ?" ; read COMMIT ; git commit -m "$$COMMIT"
	@git push -u origin dev

re: fclean all

.PHONY: cowsay_%
cowsay_%:
	@echo " -------"
	@echo "| $(*F) |"
	@echo " -------"
	@echo "        \\   ^__^"
	@echo "         \\  (oo)\\_______"
	@echo "            (__)\\       )\\/\\"
	@echo "                ||----w |"
	@echo "                ||     ||"

.PHONY: kronk
kronk:
	@echo "Oh ouais."
