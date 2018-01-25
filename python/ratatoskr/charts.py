from bokeh.layouts import layout
from bokeh.models import Range1d, CustomJS, ColumnDataSource, Slider
from bokeh.plotting import figure, show
import numpy as np

'''
Creates a Reference-Fitness-Cost (RFC) plot from the given statistic.

@author  Felix Voelker
@version 0.1.0
@since   25.1.2018
'''
def rfc(statistics):
    generations = np.arange(statistics.generations + 1)
    reverse_generations = np.array([])
    for k in range(statistics.generations + 1):
        reverse_generations = np.append(reverse_generations, generations[statistics.generations - k])

    max_relevance = 0
    all_relevance = []
    average_relevance = []

    max_fitness = 0
    all_fitness = []
    average_fitness = []

    max_cost = 0
    all_cost = []
    average_cost = []

    most_relevant_cost = []
    least_relevant_cost = []
    most_relevant_fitness = []
    least_relevant_fitness = []

    tmp = np.zeros(statistics.generations + 1)
    for ep in range(statistics.epochs):
        relevance = np.array(statistics.worstRelevance(ep))
        if np.max(relevance) > max_relevance:
            max_relevance = np.max(relevance)
        for k in range(statistics.generations + 1):
            tmp[k] = statistics.bestRelevance(ep)[statistics.generations - k]
        relevance = np.append(relevance, tmp)
        all_relevance.append(relevance)
        average_relevance.append(np.array(statistics.averageRelevance(ep)))

        fitness = np.array(statistics.worstFitness(ep))
        if np.max(fitness) > max_fitness:
            max_fitness = np.max(fitness)
        for k in range(statistics.generations + 1):
            tmp[k] = statistics.bestFitness(ep)[statistics.generations - k]
        fitness = np.append(fitness, tmp)
        all_fitness.append(fitness)
        average_fitness.append(np.array(statistics.averageFitness(ep)))

        cost = np.array(statistics.worstCost(ep))
        if np.max(cost) > max_cost:
            max_cost = np.max(cost)
        for k in range(statistics.generations + 1):
            tmp[k] = statistics.bestCost(ep)[statistics.generations - k]
        cost = np.append(cost, tmp)
        all_cost.append(cost)
        average_cost.append(np.array(statistics.averageCost(ep)))

        most_relevant_cost.append(np.array(statistics.mostRelevantCost(ep)))
        least_relevant_cost.append(np.array(statistics.leastRelevantCost(ep)))
        most_relevant_fitness.append(np.array(statistics.mostRelevantFitness(ep)))
        least_relevant_fitness.append(np.array(statistics.leastRelevantFitness(ep)))

    all_plot_data = {'generations': np.append(generations, reverse_generations),
                     'cost': all_cost[0],
                     'fitness': all_fitness[0],
                     'relevance': all_relevance[0]}

    average_plot_data = {'generations': generations,
                         'cost': average_cost[0],
                         'fitness': average_fitness[0],
                         'relevance': average_relevance[0]}

    relevant_plot_data = {'generations': generations,
                          'most_relevant_cost': most_relevant_cost[0],
                          'least_relevant_cost': least_relevant_cost[0],
                          'most_relevant_fitness': most_relevant_fitness[0],
                          'least_relevant_fitness': least_relevant_fitness[0]}

    all_statistics_data = {'cost': all_cost,
                           'fitness': all_fitness,
                           'relevance': all_relevance}

    average_statistics_data = {'cost': average_cost,
                               'fitness': average_fitness,
                               'relevance': average_relevance}

    relevant_statistics_data = {'most_relevant_cost': most_relevant_cost,
                                'least_relevant_cost': least_relevant_cost,
                                'most_relevant_fitness': most_relevant_fitness,
                                'least_relevant_fitness': least_relevant_fitness}

    all_plot_source = ColumnDataSource(all_plot_data)
    average_plot_source = ColumnDataSource(average_plot_data)
    relevant_plot_source = ColumnDataSource(relevant_plot_data)
    all_statistics_source = ColumnDataSource(all_statistics_data)
    average_statistics_source = ColumnDataSource(average_statistics_data)
    relevant_statistics_source = ColumnDataSource(relevant_statistics_data)

    relevance_plot = figure(plot_width=550, plot_height=275, tools="save")
    relevance_plot.patch('generations', 'relevance', source=all_plot_source, color="red", alpha=0.5)
    relevance_plot.line('generations', 'relevance', source=average_plot_source, color="red")
    relevance_plot.x_range = Range1d(0, len(generations) - 1)
    relevance_plot.y_range = Range1d(0, max_relevance)
    relevance_plot.xaxis.axis_label = 'Generation'
    relevance_plot.yaxis.axis_label = 'Relevance'

    fitness_plot = figure(plot_width=275, plot_height=275, tools="save")
    fitness_plot.patch('generations', 'fitness', source=all_plot_source, color="green", alpha=0.5)
    fitness_plot.line('generations', 'fitness', source=average_plot_source, color="green")
    fitness_plot.line('generations', 'most_relevant_fitness', source=relevant_plot_source, color="yellow",
                      line_dash=[1, 1], alpha=0.25)
    fitness_plot.line('generations', 'least_relevant_fitness', source=relevant_plot_source, color="red",
                      line_dash=[1, 1], alpha=0.25)
    fitness_plot.x_range = Range1d(0, len(generations) - 1)
    fitness_plot.y_range = Range1d(0, max_fitness)
    fitness_plot.xaxis.axis_label = 'Generation'
    fitness_plot.yaxis.axis_label = 'Fitness'

    cost_plot = figure(plot_width=275, plot_height=275, tools="save")
    cost_plot.patch('generations', 'cost', source=all_plot_source, color="blue", alpha=0.5)
    cost_plot.line('generations', 'cost', source=average_plot_source, color="blue")
    cost_plot.line('generations', 'most_relevant_cost', source=relevant_plot_source, color="yellow",
                      line_dash=[1, 1], alpha=0.25)
    cost_plot.line('generations', 'least_relevant_cost', source=relevant_plot_source, color="red",
                      line_dash=[1, 1], alpha=0.25)
    cost_plot.x_range = Range1d(0, len(generations) - 1)
    cost_plot.y_range = Range1d(0, max_cost)
    cost_plot.xaxis.axis_label = 'Generation'
    cost_plot.yaxis.axis_label = 'Cost'

    callback = CustomJS(args=dict(all_plot=all_plot_source,
                                  average_plot=average_plot_source,
                                  relevant_plot=relevant_plot_source,
                                  all_statistics=all_statistics_source,
                                  average_statistics=average_statistics_source,
                                  relevant_statistics=relevant_statistics_source),
                        code="""var epoch = cb_obj.value;
        all_plot.data['cost'] = all_statistics.data['cost'][epoch];
        average_plot.data['cost'] = average_statistics.data['cost'][epoch];
        all_plot.data['fitness'] = all_statistics.data['fitness'][epoch];
        average_plot.data['fitness'] = average_statistics.data['fitness'][epoch];
        all_plot.data['relevance'] = all_statistics.data['relevance'][epoch];
        average_plot.data['relevance'] = average_statistics.data['relevance'][epoch];
        
        relevant_plot.data['most_relevant_cost'] = relevant_statistics.data['most_relevant_cost'][epoch];
        relevant_plot.data['least_relevant_cost'] = relevant_statistics.data['least_relevant_cost'][epoch];
        relevant_plot.data['most_relevant_fitness'] = relevant_statistics.data['most_relevant_fitness'][epoch];
        relevant_plot.data['least_relevant_fitness'] = relevant_statistics.data['least_relevant_fitness'][epoch];

        all_plot.change.emit();
        average_plot.change.emit();
        relevant_plot.change.emit();
    """)

    slider = Slider(start=0, end=statistics.epochs - 1, value=0, step=1, title="Epoch")
    slider.js_on_change('value', callback)

    return show(layout([[slider], [relevance_plot], [fitness_plot, cost_plot]], sizing_mode="scale_width"))
