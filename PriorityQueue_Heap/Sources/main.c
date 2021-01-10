#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "string.h"
#include "../Headers/priorityqueue_heap.h"

/* 3. Build priority queue to handle real time tasks. Tasks can arrive at time. 
      The attributes of tasks are task-id, priority, arrival time, execution time and deadline. 
      Compute waiting time, turnaround time for each job. Check whether jobs are completed within 
      the deadline specified.  It is treated that 10 is maximum priority and 1 is least priority.
*/

void test_tasksHeap() {
   Task data[6];
   Task task;

   data[0].task_id = 0;
   data[0].priority = 0;
   data[0].arrival_time = 0;
   data[0].execution_time = 0;
   data[0].deadline = 0;
   data[0].waiting_time = 0;
   data[0].turnaround_time = 0;

   data[1].task_id = 101;
   data[1].priority = 3;
   data[1].arrival_time = 0;
   data[1].execution_time = 11;
   data[1].deadline = 37;
   data[1].waiting_time = 0;
   data[1].turnaround_time = 0;

   data[2].task_id = 102;
   data[2].priority = 1;
   data[2].arrival_time = 5;
   data[2].execution_time = 28;
   data[2].deadline = 75;
   data[2].waiting_time = 0;
   data[2].turnaround_time = 0;

   data[3].task_id = 103;
   data[3].priority = 4;
   data[3].arrival_time = 12;
   data[3].execution_time = 2;
   data[3].deadline = 29;
   data[3].waiting_time = 0;
   data[3].turnaround_time = 0;

   data[4].task_id = 104;
   data[4].priority = 2;
   data[4].arrival_time = 2;
   data[4].execution_time = 10;
   data[4].deadline = 50;
   data[4].waiting_time = 0;
   data[4].turnaround_time = 0;

   data[5].task_id = 105;
   data[5].priority = 5;
   data[5].arrival_time = 9;
   data[5].execution_time = 16;
   data[5].deadline = 24;
   data[5].waiting_time = 0;
   data[5].turnaround_time = 0;


   TasksHeap h1 = tasksHeap_new(data, 5);
   TasksHeap *tasksheap = &h1;
   
   assert(tasksHeap_size(tasksheap) == 5);

// Checking waiting time, turnaround time for each job and jobs are completed within the deadline specified
   task = task_high_priority(tasksheap);
   assert(task.turnaround_time == 16);
   assert(task.waiting_time == 0);
   assert(taskCompletedWithinDeadline(tasksheap, task) == 1);

   task = task_high_priority(tasksheap);
   assert(task.turnaround_time == 15);
   assert(task.waiting_time == 13);
   assert(taskCompletedWithinDeadline(tasksheap, task) == 0);

   task = task_high_priority(tasksheap);
   assert(task.turnaround_time == 38);
   assert(task.waiting_time == 27);
   assert(taskCompletedWithinDeadline(tasksheap, task) == 1);
// Checking waiting time, turnaround time for each job and jobs are completed within the deadline specified

// New Task insert
   task.task_id = 106;
   task.priority = 6;
   task.arrival_time = 4;
   task.execution_time = 10;
   task.deadline = 20;
   task.waiting_time = 0;
   task.turnaround_time = 0;
   tasksheap = tasksHeap_insert(tasksheap, task);
   assert(tasksHeap_size(tasksheap) == 3);

   task.task_id = 107;
   task.priority = 4;
   task.arrival_time = 8;
   task.execution_time = 4;
   task.deadline = 30;
   task.waiting_time = 0;
   task.turnaround_time = 0;
   tasksheap = tasksHeap_insert(tasksheap, task);
   assert(tasksHeap_size(tasksheap) == 4);
// New Task insert

}


int main() {
   
   test_tasksHeap();
   
   return 0;
}
