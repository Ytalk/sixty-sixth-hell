struct equipment_helmet{
	char name[20];
	int equipment_action;
};

struct equipment_superior_armor{
	char name[20];
	int equipment_action;
};

struct equipment_inferior_armor{
	char name[20];
	int equipment_action;
};

struct equipment_boots{
	char name[20];
	int equipment_action;
};

struct equipment_accessory{
	char name[20];
	int equipment_action;
};

struct equipment_weapon{
	char name[20];
	int equipment_action;
};

struct equipment{
	struct equipment_helmet helmet;
	struct equipment_superior_armor superior_armor;
	struct equipment_inferior_armor inferior_armor;
	struct equipment_boots boots;
	struct equipment_accessory accessory;
	struct equipment_weapon weapon;
};

struct members{
	int head;
	int torso;
	int arm_right;
	int arm_left;
	int leg_right;
	int leg_left;
};

struct character{
	char name[20];
	int HP;
	int DMG;
	float CRIT_DMG;
	float DEF;
	int SP;
	int LV;
	int agility;
	float sanity;
	struct equipment equipment;
	struct members members;
};