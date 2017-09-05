import numpy as np
from matplotlib import pyplot as plt
from matplotlib import animation


class FitnessChart:

    def __init__(self, best_fitness, average_fitness, worst_fitness, title=''):
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
        plt.title(title)
        plt.show()

    def __init__(self, average_fitness, title=''):
        self.generations = np.arange(len(self.average_fitness))
        self.average_fitness = np.array(average_fitness)

        fig = plt.figure()
        ax = plt.axes()
        self.line, = ax.plot([], [], lw=2)

        anim = animation.FuncAnimation(fig,
                                       self.animate,
                                       init_func=self.init(),
                                       frame=average_fitness.shape[0],
                                       interval=20,
                                       blit=True)
        plt.title(title)
        plt.show()

    def init(self):
        self.line.set_data([], [])

    def animate(self, k):
        self.line.set_data(self.generations[k], self.average_fitness[k])