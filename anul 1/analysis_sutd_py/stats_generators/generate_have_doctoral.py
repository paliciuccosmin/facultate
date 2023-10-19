import os
import openpyxl

# Define the path to the top-level directory
directory = "chest_stud"

x_found_array = []  # Initialize an empty dictionary

# Loop through each AC folder
for ac_folder in ["AC", "AC2", "AC3"]:
    ac_path = os.path.join(directory, ac_folder)

    # Loop through each number folder in the AC folder
    for number_folder in os.listdir(ac_path):
        number_path = os.path.join(ac_path, number_folder)

        # Look for the .xlsx file in the number folder
        for filename in os.listdir(number_path):
            if filename.endswith(".xlsx"):
                file_path = os.path.join(number_path, filename)

            # Open the workbook and look for "x" or "X" in columns C and D
            workbook = openpyxl.load_workbook(file_path)
            sheet = workbook["Sheet0"]
            
            c22_x_found = False  # Initialize the boolean variable for C22 cell
            d22_x_found = False  # Initialize the boolean variable for D22 cell
            
            # Check if "x" or "X" exists in C22 and D22 cells
            if sheet["C26"].value == "x" or sheet["C26"].value == "X":
                c22_x_found = True
            elif sheet["D26"].value == "x" or sheet["D26"].value == "X":
                d22_x_found = True
            
            # Store the answer in the list
            if c22_x_found:
                x_found_array.append(True)
            elif d22_x_found:
                x_found_array.append(False)

print(x_found_array)
