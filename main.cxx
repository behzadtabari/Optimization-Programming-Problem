#include <iostream>
#include <vector>
#include <nlopt.hpp>

// Objective or my function that is supposed to be optimized
double objective(const std::vector<double> &x, std::vector<double> &grad, void *data)
{
    return x[0] * x[0] + 2 * x[0] + 2;
}

double constraint(const std::vector<double> &x, std::vector<double> &grad, void *data)
{
    return x[0];
}

int main()
{
    nlopt::opt opt(nlopt::LN_COBYLA, 1);
    opt.set_lower_bounds(std::vector<double>{0});
    opt.set_min_objective(objective, nullptr);
    opt.add_inequality_constraint(constraint, nullptr, 1e-8);
    opt.set_xtol_rel(1e-6);


    std::vector<double> x = {0.5};
    double minf;
    nlopt::result result = opt.optimize(x, minf);

    std::cout << "Found minimum at x = " << x[0] << " with value f(x) = " << minf << std::endl;

    return 0;
}
