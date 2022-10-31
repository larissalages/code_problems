#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
/**
 * Circular Queue implementation
 */

struct CircularQueue
{
  long *_queue;
  size_t _length;
  size_t _MAX_LENGTH;
  size_t _front_idx;
  size_t _back_idx;
} typedef CircularQueue;

void circ_queue_build(CircularQueue *);
int __empty_queue_error(void);
long circ_queue_front(CircularQueue *);
long circ_queue_back(CircularQueue *);
void circ_queue_push(CircularQueue *, long);
long circ_queue_pop(CircularQueue *);
int circ_queue_length(CircularQueue *);
void ___set_circ_queue_MAX_SIZE(CircularQueue *);
void circ_queue_build(CircularQueue *queue)
{
  queue->_MAX_LENGTH = SIZE_MAX;
  (*queue->_queue) = (long *)calloc(queue->_MAX_LENGTH, sizeof(long));
  queue->_front_idx = queue->_back_idx = 0;
  queue->_length = 0;
}

void ___set_circ_queue_MAX_SIZE(CircularQueue *queue, long long int MAX_SIZE)
{
  queue->_MAX_LENGTH = MAX_SIZE;
}

int __empty_queue_error()
{
  printf("Error the queue is empty: -1");
  return -1;
}

long circ_queue_front(CircularQueue *queue)
{
  if (circ_queue_length(queue) == 0)
    __empty_queue_error();
  return queue->_queue[queue->_front_idx];
}

long circ_queue_back(CircularQueue *queue)
{
  if (circ_queue_length(queue) == 0)
    __empty_queue_error();
  return queue->_queue[queue->_back_idx - 1];
}

int circ_queue_length(CircularQueue *queue)
{
  return abs(queue->_front_idx - queue->_back_idx);
}

void circ_queue_push(CircularQueue *queue, long element)
{
  queue->_queue[queue->_back_idx] = element;
  queue->_back_idx++;
  queue->_back_idx = queue->_back_idx % queue->_MAX_LENGTH;
}

long circ_queue_pop(CircularQueue *queue)
{
  int element = queue->_queue[queue->_front_idx];
  queue->_front_idx++;
  queue->_front_idx = queue->_front_idx % queue->_MAX_LENGTH;
  return element;
}

void circ_queue_destroy(CircularQueue *queue)
{
  free((void *)(&queue->_queue));
}

void ___test(long expected, long result)
{
  assert(expected == result);
  printf("Expected: %ld ; Result: %ld \n", expected, result);
}

int main()
{
  CircularQueue queue;

  circ_queue_build(&queue);   // queue:
  circ_queue_push(&queue, 1); // 1
  circ_queue_push(&queue, 3); // 1 3
  ___test(1, circ_queue_front(&queue));
  ___test(3, circ_queue_back(&queue));
  circ_queue_push(&queue, 4); // 1 3 4
  ___test(1, circ_queue_front(&queue));
  ___test(4, circ_queue_back(&queue));
  circ_queue_pop(&queue); // 3 4
  ___test(3, circ_queue_front(&queue));
  ___test(4, circ_queue_back(&queue));
  circ_queue_pop(&queue); // 4
  ___test(4, circ_queue_front(&queue));
  ___test(4, circ_queue_back(&queue));
  circ_queue_push(&queue, 3);

  ___test(4, circ_queue_front(&queue));
  ___test(3, circ_queue_back(&queue));

  return 0;
}