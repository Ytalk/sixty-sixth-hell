struct node{
    struct node *next;
    struct character *info;
};

struct desc_LSE{
    struct node *LSE;
    int lenght;
};  

struct desc_LSE *characterList(void);

struct character *newCharacter(char name[], int HP, int DMG, float CRIT_DMG, float DEF, int LV, int SP, int agility, float sanity, 
int helmet_act, char helmet_name[], int s_armor_act, char s_armor_name[], int i_armor_act, char i_armor_name[], int boots_act, char boots_name[], int accessory_act, char accessory_name[], int weapon_act, char weapon_name[],
int head, int torso, int arm_r, int arm_l, int leg_r, int leg_l);

struct node *characterNode(struct character *character);

void insertCharacter(struct desc_LSE *list, struct node *new_character_node, int position);

void showCharacter(struct desc_LSE *list);

struct node *removeCharacter(struct desc_LSE *list, char char_name[]);

struct character *getCharacter(struct desc_LSE *list, char name[]);

void deletar(struct desc_LSE *list);

