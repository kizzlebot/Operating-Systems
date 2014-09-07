
# Scheduling (cont.d) May 22, 2014
------------------
## Last lecture
- Looked at a couple scheduling schemes.
- Some schemes happen to be biased to biased to a degree

------------------
### Shortest Process Next
- Aims to reduce bias
- Non-preemptive
    - Lets the current process finish
- The process from the queued list of process, which runs after the current one finishes is the process with the shortest running time
- Any process that is requested to execute during the time a process is running is added to the queue list.
- In terms of response time, performance is increased
- In terms of variability of the response time, predictibility for long processes are reduced
    - A steady stream of short processes prolongs the execution of long processes and results in **starvation**

------------------
### Shortest remaining time
- A preemptive version of **Short Process Next**
- Scheduler chooses process from process queue with shortest expected remaining time.
- If a process is running, and a new process is added to the ready queue, if it has a shorter expected running time, it can be switched to

------------------
### Highest Response Ratio Next
- Non-preemptive 
- Response Ratio = (time_waiting+T_s)/T_s
- Based on the fact that running time cannot be known in advance but can be estimated
- Based on past history
- When a process is completed or blocked, chooses the process in ready queue with largest response ratio
- Advantage is that it accounts for age of a process.  Aging without processing increases the response ratio.
    - Even though shorter processes are favored, the amount of time a process has remained the in response queue is taken into account to make sure that they are eventually serviced.


------------------
### Feedback technique (FB)
- Preemptive
- Used in conjunction with other scheduling methods.
- If there is no way to accurately estimate the running time of a process, it instead can focus on the time spent in execution. 
- Each time a process is taken from ready queue and executed, when it is preempted, it is put back into a ready queue of lower priority than the one it was previously  
  Then it is executed in a first-come-first-serve basis.
- Shorter processes will finish quickly without moving further down the ready queue priority hierarchy.
- Longer processes will drift down the the ready queue priority hierarchy

