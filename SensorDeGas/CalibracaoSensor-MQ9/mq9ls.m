x = [200, 500, 800, 1000]'
n = length(x);
%y = (x-3).*(x-1).*(x-4).*(x-4.5).*(x-1)+8*cos(x) + 5*rand(n,1);
%y = x.^4 + 3*x.^3 - 5*x.^2 + cos(x);
y = [1.7, 1.1, 0.89, 0.79]';
plot(x,y,'.');
%A = [x.^4 x.^3 x.^2 x x.^0];
A = [x.^-3 x.^-2 x.^-1 x.^0];
th = pinv(A)*y;
yn = A*th;
hold on
plot(x,yn);

e = y - yn; 