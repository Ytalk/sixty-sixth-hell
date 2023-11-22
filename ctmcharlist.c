#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "character.h"
#include "ctmcharlist.h"

struct desc_LSE *characterList(void){//cria o desc
    struct desc_LSE *descriptor = (struct desc_LSE*) malloc(sizeof(struct desc_LSE));
    descriptor->LSE = NULL;
    descriptor->lenght = 0;
    return descriptor;
}


struct character *newCharacter(char name[], int HP, int DMG, float CRIT_DMG, float DEF, int LV, int SP, int agility, float sanity, 

int helmet_act, char helmet_name[], int s_armor_act, char s_armor_name[], int i_armor_act, char i_armor_name[], int boots_act, char boots_name[], int accessory_act, char accessory_name[], int weapon_act, char weapon_name[],

int head, int torso, int arm_r, int arm_l, int leg_r, int leg_l){//cria um personagem. struct char, equipamentos e membros

    struct character *new_character = (struct character*) malloc(sizeof(struct character));

    strcpy(new_character->name, name);
    new_character->HP = HP;
    new_character->DMG = DMG;
    new_character->CRIT_DMG = CRIT_DMG;
    new_character->DEF = DEF;
    new_character->LV = LV;
    new_character->SP = SP;
    new_character->agility = agility;
    new_character->sanity = sanity;
    
    
    strcpy(new_character->equipment.helmet.name, helmet_name);
    new_character->equipment.helmet.equipment_action = helmet_act;
    
    strcpy(new_character->equipment.superior_armor.name, s_armor_name);
    new_character->equipment.superior_armor.equipment_action = s_armor_act;
   
   strcpy(new_character->equipment.inferior_armor.name, i_armor_name);
   new_character->equipment.inferior_armor.equipment_action = i_armor_act;
   
   strcpy(new_character->equipment.boots.name, boots_name);
   new_character->equipment.boots.equipment_action = boots_act;
   
   strcpy(new_character->equipment.accessory.name, accessory_name);
   new_character->equipment.accessory.equipment_action = accessory_act;
   
   strcpy(new_character->equipment.weapon.name, weapon_name);
   new_character->equipment.weapon.equipment_action = weapon_act;
   
    
    new_character->members.head = head;
    new_character->members.torso = torso;
    new_character->members.arm_right = arm_r;
    new_character->members.arm_left = arm_l;
    new_character->members.leg_right = leg_r;
    new_character->members.leg_left = leg_l;
    
    return new_character;
}


struct node *characterNode(struct character *character){//cria um nodo sem inserir
	struct node *new_character_node = (struct node*) malloc(sizeof(struct node));
	
	new_character_node->info = character;
	new_character_node->next = NULL;
	return new_character_node;
}

void insertCharacter(struct desc_LSE *list, struct node *new_character_node, int position){
	if((position > list->lenght) || (position < 0)){
		printf("posição inválida!\n");
		return;
	}

	if(position == 0){
		new_character_node->next = list->LSE;
		list->LSE = new_character_node;
		list->lenght++;
		return;
	}

	int i = 0;
	struct node *aux = list->LSE;
	struct node *ant;
	while(i < position){
		ant = aux;
		aux = aux->next;
		i++;
	}
	new_character_node->next = aux;
	ant->next = new_character_node;
	list->lenght++;
	return;
}

void showCharacter(struct desc_LSE *list){
	struct node* aux = list->LSE;

	if(list->lenght == 0)
		printf("lista vazia!\n");		
	else{
		while(aux != NULL){
			printf("\n[name: %s\nLV: %i\nHP: %i\nSP: %i\nDMG: %i\nCRIT_DMG: %f\nDEF: %f\nagility: %i\nsanity: %f]\n",
			aux->info->name, 
			aux->info->LV, 
			aux->info->HP, 
			aux->info->SP, 
			aux->info->DMG, 
			aux->info->CRIT_DMG,
			aux->info->DEF, 
			aux->info->agility,
			aux->info->sanity);
			
			printf("\n[cabeça: %i\ntronco: %i\nbraço direito: %i\nbraço esquerdo: %i\nperna direita: %i\nperna esquerda: %i]\n", 
			aux->info->members.head, 
			aux->info->members.torso, 
			aux->info->members.arm_right, 
			aux->info->members.arm_left, 
			aux->info->members.leg_right, 
			aux->info->members.leg_left);
		}
		
		printf("\n[elmo: %s / %i DEF\narmadura superior: %s / %i DEF\narmadura inferior: %s /%i DEF\nbotas: %s / %i DEF\nacessório: %s / %i efeito\narma: %s / %i DMG]\n", 
		aux->info->equipment.helmet.name,
		aux->info->equipment.helmet.equipment_action,
		
		aux->info->equipment.superior_armor.name,
		aux->info->equipment.superior_armor.equipment_action,
		
		aux->info->equipment.inferior_armor.name,
		aux->info->equipment.inferior_armor.equipment_action,
		 
		aux->info->equipment.boots.name,
		aux->info->equipment.boots.equipment_action,
		
		aux->info->equipment.accessory.name,
		aux->info->equipment.accessory.equipment_action,
		
		aux->info->equipment.weapon.name,
		aux->info->equipment.weapon.equipment_action);
	}
}

