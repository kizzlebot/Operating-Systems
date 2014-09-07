## Scheduling Schemes
- Turnaround Time (T_r) = (Time spent waiting) + (Time spent processing)
- Service Time (T_s) = (Time spent processing)
- Normalize Turnaround Time = T_r/T_s

### Non-Preemptive
1. First Come First Served
    - Processes are executed in the order they arrive
2. Shortest Process Next
    - The process executed next from dispatchable is the one with the smallest processing time
3. Highest Response Ratio Next
    - The next process executed is the one with the highest value of T_r/T_s


### Preemptive
1. Round-Robin
    - Process picked to run the time quantum is the one with the longest waiting time
    - Upon completion of a time quantum, the next process picked from dispatchable is the one that had been waiting the longest
2. Shortest Remaining Time
    - Every time a new process arrives to dispatcher, the new process will be processed if it has a shorter amount of process time remaining
        - Consideration is given every time a new process is added to dispatchable processes
    - If a process completes, consideration is again given to process with shorter amount of process time remaining

----------------------------------
## Process State
- Blocked Processes
    - Processes waiting on I/O or events
- Suspended Processes
    1. Placed into state because not ready for execution 
    2. Placed into state in order to provent execution by an agent; either itself, parent process, or the OS
    3. Not allowed to exit this state until agent allows it and orders for its removal
    4. May or may not be waiting on I/O. If waiting on I/O event, it’s occurance does not enable the process to be executed
