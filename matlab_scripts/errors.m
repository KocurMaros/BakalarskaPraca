% Real point
close all
clear
clc
real_point = [0, 0, 1];  % Replace with the real point coordinates
approx_point_spfn = [-0.0622 0.0351 1.8132;
                0.0550 -0.0145 1.5530;
                -0.0232 -0.0106 1.345;
                0.0407 -0.0122 1.559;
                0.0163 0.0149 1.0346;
                0.0015 0.0032 1.0823;
                0.0235 -0.0011 1.0677;
                -0.0131 0.0218 1.1271;
                0.0047 0.0141 1.0606;
                0.0322 0.0053 1.2971;
                -0.0093 0.0182 1.0258;
                -0.0815 0.0906 1.0827];
approx_point_pcl =[ 0.0000  0.0002 1.412
                -0.0016   -0.0014    1.14 ;
                 -0.0014   -0.0034    1.4317 ;
                0.0242   -0.1120    1.1345 ;
                -0.0257   -0.0135    0.8796 ;
                -0.0073    0.0008    1.0662;
                0.0026    0.0084    0.9749 ;
                0.0417    0.0082    1.0995 ;
                -0.0065   -0.0043    1.0938;
                0.0002   -0.0003    0.9800;
                -0.0089    0.0292    0.910 ;
                0.0092   -0.0131    0.9704 ];
% Approximated point
% approx_point = [0.0322, 0.0053, 129.71];  % Replace with the approximation coordinates


my_error_spfn = zeros(size(approx_point_spfn));
my_error_pcl = zeros(size(approx_point_spfn));

% Coordinates of point 1
x1 = 0;
y1 = 0;
z1 = 1;
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
