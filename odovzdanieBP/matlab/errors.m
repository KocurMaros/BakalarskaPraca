% Real point
close all
clear
clc
real_point = [0, 0, 1];  % Replace with the real point coordinates
approx_point_spfn =[ 	0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000];
approx_point_pcl =[ 	0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000;
			0.000  0.000  0.000];

my_error_spfn = zeros(size(approx_point_spfn));
my_error_pcl = zeros(size(approx_point_spfn));

% Coordinates of point 1
x1 = real_point(1);
y1 = real_point(2);
z1 = real_point(3);
for i=1:size(approx_point_spfn)

% Coordinates of point 2
x2 = approx_point_pcl(i,1);
y2 = approx_point_pcl(i,2);
z2 = approx_point_pcl(i,3);

% Calculate distance between the two points
my_error_pcl(i) = sqrt((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2);

% Coordinates of point 2
x2 = approx_point_spfn(i,1);
y2 = approx_point_spfn(i,2);
z2 = approx_point_spfn(i,3);

% Calculate distance between the two points
my_error_spfn(i) = sqrt((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2);

end 

x = [10 30 50 100 150 200];

c = 1:2:11;
z = 2:2:12;
plot(x, my_error_pcl(c),x, my_error_spfn(c));
hold on
xlim([0 200])
xlabel('Polomer objektu [cm]')
ylabel('Relatívna chyba objektu v priestore [m]')
legend("PCL","SPFN")
figure 
plot(x, my_error_pcl(z),x, my_error_spfn(z));
hold on
xlim([0 200])
xlabel('Polomer objektu [cm]')
ylabel('Relatívna chyba objektu na rovine [m]')
legend("PCL","SPFN")
