clear all;
%построение графика
F=@(x) x.^3+6.*x-1;
X=-10:1:10;
plot(X,F(X));
a=-1;
b=1;
eps=0.01;
[der1,der2]=derivative();

%производная
function[der1,der2] = derivative()
syms x; %переменная х - воспринимается как переменная, а не как символ
f = x.^3+6.*x-1; 
der1=matlabFunction(diff(f)); %производная первого порядка 
der2=matlabFunction(diff(f,2)); %производная второго порядка 
end