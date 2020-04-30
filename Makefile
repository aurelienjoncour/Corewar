##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

ASM_DIR			= 		asm/
COREWAR_DIR 	=		corewar/

all:
	make -C $(ASM_DIR)
	make -C $(COREWAR_DIR)

clean:
	make clean -C $(ASM_DIR)
	make clean -C $(COREWAR_DIR)

fclean:
	make fclean -C $(ASM_DIR)
	make fclean -C $(COREWAR_DIR)

tests_run:
	make tests_run -C $(ASM_DIR)
	make tests_run -C $(COREWAR_DIR)

debugs:
	make debugs -C $(ASM_DIR)
	make debugs -C $(COREWAR_DIR)

re: fclean all