values = zeros(1,7);

values = [point_on_axis_x point_on_axis_y point_on_axis_z axis_direction_x axis_direction_y axis_direction_z radius];

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