struct node *removeCharacter(struct desc_LSE *list, char char_name[]){
	if ((list->lenght == 0)){
		printf ("Lista vazia!\n");
		return NULL;
	}

	struct node *aux = list->LSE;
	struct node *ant;

	if(strcmp(aux->info->name, char_name) == 0){
		list->LSE = list->LSE->next;
		list->lenght--;
		//free(aux);
		printf("você foi deletado\n");
		return aux;
	}
	
	while((aux != NULL) && (strcmp(aux->info->name, char_name) != 0)){
		ant = aux;
	    aux = aux->next;
	}

    if(aux == NULL) {
        printf("Personagem com o nome %s não foi encontrado.\n", char_name);
        return NULL;
    }

	ant->next = aux->next;
	list->lenght--;
	printf("o personagem %s foi deletado\n",aux->info->name);
	//free(aux);
	return aux;
}

struct character *getCharacter(struct desc_LSE *list, char name[]){
    bool validate = false;
    struct node *aux = list->LSE;
    struct character *character = NULL;
    
    while(aux != NULL){
        if(strcasecmp(aux->info->name, name) == 0){
            printf("\n[name: %s\nLV: %i\nHP: %i\nSP: %i\nDMG: %i\nCRIT_DMG: %f\nDEF: %f\nagility: %i\nsanity: %f]\n", aux->info->name, aux->info->LV, aux->info->HP, aux->info->SP, aux->info->DMG, aux->info->CRIT_DMG, aux->info->DEF, aux->info->agility, aux->info->sanity);
			
			printf("\n[cabeça: %i\ntronco: %i\nbraço direito: %i\nbraço esquerdo: %i\nperna direita: %i\nperna esquerda: %i]\n", 
			aux->info->members.head, 
			aux->info->members.torso, 
			aux->info->members.arm_right, 
			aux->info->members.arm_left, 
			aux->info->members.leg_right, 
			aux->info->members.leg_left);
		
            printf("\n[elmo: %s / %i DEF\narmadura superior: %s / %i DEF\narmadura inferior: %s /%i DEF\nbotas: %s / %i DEF\nacessório: %s / %i efeito\narma: %s / %i DMG]\n", 
            aux->info->equipment.helmet.name,
            aux->info->equipment.helmet.equipment_action,
            
            aux->info->equipment.superior_armor.name,
            aux->info->equipment.superior_armor.equipment_action,
            
            aux->info->equipment.inferior_armor.name,
            aux->info->equipment.inferior_armor.equipment_action,
            
            aux->info->equipment.boots.name,
            aux->info->equipment.boots.equipment_action,
            
            aux->info->equipment.accessory.name,
            aux->info->equipment.accessory.equipment_action,
            
            aux->info->equipment.weapon.name,
            aux->info->equipment.weapon.equipment_action);
		
            validate = true;
            character = aux->info;
        }
    	aux = aux->next;
    }
    
    if(validate == false){
        printf("nenhum personagem com o nome %s foi encontrado!\n", name);
        return NULL;
    }
    
    return character;
}

void deletar(struct desc_LSE *list){
	struct node *aux = list->LSE;
	struct node *temp;

	while(list->lenght > 0){
		temp = aux;
 		aux = aux->next;
 		free(temp);
		list->lenght--;
	}
	list->LSE = NULL;
	printf("lista deletada com sucesso!\n");
}