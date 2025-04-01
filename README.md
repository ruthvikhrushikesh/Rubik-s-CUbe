# RUBIK's-CUBE :

-> This is my rubik's cube code in c language...
-> This solves the cube using layer by layer method...
-> I used some extra algorithms to solve cube so my code will try to reduce the number of moves that takes to solve cube.. 
-> I used basic concepts like for loops, if-else-elseif statements, functions, structures, etc.. in efficient way....
-> Without making my code complex with advanced concepts like data structures and oops... 
-> Here you can solve any colour as layer_1...
-------------------------------------------------------------------------------------------------------------------------------------------
# How to give inputs :
-------------------------------------------------------------------------------------------------------------------------------------------

-> Give name of the colour at starting..
-> According to that colour, in terminal it self, it shows how to give inputs...
For example; if you take green, it shows like:
-> TAKE GREEN AS TOP AND BLUE AS BOTTOM (and you should enter colours at the given centers)
after entering 4 colours, it will say like
-> TAKE ORANGE AS BOTTOM WHILE ENTERING GREEN (and you should enter colours at the green center)
after that it will show like,
-> TAKE ORANGE AS TOP WHILE ENTERING BLUE (and you should enter colours at the blue center)
and press enter... it will take inputs..

-> And while giving inputs, use FIRST LETTER of the colour
-> Use only SMALL LETTERS. it will not recognise the capital letters...
-------------------------------------------------------------------------------------------------------------------------------------------
# HOW TO SOLVE :
-------------------------------------------------------------------------------------------------------------------------------------------

-> After giving inputs, it will shows the formulas like U,U',U2,R',etc... by using them you should solve the cube...
-> and at starting of instructions givin in the code output (just after you enter the colour to solve as layer_1, it shows how to hold the cube.. for example:;
-> In green colour, you should take ORANGE AS FACE AND GREEN AS TOP... and apply the formulas that has shown in my output...
-> in layer_2 (after completing layer_1)  you should hold the cube upside down.... for example;
-> In green colour, you are taking orange as face and green as top.. but now SAME FACE (ORANGE) BUT TAKE GREEN AS BOTTOM...
-> In this way you can solve it...
-------------------------------------------------------------------------------------------------------------------------------------------
# SAMPLE INPUTS :
-------------------------------------------------------------------------------------------------------------------------------------------
-> Here are some sample inputs (for solving GREEN AS FIRST COLOUR)
-> to use these inputs, you should give GREEN AT STARTING to solve as layer_1 ...
-> After entering GREEN , past these directly and press enter...

// wwrgyyoryyoygrrobbrorgwwobwbyrgooobggybwgbwrgbywobwyrg
// WWRGYYORYYOYGRROBBRORGWWOBWBYRGOOOBGGYBWGBWRGBYWOBWYRG
// wwrwywgywybgbrybowworrwyoryggrgogbgoorbygoyrgooywbbbbr
// wwrwywoyyybrbrbbwgbyrowyoybgorgogwgywrbbgoyggorgobrwro
// bgwoyrowwggggrrbyoyyywwywwybrwoobbwyrorbgyrbooggbbogrr 
// gybyygybgwwwrrgobbgrywwgwrbbbroogobgrorygorwyyrowbooyw
// ggbyyywrgwrobrowogbwbbwgyoorbrworwrbybrogyywygwoybgogr 
// ygbgyorwywrywroorooowgwybryobroorgbwbbrbgygybrwgybgwwg
// owwwyoororowwrbwwrgbyowybrgobbgobrgyrybyggbrwyogybgyrg
// yrwbyyorgbogbrwyybrorgwrrbygobwoorygwwogggyyobgwwbbwro 
// wwbbyrrygworyrworrgoorwggooyborooybyygrygggybbwbwbgwbw 
// ybwrygrybgwgyryrgrwbbrwgyowygoroboryoorwgyoogbwbbbogww
// rrwwyyyyybbobrobyygbybwogwwbygworbogwworggrgwrgogborro   
// gorbyyyobwrggrworbwwwowyrryboybowgbboggggyogorrrwbbwyy
// yyywywyorbrwbrbwrybwwrwobbroooworgorogrggggggwygybboyb
// oyyoywbbybrrbrobrgwwwywyryboogbowwwwggrgggggyorrrboybo
// owwoyobbogbgwrogbwyrbgwygrrybbroybywryrwggorwygrgboowy
// goroybwrryybrrbgygowbowwrobybyrowrgowgbgggowowrgybyybw 
// yyywywyorbrwbrbwrybwwrwobbroooworgorogrggggggwygybboyb
// yywryrbwrorgbrbyoyrwwowybryrooboyrbowgggggbggbwwwbooyg
// yoobybwwrwwwyrbgogroyrwyrwygybroorrobrbyggogobgggbbyww
// yybryrwyrwrrwryybbwwwowwobroooooybbbggrggggggyworbbyog
// U set...
// gygwybwobrobyryyrwwroowboroywrworyborgwgggggybogybwbbr
// yoobyboobyybyrbwrrrrywwwwowrwbroorygygggggggogrwybwbbo   
// gybwyboobrrbyrowrryoybwwwowrworobryyogygggggwgrgybwbbo
// rybbyboobroworbwryrwowwwbowgryroyryybgygggwgggrgybwobo
// gwboyyowgwrworboywbybowwrbgrorrowyybogrgggygyoryrbbgbw
// bowbyyowgrrborwrywywyowwryygywroorrgogbgggogobbwrbbgby
// brooywowrwwgorywrwroyowygrygyybobgbbwgbgggogrrrywbboyb
// wybbywoorowgbrowworryywbgbyrogoorrybwgwgggggobryybwyrb
// yyyryybrwrrwbrobbbowrywbywbwoowowooogggggggggybwobyrrr
// yyybywrrrrrwbrybwbowrowywbywooroobobgggggggggowwybbory
// ryowyrbwbyrrbrrrbbwwwywywwyooyooobbrgggggggggoyyrbboow
// green is already set..
// worst case layer-2
// yyyyyboworrrrrrbybwwwwwwyowoooooobrbgggggggggryybbbrbw
// without using layer 1 formula...
// yrwbyyorgbogbrwyybrorgwrrbygobwoorygwwogggyyobgwwbbwro
// yyyyyyoybrrrrrrrbowwwwwwbrroooooobbbgggggggggywybbbwow
// yyyyyyybrrrrrrrwbywwwwwwrbwooooooobogggggggggbrbobwbyb
// yyyyyyrybrrrrrrorrwwwwwwbwooooooobobgggggggggwbwbbbyby
// yyyyyyybbrrrrrrybbwwwwwwwbboooooorbogggggggggwrbobwoyr
// yyyyyyrbbrrrrrrwbbwwwwwwobyoooooorbbgggggggggbwwyboyro
// rybbyboobroworbwryrwowwwbowgryroyryybgygggwgggrgybwobo
// oyrbyrowrbgogrwgbggobgwgyryrrbyorgybwowwgbyywroywbboow
// yyyyyyoborrrrrrybrwwwwwwwbyoooooorbwgggggggggbobybrbwb
// yyyyyybbbrrrrrrrbywwwwwwrboooooooybogggggggggbwwobrbyw
// yyyyyyyyyrrrrrrrrrwwwwwwwwwooooooooogggggggggbbbbbbbbb
// wwgwyowybyrbgrrwrgrywwwoyooryrbooygoygrbgbbggbwgybrobo
// yyyyyyoyrrrrrrrbrbwwwwwwrwooooooobobgggggggggwbybbbwby
