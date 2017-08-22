#!/bin/bin/env python

from setuptools import setup, Extension

setup(name='ndec',
      version='0.1',
      ext_modules=[
          Extension('ndga.problem',
                    ['ext/ndga/problem_ext.cpp'])
      ]
      )