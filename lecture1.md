# COP4600 Operating Systems
  * http://cs.ucf.edu/courses/cop4600/sum2014

- Memory management
- Process management
- HW components

-----------------------
# What is an operating system?
- Can be described as collection of system software and computer hardware  

-----------------------
- Kernel
	- Minimal process of OS that is needed at all times

-----------------------
- Model of a non-networked OS ( 4-sided pyramid )
- A model of a networked os adds another layer (5-sided pyramid)
-----------------------
- Main memory management
    - keeps track of address space of OS which is needed by multiuser environment
-----------------------
- Processor management
    - Allocates CPU time for processes (scheduling)
    - 2 types
        - Job sched
        - Process sched
-----------------------
- Device management
    - Responsibility  
        - Choose resource allocation strategy for peripheral
-----------------------
- File management
    - File access permissions
        - Binary exec
        - File read/write



----------------------------------------------
----------------------------------------------
# History
1. Mainframe
2. Minicomputer
3. Supercomputer
4. MicroComputer
    - First computer designed for single-user
5. Workstations (most powerful microcomputer)
    - Used for powerful computation
6. Servers

-----------------------
## Languages
- Fortran used for large computations
- Cobal ~ used for business (why?)
    - Most lines of code
- Flow-matic - Dr. Grace Hopper
    - Term ‘debug’ came from the fact that a moth disrupted early system hardware
- Ada

-----------------------
- Moore’s Law
    - Initially stated number of components increases exponentially every period
    - Advancements changes this
        - Physics determine how small something can get
        - “Cray” supercomputers  
            - Circular design such that control of propagation b/t wires layout (trace) is possible
              electrons moving at almost speed of light
                - When electron is flowing through a trace, and there is a bend in the circuitry and electron might escape at the right angle
                  which in turn may result in the electron jumping into adjacent wiring














-----------------------------------------------  
# Operating System Types
## Five categories of OS types
1. Batch
    - Punchcard based
    - Efficient based on *throughput* (how many jobs can be completed per unit time)
2. Interactive
    - Introduced to reduce turnaround time in debugging
    - Timesharing scheme used
3. Real-time
  - Focus on reliability
  - Used for time critical applications where data is made available within a set amount of time 100% of the time
    - Air traffic control
    - Industrial
  - 2 types of time constraints
    - Soft real-time
      - Mishaps in availability of data are tolerable
    - Hard real-time
      - Intolerable inavailability of data
      - “Bounding”
        - If many page swaps in virtual memory, overhead increases and in effect, real-time obligations may not be met
          within the required time
4. Hybrid
  - Batch and interactive hybrid
  - Accept executions of background processes
    - Batch operations are usually done in the background and given less focus until interactive operations are light
    - Interactive operations are given more focus
5. Embedded
  - Specialized Operating system, which provides only services req. by its application
  - Using only req amount of resources in hardware and software

## Distinguising Characteristics of OS types
  - Response time
  - Data input/output methods



-----------------------------------------------
# History (contd)
- First-Generation (1940’s)
  - Vacuum Tube
  - 8-bit words
  - A program usually included EVERY INSTRUCTION required by the computer to execute
    - Not the case today, as today, program includes only the instructions required to
      perform the functionality offered by program
- Second-Generation (1950’s)
    - Focused on Cost-efftiveness as computers were really expensive
- Current (2000’s)
    - Rich Design features




-----------------------------------------------
- Process
  - Two characteristics
  - Heavyweight process
    - Main program
  - Lighweight process
    - Spawned heavyweight process
  - A process is
    - A program in execution
    - Has a “Process control Block (PCB)”
    - Has a “Program Counter(PC)”
    - Can spawn threads (lightweight)


-----------------------------------------------
# Performance Measure
  - Throughput
      - u = TimeBusy/TimeTotal (where timetotal is the total amt of time of study)
      - u = TimeBusy/TimeAvail
  - Utilization
      - X = CompletedJobs/TimeFrame
      - The rate at which requests for computations are processed
