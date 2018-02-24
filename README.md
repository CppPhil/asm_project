# asm_project

## Prerequisites
- GNU/Linux based operating system  
- gcc5  
- GNU assembler  
- Doxygen (in order to generate the documentation)  

## Installing GAS, the GNU assembler
If you don't already have GAS installed you can install it by running `sudo apt-get install binutils -y`  

## Building
To build the application enter`make`  

## Cleaning
To clean the build directory enter `make clean`  

## Rebuilding
To clean the build the directory and then rebuild the application enter `make rebuild`  

## Running
To run the application after having built it enter `./application`  

## Generating the documentation
In order to generate the documentation run `doxygen ./Doxyfile`  

## Viewing the documenation
To view the documentation open the ./doc/html/index.html file in a webbrowser.
If using Mozilla Firefox run `firefox  ./doc/html/index.html &`  
