Jianing Sun
jianing@wustl.edu

return value:
cannotOpenFile  -1
success 0
missFileName 2
twoArgumentWithShuffle 3
moreThanRepquiredInpput  4
twoArgumentWithoutShuffle  5

Test1:
only one command line argument is given but it contains "-shuffle".
return 3

Test2:
two command line arguments are given but neither one contains "-shuffle".
return 5

Test3:
no command line arguments are given
return -1

Test4:
more than 2 command line arguments are given
return 4

Test5:
input file: test_FourOfAKind.txt
ac ks qd jh 10c 9s 4d 3h 2c //

ah kc qs jd 10h 9c 4s 3d 2h //

ad kh qc js 10d 9h 4c 3s 2d //

as kd qh jc 10s 9d 4h 3c 2s //

6c 6h 6s 6d 7c  7h 7s 7d 8c //

Result after sorting cards:
hand1: twoclubs twodiamonds twohearts twospades eightclubs
hand2: threeclubs threediamonds threehearts threespades sevendiamonds
hand3: fourclubs fourdiamonds fourhearts fourspades sevenspades
hand4: sixclubs aceclubs acediamonds acehearts acespades
hand5: sixdiamonds jackclubs jackdiamonds jackhearts jackspades
hand6: sixhearts kingclubs kingdiamonds kinghearts kingspades
hand7: sixspades queenclubs queendiamonds queenhearts queenspades
hand8: sevenclubs tenclubs tendiamonds tenhearts tenspades
hand9: sevenhearts nineclubs ninediamonds ninehearts ninespades
Result after sorting by poker rank:
hand1: sixclubs aceclubs acediamonds acehearts acespades
hand2: sixhearts kingclubs kingdiamonds kinghearts kingspades
hand3: sixspades queenclubs queendiamonds queenhearts queenspades
hand4: sixdiamonds jackclubs jackdiamonds jackhearts jackspades
hand5: sevenclubs tenclubs tendiamonds tenhearts tenspades
hand6: sevenhearts nineclubs ninediamonds ninehearts ninespades
hand7: fourclubs fourdiamonds fourhearts fourspades sevenspades
hand8: threeclubs threediamonds threehearts threespades sevendiamonds
hand9: twoclubs twodiamonds twohearts twospades eightclubs

Test6:
input file: test_FlushFullHouse.txt
Qc js 4h 3s 3c jh qd jd 8h//
hh
jC 6s 5h kS 5C Ah 4d 3d 8s//
jj
7C 5s Kh 7s 6c 6h 6D kD 10h//
 76
kc qS 2h As 2c 7H AD 7D 10s//

!)@)

4C 4s 3h 2s Ac qh 5D 2d  10c//

Invalid card content
Invalid card content
Invalid card content
Invalid card content
Result after sorting cards:
hand1: twoclubs threeclubs fiveclubs sixclubs aceclubs
hand2: twodiamonds threediamonds sevendiamonds jackdiamonds kingdiamonds
hand3: twodiamonds threediamonds sevendiamonds jackdiamonds kingdiamonds
hand4: twohearts threehearts fourhearts fivehearts kinghearts
hand5: twospades threespades sevenspades kingspades acespades
hand6: fourclubs sevenclubs jackclubs queenclubs kingclubs
hand7: fourdiamonds fivediamonds sixdiamonds queendiamonds acediamonds
hand8: fourspades fivespades sixspades jackspades queenspades
hand9: sixhearts sevenhearts jackhearts queenhearts acehearts
Result after sorting by poker rank:
hand1: twospades threespades sevenspades kingspades acespades
hand2: sixhearts sevenhearts jackhearts queenhearts acehearts
hand3: fourdiamonds fivediamonds sixdiamonds queendiamonds acediamonds
hand4: twoclubs threeclubs fiveclubs sixclubs aceclubs
hand5: fourclubs sevenclubs jackclubs queenclubs kingclubs
hand6: twodiamonds threediamonds sevendiamonds jackdiamonds kingdiamonds
hand7: twodiamonds threediamonds sevendiamonds jackdiamonds kingdiamonds
hand8: twohearts threehearts fourhearts fivehearts kinghearts
hand9: fourspades fivespades sixspades jackspades queenspades

