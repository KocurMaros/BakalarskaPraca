import open3d as o3d
import numpy as np

# Specify the path to the .xyz file
file_path = 'hexw.xyz'
np.set_printoptions(threshold=np.inf)

# Load the points from the .xyz file
points = np.loadtxt(file_path, skiprows=0)  # Assuming the first row contains headers

# Create an Open3D point cloud object from the numpy array
pcd = o3d.geometry.PointCloud()
pcd.points = o3d.utility.Vector3dVector(points)

# Estimate normals for the point cloud
pcd.estimate_normals()

# Access the calculated normals
normals = np.asarray(pcd.normals)

# Process the normals as needed
print(normals)