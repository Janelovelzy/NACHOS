// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "elevatortest.h"

// testnum is set in main.cc
int testnum = 1;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread()
{
    int num;
    
    for (num = 0; num < 5; num++) {
	printf("*** thread name %s uid %d priority %d looped %d times\n", currentThread->getName(),currentThread->getUserID(),currentThread->getPriority(),num);
        //currentThread->Yield();
    }
}

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1");

    Thread *t1 = new Thread("forked thread",7);
    Thread *t2 = new Thread("forked thread",2);
    Thread *t3 = new Thread("forked thread",4);

    t1->Fork(SimpleThread, t1->getThreadID());
    t2->Fork(SimpleThread, t2->getThreadID());
    t3->Fork(SimpleThread, t3->getThreadID());

    SimpleThread();
}

void p1(){
	int num = 0;
	 for (num = 0; num < 5; num++) {       
	       printf("*** thread name %s uid %d priority %d looped %d times\n", currentThread->getName(),currentThread->getUserID(),currentThread->getPriority(),num);
	       if (num == 0) {
		  Thread *t2 = new Thread("Thread2",2);
 		  t2->Fork(SimpleThread,1);
		}
	}
    }


void ThreadPriority(){
	Thread *t1 = new Thread("Thread1" ,7);
        t1->Fork(p1,1);
}







//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void
ThreadTest()
{
    switch (testnum) {
    case 1:
	ThreadTest1();
	break;
    case 2:
	ThreadPriority();
	break;
    default:
	printf("No test specified.\n");
	break;
    }
}

