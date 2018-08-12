# Academic-Project-on-Options-Pricing-based-on-object-oriented-programming-in-Cpp

• Calculated the implied volatility under dynamic price of options based on Newton-Raphson method

• Utilized Monte Carlo techniques for path-dependent derivative securities pricing

Homework 01:

ModifythePriceByCRR()functionin Options01.cpp to compute the time 0 price of an European option using CRR formula

Homework 02:

Include the ability to price digital calls and puts in the program developed in the present section by adding new payoff functions to the files Options03.h, Options03.cpp and Main07.cpp

Homework 03:

A definite integral can be computed numerically by trapezoidal approximation:
Wherexk =a+khfork=0,1,...N.WriteaclasscalledDefInttocomputethe trapezoidal approximation for a given function f(x). The class should contain the following:
1) Private members to hold the values of the integration limits a and b and a pointer
to the function f.
2) A constructor function such that the integration limits a, b and the pointer to the
function f can be initiated a the time of creating an object of the class such as
DefInt MyInt(a, b, f)
3) A public function ByTrapzoid() taking N as an argument and returning the
trapezoidal approximation to the integral when called by MyInt.ByTrapzoidal(N).
4) You may also want to include another public function BySimpson() to compute
the Simpson approximation to the integral (look it up in the literature).

Homework 04:

Addtheabilitytopricebullspreadsandbear spreads by introducing new subclasses BullSpread and BearSpread of EurOption class defined in Options06.h. Use the new classes, making suitable changes in Main10.cpp to price European bull and bear spreads.

Homework 05:

Addfurtherpayoffs,namely,strangle,and butterfly spreads, by means of subclasses of the EuroOption class placed in separate files, without changing anything in existing code, except for the necessary changes in Main11.cpp, to price options with the newly introduced payoffs.

Homework 06:

Modify the PriceByCRR() function in Options09.h and Options09.cpp to compute the replicating strategy for a European option in the binomial tree model, using the BinLattice<> class template to store the stock and money market account positions in the replicating strategy at the nodes of the binomial tree. X(n, i) is the delta (fraction) of share of stock at each node on the stock tree, y(n, i) is the money market position at each node on the money market tree. Negative value mean borrowed money

Homework 07:

Develop code to compute the approximate price for an American put option in the Black-Scholes model by means of this binomial tree approximation.

Homework 08_Q1:

AlterthecodeinSolver03.handMain17.cppto have an object of type Function passed by reference to SolveByBisect() and SolveByNR() rather than a pointer to an object of type Function passed to them.

Homework 08_Q2:

Using Solver03.h, write a program to compute the yield of a coupon bond by solving the above non-linear equation.

Homework 09:

Derive a class from the base class, PathDepOption, to compute the prices of European call and put options.

Expand the code to compute Greek parameters, such as the vega, theta and rho.

Expand the code we learned for variance reduction to compute d for an arithmetic Asian call. 
