def averageQuestion(dict):
    index = 1
    averages = []
    for key, values in dict.items():
        sum = 0
        for value in values:
            sum += value
        avg = round(sum / len(values), 2)
        print(f"{key}: {avg}")
        index += 1
        
        
def countTrueFalse(arr):
    true_count = 0
    false_count = 0
    for value in arr:
        if value == True:
            true_count += 1
        else:
            false_count += 1
    
    return (true_count, false_count)


def statisticsTrueFalseDict(dict):
    for key, values in dict.items():
        true_count, false_count = countTrueFalse(values)
        print(f"{key}: [true: {true_count}, false: {false_count}]")