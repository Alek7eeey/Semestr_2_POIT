%метод трапеции
clear all;
f=@(x) tan(5.*x)./(cos(5.*x).^2);
g=@(x) cos(5.*x.^2-3.*x+10);
a=-4.5;
b=-4.3;
n1=10;
n2=100;
arr1(1)=rectangle(a,b,f,n1);
arr1(2)=rectangle(a,b,f,n2);
arr1(3)=integral(f,a,b);
arr2(1)=rectangle(a,b,g,n1);
arr2(2)=rectangle(a,b,g,n2);
arr2(3)=integral(g,a,b);

delta_abs2=abs(arr1(3)-arr1(2));
delta_abs3=abs(arr1(3)-arr1(1));
delta_rel2=delta_abs2/arr1(3);
delta_rel3=delta_abs3/arr1(3);

function s = rectangle(a,b,f,n)
h=(b-a)/n;
s=0;
for i=a:h:b
s=s+f(i);
end
s=s*h;
end
