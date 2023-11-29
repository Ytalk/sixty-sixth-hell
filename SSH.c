	#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "character.h"
#include "ctmcharlist.h"
#include "ctmbattlequeue.h"
#include "ctmbattlesystem.h"
#include "ctminventory.h"

int main(void){
	setlocale(LC_ALL, "");
	
	struct desc_LSE *c_list = characterList();
	struct character *character_temp = NULL;
	struct node *node_temp = NULL;
    
    character_temp = newCharacter("Rogerinho", 200, 9, 0.70, 0.50, 1, 100, 70, 0.99, 10, "capacete de carapaça", 20, "casco de carapaça", 20, "escamas", 10, "botas escamosas", 1, "colar estiloso", 12, "machado", 50, 50, 25, 25, 25, 25);
	node_temp = characterNode(character_temp);
    insertCharacter(c_list, node_temp, 0);
    
    character_temp = newCharacter("You", 190, 9, 0.70, 0.50, 1, 67, 70, 0.99, 10, "capacete de carapaça", 20, "casco de carapaça", 20, "escamas", 10, "botas escamosas", 1, "colar estiloso", 10, "espada", 50, 50, 25, 25, 25, 25);
	node_temp = characterNode(character_temp);
    insertCharacter(c_list, node_temp, 0);
    
    int op_menu;

    printf(
 "   _____    _ \n"
"  / ____|  | | \n"
" | (___    | | \n"
"  |___ |   | | \n"
"  ____) |  | | \n"
" |_____/   |_| \n"
 
 );

	do{
    	printf("\n\n1. new game\n2. sair\n");
		setbuf(stdin, NULL);
    	scanf("%i",&op_menu);
    	switch(op_menu){
        	case 1:
			printf("prepare-se para morrer na fase pre-alpha, seu merda!\n");
			
			battle(c_list, c_list->LSE->info, c_list->LSE->next->info);
        	break;

	        case 2:
	        printf("encerrando...");
	        break;
	
	        default:
	        printf("error 666");
	        break;
    	}
	}while(op_menu != 2);

    return 0;
}