# Constellations
Constellations is a simple, easy to use, and lightweight application for creating and managing your own constellations. Constellations is written in C++ and uses the [raylib](https://www.raylib.com/) library for graphics and input. Constellations is currently in development and is not yet ready for use.

## Features
- Create and manage your own constellations
- Save and load constellations
- Custom Icons
- Customizable colors
- Customizable background
- Print just canvas or canvas with Icon options

## Installation
Constellations is currently in development and is not yet ready for use. 
BUT, if you want to try it out, download the source code and run the following commands in the root directory of the project:
```bash
pymake-cli build config/<os>.yaml -s
```
Where `<os>` is your operating system. For example, if you are on Windows, run:
```bash
pymake-cli build config/windows.yaml -s
```

This will create a `build` directory in the root of the project. Inside the `build` directory, there will be a directory called `bin`. Inside the `bin` directory, there will be a directory called `<os>`. Inside the `<os>` directory, there will be an executable called `constellations`. Run this executable to run Constellations.
