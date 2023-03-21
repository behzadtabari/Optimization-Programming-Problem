import nlopt
import numpy as np

def myfunc (x,grad):
    return x[0]*x[0]+2*x[0]+2

def constraint(x,grad):
    return x[0]


opt = nlopt.opt(nlopt.LN_COBYLA, 1)
opt.set_lower_bounds([0])
opt.set_min_objective(lambda x, grad:myfunc (x,grad))
opt.add_inequality_constraint(lambda x, grad:constraint(x,grad), 1e-8)
opt.set_xtol_rel(1e-4)

x0 = [0.5]
x = opt.optimize(x0)
minf = opt.last_optimum_value()
print('optimum at ', x)
print('minimum value = ', minf)
print('result code = ', opt.last_optimize_result())
print('nevals = ', opt.get_numevals())
print('initial step =', opt.get_initial_step(x0))
