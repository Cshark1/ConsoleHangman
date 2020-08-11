#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;

struct rightSide{
    string guess    = "                  ";
    string letters1 = "    ABCDEFGHIJ    ";
    string letters2 = "    KLMNOPQRST    ";
    string letters3 = "      UVWXYZ      ";
    string message  = "";
    string message2 = "";
};

string getWord(int nr){
    string words[852];
    words[0] = "ABLE"; words[1] = "ABOUT"; words[2] = "ACCOUNT"; words[3] = "ACID"; words[4] = "ACROSS"; words[5] = "ACT"; words[6] = "ADDITION"; words[7] = "ADJUSTMENT"; words[8] = "ADVERTISEMENT"; words[9] = "AFTER"; words[10] = "AGAIN"; words[11] = "AGAINST"; words[12] = "AGREEMENT"; words[13] = "AIR"; words[14] = "ALL"; words[15] = "ALMOST"; words[16] = "AMONG"; words[17] = "AMOUNT"; words[18] = "AMUSEMENT"; words[19] = "AND"; words[20] = "ANGLE"; words[21] = "ANGRY"; words[22] = "ANIMAL"; words[23] = "ANSWER"; words[24] = "ANT"; words[25] = "ANY"; words[26] = "APPARATUS"; words[27] = "APPLE"; words[28] = "APPROVAL"; words[29] = "ARCH"; words[30] = "ARGUMENT"; words[31] = "ARM"; words[32] = "ARMY"; words[33] = "ART"; words[34] = "AS"; words[35] = "AT"; words[36] = "ATTACK"; words[37] = "ATTEMPT"; words[38] = "ATTENTION"; words[39] = "ATTRACTION"; words[40] = "AUTHORITY"; words[41] = "AUTOMATIC"; words[42] = "AWAKE"; words[43] = "BABY"; words[44] = "BACK"; words[45] = "BAD"; words[46] = "BAG"; words[47] = "BALANCE"; words[48] = "BALL"; words[49] = "BAND"; words[50] = "BASE"; words[51] = "BASIN"; words[52] = "BASKET"; words[53] = "BATH"; words[54] = "BE"; words[55] = "BEAUTIFUL"; words[56] = "BECAUSE"; words[57] = "BED"; words[58] = "BEE"; words[59] = "BEFORE"; words[60] = "BEHAVIOUR"; words[61] = "BELIEF"; words[62] = "BELL"; words[63] = "BENT"; words[64] = "BERRY"; words[65] = "BETWEEN"; words[66] = "BIRD"; words[67] = "BIRTH"; words[68] = "BIT"; words[69] = "BITE"; words[70] = "BITTER"; words[71] = "BLACK"; words[72] = "BLADE"; words[73] = "BLOOD"; words[74] = "BLOW"; words[75] = "BLUE"; words[76] = "BOARD"; words[77] = "BOAT"; words[78] = "BODY"; words[79] = "BOILING"; words[80] = "BONE"; words[81] = "BOOK"; words[82] = "BOOT"; words[83] = "BOTTLE"; words[84] = "BOX"; words[85] = "BOY"; words[86] = "BRAIN"; words[87] = "BRAKE"; words[88] = "BRANCH"; words[89] = "BRASS"; words[90] = "BREAD"; words[91] = "BREATH"; words[92] = "BRICK"; words[93] = "BRIDGE"; words[94] = "BRIGHT"; words[95] = "BROKEN"; words[96] = "BROTHER"; words[97] = "BROWN"; words[98] = "BRUSH"; words[99] = "BUCKET"; words[100] = "BUILDING"; words[101] = "BULB"; words[102] = "BURN"; words[103] = "BURST"; words[104] = "BUSINESS"; words[105] = "BUT"; words[106] = "BUTTER"; words[107] = "BUTTON"; words[108] = "BY"; words[109] = "CAKE"; words[110] = "CAMERA"; words[111] = "CANVAS"; words[112] = "CARD"; words[113] = "CARE"; words[114] = "CARRIAGE"; words[115] = "CART"; words[116] = "CAT"; words[117] = "CAUSE"; words[118] = "CERTAIN"; words[119] = "CHAIN"; words[120] = "CHALK"; words[121] = "CHANCE"; words[122] = "CHANGE"; words[123] = "CHEAP"; words[124] = "CHEESE"; words[125] = "CHEMICAL"; words[126] = "CHEST"; words[127] = "CHIEF"; words[128] = "CHIN"; words[129] = "CHURCH"; words[130] = "CIRCLE"; words[131] = "CLEAN"; words[132] = "CLEAR"; words[133] = "CLOCK"; words[134] = "CLOTH"; words[135] = "CLOUD"; words[136] = "COAL"; words[137] = "COAT"; words[138] = "COLD"; words[139] = "COLLAR"; words[140] = "COLOUR"; words[141] = "COMB"; words[142] = "COME"; words[143] = "COMFORT"; words[144] = "COMMITTEE"; words[145] = "COMMON"; words[146] = "COMPANY"; words[147] = "COMPARISON"; words[148] = "COMPETITION"; words[149] = "COMPLETE"; words[150] = "COMPLEX"; words[151] = "CONDITION"; words[152] = "CONNECTION"; words[153] = "CONSCIOUS"; words[154] = "CONTROL"; words[155] = "COOK"; words[156] = "COPPER"; words[157] = "COPY"; words[158] = "CORD"; words[159] = "CORK"; words[160] = "COTTON"; words[161] = "COUGH"; words[162] = "COUNTRY"; words[163] = "COVER"; words[164] = "COW"; words[165] = "CRACK"; words[166] = "CREDIT"; words[167] = "CRIME"; words[168] = "CRUEL"; words[169] = "CRUSH"; words[170] = "CRY"; words[171] = "CUP"; words[172] = "CUP"; words[173] = "CURRENT"; words[174] = "CURTAIN"; words[175] = "CURVE"; words[176] = "CUSHION"; words[177] = "DAMAGE"; words[178] = "DANGER"; words[179] = "DARK"; words[180] = "DAUGHTER"; words[181] = "DAY"; words[182] = "DEAD"; words[183] = "DEAR"; words[184] = "DEATH"; words[185] = "DEBT"; words[186] = "DECISION"; words[187] = "DEEP"; words[188] = "DEGREE"; words[189] = "DELICATE"; words[190] = "DEPENDENT"; words[191] = "DESIGN"; words[192] = "DESIRE"; words[193] = "DESTRUCTION"; words[194] = "DETAIL"; words[195] = "DEVELOPMENT"; words[196] = "DIFFERENT"; words[197] = "DIGESTION"; words[198] = "DIRECTION"; words[199] = "DIRTY"; words[200] = "DISCOVERY"; words[201] = "DISCUSSION"; words[202] = "DISEASE"; words[203] = "DISGUST"; words[204] = "DISTANCE"; words[205] = "DISTRIBUTION"; words[206] = "DIVISION"; words[207] = "DO"; words[208] = "DOG"; words[209] = "DOOR"; words[210] = "DOUBT"; words[211] = "DOWN"; words[212] = "DRAIN"; words[213] = "DRAWER"; words[214] = "DRESS"; words[215] = "DRINK"; words[216] = "DRIVING"; words[217] = "DROP"; words[218] = "DRY"; words[219] = "DUST"; words[220] = "EAR"; words[221] = "EARLY"; words[222] = "EARTH"; words[223] = "EAST"; words[224] = "EDGE"; words[225] = "EDUCATION"; words[226] = "EFFECT"; words[227] = "EGG"; words[228] = "ELASTIC"; words[229] = "ELECTRIC"; words[230] = "END"; words[231] = "ENGINE"; words[232] = "ENOUGH"; words[233] = "EQUAL"; words[234] = "ERROR"; words[235] = "EVEN"; words[236] = "EVENT"; words[237] = "EVER"; words[238] = "EVERY"; words[239] = "EXAMPLE"; words[240] = "EXCHANGE"; words[241] = "EXISTENCE"; words[242] = "EXPANSION"; words[243] = "EXPERIENCE"; words[244] = "EXPERT"; words[245] = "EYE"; words[246] = "FACE"; words[247] = "FACT"; words[248] = "FALL"; words[249] = "FALSE"; words[250] = "FAMILY"; words[251] = "FAR"; words[252] = "FARM"; words[253] = "FAT"; words[254] = "FATHER"; words[255] = "FEAR"; words[256] = "FEATHER"; words[257] = "FEEBLE"; words[258] = "FEELING"; words[259] = "FEMALE"; words[260] = "FERTILE"; words[261] = "FICTION"; words[262] = "FIELD"; words[263] = "FIGHT"; words[264] = "FINGER"; words[265] = "FIRE"; words[266] = "FIRST"; words[267] = "FISH"; words[268] = "FIXED"; words[269] = "FLAG"; words[270] = "FLAME"; words[271] = "FLAT"; words[272] = "FLIGHT"; words[273] = "FLOOR"; words[274] = "FLOWER"; words[275] = "FLY"; words[276] = "FOLD"; words[277] = "FOOD"; words[278] = "FOOLISH"; words[279] = "FOOT"; words[280] = "FOR"; words[281] = "FORCE"; words[282] = "FORK"; words[283] = "FORM"; words[284] = "FORWARD"; words[285] = "FOWL"; words[286] = "FRAME"; words[287] = "FREE"; words[288] = "FREQUENT"; words[289] = "FRIEND"; words[290] = "FROM"; words[291] = "FRONT"; words[292] = "FRUIT"; words[293] = "FULL"; words[294] = "FUTURE"; words[295] = "GARDEN"; words[296] = "GENERAL"; words[297] = "GET"; words[298] = "GIRL"; words[299] = "GIVE"; words[300] = "GLASS"; words[301] = "GLOVE"; words[302] = "GO"; words[303] = "GOAT"; words[304] = "GOLD"; words[305] = "GOOD"; words[306] = "GOVERNMENT"; words[307] = "GRAIN"; words[308] = "GRASS"; words[309] = "GREAT"; words[310] = "GREEN"; words[311] = "GREY"; words[312] = "GRIP"; words[313] = "GROUP"; words[314] = "GROWTH"; words[315] = "GUIDE"; words[316] = "GUN"; words[317] = "HAIR"; words[318] = "HAMMER"; words[319] = "HAND"; words[320] = "HANGING"; words[321] = "HAPPY"; words[322] = "HARBOUR"; words[323] = "HARD"; words[324] = "HARMONY"; words[325] = "HAT"; words[326] = "HATE"; words[327] = "HAVE"; words[328] = "HE"; words[329] = "HEAD"; words[330] = "HEALTHY"; words[331] = "HEAR"; words[332] = "HEARING"; words[333] = "HEART"; words[334] = "HEAT"; words[335] = "HELP"; words[336] = "HIGH"; words[337] = "HISTORY"; words[338] = "HOLE"; words[339] = "HOLLOW"; words[340] = "HOOK"; words[341] = "HOPE"; words[342] = "HORN"; words[343] = "HORSE"; words[344] = "HOSPITAL"; words[345] = "HOUR"; words[346] = "HOUSE"; words[347] = "HOW"; words[348] = "HUMOUR"; words[349] = "I"; words[350] = "ICE"; words[351] = "IDEA"; words[352] = "IF"; words[353] = "ILL"; words[354] = "IMPORTANT"; words[355] = "IMPULSE"; words[356] = "IN"; words[357] = "INCREASE"; words[358] = "INDUSTRY"; words[359] = "INK"; words[360] = "INSECT"; words[361] = "INSTRUMENT"; words[362] = "INSURANCE"; words[363] = "INTEREST"; words[364] = "INVENTION"; words[365] = "IRON"; words[366] = "ISLAND"; words[367] = "JELLY"; words[368] = "JEWEL"; words[369] = "JOIN"; words[370] = "JOURNEY"; words[371] = "JUDGE"; words[372] = "JUMP"; words[373] = "KEEP"; words[374] = "KETTLE"; words[375] = "KEY"; words[376] = "KICK"; words[377] = "KIND"; words[378] = "KISS"; words[379] = "KNEE"; words[380] = "KNIFE"; words[381] = "KNOT"; words[382] = "KNOWLEDGE"; words[383] = "LAND"; words[384] = "LANGUAGE"; words[385] = "LAST"; words[386] = "LATE"; words[387] = "LAUGH"; words[388] = "LAW"; words[389] = "LEAD"; words[390] = "LEAF"; words[391] = "LEARNING"; words[392] = "LEATHER"; words[393] = "LEFT"; words[394] = "LEG"; words[395] = "LET"; words[396] = "LETTER"; words[397] = "LEVEL"; words[398] = "LIBRARY"; words[399] = "LIFT"; words[400] = "LIGHT"; words[401] = "LIKE"; words[402] = "LIMIT"; words[403] = "LINE"; words[404] = "LINEN"; words[405] = "LIP"; words[406] = "LIQUID"; words[407] = "LIST"; words[408] = "LITTLE"; words[409] = "LIVING"; words[410] = "LOCK"; words[411] = "LONG"; words[412] = "LOOK"; words[413] = "LOOSE"; words[414] = "LOSS"; words[415] = "LOUD"; words[416] = "LOVE"; words[417] = "LOW"; words[418] = "MACHINE"; words[419] = "MAKE"; words[420] = "MALE"; words[421] = "MAN"; words[422] = "MANAGER"; words[423] = "MAP"; words[424] = "MARK"; words[425] = "MARKET"; words[426] = "MARRIED"; words[427] = "MASS"; words[428] = "MATCH"; words[429] = "MATERIAL"; words[430] = "MAY"; words[431] = "MEAL"; words[432] = "MEASURE"; words[433] = "MEAT"; words[434] = "MEDICAL"; words[435] = "MEETING"; words[436] = "MEMORY"; words[437] = "METAL"; words[438] = "MIDDLE"; words[439] = "MILITARY"; words[440] = "MILK"; words[441] = "MIND"; words[442] = "MINE"; words[443] = "MINUTE"; words[444] = "MIST"; words[445] = "MIXED"; words[446] = "MONEY"; words[447] = "MONKEY"; words[448] = "MONTH"; words[449] = "MOON"; words[450] = "MORNING"; words[451] = "MOTHER"; words[452] = "MOTION"; words[453] = "MOUNTAIN"; words[454] = "MOUTH"; words[455] = "MOVE"; words[456] = "MUCH"; words[457] = "MUSCLE"; words[458] = "MUSIC"; words[459] = "NAIL"; words[460] = "NAME"; words[461] = "NARROW"; words[462] = "NATION"; words[463] = "NATURAL"; words[464] = "NEAR"; words[465] = "NECESSARY"; words[466] = "NECK"; words[467] = "NEED"; words[468] = "NEEDLE"; words[469] = "NERVE"; words[470] = "NET"; words[471] = "NEW"; words[472] = "NEWS"; words[473] = "NIGHT"; words[474] = "NO"; words[475] = "NOISE"; words[476] = "NORMAL"; words[477] = "NORTH"; words[478] = "NOSE"; words[479] = "NOT"; words[480] = "NOTE"; words[481] = "NOW"; words[482] = "NUMBER"; words[483] = "NUT"; words[484] = "OBSERVATION"; words[485] = "OF"; words[486] = "OFF"; words[487] = "OFFER"; words[488] = "OFFICE"; words[489] = "OIL"; words[490] = "OLD"; words[491] = "ON"; words[492] = "ONLY"; words[493] = "OPEN"; words[494] = "OPERATION"; words[495] = "OPINION"; words[496] = "OPPOSITE"; words[497] = "OR"; words[498] = "ORANGE"; words[499] = "ORDER"; words[500] = "ORGANIZATION"; words[501] = "ORNAMENT"; words[502] = "OTHER"; words[503] = "OUT"; words[504] = "OVEN"; words[505] = "OVER"; words[506] = "OWNER"; words[507] = "PAGE"; words[508] = "PAIN"; words[509] = "PAINT"; words[510] = "PAPER"; words[511] = "PARALLEL"; words[512] = "PARCEL"; words[513] = "PART"; words[514] = "PAST"; words[515] = "PASTE"; words[516] = "PAYMENT"; words[517] = "PEACE"; words[518] = "PEN"; words[519] = "PENCIL"; words[520] = "PERSON"; words[521] = "PHYSICAL"; words[522] = "PICTURE"; words[523] = "PIG"; words[524] = "PIN"; words[525] = "PIPE"; words[526] = "PLACE"; words[527] = "PLANE"; words[528] = "PLANT"; words[529] = "PLATE"; words[530] = "PLAY"; words[531] = "PLEASE"; words[532] = "PLEASURE"; words[533] = "PLOUGH"; words[534] = "POCKET"; words[535] = "POINT"; words[536] = "POISON"; words[537] = "POLISH"; words[538] = "POLITICAL"; words[539] = "POOR"; words[540] = "PORTER"; words[541] = "POSITION"; words[542] = "POSSIBLE"; words[543] = "POT"; words[544] = "POTATO"; words[545] = "POWDER"; words[546] = "POWER"; words[547] = "PRESENT"; words[548] = "PRICE"; words[549] = "PRINT"; words[550] = "PRISON"; words[551] = "PRIVATE"; words[552] = "PROBABLE"; words[553] = "PROCESS"; words[554] = "PRODUCE"; words[555] = "PROFIT"; words[556] = "PROPERTY"; words[557] = "PROSE"; words[558] = "PROTEST"; words[559] = "PUBLIC"; words[560] = "PULL"; words[561] = "PUMP"; words[562] = "PUNISHMENT"; words[563] = "PURPOSE"; words[564] = "PUSH"; words[565] = "PUT"; words[566] = "QUALITY"; words[567] = "QUESTION"; words[568] = "QUICK"; words[569] = "QUIET"; words[570] = "QUITE"; words[571] = "RAIL"; words[572] = "RAIN"; words[573] = "RANGE"; words[574] = "RAT"; words[575] = "RATE"; words[576] = "RAY"; words[577] = "REACTION"; words[578] = "READING"; words[579] = "READY"; words[580] = "REASON"; words[581] = "RECEIPT"; words[582] = "RECORD"; words[583] = "RED"; words[584] = "REGRET"; words[585] = "REGULAR"; words[586] = "RELATION"; words[587] = "RELIGION"; words[588] = "REPRESENTATIVE"; words[589] = "REQUEST"; words[590] = "RESPECT"; words[591] = "RESPONSIBLE"; words[592] = "REST"; words[593] = "REWARD"; words[594] = "RHYTHM"; words[595] = "RICE"; words[596] = "RIGHT"; words[597] = "RING"; words[598] = "RIVER"; words[599] = "ROAD"; words[600] = "ROD"; words[601] = "ROLL"; words[602] = "ROOF"; words[603] = "ROOM"; words[604] = "ROOT"; words[605] = "ROUGH"; words[606] = "ROUND"; words[607] = "RUB"; words[608] = "RULE"; words[609] = "RUN"; words[610] = "SAD"; words[611] = "SAFE"; words[612] = "SAIL"; words[613] = "SALT"; words[614] = "SAME"; words[615] = "SAND"; words[616] = "SAY"; words[617] = "SCALE"; words[618] = "SCHOOL"; words[619] = "SCIENCE"; words[620] = "SCISSORS"; words[621] = "SCREW"; words[622] = "SEA"; words[623] = "SEAT"; words[624] = "SECOND"; words[625] = "SECRET"; words[626] = "SECRETARY"; words[627] = "SEE"; words[628] = "SEED"; words[629] = "SEEM"; words[630] = "SELECTION"; words[631] = "SELF"; words[632] = "SEND"; words[633] = "SENSE"; words[634] = "SEPARATE"; words[635] = "SERIOUS"; words[636] = "SERVANT"; words[637] = "SEX"; words[638] = "SHADE"; words[639] = "SHAKE"; words[640] = "SHAME"; words[641] = "SHARP"; words[642] = "SHEEP"; words[643] = "SHELF"; words[644] = "SHIP"; words[645] = "SHIRT"; words[646] = "SHOCK"; words[647] = "SHOE"; words[648] = "SHORT"; words[649] = "SHUT"; words[650] = "SIDE"; words[651] = "SIGN"; words[652] = "SILK"; words[653] = "SILVER"; words[654] = "SIMPLE"; words[655] = "SISTER"; words[656] = "SIZE"; words[657] = "SKIN"; words[658] = "SKIRT"; words[659] = "SKY"; words[660] = "SLEEP"; words[661] = "SLIP"; words[662] = "SLOPE"; words[663] = "SLOW"; words[664] = "SMALL"; words[665] = "SMASH"; words[666] = "SMELL"; words[667] = "SMILE"; words[668] = "SMOKE"; words[669] = "SMOOTH"; words[670] = "SNAKE"; words[671] = "SNEEZE"; words[672] = "SNOW"; words[673] = "SO"; words[674] = "SOAP"; words[675] = "SOCIETY"; words[676] = "SOCK"; words[677] = "SOFT"; words[678] = "SOLID"; words[679] = "SOME"; words[680] = "SON"; words[681] = "SONG"; words[682] = "SORT"; words[683] = "SOUND"; words[684] = "SOUP"; words[685] = "SOUTH"; words[686] = "SPACE"; words[687] = "SPADE"; words[688] = "SPECIAL"; words[689] = "SPONGE"; words[690] = "SPOON"; words[691] = "SPRING"; words[692] = "SQUARE"; words[693] = "STAGE"; words[694] = "STAMP"; words[695] = "STAR"; words[696] = "START"; words[697] = "STATEMENT"; words[698] = "STATION"; words[699] = "STEAM"; words[700] = "STEEL"; words[701] = "STEM"; words[702] = "STEP"; words[703] = "STICK"; words[704] = "STICKY"; words[705] = "STIFF"; words[706] = "STILL"; words[707] = "STITCH"; words[708] = "STOCKING"; words[709] = "STOMACH"; words[710] = "STONE"; words[711] = "STOP"; words[712] = "STORE"; words[713] = "STORY"; words[714] = "STRAIGHT"; words[715] = "STRANGE"; words[716] = "STREET"; words[717] = "STRETCH"; words[718] = "STRONG"; words[719] = "STRUCTURE"; words[720] = "SUBSTANCE"; words[721] = "SUCH"; words[722] = "SUDDEN"; words[723] = "SUGAR"; words[724] = "SUGGESTION"; words[725] = "SUMMER"; words[726] = "SUN"; words[727] = "SUPPORT"; words[728] = "SURPRISE"; words[729] = "SWEET"; words[730] = "SWIM"; words[731] = "SYSTEM"; words[732] = "TABLE"; words[733] = "TAIL"; words[734] = "TAKE"; words[735] = "TALK"; words[736] = "TALL"; words[737] = "TASTE"; words[738] = "TAX"; words[739] = "TEACHING"; words[740] = "TENDENCY"; words[741] = "TEST"; words[742] = "THAN"; words[743] = "THAT"; words[744] = "THE"; words[745] = "THEN"; words[746] = "THEORY"; words[747] = "THERE"; words[748] = "THICK"; words[749] = "THIN"; words[750] = "THING"; words[751] = "THIS"; words[752] = "THOUGHT"; words[753] = "THREAD"; words[754] = "THROAT"; words[755] = "THROUGH"; words[756] = "THROUGH"; words[757] = "THUMB"; words[758] = "THUNDER"; words[759] = "TICKET"; words[760] = "TIGHT"; words[761] = "TILL"; words[762] = "TIME"; words[763] = "TIN"; words[764] = "TIRED"; words[765] = "TO"; words[766] = "TOE"; words[767] = "TOGETHER"; words[768] = "TOMORROW"; words[769] = "TONGUE"; words[770] = "TOOTH"; words[771] = "TOP"; words[772] = "TOUCH"; words[773] = "TOWN"; words[774] = "TRADE"; words[775] = "TRAIN"; words[776] = "TRANSPORT"; words[777] = "TRAY"; words[778] = "TREE"; words[779] = "TRICK"; words[780] = "TROUBLE"; words[781] = "TROUSERS"; words[782] = "TRUE"; words[783] = "TURN"; words[784] = "TWIST"; words[785] = "UMBRELLA"; words[786] = "UNDER"; words[787] = "UNIT"; words[788] = "UP"; words[789] = "USE"; words[790] = "VALUE"; words[791] = "VERSE"; words[792] = "VERY"; words[793] = "VESSEL"; words[794] = "VIEW"; words[795] = "VIOLENT"; words[796] = "VOICE"; words[797] = "WAITING"; words[798] = "WALK"; words[799] = "WALL"; words[800] = "WAR"; words[801] = "WARM"; words[802] = "WASH"; words[803] = "WASTE"; words[804] = "WATCH"; words[805] = "WATER"; words[806] = "WAVE"; words[807] = "WAX"; words[808] = "WAY"; words[809] = "WEATHER"; words[810] = "WEEK"; words[811] = "WEIGHT"; words[812] = "WELL"; words[813] = "WEST"; words[814] = "WET"; words[815] = "WHEEL"; words[816] = "WHEN"; words[817] = "WHERE"; words[818] = "WHILE"; words[819] = "WHIP"; words[820] = "WHISTLE"; words[821] = "WHITE"; words[822] = "WHO"; words[823] = "WHY"; words[824] = "WIDE"; words[825] = "WILL"; words[826] = "WIND"; words[827] = "WINDOW"; words[828] = "WINE"; words[829] = "WING"; words[830] = "WINTER"; words[831] = "WIRE"; words[832] = "WISE"; words[833] = "WITH"; words[834] = "WOMAN"; words[835] = "WOOD"; words[836] = "WOOL"; words[837] = "WORD"; words[838] = "WORK"; words[839] = "WORM"; words[840] = "WOUND"; words[841] = "WRITING"; words[842] = "WRONG"; words[843] = "YEAR"; words[844] = "YELLOW"; words[845] = "YES"; words[846] = "YESTERDAY"; words[847] = "YOU"; words[848] = "YOUNG"; words[849] = "BERNHARD"; words[850] = "BREYTENBACH"; words[851] = "ANDROID";
    return words[nr];
}

