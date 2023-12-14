#ifndef CTMBATTLESYSTEM_H
#define CTMBATTLESYSTEM_H

void delay(int MS);
bool probability(int success);
int hitOrMiss(int DMG, float CRIT_DMG, int agility);
void attack(struct character *char_attacked, int atk, struct equipment_weapon weapon, float crit, int agility, char author_name[20], int NPC);
void battle(struct desc_LSE *list, struct character *player, struct character *oponent);

#endif // CTMBATTLESYSTEM_H