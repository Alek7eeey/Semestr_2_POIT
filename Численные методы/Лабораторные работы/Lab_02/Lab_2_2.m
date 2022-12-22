clear all;
X=[0.3 0.7 1.3 1.4 1.9 2 2.5 3.1 4];
Y=[-2 -5 -7 -8 -11 -12 -16 -17 -25];
[f,a0, a1, a2]=least_squares(X,Y);
plot(X,f(X),X,Y);
legend('-0.7-4.9.*x-0.26.*x^2','Исходная функция')

function [y,a0, a1, a2]=least_squares(X,Y)
n=size(X,2);
A=[n sum(X) sum(X.^2);sum(X) sum(X.^2) sum(X.^3);sum(X.^2) sum(X.^3) sum(X.^4)];
b=[sum(Y);sum(X.*Y);sum(X.^2.*Y)]; %столбец свободных членов
Koef=inv(A)*b; %находим решение системы
a0=Koef(1);
a1=Koef(2);
a2=Koef(3);
y=@(x)(a0+a1.*x+a2.*x.^2); %2ой степени
end