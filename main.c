#include <stdio.h>
#include <string.h>

int main(void)
{
    char animal[7] =  "animal";
    char human[7] = "human";
    char car[7] = "car";
    char text[7] = {};
    printf("Give me a word command:\n1.animal\n2.human\n3.car\n:");
    scanf("%s", &text);
    if (strcmp(animal, text) == 0)
    {
        printf("--------------------------$$$$$$\n------------------------$$.......$$$\n ---------------------$$$..........$$$\n"
               "-------------------$$$.............$$$\n -----$*-$*-------$$................$$$\n -----$.$..$------$$..................$$\n"
               " -----+$.$$$----$$...................$$\n ---+*......$$----$$..................$$\n --$............$$---$$................$$\n"
               " -$..О...........$$$$................$$\n $................$$$:...............$$\n $$................$$$$............$$\n"
               " --*$$$................$$..........$$\n------$................$$...........$$\n -----$.....$$............$.........$$\n"
               " ------$..$....$$..........;$......$$\n ----$$$$$......$........;$......$$\n --------$................;$.....$$\n"
               "-------$$.....................$$\n-------$$$..................$$\n ----$$$$$$$$$$$$$$$$$\n");
    }
    else if (strcmp(human, text) == 0)
    {
        printf("    .#########.#######..\n   .#######################.\n  .############################.\n"
               " .################################.\n.#########,##,#####################.\n.#########-#,'########## ############.\n"
               ".######'#-##' # ##'### #. `####:#######.\n#####:'# #'###,##' # # +#. `###:':######\n"
               ".####,'###,##  ###  # # #`#. -####`######.\n.####+.' ,'#  ##' #   # # #`#`.`#####::####\n"
               "####'    #  '##'  #   #_'# #.## `#######;##\n#:##'      '       #   # ``..__# `#######:#\n"
               "#:##'  .#######s.   #.  .s######.\\`#####:##\n#:##   .\"______\"\"'    '\"\"_____\"\". `.#####:#\n"
               ".#:##   ><'(##)'> )    ( <'(##)`><   `####;#\n##:##  , , -==-' '.    .` `-==- . \\  ######'\n"
               "#|-'| / /      ,  :    : ,       \\ ` :####:'\n:#  |: '  '   /  .     .  .  `    `  |`####\n"
               "#|  :|   /   '  '       `  \\   . ,   :  #:#\n#L. | | ,  /   `.-._ _.-.'   .  \\ \\  : ) J##\n"
               "###\\ `  /  '                   \\  : : |  /##\n## #|.:: '       _    _        ` | | |'####\n"
               "#####|\\  |  (.-'.__`-'__.`-.)   :| ' ######\n######\\:      `-...___..-' '     :: /######\n"
               "#######\\``.                   ,'|  /#######\n# ######\\  \\       ___       / /' /#######\n"
               "# #'#####|\\  \\    -     -    /  ,'|### #. #.\n`#  #####| '-.`             ' ,-'  |### #  #\n         "
               "#' `#|    '._         ,.-'     #`#`#.\n         |       .'------' :       |#   #\n         |      :         :       |\n       "
               " |       :         :       |\n                :         :          dp\n");
    }
    else if (strcmp(car, text) == 0)
    {
        printf("       _______\n      //  ||\\ \\\n_____//___||_\\ \\___\n"
               ")  _          _    \\\n|_/ \\________/ \\___|\n__\\_/________\\_/______ \n");
    }
    return 0;

}