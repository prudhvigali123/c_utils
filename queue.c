#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sll_s
{
  int val;
  struct sll_s* next;
}sll_t;

typedef struct 
{
  sll_t* front;
  sll_t* rear;
  int size;
}queue_t;

queue_t* create_queue()
{
  queue_t* q = malloc(sizeof(queue_t));
  q->front = malloc(sizeof(sll_t));
  q->front->val = 0;
  q->front->next = NULL;
  q->rear = q->front;
  return q;
}

void enqueue(queue_t* q, int val)
{
  sll_t* new_node = malloc(sizeof(sll_t));
  new_node->val = val;
  q->rear->next = new_node;
  new_node->next = NULL;
  q->rear = new_node;
}
bool is_empty(queue_t* q)
{
  return q->front == q->rear;
}
int dequeue(queue_t* q)
{
  if(!is_empty(q))
  {
    sll_t* ele = q->front->next;
    q->front->next = q->front->next->next;
    ele->next = NULL;
    int ret = ele->val;
    free(ele);
    return ret;
  }
  else
  {
    printf("Queue is empty!!\n");
    return -1;
  }
}
int front_q(queue_t* q)
{
  if(!is_empty(q))
  {
    return q->front->next->val;
  }
  else
  {
    printf("Queue is empty!!\n");
    return -1;
  }
}
int rear_q(queue_t* q)
{
  if(!is_empty(q))
  {
    return q->rear->val;
  }
  else
  {
    printf("Queue is empty!!\n");
    return -1;
  }
}
void print_queue(queue_t* q)
{
  sll_t* temp = q->front->next;
  while(temp)
  {
    printf("%d ",temp->val);
    temp = temp->next;
  }
  printf("\n");
}
int main()
{
  queue_t* q = create_queue();
  dequeue(q);
  enqueue(q,1);
  enqueue(q,2);
  dequeue(q);
  enqueue(q,3);
  enqueue(q,4);
  print_queue(q);
  return 0;
}
