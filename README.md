# Ratatoskr - A multi-language framework for NDEC
Ratatoskr is an open-source Neuro-Dynamic Evolutionary Computation (NDEC) framework that is driven by a C++ core engine. This 
engine is supposed to allow simple configuration through a multi-language supported API. Please note, that the project is 
currently under development and therefore is not provided with all features yet. The state of the framework and all current
features will be listed in this document.

## Current Features (v0.1)
* Core-Engine
   * Supports traditional Evolutionary Computation only
   * Programmable representations, initialization, evaluation, variation and sessions
   * Statistics: Recoring of the best, average and worst getFitness of each generation
* C++-API
  * Toolkit
    * Neuro-Dynamic Genetic Algorithm (NDGA)
      * OneMax-Task
* Python-API
  * Programmable Problems
  * Running existing C++ sessions
  
## Prerequiries
Ratatoskr's C++ API does only require you to have cmake installed. However, if you want to use the framework in Python, you will 
need the following:
* wheels
* pip
* Python 3.0 
* Boost.Python 1.64
  * Troubleshooting: Make sure Boost.Python is linked against python3 not python2. 
  
# Building from sources (Linux only)
Independently of what API you may want to use, it is necessary to build the C++ API first. This is simply done using cmake. 
If you want to use the C++-API only, run the following in your terminal
```{r, engine='bash', count_lines}
cd ratatoskr-master
cmake ndec_cc
cd build
make
```
This builds the C++-API as a shared library that has to be linked against only. For the additional Python-API exchange the cmake command to
```{r, engine='bash', count_lines}
cmake ndec_py
```
in order to build all extension modules. Afterwards, move in the python directory and install the ratatoskr package:
```{r, engine='bash', count_lines}
cd python
python3 setup.py bdist_wheel
cd dist
pip install ratatoskr_wheel_file.whl
```
## A simple example (TBA) 