bool checkForWin(const rightSide& rightSide){
    if((rightSide.guess.find('_') < 0) || (rightSide.guess.find('_') > 19)){
        return true;
    } else
        return false;
}

int isValid(string guess,const rightSide& rightSide){
    transform(guess.begin(),guess.end(),guess.begin(), ::toupper);
    int l1=rightSide.letters1.find(guess),l2=rightSide.letters2.find(guess),l3=rightSide.letters3.find(guess);
    if(guess.empty())
        return 2; //empty input
    if(guess.size() > 1)
        return 3; //only 1 character allowed
    if(!(guess == "A" || guess == "B" || guess == "C" || guess == "D" || guess == "E" || guess == "F" || guess == "G" || guess == "H" || guess == "I" || guess == "J" || guess == "K" || guess == "L" || guess == "M" || guess == "N" || guess == "O" || guess == "P" || guess == "Q" || guess == "R" || guess == "S" || guess == "T" || guess == "U" || guess == "V" || guess == "W" || guess == "X" || guess == "Y" || guess == "Z"))
        return 4; //character not valid
    if(!((rightSide.letters1.find(guess) <= 19 && rightSide.letters1.find(guess) > 0) || (rightSide.letters2.find(guess) <= 19 && rightSide.letters2.find(guess) > 0) || (rightSide.letters3.find(guess) <= 19 && rightSide.letters3.find(guess) > 0)))
        return 5; //letter already guessed
    return 1;
}

