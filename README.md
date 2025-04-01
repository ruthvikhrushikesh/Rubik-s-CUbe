------------------------------------------------------------------------------------------------------------------------------------------
# RUBIK's-CUBE :
------------------------------------------------------------------------------------------------------------------------------------------

-> This is my Rubik's Cube code in C...

-> It solves the cube using the layer-by-layer method

-> I used some extra algorithms to reduce the number of moves needed to solve the cube.. 

-> I used basic concepts only, like for loops, if else statements, functions, and structures but some what efficient manner....

-> I avoided using advanced concepts like data structures and OOP not to make my code complex... 

-> You can solve any color as Layer 1

------------------------------------------------------------------------------------------------------------------------------------------
# How to give inputs :
------------------------------------------------------------------------------------------------------------------------------------------

-> Give the name of the color at the start..

-> According to that color, the terminal itself shows how to give inputs.
For example, if you take green, it shows:

-> TAKE GREEN AS TOP AND BLUE AS BOTTOM (and you should enter colours at the given centers)
after entering 4 colours, it will say like

-> take ORANGE as bottom while entering GREEN (and you should enter colors at the green center)
After that, it will show:

-> TAKE ORANGE AS TOP WHILE ENTERING BLUE (and you should enter colours at the blue center)
and press enter... it will take inputs..

-> While giving inputs, use the FIRST LETTER of the color

-> Use only SMALL LETTERS. it will not recognise the capital letters...

------------------------------------------------------------------------------------------------------------------------------------------
# HOW TO SOLVE :
------------------------------------------------------------------------------------------------------------------------------------------

-> After giving inputs, it will show the formulas like U, U', U2, R', etc... By using them, you should solve the cube...

-> And at the start of the instructions given in the code output (just after you enter the colour to solve as layer_1), it shows how to hold the cube.. for example:

-> In green colour, you should take ORANGE AS FACE AND GREEN AS TOP... and apply the formulas that are shown in my output...

-> In layer_2 (after completing layer_1), you should hold the cube upside down.... for example:

-> In green colour, you took ORANGE AS FACE AND GREEN AS TOP.. but now keep the SAME FACE (ORANGE) BUT TAKE GREEN AS BOTTOM...

-> In this way, you can solve it...

------------------------------------------------------------------------------------------------------------------------------------------
# SAMPLE INPUTS :
------------------------------------------------------------------------------------------------------------------------------------------

-> Here are some sample inputs (for solving GREEN AS FIRST COLOUR)

-> To use these inputs, you should give GREEN AT THE START to solve as layer_1...

-> After entering GREEN, paste these directly and press enter...

// wwrgyyoryyoygrrobbrorgwwobwbyrgooobggybwgbwrgbywobwyrg
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
