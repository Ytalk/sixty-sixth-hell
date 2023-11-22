struct equipment_label{
	char name[20];
	int equipment_action;
};

struct equipment{
	struct equipment_label helmet;
	struct equipment_label superior_armor;
	struct equipment_label inferior_armor;
	struct equipment_label boots;
	struct equipment_label accessory;
	struct equipment_label weapon;
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