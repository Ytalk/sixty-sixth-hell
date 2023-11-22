#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>


#include "character.h"
#include "ctmcharlist.h"
#include "ctmbattlequeue.h"
#include "ctmbattlesystem.h"

bool probability(int success){
    srand(time(NULL));

    int result = rand() % 100;  //numero de 0 a 99

    if (result < success){
        //porcentagem de sucesso foi correspondida
        return true;
    }
	else{
        //nao foi correspondida
        return false;
    }
}


int hitOrMiss(int DMG, float CRIT_DMG, int agility){
	int true_DMG;
	
	if(probability(agility)){
		true_DMG = DMG;
	}
	else{
		printf("miss\n");
		return 0;
	}
	
	int critical_agility = agility/2;
	
	if(probability(critical_agility)){
		printf("dano critico\n");
		true_DMG += (true_DMG * CRIT_DMG);
	}
	return true_DMG;
}


void attack(struct character *char_attacked, int atk, float crit, int agility, char author_name[20], int NPC){
	
	float def = char_attacked->DEF;

	srand(time(NULL));
    int min = 1;
    int max = 6;
    int local = rand() % (max - min + 1) + min;
	
	do{
		if(NPC == 1){
			printf("\nescolha a parte do corpo que deseja atacar:\n\n1. cabeça\n2. tronco\n3. braço direito\n4. braço esquerdo\n5. perna direita\n6. perna esquerda\n");
			setbuf(stdin, NULL);
			scanf("%i",&local);
		}

		switch (local){	
			case 1:
				if(char_attacked->members.head > 0){
					atk	 = hitOrMiss(atk, crit, agility);
					printf("%s infligiu %i de dano na cabeça do(a) %s.\n", author_name, atk, char_attacked->name);
					printf("%i ->", char_attacked->members.head);
					char_attacked->members.head -= atk-(atk*def);
					printf(" %i\n", char_attacked->members.head);
					
					if(char_attacked->members.head <= 0){
						printf("a cabeça do(a) %s foi arrancada.\n", char_attacked->name);
						char_attacked->HP = 0;
					}

					printf("vida total: %i ->", char_attacked->HP);
					char_attacked->HP -= atk-(atk*def);
					printf(" %i\n", char_attacked->HP);
				}
			break;
			
			case 2:
				if(char_attacked->members.torso > 0){
					atk = hitOrMiss(atk, crit, agility);
					printf("%s infligiu %i de dano no tronco do(a) %s.\n", author_name, atk, char_attacked->name);
					printf("%i ->", char_attacked->members.torso);
					char_attacked->members.torso -= atk-(atk*def);
					printf(" %i\n", char_attacked->members.torso);
					
					
					if(char_attacked->members.torso <= 0){
						//printf("a cabeça do(a) %s foi arrancada.\n", char_attacked->name);
						char_attacked->HP = 0;
					}

					printf("vida total: %i ->", char_attacked->HP);
					char_attacked->HP -= atk-(atk*def);
					printf(" %i\n", char_attacked->HP);
				}
			break;
			
			case 3:
				if(char_attacked->members.arm_right > 0){
					atk = hitOrMiss(atk, crit, agility);
					printf("%s infligiu %i de dano no braço direito do(a) %s.\n", author_name, atk, char_attacked->name);
					printf("%i ->", char_attacked->members.arm_right);
					char_attacked->members.arm_right -= atk-(atk*def);
					printf(" %i\n", char_attacked->members.arm_right);

					if(char_attacked->members.arm_right <= 0)
						printf("o braço direito do(a) %s foi arrancado.\n", char_attacked->name);

					printf("vida total: %i ->", char_attacked->HP);
					char_attacked->HP -= atk-(atk*def);
					printf(" %i\n", char_attacked->HP);
				}
				else{
					printf("o braço direito do(a) %s já foi arrancado.\n", char_attacked->name);
					local = 666;
				}
			break;
				
			case 4:
				if(char_attacked->members.arm_left > 0){
					atk = hitOrMiss(atk, crit, agility);
					printf("%s infligiu %i de dano no braço esquerdo do(a) %s.\n", author_name, atk, char_attacked->name);
					printf("%i ->", char_attacked->members.arm_left);
					char_attacked->members.arm_left -= atk-(atk*def);
					printf(" %i\n", char_attacked->members.arm_left);

					if(char_attacked->members.arm_left <= 0)
						printf("o braço esquerdo do(a) %s foi arrancado.\n", char_attacked->name);

					printf("vida total: %i ->", char_attacked->HP);
					char_attacked->HP -= atk-(atk*def);
					printf(" %i\n", char_attacked->HP);
				}
				else{
					printf("o braço esquerdo do(a) %s já foi arrancado.\n", char_attacked->name);
					local = 666;
				}
			break;
			
			case 5:
				if(char_attacked->members.leg_right > 0){
					atk = hitOrMiss(atk, crit, agility);
					printf("%s infligiu %i de dano na perna direita do(a) %s.\n", author_name, atk, char_attacked->name);
					printf("%i ->", char_attacked->members.leg_right);
					char_attacked->members.leg_right -= atk-(atk*def);
					printf(" %i\n", char_attacked->members.leg_right);

					if(char_attacked->members.leg_right <= 0)
						printf("a perna direita do(a) %s foi arrancado.\n", char_attacked->name);

					printf("vida total: %i ->", char_attacked->HP);
					char_attacked->HP -= atk-(atk*def);
					printf(" %i\n", char_attacked->HP);
				}
				else{
					printf("a perna direita do(a) %s já foi arrancada.\n", char_attacked->name);
					local = 666;
				}
			break;
			
			case 6:
				if(char_attacked->members.leg_left > 0){
					atk = hitOrMiss(atk, crit, agility);
					printf("%s infligiu %i de dano na perna esquerda do(a) %s.\n", author_name, atk, char_attacked->name);
					printf("%i ->", char_attacked->members.leg_left);
					char_attacked->members.leg_left -= atk-(atk*def);
					printf(" %i\n", char_attacked->members.leg_left);

					if(char_attacked->members.leg_left <= 0)
						printf("a perna esquerda do(a) %s foi arrancado.\n", char_attacked->name);

					printf("vida total: %i ->", char_attacked->HP);
					char_attacked->HP -= atk-(atk*def);
					printf(" %i\n", char_attacked->HP);
				}
				else{
					printf("a perna esquerda do(a) %s já foi arrancada.\n", char_attacked->name);
					local = 666;
				}
			break;
		
			default:
				printf("escolha invalida.\n");
			break;
		}
			
	}while((local > 6) || (local < 1));
	return;		
}


