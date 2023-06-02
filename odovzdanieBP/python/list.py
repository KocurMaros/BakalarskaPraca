import h5py
import argparse

parser = argparse.ArgumentParser(description='Optional app description')
parser.add_argument('input_h5', type=str,
                    help='h5 file to be read')
args = parser.parse_args()

# Open the .h5 file in read mode
file = h5py.File(args.input_h5, 'r')

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


