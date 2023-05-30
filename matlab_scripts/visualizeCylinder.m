% function visualizeCylinder(x, y, z, radius)
%     % Define height of the cylinder
%     height = 2*radius;
%     
%     % Generate points for the cylinder
%     [X, Y, Z] = cylinder(radius, 100);
%     
%     % Scale the cylinder and shift to the desired location
%     Z = Z * height + z;
%     X = X + x;
%     Y = Y + y;
%     
%     % Plot the cylinder
% %     figure;
%     hold on;
%     surf(X, Y, Z, 'FaceColor', 'blue', 'EdgeColor', 'none');
%     axis equal;
%     view(3);
%     xlabel('X');
%     ylabel('Y');
%     zlabel('Z');
%     title('Cylinder Visualization');
% %     hold off;
% end
function visualizeCylinder(x, y, z, radius, axs, color)
    % Define height of the cylinder
    height = 2 * radius;
    
    % Generate points for the cylinder
    [X, Y, Z] = cylinder(radius, 100);
    
    % Scale the cylinder and shift to the desired location
    Z = Z * height + z;
    X = X + x;
    Y = Y + y;
    
    % Apply rotation to the cylinder
    R = vrrotvec2mat([0, axs]);
    points = [X(:), Y(:), Z(:)];
    rotatedPoints = points * R(:, 1:3)';
    X = reshape(rotatedPoints(:, 1), size(X));
    Y = reshape(rotatedPoints(:, 2), size(Y));
    Z = reshape(rotatedPoints(:, 3), size(Z));
    
    % Plot the cylinder
%     figure;
    hold on;
    surf(X, Y, Z, 'FaceColor', color, 'EdgeColor', 'none');
    axis equal;
    view(3);
    xlim([-120 120]);
    ylim([-120 120]);
    zlim([-120 120]);
    xlabel('X');
    ylabel('Y');
    zlabel('Z');    title('Cylinder Visualization');
%     hold off;
end
