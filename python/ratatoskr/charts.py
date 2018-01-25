from bokeh.layouts import gridplot
from bokeh.models import Range1d, CustomJS, ColumnDataSource, Slider
from bokeh.plotting import figure, show
import numpy as np


def rfc(statistics):
    generations = np.arange(statistics.generations + 1)
    reverse_generations = np.array([])
    for k in range(statistics.generations + 1):
        reverse_generations = np.append(reverse_generations, generations[statistics.generations - k])

    max_relevance = 0
    all_relevances = []
    average_relevances = []

    max_fitness = 0
    all_fitnesses = []
    average_fitnesses = []

    max_cost = 0
    all_costs = []
    average_costs = []

    tmp = np.zeros(statistics.generations + 1)
    for ep in range(statistics.epochs):
        relevances = np.array(statistics.worstRelevances(ep))
        if np.max(relevances) > max_relevance:
            max_relevance = np.max(relevances)
        for k in range(statistics.generations + 1):
            tmp[k] = statistics.bestRelevances(ep)[statistics.generations - k]
        relevances = np.append(relevances, tmp)
        all_relevances.append(relevances)
        average_relevances.append(np.array(statistics.averageRelevances(ep)))

        fitnesses = np.array(statistics.worstFitnesses(ep))
        if np.max(fitnesses) > max_fitness:
            max_fitness = np.max(fitnesses)
        for k in range(statistics.generations + 1):
            tmp[k] = statistics.bestFitnesses(ep)[statistics.generations - k]
        fitnesses = np.append(fitnesses, tmp)
        all_fitnesses.append(fitnesses)
        average_fitnesses.append(np.array(statistics.averageFitnesses(ep)))

        costs = np.array(statistics.worstCosts(ep))
        if np.max(costs) > max_cost:
            max_cost = np.max(costs)
        for k in range(statistics.generations + 1):
            tmp[k] = statistics.bestCosts(ep)[statistics.generations - k]
        costs = np.append(costs, tmp)
        all_costs.append(costs)
        average_costs.append(np.array(statistics.averageCosts(ep)))

    all_plot_data = {'generations': np.append(generations, reverse_generations),
                     'all_cost': all_costs[0],
                     'all_fitness': all_fitnesses[0],
                     'all_relevance': all_relevances[0]}

    all_statistics_data = {'all_costs': all_costs,
                           'all_fitnesses': all_fitnesses,
                           'all_relevances': all_relevances}

    average_plot_data = {'generations': generations,
                         'average_cost': average_costs[0],
                         'average_fitness': average_fitnesses[0],
                         'average_relevance': average_relevances[0]}

    average_statistics_data = {'average_costs': average_costs,
                               'average_fitnesses': average_fitnesses,
                               'average_relevances': average_relevances}

    all_plot_source = ColumnDataSource(all_plot_data)
    average_plot_source = ColumnDataSource(average_plot_data)
    all_statistics_source = ColumnDataSource(all_statistics_data)
    average_statistics_source = ColumnDataSource(average_statistics_data)

    relevance_plot = figure(plot_width=300, plot_height=300, tools="save")
    relevance_plot.patch('generations', 'all_relevance', source=all_plot_source, color="red", alpha=0.5)
    relevance_plot.line('generations', 'average_relevance', source=average_plot_source, color="red")
    relevance_plot.x_range = Range1d(0, len(generations) - 1)
    relevance_plot.y_range = Range1d(0, max_relevance)
    relevance_plot.xaxis.axis_label = 'Generation'
    relevance_plot.yaxis.axis_label = 'Relevance'

    fitness_plot = figure(plot_width=300, plot_height=300, tools="save")
    fitness_plot.patch('generations', 'all_fitness', source=all_plot_source, color="green", alpha=0.5)
    fitness_plot.line('generations', 'average_fitness', source=average_plot_source, color="green")
    fitness_plot.x_range = Range1d(0, len(generations) - 1)
    fitness_plot.y_range = Range1d(0, max_fitness)
    fitness_plot.xaxis.axis_label = 'Generation'
    fitness_plot.yaxis.axis_label = 'Fitness'

    cost_plot = figure(plot_width=300, plot_height=300, tools="save")
    cost_plot.patch('generations', 'all_cost', source=all_plot_source, color="blue", alpha=0.5)
    cost_plot.line('generations', 'average_cost', source=average_plot_source, color="blue")
    cost_plot.x_range = Range1d(0, len(generations) - 1)
    cost_plot.y_range = Range1d(0, max_cost)
    cost_plot.xaxis.axis_label = 'Generation'
    cost_plot.yaxis.axis_label = 'Cost'

    callback = CustomJS(args=dict(all_plot=all_plot_source,
                                  average_plot=average_plot_source,
                                  all_statistics=all_statistics_source,
                                  average_statistics=average_statistics_source),
                        code="""var epoch = cb_obj.value;
        all_plot.data['all_cost'] = all_statistics.data['all_costs'][epoch];
        average_plot.data['average_cost'] = average_statistics.data['average_costs'][epoch];
        all_plot.data['all_fitness'] = all_statistics.data['all_fitnesses'][epoch];
        average_plot.data['average_fitness'] = average_statistics.data['average_fitnesses'][epoch];
        all_plot.data['all_relevance'] = all_statistics.data['all_relevances'][epoch];
        average_plot.data['average_relevance'] = average_statistics.data['average_relevances'][epoch];
        all_plot.change.emit();
        average_plot.change.emit();
    """)

    slider = Slider(start=0, end=statistics.epochs - 1, value=0, step=1, title='Epochs')
    slider.js_on_change('value', callback)

    grid = gridplot([[None, slider, None], [relevance_plot, fitness_plot, cost_plot]])
    return show(grid)