void isGood(string guess, string word, rightSide& rightSide, short int& mistakes){
    int appearance = 0;
    if(word.find(guess) <= word.size() && word.find(guess) >= 0){
        while (word.find(guess) <= word.size()) {
            int startpos = 9 - word.size() / 2 - 1;
            int inwordpos = word.find(guess);
            int pos = startpos + inwordpos;
            rightSide.guess[pos] = word[inwordpos];
            word[inwordpos] = '-';
            appearance++;
        }
        if(appearance <= 1)
            rightSide.message = "Lertter '" + guess + "' appears " + to_string(appearance) + " time!";
        else
            rightSide.message = "Lertter '" + guess + "' appears " + to_string(appearance) + " times!";
    } else{
        mistakes++;
        rightSide.message = "There are no '" + guess + "'s in the word!";
    }
}

void show(rightSide& rightSide,const int& mistakes, bool& alive, bool win, string word){
    if (win)
        rightSide.message2 = "You win!";
    else
        rightSide.message2 = "Please input a letter: ";
    switch (mistakes) {
        //stage 0
        case 0: {
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃                    " << endl
                 << "        ┃                    " << endl
                 << "        ┃                    " << rightSide.letters1 << endl
                 << "        ┃                    " << rightSide.letters2 << endl
                 << "        ┃                    " << rightSide.letters3 << endl
                 << "        ┃                    " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 1: {
            //stage 1
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃                    " << rightSide.letters1 << endl
                 << "        ┃                    " << rightSide.letters2 << endl
                 << "        ┃                    " << rightSide.letters3 << endl
                 << "        ┃                    " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 2: {
            //stage 2
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃        ┃           " << rightSide.letters1 << endl
                 << "        ┃        ┃           " << rightSide.letters2 << endl
                 << "        ┃        ┃           " << rightSide.letters3 << endl
                 << "        ┃                    " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 3: {
            //stage 3
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃        ┃           " << rightSide.letters1 << endl
                 << "        ┃        ┃           " << rightSide.letters2 << endl
                 << "        ┃        ┃           " << rightSide.letters3 << endl
                 << "        ┃       ╱            " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 4: {
            //stage 4
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃        ┃           " << rightSide.letters1 << endl
                 << "        ┃        ┃           " << rightSide.letters2 << endl
                 << "        ┃        ┃           " << rightSide.letters3 << endl
                 << "        ┃       ╱ ╲          " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 5: {
            //stage 5
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃       ╱┃           " << rightSide.letters1 << endl
                 << "        ┃        ┃           " << rightSide.letters2 << endl
                 << "        ┃        ┃           " << rightSide.letters3 << endl
                 << "        ┃       ╱ ╲          " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 6: {
            //stage 6
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃       ╱┃╲          " << rightSide.letters1 << endl
                 << "        ┃        ┃           " << rightSide.letters2 << endl
                 << "        ┃        ┃           " << rightSide.letters3 << endl
                 << "        ┃       ╱ ╲          " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl
                 << "Game over! The word was: " + word + ".";
            cout.flush();
            std::this_thread::sleep_for(std::chrono::seconds(3));
            cout << endl << endl << endl << endl << endl << endl;
            alive = false;
            break;
        }
    }
}

void markAsGuessed(rightSide& rightSide, string guess){
    if (rightSide.letters1.find(guess) <= 18){
        rightSide.letters1[rightSide.letters1.find(guess)] = '-';
    } else if(rightSide.letters2.find(guess) <= 18){
        rightSide.letters2[rightSide.letters2.find(guess)] = '-';
    } else if(rightSide.letters3.find(guess) <= 18){
        rightSide.letters3[rightSide.letters3.find(guess)] = '-';
    }
}

void initRightSideGuess(rightSide& rightSide,const string& word){
    int start = 9 - word.size() / 2 - 1, finish = start + word.size();
    //add "_" in rightSide.guess
    for (int i = start, n = 0; i < finish; ++i) {
        rightSide.guess[i] = '_';
        n++;
    }
}

void setSeed(){
    srand(time(nullptr));
}

void getRandomWord(rightSide& rightSide, string& word){
    setSeed();
    int ranword = rand() % 854;
    word = getWord(ranword);
    initRightSideGuess(rightSide,word);
}

bool game(rightSide& rightSide, short int& mistakes, bool& alive, string& word, bool& win){
    show(rightSide,mistakes,alive,0,word);
    while (alive) {
        string guess;
        cin >> guess;
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        bool win = checkForWin(rightSide);
        switch (isValid(guess, rightSide)) {
            case 1:
                isGood(guess, word, rightSide, mistakes);
                markAsGuessed(rightSide, guess);
                win = checkForWin(rightSide);
                show(rightSide, mistakes, alive, win, word);
                break;
            case 2:
                rightSide.message = "Input can't be empty!";
                show(rightSide, mistakes, alive, win, word);
                break;
            case 3:
                rightSide.message = "Please enter 1 letter at a time!";
                show(rightSide, mistakes, alive, win, word);
                break;
            case 4:
                rightSide.message = "Please input a letter!";
                show(rightSide, mistakes, alive, win, word);
                break;
            case 5:
                rightSide.message = "Letter already guessed!";
                show(rightSide, mistakes, alive, win, word);
                break;
        }
        if (win)
            return true;
    }
    return false;
}

bool startGame(rightSide& rightSide, short int& mistakes, bool& alive, string& word, bool& win){
    mistakes = 0;
    win = false;
    alive = 1;
    word = "";
    rightSide.guess    = "                  ";
    rightSide.letters1 = "    ABCDEFGHIJ    ";
    rightSide.letters2 = "    KLMNOPQRST    ";
    rightSide.letters3 = "      UVWXYZ      ";
    rightSide.message  = "";
    rightSide.message2 = "";
    getRandomWord(rightSide, word);
    bool hasWon = game(rightSide,mistakes,alive,word,win);
    return hasWon;
}

void checkIfGameIsWon(const bool& hasWon, unsigned short int& wins, unsigned short int& loses){
    if (hasWon) {
        wins++;
        return;
    } else {
        loses++;
        return;
    }
}

void mainMenu(rightSide& rightSide, short int& mistakes, unsigned short int& wins, unsigned short int& loses, bool& alive, bool& win, string& word){
    bool quit = false, correctOption = false;
    int option;
    while (!quit) {
        correctOption = false;
        cout << "  _    _                                            _               _____     _                _    \n"
                " | |  | |                                          | |             / ____|   | |              | |   \n"
                " | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __    | |__  _   _   | |     ___| |__   __ _ _ __| | __\n"
                " |  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\   | '_ \\| | | |  | |    / __| '_ \\ / _` | '__| |/ /\n"
                " | |  | | (_| | | | | (_| | | | | | | (_| | | | |  | |_) | |_| |  | |____\\__ \\ | | | (_| | |  |   < \n"
                " |_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|  |_.__/ \\__, |   \\_____|___/_| |_|\\__,_|_|  |_|\\_\\\n"
                "                      __/ |                                __/ |                                    \n"
                "                     |___/                                |___/                                     "
             << endl << endl << endl
             << "     Statistics:     " << endl << endl
             << "Wins: " << wins << " "
             << "Loses: " << loses << "."
             << endl << endl << endl
             << "Press 1 for a new game."
             << endl << endl
             << "Press 2 to exit."
             << endl << endl << endl;

        while (!correctOption) {
            cout << "Please enter your option: ";
            if(cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cin >> option;
            if (option == 1) {
                //start a new game
                bool hasWon = startGame(rightSide, mistakes, alive, word, win);
                checkIfGameIsWon(hasWon, wins, loses);
                correctOption = true;
                break;
            } else if (option == 2) {
                quit = true;
                correctOption = true;
                break;
            } else{
                cout << endl << endl;
                cout << "Invalid option!" << endl << endl;
            }
        }
    }
}

int main() {
    rightSide rightSide;
    short int mistakes = 0;
    unsigned short int wins = 0,loses = 0;
    bool alive = 1;
    bool win = 0;
    string word;
    mainMenu(rightSide,mistakes,wins,loses,alive,win,word);
}
/* 2500
  1.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃
        ┃
        ┃
        ┃
        ┃
        ┃
 ━━━━━━━┻━━━━━━━
  2.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃
        ┃
        ┃
        ┃
 ━━━━━━━┻━━━━━━━
  3.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃        ┃
        ┃        ┃
        ┃        ┃
        ┃
 ━━━━━━━┻━━━━━━━
  4.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃        ┃
        ┃        ┃
        ┃        ┃
        ┃       ╱
 ━━━━━━━┻━━━━━━━
  5.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃        ┃
        ┃        ┃
        ┃        ┃
        ┃       ╱ ╲
 ━━━━━━━┻━━━━━━━
  6.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃       ╱┃
        ┃        ┃
        ┃        ┃
        ┃       ╱ ╲
 ━━━━━━━┻━━━━━━━
  7.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃       ╱┃╲
        ┃        ┃
        ┃        ┃
        ┃       ╱ ╲
 ━━━━━━━┻━━━━━━━
 */


