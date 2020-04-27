//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1                    ossim.cpp
//
//  ** SOLUTION: Operating system task scheduling simulation **
//
//--------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).

#include <iostream>
#include <cstdlib>

using namespace std;

#include "PriorityQueue.cpp"

//--------------------------------------------------------------------
//
// Declaration for the task data struct
//

struct TaskData
{
    int getPriority () const
        { return priority; }     // Returns the priority. Needed by the heap.

    int priority,                // Task's priority
        arrived;                 // Time when task was enqueued

};


//--------------------------------------------------------------------

int main ()
{
    PriorityQueue<TaskData, int, Less<int> > taskPQ;   // Priority queue of tasks
    TaskData task;               // Task
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        numPtyLevels,            // Number of priority levels
        numArrivals,             // Number of new tasks arriving
        j;                       // Loop counter

    // Seed the random number generator
    srand( (unsigned int) time( NULL ) );

    cout << endl << "Enter the number of priority levels : ";
    cin >> numPtyLevels;

    cout << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    for ( minute = 0 ; minute < simLength ; minute++ )
    {
        // Dequeue the first task in the queue (if any).

        if ( ! taskPQ.isEmpty() )
        {
           task = taskPQ.dequeue();
           cout << "At " << minute << " dequeued : "
                << task.priority << " " << task.arrived << " "
                << (minute-task.arrived) << endl;
        }

        // Determine the number of new tasks and add them to
        // the queue.

        switch ( rand() % 4 )
        {
          case 0 :
          case 3 : numArrivals = 0; break;
          case 1 : numArrivals = 1; break;
          case 2 : numArrivals = 2;
        }

        task.arrived = minute;
        for ( j = 0 ; j < numArrivals ; j++ )
        {
            task.priority = rand() % numPtyLevels;
            taskPQ.enqueue(task);
        }
    }

    return 0;
}

