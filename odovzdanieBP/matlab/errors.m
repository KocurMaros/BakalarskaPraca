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
approx_point_plc =[ 0.0000  0.0002 1.412
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

% Calculate the Euclidean distance between the two points
absolute_error_plc= zeros(size(approx_point_plc));
relative_error_plc = zeros(size(approx_point_plc));

absolute_error_spfn= zeros(size(approx_point_spfn));
relative_error_spfn = zeros(size(approx_point_spfn));
for i=1:size(approx_point_spfn)
    distance_plc = norm(real_point - approx_point_plc(i,:));
    distance_spfn = norm(real_point - approx_point_spfn(i,:));
    
    % Calculate the relative error as the ratio of the distance to the magnitude of the real point
    relative_error_plc(i) = distance_plc / norm(real_point);
    absolute_error_plc(i) = distance_plc ;
    relative_error_spfn(i) = distance_spfn / norm(real_point);
    absolute_error_spfn(i) = distance_spfn ;
%     hold on
%     hold on
%     plot(i, absolute_error(1));
end
x = 1:12;
plot(x,relative_error_plc(:,1),x,relative_error_spfn(:,1))
hold on
xlim([1 12])
xlabel('Bod')
ylabel('relative error[%]')
legend("PLC","SPFN")
figure 
plot(x,absolute_error_plc(:,1),x,absolute_error_spfn(:,1))
hold on
xlabel('Bod')
xlim([1 12])
ylabel('absolut error[%]')
legend("PLC","SPFN")