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

### Installation

From terminal, the program can be install with git clone from the repository followed by name of directory you wish to download repository to.

#### Example
```
$ git clone git@github.com:jdsmith022/fractol.git [name-directory]
```

### Usage

In terminal, go into the project directory. Run Make to compile. 
```
$ make
```
The executable name is fractol. Run program with:
```
$ ./fractol [name-of-desire-fractol]
```

#### Example:
```
$ ./fractol Julia
```

If incorrect fractal is name, a usage error will but given.

To delete all .o files from directory, run:
```
$ make clean
```
To delete executible from directory, run:
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
