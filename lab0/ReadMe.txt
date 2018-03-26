CSE504 ReadMe
Jianing Sun

clab0 is a program that read a card file containing card suit and rank information then print the
formated card information.

Test results:

Test1
input: clab0.exe card_file.txt
output: correct formated card informaiton as expected

Test2
input: clab0.exe card.txt(card.txt doesn't exist)
output: Cannot open file

Test3
input: clab0.exe 4digit_input.txt
4digit_input.txt content: 22CC 33CC 4S 5S
output:
Cardinput length error
Cardinput length error
four of spades
five of spades
Invalid card are skipped and with a print "Cardinput length error".

Test4
input: clab0.exe rank.txt 4S 5S
rank.txt content: TT GG
output:
Rank name error
Suit name error
Rank name error
Suit name error
four of spades
five of spades
Invalid card rank and invalid card suit are skipped and with a print
"Rank name error", "Suit name error".
five of spades".