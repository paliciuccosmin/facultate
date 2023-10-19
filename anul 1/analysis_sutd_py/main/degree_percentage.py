def getBachlorPercentage(has_bach):
    length = len(has_bach)
    total = sum(option for option in has_bach if option)
    percentage = total / length * 100
    print(f"Percentage of students that have a bachelor degree: {percentage}")
    return percentage


def getMastersPercentage(has_master):
    length = len(has_master)
    total = sum(option for option in has_master if option)
    percentage = total / length * 100
    print(f"Percentage of students that have a masters degree: {percentage}")
    return percentage


def getDoctoralPercentage(has_doc):
    length = len(has_doc)
    total = sum(option for option in has_doc if option)
    percentage = total / length * 100
    print(f"Percentage of students that have a doctoral degree: {percentage}")
    return percentage