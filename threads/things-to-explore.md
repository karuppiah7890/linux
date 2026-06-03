- How to observe the Linux Kernel threads? As a whole, in general
    - How to observe the number of threads?
    - How to observe the size of the stack of the threads?
    - How to observe the state of the threads? complete / done, vs still running
    - How to observe the CPU usage of the threads?
    - How to observe the IO usage of the threads? Disk, Network etc

- What these configurations are? And what can they be set to?
    - `sudo sysctl vm.max_map_count`
    - `sudo sysctl kernel.threads-max`
    - For example
        - `sudo sysctl -w kernel.threads-max=2000000`
        - `sudo sysctl -w kernel.threads-max=999999999`
        - `sysctl -w vm.max_map_count=1000000`
        - `sudo sysctl -w vm.max_map_count=2146999999`

- How to use multiple cores? How to ensure that your program uses all the CPU cores?
