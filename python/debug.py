from copy import copy
from ratatoskr.core import *

class TestIndividual(Individual):

    def __init__(self, session):
        self.str = ""

    def tostring(self):
        return self.str

class TestBuilder(Builder):

    def __init__(self, session):
        super().__init__(session)

    def initialize(self, ind):
        ind.str = "init"

class TestProblem(Problem):

    def __init__(self, popsize):
        super().__init__(popsize)

    def __copy__(self):
        return TestProblem(self.popsize)

class TestSession(Session):

    def __init__(self, problem):
        super().__init__(problem)
        self.builder = TestBuilder(self)
        self.cost = Cost(self)
        self.featuremap = FeatureMap(self)
        self.fitness = Fitness(self)
        self.individual = TestIndividual(self)

    def builder(self, builder):
        self.builder = builder

    def cost(self, cost):
        self.cost = cost

    def featuremap(self, featuremap):
        self.featuremap = featuremap

    def fitness(self, fitness):
        self.fitness = fitness

    def individual(self, individual):
        self.individual = individual


problem = TestProblem(10)
session = TestSession(problem)
print(session.individual.tostring())
session.builder.initialize(session.individual)
print(session.individual.tostring())