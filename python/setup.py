from setuptools import setup, find_packages

setup(
    name='ratatoskr',
    version='0.1',
    include_package_dir=True,
    packages=find_packages(),
    package_data={
        '': ['*.so'],
    },

    author='Felix Voelker',
    author_email='fel.voelker@googlemail.com',
    description=('Python-API for the Ratatoskr C++ engine.'),
    license='Apache 2.0',
    url='https://github.com/ratatoscr/ratatoskr',
)
