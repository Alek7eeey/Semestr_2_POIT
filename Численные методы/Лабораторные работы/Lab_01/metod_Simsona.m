%Метод Симпсона
clear all;
f=@(x) tan(5.*x)./(cos(5.*x).^2);
g=@(x) cos(5.*x.^2-3.*x+10);
a=-4.5;
b=-4.3;
n1=10;
n2=100;
Simps_tochn=integral(f,a,b);
h = (b-a) / n1;
h1=(b-a)/n2;
x=a:h:b;

Simps_f(1)=quad('tan(5.*x)./(cos(5.*x).^2)',a,b,h);
Simps_g(1)=quad('cos(5.*x.^2-3.*x+10)',a,b,h);

Simps_f(2)=quad('tan(5.*x)./(cos(5.*x).^2)',a,b,h1);
Simps_g(2)=quad('cos(5.*x.^2-3.*x+10)',a,b,h1);

delta_abs_f1=abs(Simps_tochn-Simps_f(1));
delta_abs_f2=abs(Simps_tochn-Simps_f(2));
delta_rel_f1=delta_abs_f1/Simps_tochn;
delta_rel_f2=delta_abs_f2/Simps_tochn;

delta_abs_g1=abs(Simps_tochn-Simps_g(1));
delta_abs_g2=abs(Simps_tochn-Simps_g(2));
delta_rel_g1=delta_abs_g1/Simps_tochn;
delta_rel_g2=delta_abs_g2/Simps_tochn;