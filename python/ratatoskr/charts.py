from bokeh.layouts import column
from bokeh.models import Range1d, CustomJS, ColumnDataSource, Slider
from bokeh.plotting import figure
import sys

class InitializationError(Exception):
    pass

def fitnessChart(best_fitnesses, average_fitnesses, worst_fitnesses):
    try:
        if (len(best_fitnesses) != len(average_fitnesses) or len(average_fitnesses) != len(worst_fitnesses)):
            raise InitializationError()
    except InitializationError:
        print("All fitnesses need to be recorded over the same number of generations.")
        sys.exit(1)

    generations = len(best_fitnesses)
    g = list(range(generations))

    p = figure(plot_width=500, plot_height=500)
    p.line(g, best_fitnesses, color="blue", line_width=2, legend='best')
    #p.circle(g, best_fitnesses, fill_color="white", size=2)
    p.line(g, average_fitnesses, color="red", line_width=2, legend='average')
    #p.circle(g, average_fitnesses, fill_color="white", size=2)
    p.line(g, worst_fitnesses, color="green", line_width=2, legend='worst')
    #p.circle(g, worst_fitnesses, fill_color="white", size=2)
    p.x_range = Range1d(0, generations - 1)
    p.y_range = Range1d(0, max(worst_fitnesses))
    p.xaxis.axis_label = 'Generation'
    p.yaxis.axis_label = 'Value'
    return p

def fitnessAnimation(best_fitnesses, average_fitnesses, worst_fitnesses):
    try:
        if (len(best_fitnesses) != len(average_fitnesses) or len(average_fitnesses) != len(worst_fitnesses)):
            raise InitializationError()
    except InitializationError:
        print("All fitnesses need to be recorded over the same number of epochs.")
        sys.exit(1)

    try:
        if (len(best_fitnesses) == 1):
            raise InitializationError()
    except InitializationError:
        print("The number of recorded epochs needs to be larger than 1.")
        sys.exit(1)

    try:
        if (len(best_fitnesses[0]) != len(average_fitnesses[0]) or len(average_fitnesses[0]) != len(worst_fitnesses[0])):
            raise InitializationError()
    except InitializationError:
        print("All fitnesses need to be recorded over the same number of generations.")
        sys.exit(1)

    epochs = len(best_fitnesses)
    generations = len(best_fitnesses[0])
    g = list(range(generations))

    max_fitness = max(worst_fitnesses[0])
    for k in range(1,len(best_fitnesses)):
        m = max(worst_fitnesses[k])
        if (m > max_fitness):
            max_fitness = m

    x = g
    b = best_fitnesses[0]
    a = average_fitnesses[0]
    w = worst_fitnesses[0]

    bs = best_fitnesses
    avs = average_fitnesses
    ws = worst_fitnesses

    source = ColumnDataSource(data=dict(x=x,b=b,a=a,w=w))
    fitness = ColumnDataSource(data=dict(bs=bs,avs=avs,ws=ws))

    p = figure(plot_width=500, plot_height=500)
    p.line('x', 'b', source=source, color="blue", line_width=2, legend='best')
    #p.circle('x', 'b', source=source, fill_color="white", size=8)
    p.line('x', 'a', source=source, color="red", line_width=2, legend='average')
    #p.circle('x', 'a', source=source, fill_color="white", size=8)
    p.line('x', 'w', source=source, color="green", line_width=2, legend='worst')
    #p.circle('x', 'w', source=source, fill_color="white", size=8)
    p.x_range = Range1d(0, generations - 1)
    p.y_range = Range1d(0, max_fitness)
    p.xaxis.axis_label = 'Generation'
    p.yaxis.axis_label = 'Value'

    callback = CustomJS(args=dict(source=source,fitness=fitness), code="""
        var data = source.data;
        var fit = fitness.data;
        var k = cb_obj.value
        x = data['x']
        b = data['b']
        a = data['a']
        w = data['w']
        bs = fit['bs']
        avs = fit['avs']
        ws = fit['ws']
        for (i = 0; i < x.length; i++) {
            b[i] = bs[k][i]
            a[i] = avs[k][i]
            w[i] = ws[k][i]
        }
        source.change.emit();
    """)

    slider = Slider(start=0, end=epochs-1, value=0, step=1, title='Epochs')
    slider.js_on_change('value', callback)

    return column(slider, p)