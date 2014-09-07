# Types of Operating Systems
- Real-time Operating Systems
    - Five requirements (Characteristics)
        1. Determinism
            - Operations are performed at fixed, predetermined times or withint predetermined time intervals
            - When multiples processes are competing for resources and processor time, no system will be full deterministic
            - In a real-time os, process requests for service are dictated by external events and times
            - The extent to which an os can deterministically satisfy requests depend on 
                1. Speed with which it can respond to interrupts 
                2. Whether the system has sufficient capacity to handle all requests within the required time.
            - A useful measure of the ability of an OS to function deterministically is the maximum delay from the arrival of a high prioirty device interupt to when servicing the interupt begins
            - In non-real-time OS, this delay may be in the range of tens to hundreds of milliseconds
        2. Responsiveness
            - Determinism is converned with how long an OS delays before acknowledging an interrupt, responsiveness is concerned with how long after acknowledgement it takes an OS to service the interrupt
            - Aspects
                - Amount of time required to initially handle the interrupt and begin execution of the interrupt service routine (ISR).
                    - If execution of the ISR requires a process switch, then the delay will be longer than if the ISR can be executed within the context of the current process
            - Reponse time requirements are critical for real-time systems because such systems must meet timing requirements impose by individuals, devices and data flows external to the system.
        3. User Control
            - Generally much broader in real-time OS than in ordinary OS
            - In a typical OS, the user either has no control over the scheduling function of the OS or can only provide broad guidance such as grouping users into more than one priority class
            - In a real-time system it is essential to allow the user fine-grained control over task priority.
            - In a real-time system the user can
                1. Specity priority 
                2. distinguish between hard and soft tasks
                3. Specify paging and/or process swapping
                4. Specify which processes mush always reside in main memory
                ....

        4. Reliability
            - Typically far more important for real-time systems than non-real-time systems
            - A transient failure in a non-real-time system may be solved by simply rebooting the system. A processor failure in a multiprocessor non-real-time system is not catastrophic
            - A real-time system is responding to and controlling events in real time. 
                - Loss or degradation of of performance may have catastrophic consequences, ranging from financial loss to major equipment damage and even loss of life.

    - Determinism and responsiveness together make up the response time to external events.
    

