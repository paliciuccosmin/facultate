import os
import openpyxl

# Define the path to the top-level directory
directory = "chest_stud"

x_found_dict = {}  # Initialize an empty dictionary

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

                # Open the workbook and look for "x" or "X" in columns D and E
                workbook = openpyxl.load_workbook(file_path)
                sheet = workbook["Sheet1"]
                
                for i, row in enumerate(sheet.iter_rows(min_row=16, max_row=33, min_col=4, max_col=5)):
                    row_x_found = False
                    column_x_found = None  # initialize the column to None
                    for j, cell in enumerate(row):
                        if cell.value == "x" or cell.value == "X":
                            row_x_found = True
                            column_x_found = True if j == 0 else False  # set the column to "D" or "E" based on the index
                    
                    # Store the answer in the dictionary
                    if i+16 not in x_found_dict:
                        x_found_dict[i+16] = []
                    x_found_dict[i+16].append(column_x_found)

print(x_found_dict)
