from ratatoskr import core, common, ndga

problem = common.Problem(ndga.EvaluationFunctions.oneMax(), 200, 20)
session = ndga.Session(problem)
config = session.configuration
config.system.complete = True
config.system.epochs = 1
config.system.episodes = 1
config.system.generations = 200
system = session.build()
system.run()
