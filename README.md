# Particles
A simple CPU driven particles system with an OpenGL renderer. Used Qt 5 as the base framework.

## Features
- Control the camera (`WASD` keys for movement, and `mouse click` + `mouse movement` for orientation).
- Numerical solvers implemented:
	- Euler
	- Semi Implicit Euler
	- Verlet
- Collider types implemented:
	- Sphere
	- Plane
	- Triangle
- Force fields implemented:
	- Gravity
	- Drag

## Known issues
- Some particles scape the box on the edges/vertices. This is due to not cheking for a collision again once the particle has been corrected. This can be easly fix in exchange of performance.

## Requirments
The software requires the following libraries to be installed:
- GLEW
- Eigen
- QT 5

## Build
Clone the repositroy:

	git clone https://github.com/GerardMT/Particles
	cd Particles

Compile the code:

    cd src
    qmake-qt5
    make

The builds can be found at `build/`.

## Run
Once build, simply run:

	../build/release/particles

## Screenshots
<img src="docs/screenshots/waterfall.gif" alt="Waterfall" width="50%">
<img src="docs/screenshots/fountain.png" alt="Fountain" width="50%">

## Other
Have a look at my other physics based projects:
- [Hair](https://github.com/GerardMT/Hair)
- [Cloth](https://github.com/GerardMT/Cloth)
- [Rigid-Bodies](https://github.com/GerardMT/Rigid-Bodies)

If you want to fork this project I recomend cloning [Cloth](https://github.com/GerardMT/Cloth), which includes all the code from [Particles](https://github.com/GerardMT/Particles) and [Hair](https://github.com/GerardMT/Hair), including some improvements.