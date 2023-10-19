import os
import openpyxl
import re

# Define the path to the top-level directory
directory = "chest_stud"

i9_values = []

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

                # Open the workbook and get the value from cell I9 in sheet 1
                workbook = openpyxl.load_workbook(file_path)
                sheet = workbook["Sheet1"]
                i9_value = sheet.cell(row=9, column=9).value

                # Do something with the value (e.g. print it)
                if isinstance(i9_value, int):
                    i9_str = str(i9_value)
                    if re.match("^\d\d\d\d$", i9_str):
                        i9_values.append(i9_str)