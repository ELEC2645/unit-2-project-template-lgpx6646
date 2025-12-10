[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=21756441)
# ELEC2645 Unit 2 Project - Power Converter Calculator

### Features
This program allows the user to import data via csv files or manually, by typing values, and perform power converter calculations such as:
-  Inductor selector calculations
-  Output capacitor selector calculations
-  Boundary current calculations
These calculations can be performed for both buck and boost converters, as selected by the user

The results of the boundary current calculations, when using a file of data, are written into a csv file, which can be exported into excel and used to produce a graph.

### Run code

Please first compile the code with `gcc main.c funcs.c -o main.out -lm` `Makefile`.

Then run the code with `./main.out`


