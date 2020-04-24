##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

ASM_DIR			= 		asm/
COREWAR_DIR 	=		corewar/

all:
	make -C $(SOLVER_DIR)
	make -C $(GENERATOR_DIR)

clean:
	make clean -C $(SOLVER_DIR)
	make clean -C $(GENERATOR_DIR)

fclean:
	make fclean -C $(SOLVER_DIR)
	make fclean -C $(GENERATOR_DIR)

tests_run:
	make tests_run -C $(SOLVER_DIR)
	make tests_run -C $(GENERATOR_DIR)

re: fclean all