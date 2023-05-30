import h5py
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Open the .h5 file
file = h5py.File('h5/bushinghl_HL-48-28_bundle.h5', 'r')

# List the groups available in the file
print("Groups available in the .h5 file:")
for group_name in file:
    print(group_name)

# Choose a group to explore
group_name = input("Enter the name of the group to explore: ")

# Access the group
group = file[group_name]

# List the datasets within the group
print("Datasets available in the selected group:")
for dataset_name in group:
    print(dataset_name)

# Choose a dataset to visualize
dataset_name = input("Enter the name of the dataset to visualize: ")

# Access the dataset within the group
dataset = group[dataset_name]

# Get the data from the dataset
data = dataset[:]

# Close the .h5 file
file.close()

# Visualize the 3D data
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Extract x, y, and z coordinates from the 3D data
x = data[:, 0]
y = data[:, 1]
z = data[:, 2]

# Plot the 3D data
ax.scatter(x, y, z)

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('3D Data Visualization')

plt.show()

