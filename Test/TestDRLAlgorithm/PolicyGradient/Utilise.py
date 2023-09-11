# Used when dealing with the data from the csv, if is numeric return true
def isNumeric(s):
    if s == " " or s == "[" or s == "]" or s == "\n":
        return False

    return True


# help change a string to a float list
def convertToFloat(input_str):

    """
    Note : we multiply a 0.2 to the state to make it smaller
    """

    i = 0
    Numbers = []

    while i < len(input_str):
        if isNumeric(input_str[i]):
            Number = ""
            while isNumeric(input_str[i]):
                Number += input_str[i]
                i = i + 1

            Numbers.append(Number)

        i = i + 1

    for i in range(len(Numbers)):
        Numbers[i] = float(Numbers[i])

    return Numbers
