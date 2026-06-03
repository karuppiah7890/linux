It might get tricky to install `perf`. Commands like below will not work

```bash
sudo apt update
sudo apt install -y linux-tools-common linux-tools-$(uname -r)
```

The above command might help install `perf` for specific Linux kernel versions but maybe not for all

To install `perf` for your specific Linux kernel version, follow the below steps :)

For example, on Ubuntu, you would do the following -

So, just find the Linux kernel version first, like this -

```bash
uname -a

uname -r
```

Assuming kernel version is `6.1.167`, you download the Linux kernel source code and use it to build `perf` from source

```bash
# install flex, bison
sudo apt update
sudo apt install -y flex bison

# Download the kernel source. For example -
wget https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.1.167.tar.xz

# uncompress the compressed file. For example -
tar -xf linux-6.1.167.tar.xz

# go inside the `perf` directory in the `tools` directory
cd linux-6.1.167/tools/perf

# check if `nproc` works
nproc

make -j$(nproc)

sudo make install

# check perf version
./perf version
```

---

Appendix:

After installing `perf`, the output of `perf` would look like this

```bash
$ ./perf

 usage: perf [--version] [--help] [OPTIONS] COMMAND [ARGS]

 The most commonly used perf commands are:
   annotate        Read perf.data (created by perf record) and display annotated code
   archive         Create archive with object files with build-ids found in perf.data file
   bench           General framework for benchmark suites
   buildid-cache   Manage build-id cache.
   buildid-list    List the buildids in a perf.data file
   c2c             Shared Data C2C/HITM Analyzer.
   config          Get and set variables in a configuration file.
   daemon          Run record sessions on background
   data            Data file related processing
   diff            Read perf.data files and display the differential profile
   evlist          List the event names in a perf.data file
   ftrace          simple wrapper for kernel's ftrace functionality
   inject          Filter to augment the events stream with additional information
   iostat          Show I/O performance metrics
   kallsyms        Searches running kernel for symbols
   kmem            Tool to trace/measure kernel memory properties
   kvm             Tool to trace/measure kvm guest os
   kwork           Tool to trace/measure kernel work properties (latencies)
   list            List all symbolic event types
   lock            Analyze lock events
   mem             Profile memory accesses
   record          Run a command and record its profile into perf.data
   report          Read perf.data (created by perf record) and display the profile
   sched           Tool to trace/measure scheduler properties (latencies)
   script          Read perf.data (created by perf record) and display trace output
   stat            Run a command and gather performance counter statistics
   test            Runs sanity tests.
   timechart       Tool to visualize total system behavior during a workload
   top             System profiling tool.
   version         display the version of perf binary
   trace           strace inspired tool

 See 'perf help COMMAND' for more information on a specific command.

$ ./perf version
perf version 6.1.167
```

When you don't have `perf` properly installed, you might get output like this for example -

```bash
$ perf
WARNING: perf not found for kernel 6.1.167

  You may need to install the following packages for this specific kernel:
    linux-tools-6.1.167-6.1.167
    linux-cloud-tools-6.1.167-6.1.167

  You may also want to install one of the following packages to keep up to date:
    linux-tools-6.1.167
    linux-cloud-tools-6.1.167
```

To search for `linux-tools` related packages, do something like this to search the package list

```bash
sudo apt update
sudo apt search linux-tools
```
