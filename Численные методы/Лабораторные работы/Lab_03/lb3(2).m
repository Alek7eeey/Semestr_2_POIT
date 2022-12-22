clear all;


F = @(x) x.^3+12.*x-12;

X = -10:1:10;
%plot(X,F(X))
a = -2;
b = 2;
eps = 0.01; %допустимая погрешность
[der1, der2] = derivative(); %находим производную
ans1 = first(F,a,b,eps);
ans2 = second(F,a,b,eps,der1,der2);
ans3 = third(F,a,eps,der1);

function ansver = first(F,a,b,eps) %метод деления отрезка пополам
    while abs(b-a) > eps  %пока больше допустимой погрешности 
        ansver = (a+b)/2;
        if F(a)*F(ansver) < 0 %если принемает значения разных знаков, то b будет принят как интервал 
            b = ansver;
        elseif F(b)*F(ansver) < 0
            a = ansver;
        end     
    end
    ansver = (a+b)/2;
end

%Метод Ньютона (метод касательных)
function ansver = second(F,a,b,eps, der1,der2) 

    if F(a)*der2(a) > 0 %если верно, то за начальное приближен будет конец отрезка на a
            ansver = a;
    elseif F(b)*der2(b) > 0
            ansver = b;
    end     
    pr = F(ansver)/der1(ansver); %за след приближ 
    while abs(pr) > eps
        pr = F(ansver)/der1(ansver);
        ansver = ansver- pr;
    end
end
%Метод простой итерации
function ansver = third(F,a,eps,der1)
    M = @(a) 1.01.*der1(a); %Неизвестн постоян велич,которая определяется из условия сходимости метода простой итерации
    k = M(a);
    f = @(ansver) ansver-F(ansver)./k; %привод к функц, для дальн использ
    ansver = a;
    pr = 1;
    while pr > eps %прекращ, если результ двух послед итерац близки 
       ansver = a;
       a = f(ansver);
       pr = abs(a - ansver);
    end
    
end


%производная
function [der1,der2] = derivative()
    syms x;   %переменная
    f = x.^3+12.*x-12;
    der1 = matlabFunction(diff(f));
    der2 = matlabFunction(diff(f, 2));
    
end
