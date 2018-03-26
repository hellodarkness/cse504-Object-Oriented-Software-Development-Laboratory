Jianing lab1

This program print the hand rank then print the sorted hand cards.

Return Values:
-1 : cannot open file
 0 : success
 2 : missing file name, zero arguments
 3 : no card content, input file is blank, or less than 5 cards input
 4 : more than one input file, two additional arguments
 
 For the hands.txt test, the program return the deck ranking as expected:
Invalid card number
Invalid card number
no rank
full house
straight
three of a kind
straight flush
one pair
four of a kind
flush
two pairs

when there are not exactly 5 valid card definition strings from the line, the program generate a warning message but continue to process other lines from the file.