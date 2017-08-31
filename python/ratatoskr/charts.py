import numpy as np
import matplotlib.pyplot as plt


class FitnessChart():

    def __init__(self, best_fitness, average_fitness, worst_fitness):
        generations = np.arange(len(best_fitness))
        best = np.array(best_fitness)
        average = np.array(average_fitness)
        worst = np.array(worst_fitness)

        plt.plot(generations, best, label='Best')
        plt.plot(generations, average, label='Average')
        plt.plot(generations, worst, label='Worst')
        plt.xlabel('Generation')
        plt.xlim(0, generations.shape[0])
        plt.ylabel('Fitness Value')
        plt.legend()
        plt.show()