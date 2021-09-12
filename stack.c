#include <stdio.h>
#include <stdlib.h>

typedef struct {
 int *buffer;
 int top;
 int size;
}_stack_t;

_stack_t* create_stack(int k)
{
  _stack_t* s = malloc(sizeof(_stack_t));
  s->buffer = malloc(k*sizeof(int));
  s->top = -1;
  s->size = k;
  return s;
}

void push_stack(_stack_t *s,int val)
{
  if(s->size-1==s->top)
  {
    printf("Stack Overflow!!!\n");
    return;
  }
  s->buffer[s->top+1]=val;
  s->top+=1;
}
int pop_stack(_stack_t *s)
{
  if(s->top==-1)
  {
    printf("Stack underflow!!\n");
    return -1;
  }
  return s->buffer[s->top--];
}
int top_stack(_stack_t *s)
{
  if(s->top==-1)
  {
    printf("Stack underflow!!\n");
    return -1;
  }
  return s->buffer[s->top];
}
void print_stack(_stack_t *s)
{
  for(int i=0;i<=s->top;i++)
  {
    printf("%d ",s->buffer[i]);
  }
  printf("\n");
}
void free_stack(_stack_t *s)
{
  free(s->buffer);
  free(s);
}

int main()
{
  _stack_t* s= create_stack(10);
  push_stack(s,1);
  push_stack(s,2);
  push_stack(s,3);
  pop_stack(s);
  push_stack(s,4);
  push_stack(s,5);
  int a = top_stack(s);
  printf("top_stack:%d\n",a);
  pop_stack(s);
  print_stack(s);
  free_stack(s);
  return 0;
}

