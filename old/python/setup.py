from setuptools import setup, find_packages

setup(
    name='ratatoskr',
    version='0.1.0',
    include_package_dir=True,
    packages=find_packages(),
    package_data={
        '': ['*.so'],
    },

    author='Felix Voelker',
    author_email='ratatoskr-engine@googlemail.com',
    description=('Python-API for the Ratatoskr C++ engine.'),
    license='BSD 3-clause "New" or "Revised" License',
    url='https://github.com/FelixVoelker/ratatoskr',
)