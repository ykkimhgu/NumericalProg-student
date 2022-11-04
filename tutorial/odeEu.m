function [x, yE] = odeEu(ODE,a,b,h,y0)
% odeRK4 solves a first order initial value ODE using Ronge-Kutta fourth
% order method.
% Input variables:
% ODE    Name of a function file that calculates dy/dx.
% a      The first value of x.
% b      The last value of x.
% h      Step size.
% yIni     The value of the solution y at the first point (initial value).
% Output variable:
% x      A vector with the x coordinate of the solution points.
% y      A vector with the y coordinate of the solution points. 

x(1) = a;  yE(1) = y0;
N = (b-a)/h;
yE=zeros(1,N+1);

for i = 1:N
    x(i+1) = x(i) + h;
    
    func= ODE(x(i),yE(i));          
    yE(i+1) = yE(i) + func*h;
    
end