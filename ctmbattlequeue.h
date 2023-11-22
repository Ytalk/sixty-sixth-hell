struct desc_queue{
	struct queue_node *head;
	struct queue_node *tail;
	int lenght;
};

struct queue_node{
	struct queue_node *next;
	struct character *info;
	struct queue_node *ant;
};

struct desc_queue *newQueue(void);
struct queue_node *queueNode(struct character *character);
int empty_queue(struct desc_queue *queue);
void enqueue(struct desc_queue *queue, struct queue_node *new_queue_node);
struct queue_node *dequeue(struct desc_queue *queue);
int length(struct desc_queue *queue);
void makeNull(struct desc_queue *queue);
struct queue_node *head(struct desc_queue *queue);
void showQueue(struct desc_queue *queue);
