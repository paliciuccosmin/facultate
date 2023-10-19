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
                sheet = workbook["Sheet6"]

                for i, row in enumerate(sheet.iter_rows(min_row=13, max_row=21, min_col=4, max_col=8)):
                    row_x_found = False
                    column_x_found = None  # initialize the column to None
                    for j, cell in enumerate(row):
                        if cell.value == "x" or cell.value == "X":
                            row_x_found = True
                            column_x_found = j - 3  # set the column to 1 for D, 2 for E, etc.

                    # Store the answer in the dictionary
                    if i+13 not in x_found_dict:
                        x_found_dict[i+13] = []
                    if column_x_found is not None:
                        column_num = 4 + column_x_found  # add the index of the starting column
                        if column_num <= 8:  # only add values between 1 and 5
                            x_found_dict[i+13].append(column_num)

print(x_found_dict)
