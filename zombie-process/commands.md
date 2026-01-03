
```bash
sudo apt update

sudo apt install build-essential

sudo apt install forkstat
```

```bash
ls /proc

mount | grep proc

mount | grep sysfs

mount | grep cgroup

ls /proc/sys/kernel

ls /proc/sys/kernel/pid_max

ls /sys/fs/cgroup/

find /sys/fs/cgroup -name pids.max

find /sys/fs/cgroup -name "pids.max"

find /sys/fs/cgroup -name pids.max | xargs cat

find /sys/fs/cgroup -name "pids.max" | xargs cat
```

```bash
ps aux | grep defunct | grep Z

forkstat

ulimit -a

ulimit -u

ulimit -u 1000

cat /etc/security/limits.conf

sudo vi /etc/security/limits.conf

while true; do ps aux | grep defunct | grep Z; date -Ins ; done

gcc process_example.c -o process_example
./process_example

gcc zombie_process_example.c -o zombie_process_example
./zombie_process_example

gcc another_zombie_process.c -o another_zombie_process
./another_zombie_process

gcc many_zombie_processes_example.c -o many_zombie_processes_example
./many_zombie_processes_example

gcc infinite_zombie_processes.c -o infinite_zombie_processes
./infinite_zombie_processes
```