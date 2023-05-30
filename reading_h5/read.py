import numpy as np
import h5py
import argparse

parser = argparse.ArgumentParser(description='Optional app description')
parser.add_argument('input_h5', type=str,
                    help='h5 file to be read')
args = parser.parse_args()

# Open the .h5 file in read mode
file = h5py.File(args.input_h5, 'r')
np.set_printoptions(threshold=np.inf)
# Access a specific dataset
for i in range(9):
    to_read =  'hex_bolt_8_un_series_3_1_4x8x6_75_ansi_b18_2_1_soup_'+str(i)+'/gt_points'
    dataset = file[to_read]

    # Read the data from the dataset
    data = dataset[()]
    print(data)

# Close the file
file.close()

# Set the print options to display all array elements

# Process the data as needed

