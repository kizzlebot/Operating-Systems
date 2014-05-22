## Scheduling
### Layers of scheduling
- If long term scheduler does not see a process then medium term and short term scheduler does not see it either
- Layered similar to how the memory hierarchy is laid out.
    - Long-term is the super set
    - Medium-term is a subset of long-term
    - Short-term is a subset of Medium-term 

-----------------------
- Long-term Scheduling
    - Decides if process is to be added to pool of processes to execute using **Criteria**
        - Priority
        - Expected exec time
        - I/O requirements

    - Least frequently executed 

- Medium-term Scheduling
    - “Big aspect of the swapping function”
    - Set of processes in main memory (fully or partial)
    - Suspended processes in queue
        - Swap space/Virtual Memory

- Short-term Scheduling
    - “The Dispatcher” 
    - Anything that can interrupt a process determined by **criteria**
    - Criteria
        - Clock/Input/Output/Syscalls Interrupts
    - Types
        - User-oriented: response time of req to fulfillment
        - System-oriented: throughput (the rate at which processess are completed)
        - Performance-related
            - A measureable and analyzable
        - Non-performance-related
            - A measureable and analyzable

-----------------------
### Summary of scheduling
- System oriented / Performance-related
    - Throughput
        - Scheduling policy tries to maximize throughput (the number of processes completed per unit time)
    - Processor utilization
- System oriented / Other
    - Fairness
    - Enforcing priority
    - Balancing resources

-----------------------
### Priorities in scheduling
- Priority is a quantity that is used to determine scheduling, Processes of a priority level are assigned a “ready-queue number” (RQ#)
    - It is not sufficient because low priority processes may not receive attention from CPU (starvation)
    - Solution is to have priority that varies over time (aging)

-----------------------
### Decision Mode
#### Preemptive vs Non-Preemptive
- Preemptive 
    - Current process is allowed to be interrupted (overrided) 
- Non-Preemptive 
    - Currently running process will run until termination or until it blocks itself in the case of a interrupt
-----------------------
### Quantification
- Turnaround time 
    - Amount of time for a process to complete for given instance of process execution


-----------------------
### Scheduling Schemes
1. First come first serve scheduling
    - Queue is nonchanging for any reason 
    - “Gantt Chart” representation
        - Rows are processes
        - Columns are a unit of time
        - Gray boxes are in queue
    - If a CPU bound process is running, an I/O interrupt will cause the process to go to queue and can stack processes up if multiple I/O interrupts occur back to back

2. Round-robin scheduling
    - Uses preemption based on clock
        - Interrupt signal at determined intervals at which the currently running process is placed into the ready queue and the next item in queue is executed
        - A process in execution can be interrupted
        - CPU time sharing for processes of equal priority.  
    - Worst case scenario
        - A single process is executing 
            - Process is switched in and out for no reason, wasting CPU cycles
    - Time quantum is the determined amount of time set for process to use CPU
    - Effect of time quantum size
        1. Average turnaround time per process unaffected
        2. Average turnaround time overall is less for larger time quantum
2a. Virtual Round-robin scheduling
    - Uses two queues which is picked as next to run

3. Shortest Process Next
    - Non-Preemptive and Strictly Priority based
    - Priority based on time required for process to execute.
        - Picks process currently in ready queue with lowest time required for completion
    
4. Shortest Remaining Time
5. Highest Response Ratio Next










