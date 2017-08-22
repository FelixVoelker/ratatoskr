from ndec import core, ndga

problem = ndga.OneMaxProblem(200, 10)
session = ndga.NDGASession(problem)
core.EvolutionarySystem(session).run()
