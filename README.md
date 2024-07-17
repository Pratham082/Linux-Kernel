
# Linux Kernel Project

## Overview

This project is an implementation of basic Ubuntu command line functionalities using C and OS system calls. The functionalities included in this project are:

- `mkdir`: Create a new directory.
- `rm`: Remove a file or directory.
- `ls`: List directory contents.
- `cat`: Concatenate and display files.
- `cd`: Change the current directory.
- `pwd`: Print the current working directory.

## Project Structure

The project consists of the following files and directories:

```
├── src
│   ├── main.c
│   ├── mkdir.c
│   ├── rm.c
│   ├── ls.c
│   ├── cat.c
│   ├── cd.c
│   ├── pwd.c
├── include
│   ├── mkdir.h
│   ├── rm.h
│   ├── ls.h
│   ├── cat.h
│   ├── cd.h
│   ├── pwd.h
├── Makefile
├── README.md
```

- `src`: Contains the source code for each command functionality.
- `include`: Contains the header files for each command functionality.
- `Makefile`: Used to compile the project.

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/linux-kernel-project.git
   ```
2. Navigate to the project directory:
   ```sh
   cd linux-kernel-project
   ```
3. Compile the project using the Makefile:
   ```sh
   make
   ```

## Usage

After compiling the project, you can run the executable to use the implemented functionalities. Below are the commands and their usage:

### `mkdir`

Creates a new directory.

```sh
./your_executable_name mkdir <directory_name>
```

### `rm`

Removes a file or directory.

```sh
./your_executable_name rm <file_or_directory_name>
```

### `ls`

Lists the contents of a directory.

```sh
./your_executable_name ls <directory_name>
```

### `cat`

Concatenates and displays files.

```sh
./your_executable_name cat <file_name>
```

### `cd`

Changes the current directory.

```sh
./your_executable_name cd <directory_name>
```

### `pwd`

Prints the current working directory.

```sh
./your_executable_name pwd
```

## Contributing

If you would like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch.
3. Make your changes.
4. Submit a pull request.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgments

- [Your Name](https://github.com/yourusername) - Project Author

Feel free to contact me if you have any questions or suggestions.
