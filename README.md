# Subject Directory Organizer

## Overview
The Subject Directory Organizer is a C++ utility designed to automate the process of creating directories and subdirectories based on a list of subjects provided in a text file. It is particularly useful for organizing academic materials, such as notes, assignments, projects, and quizzes, into structured folders.

### Features:
- **Automatic Directory Creation**: Quickly generate directories and subdirectories with predefined folder structures for each subject.
- **Customizable Paths**: Choose a custom destination path where the directories will be created.
- **Flexible Input**: Provide a list of subjects in a text file to dynamically generate directories based on the subject names.

## Usage
1. **Custom Path**:
   - Enter the custom destination path where the directories will be created. For example:
     ```
     Enter custom path (e.g., C:\\Users\\username\\Desktop):
     ```

2. **File Path**:
   - Enter the file path containing the list of subject names. For example:
     ```
     Enter file path (e.g., C:\\Users\\username\\Desktop\\subject_names.txt):
     ```

3. **Execution**:
   - Run the program, and it will automatically create directories and subdirectories based on the provided subject names.

## Prerequisites
- **C++ Compiler**: Ensure you have a C++ compiler installed on your system to compile and run the program.

## Example
Suppose you have a file named `subject_names.txt` containing the following subject names, with each name on a separate line:

Mathematics
Physics
Chemistry
Biology

And you want to create directories for these subjects on your desktop. You would provide the custom path as `C:\\Users\\username\\Desktop` and the file path as `C:\\Users\\username\\Desktop\\subject_names.txt`. The program will then create directories and subdirectories for each subject under the specified custom path.
