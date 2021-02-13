
data = load('f_n.dat'); 

n= data(:,1);

Smin = data(:,2);
Smax = data(:,3);

subplot (1,3,1, "align");
plot (n, Smin, "r-", n, Smax, "g-", n, 0.020964, "k.-",
 10, data(10, 2), "cx",
 10, data(10, 3), "bx",
 50, data(50, 2), "cx",
 50, data(50, 3), "bx",
 200, data(200, 2), "cx",
 200, data(200, 3), "bx");

xlim([0 205])
ylim([0 0.025])
 
grid on;
grid minor;
xlabel ("n");
ylabel ("Surface");
title ("Variation de I1 en fonction de n");
legend ("I1min", "I1max", "Integrale de f");

data = load('g_n.dat'); 

n= data(:,1);

Smin = data(:,2);
Smax = data(:,3);

subplot (1,3,2, "align");
plot (n, Smin, "r-", n, Smax, "g-", n, 0.000000, "k.-",
 10, data(10, 2), "cx",
 10, data(10, 3), "bx",
 50, data(50, 2), "cx",
 50, data(50, 3), "bx",
 200, data(200, 2), "cx",
 200, data(200, 3), "bx");

xlim([0 205])
ylim([-0.01 0.12])
 
grid on;
grid minor;
xlabel ("n");
ylabel ("Surface");
title ("Variation de I2 en fonction de n");
legend ("I2min", "I2max", "Integrale de g");

data = load('h_n.dat'); 

n= data(:,1);

Smin = data(:,2);
Smax = data(:,3);

subplot (1,3,3, "align");
plot (n, Smin, "r-", n, Smax, "g-", n, 0.000000, "k.-",
 10, data(10, 2), "cx",
 10, data(10, 3), "bx",
 50, data(50, 2), "cx",
 50, data(50, 3), "bx",
 200, data(200, 2), "cx",
 200, data(200, 3), "bx");

xlim([0 205])
ylim([-0.12 1])
 
grid on;
grid minor;
xlabel ("n");
ylabel ("Surface");
title ("Variation de I3 en fonction de n");
legend ("I3min", "I3max", "Integrale de h");
