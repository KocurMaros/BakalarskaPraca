% Sample data
radii = [1, 2, 1.5, 2.5, 1, 3, 2, 1, 2, 1.5, 2.5, 1, 3, 2, 1, 2, 1.5, 2.5, 1, 3, 2, 1, 2, 1.5];
x = [0, 2, -1, 3, -2, 1, 0, 2, -1, 3, -2, 1, 0, 2, -1, 3, -2, 1, 0, 2, -1, 3, -2, 1];
y = [0, 1, -2, 2, 1, -3, 0, 1, -2, 2, 1, -3, 0, 1, -2, 2, 1, -3, 0, 1, -2, 2, 1, -3];
z = [0, 3, -1, 2, -3, 0, 0, 3, -1, 2, -3, 0, 0, 3, -1, 2, -3, 0, 0, 3, -1, 2, -3, 0];

% Visualization
figure;
hold on;

for i = 1:numel(radii)
    [X, Y, Z] = cylinder2P(radii(i), 10, [x(i), y(i), z(i)], [x(i), y(i), z(i)+1]);
    surf(X, Y, Z, 'FaceAlpha', 0.3);
end

axis equal;
xlabel('X');
ylabel('Y');
zlabel('Z');
title('Visualization of Cylinders');
grid on;
view(3);

% Function to generate cylinder surface points
function [X, Y, Z] = cylinder2P(radius, height, pt1, pt2)
    v = pt2 - pt1;
    mag = norm(v);
    v = v ./ mag;
    N = 10;
    
    if v(3) > 0.9999
        v_aux = [0, 1, 0];
    else
        v_aux = [0, 0, 1];
    end
    
    v_perp1 = cross(v, v_aux);
    v_perp1 = v_perp1 ./ norm(v_perp1);
    v_perp2 = cross(v, v_perp1);
    
    theta = linspace(0, 2*pi, N);
    X = pt1(1) + radius * (v_perp1(1) * cos(theta) + v_perp2(1) * sin(theta));
    Y = pt1(2) + radius * (v_perp1(2) * cos(theta) + v_perp2(2) * sin(theta));
    Z = pt1(3) + linspace(0, height, N);
end
