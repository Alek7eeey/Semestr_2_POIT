%Метод средних прямоугольников
clear all;
f=@(x) log(x)./sqrt(x);
g=@(x) sin(x)./(x.^2);
a=5;
b=7;
n1=10;
n2=100;
arr_f=[0 0 0];
arr_f(1)=rectangle(a,b,f,n1);
arr_f(2)=rectangle(a,b,f,n2);
arr_f(3)=integral(f,a,b);

arr_g=[0 0 0];
arr_g(1)=rectangle(a,b,g,n1);
arr_g(2)=rectangle(a,b,g,n2);
arr_g(3)=integral(g,a,b);

delta_abs_f1=abs(arr_f(3)-arr_f(2));
delta_abs_f2=abs(arr_f(3)-arr_f(1));
delta_rel_f1=delta_abs_f1/abs(arr_f(3));
delta_rel_f2=delta_abs_f2/abs(arr_f(3));

delta_abs_g1=abs(arr_g(3)-arr_g(2));
delta_abs_g2=abs(arr_g(3)-arr_g(1));
delta_rel_g1=delta_abs_g1/abs(arr_g(3));
delta_rel_g2=delta_abs_g2/abs(arr_g(3));

function s = rectangle(a,b,f,n)
h=(b-a)/n;
s=0;
for i=a:h:(b-h)
    s=s+f(i+(h/2))*h;
end
end