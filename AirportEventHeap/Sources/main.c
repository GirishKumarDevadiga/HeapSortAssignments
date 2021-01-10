#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "string.h"
#include "../Headers/airportevent.h"

/* 4. An airport is developing a computer simulation of air-traffic control that handles events 
      such as landings and takeoffs. Each event has a time stamp that denotes the time when the 
      event will occur with additional information like, plane number, takeoff or landing. The simulation
      program needs to efficiently perform the following two fundamental operations: 
      1. Insert an event with a given time stamp, aircraft number, takeoff / landing (add a future event).
      2. Extract the event with smallest time stamp (that is, determine the next event to process). 
         Design and implement suitable data structures that work efficiently in terms of time.
*/

void test_neweventsHeap(){
   Event data[5];

   data[0].planeNumber = 0;
   data[0].timeStamp = 0;
   strcpy(data[0].eventStatus, "");
      
   data[1].planeNumber = 1;
   data[1].timeStamp = 200;
   strcpy(data[1].eventStatus, "landing");

   data[2].planeNumber = 2;
   data[2].timeStamp = 500;
   strcpy(data[2].eventStatus, "takeoff");

   data[3].planeNumber = 3;
   data[3].timeStamp = 100;
   strcpy(data[3].eventStatus, "takeoff");

   data[4].planeNumber = 4;
   data[4].timeStamp = 150;
   strcpy(data[4].eventStatus, "landing");

   eventsHeap h1 = eventsHeap_new(data, 4);
   eventsHeap *eventsheap = &h1;
   
   assert(eventsHeap_size(eventsheap) == 4);

}

// 1. Insert an event with a given time stamp, aircraft number, takeoff / landing (add a future event).
void test_eventsHeap_insert(){
   Event data[5];
   Event key;

   data[0].planeNumber = 0;
   data[0].timeStamp = 0;
   strcpy(data[0].eventStatus, "");
      
   data[1].planeNumber = 1;
   data[1].timeStamp = 200;
   strcpy(data[1].eventStatus, "landing");

   data[2].planeNumber = 2;
   data[2].timeStamp = 500;
   strcpy(data[2].eventStatus, "takeoff");

   data[3].planeNumber = 3;
   data[3].timeStamp = 100;
   strcpy(data[3].eventStatus, "takeoff");

   data[4].planeNumber = 4;
   data[4].timeStamp = 150;
   strcpy(data[4].eventStatus, "landing");

   eventsHeap h1 = eventsHeap_new(data, 4);
   eventsHeap *eventsheap = &h1;

   assert(eventsHeap_size(eventsheap) == 4);

   key.planeNumber = 5;
   key.timeStamp = 20;
   strcpy(key.eventStatus, "takeoff");

   eventsheap = eventsHeap_insert(eventsheap, key);
   assert(eventsHeap_test(eventsheap) == 1);

   key.planeNumber = 6;
   key.timeStamp = 50;
   strcpy(key.eventStatus, "takeoff");

   eventsheap = eventsHeap_insert(eventsheap, key);
   assert(eventsHeap_test(eventsheap) == 1);
}

void test_eventsHeap_test(){
   Event data[5];

   data[0].planeNumber = 0;
   data[0].timeStamp = 0;
   strcpy(data[0].eventStatus, "");
      
   data[1].planeNumber = 1;
   data[1].timeStamp = 200;
   strcpy(data[1].eventStatus, "landing");

   data[2].planeNumber = 2;
   data[2].timeStamp = 500;
   strcpy(data[2].eventStatus, "takeoff");

   data[3].planeNumber = 3;
   data[3].timeStamp = 100;
   strcpy(data[3].eventStatus, "takeoff");

   data[4].planeNumber = 4;
   data[4].timeStamp = 150;
   strcpy(data[4].eventStatus, "landing");

   eventsHeap h1 = eventsHeap_new(data, 4);
   eventsHeap *eventsheap = &h1;
    
   assert(eventsHeap_size(eventsheap) == 4);
   assert(eventsHeap_test(eventsheap) == 1);
}

// 2. Extract the event with smallest time stamp (that is, determine the next event to process).
void test_event_smallest_timestamp(){
   Event data[5];
   Event event;

   data[0].planeNumber = 0;
   data[0].timeStamp = 0;
   strcpy(data[0].eventStatus, "");
      
   data[1].planeNumber = 1;
   data[1].timeStamp = 200;
   strcpy(data[1].eventStatus, "landing");

   data[2].planeNumber = 2;
   data[2].timeStamp = 500;
   strcpy(data[2].eventStatus, "takeoff");

   data[3].planeNumber = 3;
   data[3].timeStamp = 100;
   strcpy(data[3].eventStatus, "takeoff");

   data[4].planeNumber = 4;
   data[4].timeStamp = 150;
   strcpy(data[4].eventStatus, "landing");

   eventsHeap h1 = eventsHeap_new(data, 4);
   eventsHeap *eventsheap = &h1;
    
   assert(eventsHeap_size(eventsheap) == 4);

   event = event_smallest_timestamp(eventsheap);
   assert(event.timeStamp == 100 && event.planeNumber == 3);
}

int main(){
   
   test_neweventsHeap();
   test_eventsHeap_insert();
   test_eventsHeap_test();
   test_event_smallest_timestamp();
   
   return 0;
}
