def formatString(inputString, type=str):
    capString = str.upper(inputString)
    formattedChars = ['_' + char for char in capString]
    counter = 4 
    length = len(formattedChars)

    while counter < length:
        i = ", ".join(formattedChars[0:4])
        print("mux({});".format(i))
        del formattedChars[0]
        length = len(formattedChars)
        counter +1

  
formatString("____have_a_great_day___always_think_positive____")