# Multiprocessor Scheduling (contd) [May 27]
-------------
1. Load Sharing
- Processes not assigned to particular processor 
    - Distributed evenly
- Simplest approach
- Carries over directly from uniprocessor environment

2. Gang Scheduling
3. Dedicated Processor Assignment
4. Dynamic Scheduling
-------------
1. Load Sharing
- Advantage
    - Evenly distributed workload, assuring that no processor is idle while work is available to do
    - No centralized scheduler required
        - When a processor becomes available, the next process to execute is given to the processor.
    - Global queue is organized and accessed using any scheduling scheme used for uniprocessor 
- Disadvantage
    - Central queue occupies memory space and forces mutual exclusion.
        - Becomes a bottleneck if many processors are looking for work at the same time.
        - When many processors are available the bottleneck is far more of a factor than small number of processors

------------- 
2. Gang Sharing
- Simulataneous scheduling of all threads that compose a program
- Goals
    - If closely related processes are executed in parallel, synchronization blocking is reduced, less process switching is required and therefore performance is increased
    - Scheduling overhead may be reduced due to the fact that a single decision affects a number of processors and processes at the same time.
- Improves the performance of a single application, is that process switches are reduced
    - If application requires tight process synchronization, overall performance is reduced
- Time division
    1. Uniform Distribution
        - Two programs with n number of threads are given equal number of time slice of the processor
    2. Division By Weight
        - Depending on the number of threads a program uses, the program is assigned a time slice
------------- 
3. Dedicated Processor Assignment
    - A group of processors is assigned to a certain application
    - Observation
        - No more need to worry about processor utilization
        - No more multiprogramming. The task of scheduling is reduced to point of being negligible
            - No more need to worry about context switching
------------- 
4. Dynamic Scheduling
    - Uses programming language tools and system tools as an advantage. 
        - ie Java mutithreaded application
    - Allows OS to accordingly adjust the load for better utilization

