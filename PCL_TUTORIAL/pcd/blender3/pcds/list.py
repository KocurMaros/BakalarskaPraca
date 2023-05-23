import h5py

# Open the .h5 file in read mode
file = h5py.File('kinectt.h5', 'r')

# List all the groups and datasets in the file
print("Groups and Datasets:")
def print_attrs(name, obj):
    print(name)
    if isinstance(obj, h5py.Dataset):
        print(obj.shape)
        print(obj.dtype)
        print(obj[:])  # Print the data
    elif isinstance(obj, h5py.Group):
        print(obj.attrs.keys())  # Print the attributes

file.visititems(print_attrs)

# Close the file
file.close()