void battle(struct desc_LSE *list, struct character *player, struct character *oponent){
	bool victory = false;
	bool defeat = false;
	struct desc_queue *queue = newQueue();
	struct queue_node *new_queue_node = NULL;
	
	while((victory == false) && (defeat == false)){
		new_queue_node = queueNode(player);
		enqueue(queue, new_queue_node);
		new_queue_node = queueNode(oponent);
		enqueue(queue, new_queue_node);

		new_queue_node = head(queue);
		if(strcmp(new_queue_node->info->name, player->name) == 0){
			printf("\n\n===================================================================\n\t\t\tS E U   T U R N O\n");
			int op;
			do{
				printf("\n\n1. a t t a c k\t\t2. r e s t\t\t3. s k i l l s\n\n4. t a l k\t\t5. i t e m\t\t6. r u n\n");
				setbuf(stdin, NULL);
				scanf("%i",&op);
				switch(op){
					case 1:
					if(player->SP >= 12){
						attack(oponent, player->DMG, player->CRIT_DMG, player->agility, player->name, 1);
						player->SP -= 12;
					}
					else{
						printf("estamina insuficiente.\n");
						op = 666;
					}
					break;

					case 2:
					printf("descansando...\n");
					player->SP += 9;
					break;

					case 3:
					printf("NAO IMPLEMENTADO\n");
					break;

					case 4:
					printf("NAO IMPLEMENTADO\n");
					break;

					case 5:
					printf("NAO IMPLEMENTADO\n");
					break;
					
					case 6:
					if(probability(player->agility)){
						printf("você escapou com sucesso!\n");
						return;
					}
					printf("você não conseguiu escapar!\n");
					break;

					default:
					printf("escolha inválida na batalha.\n");
					break;
					
				}
			}while((op > 6) || (op < 1));
			printf("===================================================================\n\n");
			dequeue(queue);
			if(oponent->HP <= 0)
				victory = true;
		}

		new_queue_node = head(queue);
		if(strcmp(new_queue_node->info->name, oponent->name) == 0){
			printf("\n\n===================================================================\n\t\tT U R N O   D O   O P O N E N T E\n\n\n");
			if(oponent->SP >= 12){
				sleep(2);
				attack(player, oponent->DMG, oponent->CRIT_DMG, oponent->agility, oponent->name, 2);
				oponent->SP -= 12;
			}
			else{
				printf("descansando...\n");
				oponent->SP += 9;
			}
			printf("===================================================================\n\n");
			dequeue(queue);
			if(player->HP <= 0)
				defeat = true;
		}
	}

	if(victory == true){
		printf("you win!\n");
		removeCharacter(list ,oponent->name);
	}
	else{
		printf("you lose!\n");
		removeCharacter(list, player->name);
	}

	return;
}