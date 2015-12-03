# Banker-s-Algo

## Introduction
This repository contains a program for simulating a system governed by
the classic "Banker's Algorithm." Users are given the opportunity to 
initialize system parameters (i.e. the number of running processes along
with the number of resource types and instances). Users are then 
allowed to "run" the system to view the occurrences of safe and unsafe
states. 

## Building and Running
The project directory contains a Makefile and can be compiled with <code>make</code>.
The resulting executable, "banker," can be run with  <code>./banker</code>. 
Then, the user may follow the prompts and examine the results as 
desired. This build/execute process works on any system with gcc installed.

## Further Reading
The inspiration for this project came from the textbook *Operating Systems
Concepts, 9 ed.*, by Silberschatz, Galvin, and Gagne. For a full 
understanding of this project and its source code, reading section 7.5.3, 
pgs. 330-332, is almost necessary. 
