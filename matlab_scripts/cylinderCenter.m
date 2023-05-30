values = zeros(1,7);

values = [-1.60138 -1.07694  1.83944  0.829885 0.557934  0.00115169 0.213326];

point_on_axis = [values(1:3)];
axis_direction = [values(4:6)];
radius = values(7);
normalized_axis_direction = axis_direction / norm(axis_direction);

% Step 2: Calculate distance to center
distance_to_center = dot(point_on_axis, normalized_axis_direction);

% Step 3: Calculate cylinder center
cylinder_center = point_on_axis - distance_to_center * normalized_axis_direction;

% Display the result
disp("Cylinder Center:");
disp(cylinder_center);