since there are four lines having invaid card content, the program print out 4 "Invalid card content" in the command 

Test7:
input file: test_StraightThreeKindNoRank.txt
2C 5C 10C 9S  3C 2H  4C KS KD//AS

3H 6H JC  10S 3D 2S  4S JH JD//AS
  
4H 7C QC  JS  3S 2D  4D 5S 5D//AS

5H 8C KS  QS  7S 7H  8H 6D 7D//As

AH 9C AC  KC  6S 6c  9D 9H 8S//As

Result after sorting cards:
hand1: twoclubs threehearts fourhearts fivehearts acehearts
hand2: twodiamonds twohearts twospades sixclubs sevenhearts
hand3: threeclubs threediamonds threespades sixspades sevenspades
hand4: fourclubs fourdiamonds fourspades eighthearts ninediamonds
hand5: fiveclubs sixhearts sevenclubs eightclubs nineclubs
hand6: fivespades sixdiamonds ninehearts jackhearts kingspades
hand7: fivespades sixdiamonds ninehearts jackhearts kingspades
hand8: ninespades tenspades jackspades queenspades kingclubs
hand9: tenclubs jackclubs queenclubs kingspades aceclubs
Result after sorting by poker rank:
hand1: tenclubs jackclubs queenclubs kingspades aceclubs
hand2: ninespades tenspades jackspades queenspades kingclubs
hand3: fiveclubs sixhearts sevenclubs eightclubs nineclubs
hand4: fourclubs fourdiamonds fourspades eighthearts ninediamonds
hand5: threeclubs threediamonds threespades sixspades sevenspades
hand6: twodiamonds twohearts twospades sixclubs sevenhearts
hand7: twoclubs threehearts fourhearts fivehearts acehearts
hand8: fivespades sixdiamonds ninehearts jackhearts kingspades
hand9: fivespades sixdiamonds ninehearts jackhearts kingspades

Test8: 
input file: test_TwoPairOnePair.txt
Ac Kc QC  JC 10c 9c 8C 7c 6c //

As ks qs  js 10s 9s 8s 7s 6s //

kd ad 10d qd 5d  4c jd 4d 3d //

kH ah 10h qh 5h  6h 4H Jh 5s //

2s 3s 2d  2H 2C  3c 6d 3h 4s // As

Result after sorting cards:
hand1: twoclubs fivediamonds fivehearts tenclubs tenspades
hand2: twodiamonds tendiamonds tenhearts queenclubs queenspades
hand3: twohearts jackclubs jackspades queendiamonds queenhearts
hand4: twospades kingdiamonds kinghearts aceclubs acespades
hand5: threeclubs fourclubs sixhearts nineclubs ninespades
hand6: threediamonds fourspades fivespades sixclubs sixspades
hand7: threehearts fourdiamonds sevenclubs sevenspades jackhearts
hand8: threespades kingclubs kingspades acediamonds acehearts
hand9: fourhearts sixdiamonds eightclubs eightspades jackdiamonds
Result after sorting by poker rank:
hand1: threespades kingclubs kingspades acediamonds acehearts
hand2: twospades kingdiamonds kinghearts aceclubs acespades
hand3: twohearts jackclubs jackspades queendiamonds queenhearts
hand4: twodiamonds tendiamonds tenhearts queenclubs queenspades
hand5: twoclubs fivediamonds fivehearts tenclubs tenspades
hand6: threeclubs fourclubs sixhearts nineclubs ninespades
hand7: fourhearts sixdiamonds eightclubs eightspades jackdiamonds
hand8: threehearts fourdiamonds sevenclubs sevenspades jackhearts
hand9: threediamonds fourspades fivespades sixclubs sixspades
