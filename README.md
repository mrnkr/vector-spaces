# Vector Spaces

This repo is a project I made for the calculus class at the ORT University in Uruguay. It offers basic functionality to work with vector sets and determine the properties of the vector spaces they generate.

## Matrix

There is a namespace called matrix in this project which contains functions from this repo made by a friend of mine: https://github.com/SebastianBandera/Java
As its name implies, the original code is written in Java, I just fixed a few bugs and 'translated' it to C++ to use it here.

The overall aim of the namespace is to be able to work with simpler matrices instead when trying to solve equation systems. More specifically, I wanted to solve said systems with the Gauss method.

## Equation Systems

The namespace for equation systems uses the previously mentioned Gauss Method to solve the systems. It takes a vector of vectors and magically solves it :)
Details on how it does it are clearly commented in the code.

## Vector Spaces

The star of the show, the main namespace of this project, includes a method for each one of the following functionalities:

* Making the equation system necessary to determine whether a given set of vectors is linearly independent or if it generates a specific vector.
* Determining whether a given set of vectors is linerly independent or not.
* Turning a linerly dependent set of vectors into an independent one.
* Getting the dimension of the vector space generated by the set that is passed as an arg.
* Getting the coordinates for a vector inside a given space.
* Checking if two sets of vectors generate the same subspace.

> I haven't properly tested this so use this code in your own discretion.