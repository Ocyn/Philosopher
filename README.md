<br/>
<p>
  <a href="https://github.com/Ocyn/Philosopher">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/768px-42_Logo.svg.png" alt="Logo" width="80" height="80">
  </a>

  <h1>Philosopher</h1>

  <p>
    42 School Project | Made in 2023 - 2024
    <br/>
    <br/>
  </p>
</p>

![Contributors](https://img.shields.io/github/contributors/Ocyn/Philosopher?color=dark-green) ![Issues](https://img.shields.io/github/issues/Ocyn/Philosopher) 

## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Authors](#authors)
* [Acknowledgements](#acknowledgements)

## About The Project

**Philosopher** is a multi-threaded program that simulates the dining philosophers problem.
The program creates threads to represent philosophers sitting at a round table, where they alternate between eating, thinking, and sleeping.
Philosophers must share forks to eat, and the simulation stops when a philosopher dies of starvation or when each philosopher has eaten a specified number of times.

## Project Structure

- **Source Files (`src/`):**
  - `philo.c`: Main entry point and program flow.
  - `parsing.c`: Parsing functions for command-line arguments.
  - `error.c`: Error handling functions.
  - `tools.c` and `tools_2.c`: Utility functions and helpers.
  - `threads.c`: Functions related to thread management.
  - `init.c`: Initialization functions.

- **Header File (`Philosopher.h`):**
  - Declarations of structures and function prototypes.

## Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language))

## Getting Started

**Compatibility and Performance Notice**

This project, **Philosopher**, has been primarily developed and tested on a Linux Ubuntu system. It is important to note that the project may encounter compatibility issues when executed on different operating systems. The utilization of Linux-specific features, libraries, or commands could lead to unexpected behavior on non-Linux platforms.

Additionally, since **Philosopher** is a project that involves manipulating threads and focuses on optimizing performance, it is crucial to emphasize that the stability and smooth execution of the project depend significantly on the hardware and software configuration of the machine on which the program runs.

For optimal performance and compatibility, it is recommended to execute this project on a Linux environment, preferably Ubuntu. Attempting to run the project on other operating systems may result in errors or unintended behavior. Please consider these factors before proceeding with the compilation and execution of **Philosopher**.

### Prerequisites

If you don't have Make
* Make

```sh
apt-get install build-essential make
```

### Installation

Clone the repo

```sh
git clone https://github.com/Ocyn/Philosopher.git
cd Philosopher/
```

## Compilation and Usage:

1. **Makefile:**
   - The project includes a Makefile with the following rules: `NAME`, `all`, `clean`, `fclean`, and `re`.

2. **Compilation:**
   - Compile the project using the provided Makefile.

  ```bash
  make
  ```

3. **Execution:**

Run the program with file names and shell commands.
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
  - **number_of_philosophers:** Specifies the total number of philosophers in the simulation, and consequently, the number of forks on the table.
  - **time_to_die:** Represents the time limit, in milliseconds, within which a philosopher must start eating to avoid starvation.
  - **time_to_eat:** Signifies the time, in milliseconds, it takes for a philosopher to complete a meal while holding two forks.
  - **time_to_sleep:** Denotes the time, in milliseconds, a philosopher spends sleeping after finishing a meal or thinking.
  - **[number_of_times_each_philosopher_must_eat]:** Optional argument; if provided, indicates the number of times each philosopher must eat before the simulation concludes. If not specified, the simulation halts when any philosopher dies.

4. **Clean Up:**
Clean up object files and executable.
```bash
make clean
```

# Behavior:
The Philosopher program operates through the following steps:
1. Philosophers are represented as threads.
2. Each philosopher has access to a fork on their left and a fork on their right.
3. Mutexes are employed to safeguard shared resources, such as forks, ensuring thread safety.
4. The program meticulously logs various states of philosophers, along with corresponding timestamps.
5. The simulation halts if a philosopher succumbs to death or when each philosopher completes the specified number of meals.


# Important Notes:
- Command-line arguments specify the number of philosophers, times, and optional eat count.
- Thread and mutex functions are used for synchronization.
- Detailed logs and error handling are implemented.
- The program must not have any data races.


## Program Instructions:
- The program creates threads to represent philosophers.
- Each philosopher has a fork on their left and a fork on their right.
- Mutexes are used to protect shared resources like forks and ensure thread safety.
- The program logs various states of philosophers with timestamps.
- The simulation stops if a philosopher dies or when each philosopher has eaten the specified number of times..

## Rules and Requirements:
- The project must be written in C and adhere to the Norme.
- Functions should not terminate unexpectedly, and no memory leaks are tolerated.
- Error handling must be implemented sensibly.
- No global variables are allowed.
- Follow the provided instructions in the README file for successful compilation and execution of the program.

## Authors

* **Ocyn** - *A Random Dev* - [Ocyn](https://github.com/Ocyn) - *Made the project*

## Acknowledgements

* [42 School](https://github.com/42School)
