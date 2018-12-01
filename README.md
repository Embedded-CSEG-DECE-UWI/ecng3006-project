# GroupFProject
ECNG 3006 Group Project

This file is a guide to the various source files uploaded across Group-F's multiple branches. 

Each branch name describes the module that was developed. Example: "Group-F-Flash_Ram" contains source files source files for the flash ram module. However, we had issues merging the branches into one complete branch and as such the various integration source files are located in "Group-F-Keypad".

Additionally, the final source code file, "Final.c" is also located in this branch.

When building a project, if any source file requires the xlcd files, the "xlcd.h" file along with the 10 C source files should be included in the project. If the source requires temperature readings, the "ow.h" file should be included in the project. THis header file is responsible for faciltating One Wire communication inherent to DS1822 communciation. 
