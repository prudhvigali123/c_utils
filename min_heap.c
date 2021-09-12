#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *buffer;
  int idx;
  int size;
}heap_t;

heap_t* create_heap(int k)
{
  heap_t* heap = (heap_t*)malloc(sizeof(heap_t));
  heap->buffer = (int*)malloc(k*sizeof(int));
  heap->size = k;
  heap->idx = 0;
  return heap;
}
void sift_up(heap_t* heap,int endpos, int pos)
{
  int child_pos = 2*pos+1;
  while(child_pos<=endpos)
  {
    int right_pos = child_pos+1;
    if(right_pos<=endpos && heap->buffer[child_pos]>heap->buffer[right_pos])
    {
      child_pos = right_pos;
    }
    if(heap->buffer[pos]>heap->buffer[child_pos])
    {
      int temp = heap->buffer[child_pos];
      heap->buffer[child_pos] = heap->buffer[pos];
      heap->buffer[pos] = temp;
      pos = child_pos;
      child_pos = 2*pos+1;
      continue;
    }
    break;
  } 
}
void sift_down(heap_t* heap, int startpos, int pos)
{
  while(pos>startpos)
  {
    int parent = (pos-1)>>1;
    if(heap->buffer[pos]<heap->buffer[parent])
    {
      int temp = heap->buffer[parent];
      heap->buffer[parent] = heap->buffer[pos];
      heap->buffer[pos] = temp;
      pos = parent;
      continue;
    }
    break;
  }
}

void heappush(heap_t* heap,int val)
{
  heap->buffer[heap->idx] = val;
  sift_down(heap,0,heap->idx);
  heap->idx+=1;
}

int heappop(heap_t* heap)
{
  int last_item = heap->buffer[heap->idx-1];
  if(heap->idx)
  {
    int ret = heap->buffer[0];
    heap->buffer[0] = last_item;
    sift_up(heap,heap->idx-1,0);
    return ret;
  }
  heap->idx-=1;
  return last_item;
} 
 
int main()
{
  heap_t* h = create_heap(100);
  heappush(h,10);
  heappush(h,5);
  heappush(h,11);
  heappush(h,-1);
  heappush(h,100);
  int pop = heappop(h);
  printf("pop value:%d\n",pop);
  pop = heappop(h);
  printf("pop value:%d\n",pop);
  pop = heappop(h);
  printf("pop value:%d\n",pop);
  pop = heappop(h);
  printf("pop value:%d\n",pop);
  pop = heappop(h);
  printf("pop value:%d\n",pop);
}
