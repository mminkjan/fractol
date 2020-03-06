# fract'ol
## Codam Coding College project fract'ol

![Demo of Mandelbrot](https://github.com/jdsmith022/fractol/blob/master/pictures/fractol.gif)

### Description
fract'ol is a program written in C that displays a fractal of the users choice. The program allows the user to manipulate the displayed fractal and change between the four different fractals handled by the program as instructed by a user interface. The fractals available for this project are Mandelbrot, Julia, Burning Ship and Mandelbar.

The purpose of this project was to gain a better understanding of miniLibX library, to discover and use the mathematical notion of complex numbers, and to take a peak at the concept of optimzation in computer graphics through multithreading.

For full pdf of project requirements click [here](https://github.com/jdsmith022/fractol/blob/master/fract_ol.en.pdf).

### Prerequisites
XQuartz 
To download, click [here](https://www.xquartz.org/).
This program was written on LinuxOS and complies with a Makefile.

### Installation

From terminal, the program can be install with git clone from the repository followed by name of directory you wish to download repository to.

#### Example
```
$ git clone git@github.com:jdsmith022/fractol.git [directory-name]
```

### Usage

In terminal, go into the project directory. This program uses a makefile to compile. To compile, run: 
```
$ make
```
The executable name is fractol. To run, chose one of the four optional fractal as a parameter. Run program with:
```
$ ./fractol [name-of-desire-fractol]
```

#### Example:
```
$ ./fractol Julia
```

If incorrect fractal is name, a usage error will but given. The user interface provides information for the use and exit of the program. 

To delete all object files from directory, run:
```
$ make clean
```
To delete executable from directory, run:
```
$ make fclean
```



#### Fractals from project

Mandelbrot:
![Image of Mandelbrot](https://github.com/jdsmith022/fractol/blob/master/pictures/Mandelbrot.png)

Julia: 
![Image description](https://github.com/jdsmith022/fractol/blob/master/pictures/Julia.png)

BurningShip:
![Image description](https://github.com/jdsmith022/fractol/blob/master/pictures/BurningShip.png)

Mandelbar: 
![Image description](https://github.com/jdsmith022/fractol/blob/master/pictures/Mandelbar.png)
