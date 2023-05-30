import numpy as np
import h5py

# Open the .h5 file in read mode
file = h5py.File('h5/bushinghl_HL-48-28_bundle.h5', 'r')

# Access a specific dataset
dataset = file['data/P']

# Read the data from the dataset
data = dataset[()]

# Close the file
file.close()

# Set the print options to display all array elements
np.set_printoptions(threshold=np.inf)

# Process the data as needed
print(data)

