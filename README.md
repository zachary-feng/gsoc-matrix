# SymMat

Welcome to the SymMat symmetric matrices package for Eigen!

You should find these three files in your working directory:

```
main.cpp
SymMat.cpp
SymMat.h
```

In addition, you should download the latest Eigen release from [their website](http://eigen.tuxfamily.org/index.php?title=Main_Page). Download the zip and extract the folder into your working directory. We will rename this folder to `eigen` but you do not have to.

To launch the demo (i.e. `main.cpp`), run the following commands in the Linux shell:

```
g++ -c main.cpp -I ./eigen
g++ -c SymMat.cpp -I ./eigen
g++ main.o SymMat.o -o main
./main
```
> Note: `./eigen` is the path to the Eigen library folder which you downloaded.

Enjoy!
