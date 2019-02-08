# Ratatoskr - A multi-language framework for ACEAs
Ratatoskr is an open-source framework for an Actor-Critic Evolutionary Algorithm (ACEA) that is driven by a C++ core engine. It provides several APIs to build and evaluate these EAs on a broad range of programming languages. Please note, the project is currently under development and does not provided a stable build yet.

## Current Features (v0.1.0)
* Core-Engine
* C++-API
* Python3-API
* Statistics
  
## Building from source (Linux only)
Independently of what API you may want to use, make sure that cmake is installed. 

### Installing the C++-API
Open a terminal and switch to the Ratatoskr root directory. Then run the following script:
```{r, engine='bash', count_lines}
cmake ratatoskr_cc
cd build
make
```
This builds the C++-API as a shared library to link against.

### Installing the Python3-API
Prerequiries:
* pip
* wheels
* Boost.Python 1.64
** Troubleshooting: Make sure Boost.Python is linked against python3 not python2. 
  
Open a terminal and switch to the Ratatoskr root directory. Then run the following script:
```{r, engine='bash', count_lines}
cmake ratatoskr_py
```
This builds the c++ library and all extension models. Now, move into the python directory and install the ratatoskr packages:
```{r, engine='bash', count_lines}
cd python
python3 setup.py bdist_wheel
cd dist
pip install ratatoskr_wheel_file.whl
```
