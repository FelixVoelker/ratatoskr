from ratatoskr import core, common, ndga

problem = common.Problem(ndga.EvaluationFunctions.one_max(), 200, 20)
session = ndga.Session(problem)
config = session.configuration
config.system.complete = True
config.system.epochs = 1
config.system.episodes = 1000
config.system.generations = 200
config.initializer.threads = 3
config.evaluator.threads = 3
config.breeder.threads = 3

system = session.build()
system.run()
