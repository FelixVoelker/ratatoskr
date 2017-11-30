from copy import copy
from ratatoskr.core import *


class TestProblem(Problem):

    def __init__(self, popsize):
        super().__init__(popsize)

    def __copy__(self):
        return TestProblem(self.popsize)

class TestSession(Session):

    def __init__(self, problem):
        super().__init__(problem)

    def fitness(self, fitness):
        self.fitness = fitness

problem = TestProblem(10)
session = TestSession(problem)
f = Fitness(session)
f.fitness = 5
f1 = copy(f)
f.fitness = 0
print(f.fitness)
print(f1.fitness)
print(f.isideal())
print(f > f1)
