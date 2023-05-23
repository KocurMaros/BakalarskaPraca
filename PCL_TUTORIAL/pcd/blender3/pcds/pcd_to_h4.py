import h5py
import open3d as o3d
import numpy as np

# Path to the PCD file
pcd_file = "base.pcd"

# Read PCD file using open3d
pcd = o3d.io.read_point_cloud(pcd_file)

# Get the point cloud data as a NumPy array
points = np.asarray(pcd.points)
colors = np.asarray(pcd.colors)

# Create an HDF5 file
h5_file = "base.h5"
file = h5py.File(h5_file, "w")

# Create a group in the HDF5 file
group = file.create_group("PointCloud")

# Write the point cloud data to the HDF5 file
group.create_dataset("points", data=points)
#group.create_dataset("colors", data=colors)

# Close the HDF5 file
file.close()

print("PCD to HDF5 conversion complete.")

