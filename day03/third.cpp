#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <random>


struct helper
{
	helper(int x, int y, int width, int height):
		x(x), y(y), width(width), height(height)
	{

	}
	int x;
	int y;
	int width;
	int height;
};


int main()
{
	std::vector<helper> data{ {108, 350, 22, 29}, {370, 638, 13, 12}, {242, 156, 26, 23}, {638, 540, 14, 27}, {8, 793, 24, 29}, {158, 828, 15, 15}, {103, 549, 22, 26}, {942, 637, 15, 15}, {405, 628, 19, 11}, {419, 259, 18, 12}, {698, 565, 15, 22}, {150, 478, 23, 12}, {383, 112, 25, 23}, {675, 306, 28, 19}, {110, 919, 19, 18}, {514, 568, 23, 19}, {748, 481, 22, 23}, {383, 79, 13, 6}, {727, 848, 19, 18}, {165, 463, 10, 18}, {108, 559, 21, 23}, {576, 345, 13, 19}, {617, 575, 26, 11}, {914, 319, 10, 29}, {110, 600, 11, 16}, {780, 154, 14, 18}, {620, 756, 11, 21}, {162, 843, 17, 22}, {485, 231, 10, 27}, {646, 443, 17, 19}, {512, 520, 20, 28}, {0, 896, 24, 27}, {428, 689, 24, 11}, {7, 827, 11, 22}, {341, 149, 11, 23}, {460, 480, 28, 16}, {795, 226, 27, 23}, {805, 595, 21, 15}, {803, 235, 17, 19}, {528, 104, 25, 25}, {761, 616, 21, 29}, {140, 673, 16, 10}, {424, 75, 18, 23}, {568, 279, 22, 14}, {917, 645, 22, 24}, {357, 702, 18, 28}, {388, 952, 29, 16}, {352, 737, 22, 21}, {365, 731, 18, 20}, {664, 614, 11, 23}, {632, 549, 18, 20}, {756, 61, 28, 11}, {706, 283, 28, 14}, {900, 635, 19, 29}, {118, 925, 10, 19}, {634, 729, 26, 19}, {940, 102, 24, 13}, {562, 223, 17, 16}, {177, 233, 23, 23}, {654, 600, 27, 12}, {469, 357, 12, 6}, {3, 481, 28, 28}, {346, 210, 19, 22}, {157, 973, 20, 13}, {159, 281, 27, 12}, {135, 817, 29, 16}, {76, 209, 28, 27}, {802, 587, 26, 28}, {39, 276, 16, 12}, {258, 749, 19, 25}, {23, 820, 26, 24}, {173, 99, 20, 16}, {365, 125, 23, 22}, {135, 897, 21, 15}, {380, 342, 24, 19}, {106, 833, 26, 25}, {25, 576, 11, 23}, {343, 585, 21, 10}, {394, 771, 11, 25}, {110, 83, 29, 24}, {420, 79, 28, 17}, {805, 276, 29, 11}, {710, 294, 10, 29}, {107, 194, 14, 21}, {738, 695, 15, 16}, {180, 15, 13, 25}, {105, 718, 27, 23}, {949, 501, 20, 21}, {335, 922, 14, 26}, {56, 564, 12, 20}, {391, 358, 13, 29}, {86, 131, 11, 16}, {249, 528, 22, 29}, {449, 620, 28, 15}, {274, 745, 14, 15}, {518, 550, 21, 21}, {763, 909, 28, 24}, {809, 939, 24, 19}, {148, 444, 22, 21}, {967, 901, 24, 20}, {289, 559, 19, 27}, {894, 639, 10, 16}, {758, 45, 15, 15}, {572, 462, 20, 16}, {254, 803, 14, 20}, {771, 850, 17, 19}, {131, 784, 27, 11}, {779, 102, 23, 21}, {582, 722, 19, 12}, {810, 93, 27, 12}, {346, 322, 18, 20}, {86, 101, 21, 24}, {117, 921, 14, 11}, {49, 598, 18, 19}, {687, 969, 27, 28}, {294, 597, 17, 13}, {64, 115, 29, 13}, {360, 971, 13, 12}, {465, 354, 21, 13}, {853, 410, 19, 25}, {669, 843, 17, 19}, {712, 745, 21, 18}, {839, 363, 18, 26}, {412, 73, 29, 27}, {692, 962, 14, 15}, {66, 827, 10, 10}, {265, 96, 19, 18}, {387, 163, 26, 29}, {362, 384, 11, 16}, {902, 407, 21, 11}, {333, 580, 28, 16}, {794, 106, 15, 18}, {441, 602, 11, 28}, {412, 369, 26, 15}, {441, 293, 24, 27}, {235, 469, 24, 25}, {72, 113, 19, 16}, {425, 242, 11, 25}, {14, 908, 12, 23}, {969, 150, 17, 19}, {847, 861, 26, 23}, {915, 204, 22, 28}, {559, 647, 15, 27}, {561, 338, 15, 23}, {667, 616, 4, 18}, {267, 351, 22, 12}, {610, 684, 13, 10}, {885, 970, 21, 12}, {165, 838, 20, 10}, {70, 650, 26, 24}, {965, 143, 19, 23}, {422, 427, 13, 10}, {200, 556, 10, 21}, {903, 14, 25, 12}, {193, 913, 23, 24}, {649, 713, 25, 29}, {103, 841, 13, 22}, {573, 486, 10, 16}, {465, 383, 27, 11}, {629, 548, 17, 22}, {969, 580, 29, 25}, {198, 223, 29, 17}, {604, 157, 27, 23}, {452, 381, 29, 23}, {117, 14, 11, 12}, {965, 140, 13, 29}, {337, 198, 22, 24}, {667, 743, 21, 21}, {89, 138, 23, 28}, {455, 903, 18, 21}, {60, 466, 13, 29}, {907, 786, 11, 23}, {933, 455, 12, 18}, {961, 207, 28, 16}, {779, 679, 12, 20}, {323, 151, 5, 13}, {633, 556, 13, 23}, {348, 74, 21, 19}, {886, 684, 12, 12}, {694, 192, 20, 15}, {343, 376, 25, 24}, {373, 0, 10, 27}, {157, 480, 10, 16}, {694, 184, 17, 11}, {206, 222, 24, 17}, {716, 524, 24, 26}, {301, 750, 15, 15}, {426, 13, 19, 14}, {506, 540, 29, 17}, {607, 980, 25, 14}, {782, 219, 14, 29}, {342, 157, 15, 20}, {259, 739, 27, 25}, {698, 744, 16, 10}, {521, 507, 22, 28}, {817, 90, 28, 19}, {796, 268, 11, 11}, {261, 99, 12, 13}, {972, 469, 15, 15}, {833, 445, 18, 17}, {181, 911, 27, 16}, {898, 330, 12, 15}, {265, 179, 14, 29}, {782, 647, 20, 18}, {189, 122, 18, 16}, {142, 533, 25, 29}, {734, 313, 21, 27}, {776, 66, 24, 12}, {860, 853, 10, 23}, {669, 699, 15, 27}, {971, 161, 20, 12}, {509, 169, 29, 29}, {786, 82, 27, 15}, {906, 716, 24, 16}, {19, 823, 18, 27}, {673, 960, 22, 18}, {927, 264, 22, 13}, {133, 321, 10, 14}, {839, 844, 26, 15}, {334, 586, 18, 25}, {725, 872, 22, 21}, {719, 674, 11, 13}, {134, 846, 26, 23}, {57, 384, 10, 26}, {590, 131, 27, 29}, {756, 271, 14, 19}, {576, 452, 14, 25}, {760, 673, 20, 13}, {444, 350, 26, 10}, {730, 37, 12, 13}, {746, 844, 3, 15}, {767, 538, 19, 10}, {747, 295, 22, 20}, {54, 919, 12, 22}, {257, 215, 28, 25}, {799, 83, 28, 14}, {505, 856, 17, 14}, {570, 679, 23, 24}, {42, 71, 26, 28}, {607, 596, 22, 16}, {24, 805, 16, 21}, {624, 864, 20, 26}, {359, 309, 14, 18}, {788, 636, 16, 27}, {471, 537, 18, 16}, {119, 450, 19, 21}, {807, 130, 20, 25}, {213, 637, 25, 17}, {240, 410, 12, 29}, {929, 359, 18, 16}, {371, 945, 16, 18}, {840, 733, 13, 11}, {273, 75, 28, 26}, {549, 445, 27, 10}, {602, 103, 18, 20}, {298, 971, 29, 25}, {890, 244, 12, 25}, {525, 16, 12, 14}, {238, 528, 16, 19}, {136, 632, 16, 17}, {568, 165, 11, 12}, {210, 901, 24, 27}, {900, 327, 17, 23}, {517, 659, 12, 19}, {588, 103, 23, 26}, {459, 508, 23, 28}, {675, 132, 15, 10}, {629, 377, 11, 23}, {349, 25, 15, 23}, {214, 627, 14, 19}, {211, 631, 24, 25}, {662, 248, 13, 10}, {939, 439, 20, 10}, {271, 90, 20, 25}, {257, 872, 19, 16}, {330, 355, 23, 14}, {95, 684, 25, 28}, {907, 786, 21, 17}, {272, 98, 7, 10}, {286, 525, 20, 27}, {66, 229, 13, 15}, {449, 85, 25, 26}, {522, 982, 16, 17}, {119, 294, 25, 18}, {183, 132, 15, 26}, {203, 419, 21, 11}, {505, 681, 12, 28}, {89, 716, 28, 22}, {281, 62, 25, 21}, {717, 686, 19, 22}, {610, 143, 11, 29}, {833, 920, 11, 27}, {647, 132, 16, 15}, {503, 272, 14, 21}, {917, 221, 15, 27}, {666, 698, 24, 25}, {908, 710, 18, 16}, {914, 562, 25, 24}, {136, 538, 14, 22}, {53, 872, 21, 22}, {140, 644, 28, 23}, {681, 24, 24, 29}, {727, 67, 13, 19}, {600, 166, 12, 16}, {118, 329, 19, 23}, {632, 897, 10, 28}, {533, 258, 14, 27}, {371, 22, 24, 16}, {322, 395, 13, 22}, {661, 464, 25, 14}, {52, 561, 17, 24}, {83, 197, 10, 15}, {682, 804, 22, 12}, {366, 555, 22, 27}, {169, 675, 13, 24}, {89, 186, 23, 21}, {500, 308, 13, 20}, {149, 961, 28, 21}, {238, 672, 15, 27}, {458, 432, 25, 15}, {666, 843, 12, 25}, {600, 411, 16, 18}, {570, 440, 26, 28}, {13, 44, 18, 27}, {628, 35, 13, 20}, {423, 725, 24, 13}, {445, 147, 15, 24}, {650, 295, 17, 17}, {941, 862, 22, 26}, {313, 778, 10, 18}, {488, 212, 23, 20}, {773, 679, 16, 28}, {964, 259, 10, 19}, {54, 282, 21, 16}, {24, 810, 28, 26}, {135, 511, 10, 15}, {362, 618, 5, 21}, {673, 630, 17, 17}, {461, 852, 20, 11}, {353, 86, 13, 10}, {128, 838, 17, 16}, {900, 621, 28, 23}, {298, 485, 20, 15}, {821, 341, 24, 28}, {135, 21, 14, 25}, {555, 328, 29, 16}, {260, 550, 28, 21}, {253, 858, 15, 22}, {652, 421, 11, 19}, {708, 258, 18, 10}, {744, 640, 21, 20}, {756, 723, 21, 21}, {579, 446, 13, 15}, {467, 390, 18, 28}, {15, 420, 29, 19}, {657, 874, 28, 27}, {641, 967, 16, 23}, {747, 683, 17, 12}, {557, 586, 10, 26}, {315, 235, 29, 19}, {954, 164, 22, 23}, {83, 196, 10, 25}, {371, 316, 11, 24}, {437, 914, 25, 27}, {443, 844, 12, 16}, {36, 388, 16, 29}, {332, 328, 18, 12}, {363, 532, 11, 16}, {217, 198, 17, 29}, {721, 712, 25, 17}, {507, 847, 20, 14}, {873, 28, 11, 21}, {280, 344, 20, 5}, {846, 28, 18, 18}, {144, 627, 12, 26}, {273, 349, 15, 25}, {387, 230, 21, 24}, {963, 641, 26, 26}, {908, 235, 24, 11}, {420, 386, 28, 19}, {570, 637, 21, 29}, {19, 923, 14, 27}, {758, 357, 27, 16}, {232, 465, 11, 18}, {99, 542, 16, 28}, {334, 327, 11, 19}, {349, 147, 10, 25}, {672, 893, 12, 26}, {347, 544, 26, 27}, {944, 295, 18, 24}, {967, 825, 13, 10}, {185, 36, 17, 16}, {407, 7, 25, 18}, {610, 911, 21, 23}, {419, 664, 16, 16}, {773, 254, 13, 24}, {572, 828, 25, 20}, {107, 716, 20, 20}, {702, 408, 13, 10}, {321, 149, 11, 19}, {663, 601, 11, 29}, {206, 923, 19, 17}, {618, 873, 15, 13}, {108, 900, 16, 21}, {162, 620, 16, 29}, {908, 814, 18, 28}, {30, 666, 10, 15}, {703, 619, 20, 12}, {291, 823, 25, 25}, {748, 402, 28, 10}, {283, 486, 16, 18}, {908, 182, 16, 16}, {553, 754, 19, 24}, {627, 500, 13, 16}, {452, 314, 25, 25}, {404, 625, 17, 28}, {320, 68, 28, 26}, {742, 862, 13, 19}, {698, 249, 25, 16}, {681, 736, 16, 12}, {604, 806, 18, 15}, {123, 905, 27, 19}, {189, 606, 17, 26}, {10, 616, 27, 16}, {160, 12, 19, 18}, {242, 314, 18, 29}, {508, 440, 25, 10}, {283, 305, 9, 4}, {314, 249, 27, 22}, {588, 792, 17, 23}, {310, 616, 26, 12}, {355, 105, 16, 23}, {926, 217, 14, 16}, {907, 167, 16, 10}, {280, 783, 17, 17}, {247, 915, 19, 25}, {526, 248, 21, 14}, {660, 437, 23, 19}, {577, 193, 26, 25}, {786, 805, 28, 16}, {431, 155, 24, 15}, {105, 443, 9, 5}, {746, 654, 23, 29}, {147, 78, 21, 19}, {663, 804, 22, 15}, {99, 441, 19, 10}, {582, 284, 25, 28}, {577, 640, 7, 20}, {865, 388, 11, 23}, {149, 336, 20, 11}, {523, 552, 12, 12}, {726, 752, 12, 28}, {463, 460, 11, 13}, {364, 960, 13, 29}, {101, 149, 17, 11}, {244, 9, 19, 22}, {106, 868, 26, 29}, {722, 844, 16, 18}, {162, 964, 24, 21}, {308, 451, 18, 25}, {275, 633, 27, 10}, {439, 702, 24, 18}, {173, 791, 19, 29}, {95, 343, 12, 19}, {768, 812, 27, 23}, {827, 331, 17, 22}, {623, 188, 26, 11}, {19, 949, 19, 23}, {663, 684, 26, 10}, {153, 88, 24, 20}, {778, 828, 26, 24}, {443, 652, 21, 15}, {720, 770, 15, 6}, {275, 549, 22, 23}, {483, 103, 27, 16}, {670, 462, 13, 11}, {146, 873, 26, 27}, {540, 111, 18, 17}, {151, 629, 25, 11}, {417, 254, 22, 29}, {809, 808, 13, 13}, {673, 797, 13, 23}, {354, 71, 17, 12}, {55, 877, 11, 21}, {807, 887, 14, 14}, {729, 26, 19, 27}, {483, 521, 28, 22}, {715, 518, 14, 14}, {807, 96, 12, 14}, {95, 914, 28, 27}, {228, 326, 26, 27}, {945, 714, 25, 28}, {535, 974, 11, 16}, {490, 288, 23, 26}, {266, 906, 11, 19}, {363, 254, 25, 13}, {469, 382, 23, 14}, {697, 802, 27, 18}, {458, 779, 27, 27}, {505, 80, 25, 13}, {877, 25, 22, 11}, {295, 834, 11, 12}, {830, 336, 16, 14}, {527, 73, 20, 16}, {661, 201, 24, 19}, {129, 450, 25, 13}, {632, 188, 14, 12}, {952, 443, 18, 24}, {927, 204, 13, 29}, {420, 386, 27, 12}, {369, 103, 25, 26}, {417, 77, 14, 10}, {552, 84, 19, 29}, {488, 951, 28, 14}, {579, 476, 20, 11}, {423, 237, 11, 21}, {648, 901, 28, 24}, {795, 888, 20, 13}, {593, 13, 6, 4}, {886, 99, 18, 16}, {522, 517, 28, 29}, {767, 477, 11, 21}, {271, 239, 21, 14}, {30, 842, 24, 21}, {924, 242, 13, 7}, {876, 28, 22, 23}, {508, 860, 22, 27}, {183, 552, 20, 20}, {590, 4, 13, 17}, {760, 897, 19, 19}, {779, 106, 28, 16}, {245, 12, 15, 25}, {938, 462, 26, 17}, {513, 7, 18, 16}, {195, 337, 13, 28}, {228, 799, 28, 11}, {552, 554, 13, 12}, {390, 85, 26, 12}, {415, 247, 15, 14}, {173, 810, 21, 11}, {970, 829, 12, 11}, {240, 430, 11, 21}, {195, 583, 20, 18}, {535, 409, 15, 11}, {240, 195, 28, 14}, {36, 855, 23, 17}, {424, 375, 19, 15}, {428, 884, 29, 16}, {19, 186, 23, 27}, {490, 212, 24, 11}, {662, 628, 14, 18}, {27, 602, 13, 24}, {911, 52, 26, 15}, {448, 638, 23, 20}, {69, 384, 29, 21}, {349, 575, 20, 23}, {665, 538, 28, 22}, {100, 906, 29, 18}, {118, 742, 16, 13}, {299, 731, 23, 29}, {29, 817, 14, 12}, {770, 109, 23, 10}, {924, 225, 15, 13}, {979, 590, 14, 24}, {616, 275, 23, 15}, {393, 961, 13, 10}, {35, 809, 19, 13}, {121, 832, 11, 18}, {100, 916, 27, 11}, {649, 866, 23, 11}, {778, 224, 20, 26}, {55, 638, 24, 16}, {110, 600, 11, 18}, {289, 654, 25, 12}, {45, 665, 28, 15}, {466, 351, 19, 26}, {722, 123, 14, 13}, {508, 848, 25, 18}, {802, 80, 15, 24}, {478, 118, 26, 23}, {147, 432, 28, 22}, {920, 383, 29, 27}, {414, 788, 28, 12}, {190, 588, 15, 11}, {117, 674, 23, 22}, {203, 953, 18, 19}, {0, 605, 18, 29}, {711, 347, 29, 18}, {117, 214, 12, 22}, {547, 112, 22, 17}, {243, 154, 14, 22}, {628, 943, 10, 17}, {555, 738, 21, 23}, {276, 504, 27, 17}, {396, 352, 23, 29}, {454, 145, 17, 27}, {738, 718, 22, 16}, {903, 21, 14, 10}, {400, 768, 17, 26}, {712, 92, 10, 11}, {784, 698, 14, 29}, {586, 654, 18, 18}, {512, 595, 27, 25}, {573, 439, 15, 24}, {457, 488, 18, 23}, {628, 708, 17, 23}, {246, 707, 20, 13}, {555, 85, 28, 19}, {812, 344, 11, 4}, {825, 437, 15, 29}, {131, 283, 18, 22}, {496, 287, 27, 18}, {385, 397, 14, 16}, {776, 944, 12, 15}, {618, 895, 12, 26}, {289, 518, 26, 24}, {944, 252, 24, 26}, {182, 102, 17, 10}, {729, 540, 26, 12}, {262, 899, 25, 15}, {330, 366, 17, 22}, {471, 908, 24, 19}, {401, 229, 13, 19}, {864, 145, 26, 14}, {357, 976, 24, 22}, {698, 357, 22, 21}, {893, 659, 29, 10}, {111, 320, 11, 23}, {956, 256, 16, 19}, {620, 269, 15, 10}, {217, 409, 16, 11}, {29, 693, 23, 20}, {297, 925, 28, 19}, {257, 327, 26, 25}, {942, 495, 14, 29}, {683, 761, 21, 19}, {525, 547, 22, 21}, {93, 254, 27, 11}, {150, 815, 26, 22}, {193, 817, 23, 20}, {116, 310, 27, 22}, {60, 611, 12, 26}, {255, 901, 14, 18}, {263, 664, 10, 12}, {831, 802, 28, 15}, {810, 407, 25, 14}, {177, 157, 14, 28}, {928, 646, 27, 10}, {193, 228, 20, 25}, {289, 601, 28, 27}, {785, 638, 27, 24}, {788, 206, 22, 10}, {3, 92, 24, 28}, {935, 755, 29, 11}, {446, 464, 22, 21}, {114, 812, 28, 29}, {309, 453, 24, 14}, {572, 365, 14, 22}, {930, 882, 29, 21}, {752, 121, 29, 23}, {164, 686, 13, 26}, {244, 565, 17, 18}, {691, 860, 17, 20}, {628, 198, 13, 4}, {203, 819, 11, 13}, {600, 425, 14, 13}, {611, 605, 20, 11}, {902, 93, 24, 17}, {347, 249, 18, 19}, {333, 956, 29, 15}, {106, 0, 29, 16}, {676, 137, 19, 24}, {545, 355, 28, 15}, {234, 620, 25, 28}, {884, 413, 10, 3}, {854, 407, 27, 20}, {113, 853, 12, 25}, {857, 130, 19, 16}, {460, 154, 25, 28}, {732, 125, 16, 18}, {840, 539, 24, 17}, {124, 405, 11, 12}, {618, 691, 15, 16}, {330, 563, 29, 24}, {511, 859, 23, 12}, {911, 781, 21, 17}, {527, 69, 10, 29}, {825, 578, 21, 12}, {965, 175, 22, 25}, {230, 188, 17, 24}, {462, 880, 27, 15}, {75, 128, 21, 16}, {350, 582, 21, 18}, {377, 72, 28, 22}, {882, 836, 17, 19}, {25, 419, 17, 26}, {987, 886, 12, 23}, {918, 415, 16, 18}, {793, 344, 29, 25}, {380, 609, 12, 10}, {241, 428, 29, 18}, {363, 15, 11, 20}, {438, 552, 21, 10}, {582, 144, 21, 19}, {192, 815, 19, 13}, {750, 625, 18, 22}, {326, 980, 25, 13}, {613, 480, 20, 14}, {913, 722, 16, 12}, {405, 254, 23, 20}, {423, 380, 10, 27}, {641, 578, 16, 15}, {639, 967, 29, 17}, {903, 184, 10, 22}, {569, 258, 13, 25}, {839, 319, 10, 29}, {67, 63, 22, 12}, {987, 905, 12, 21}, {619, 196, 26, 13}, {290, 637, 10, 24}, {197, 905, 14, 28}, {705, 615, 13, 26}, {677, 527, 16, 18}, {605, 204, 21, 25}, {615, 210, 11, 24}, {582, 436, 13, 24}, {314, 50, 20, 22}, {207, 118, 29, 26}, {764, 638, 27, 11}, {320, 336, 26, 24}, {911, 633, 28, 14}, {385, 556, 27, 24}, {447, 884, 12, 14}, {700, 74, 26, 28}, {13, 552, 23, 28}, {236, 580, 11, 23}, {122, 14, 28, 14}, {289, 468, 16, 13}, {170, 28, 23, 18}, {924, 721, 12, 13}, {40, 740, 20, 27}, {424, 283, 18, 28}, {584, 102, 27, 11}, {511, 485, 16, 25}, {569, 98, 28, 18}, {480, 948, 20, 12}, {412, 392, 11, 17}, {751, 914, 24, 10}, {21, 959, 13, 11}, {266, 49, 13, 23}, {890, 625, 10, 22}, {973, 186, 14, 15}, {21, 594, 15, 24}, {115, 839, 5, 6}, {449, 552, 12, 29}, {475, 747, 23, 29}, {567, 559, 28, 20}, {836, 529, 25, 27}, {280, 302, 29, 11}, {400, 637, 26, 22}, {389, 336, 20, 29}, {93, 745, 26, 27}, {70, 821, 11, 29}, {36, 794, 10, 24}, {623, 189, 20, 17}, {720, 620, 16, 29}, {695, 798, 25, 12}, {120, 381, 28, 10}, {667, 840, 29, 13}, {13, 31, 15, 22}, {667, 621, 14, 22}, {819, 580, 18, 19}, {165, 434, 25, 28}, {387, 831, 25, 26}, {267, 189, 11, 19}, {515, 161, 25, 24}, {497, 941, 13, 28}, {810, 352, 14, 21}, {29, 864, 17, 15}, {339, 318, 14, 24}, {969, 649, 16, 4}, {429, 788, 11, 29}, {346, 69, 18, 29}, {930, 705, 28, 24}, {705, 770, 26, 23}, {721, 599, 10, 15}, {467, 212, 28, 12}, {444, 85, 15, 24}, {614, 146, 3, 19}, {190, 448, 16, 12}, {5, 99, 13, 7}, {23, 668, 10, 25}, {725, 265, 10, 18}, {667, 321, 27, 12}, {0, 774, 28, 26}, {812, 15, 14, 26}, {947, 480, 15, 17}, {599, 676, 21, 22}, {181, 19, 10, 20}, {955, 162, 20, 17}, {515, 865, 20, 13}, {13, 812, 26, 28}, {553, 841, 27, 28}, {80, 62, 21, 11}, {189, 430, 22, 25}, {605, 191, 19, 12}, {65, 31, 26, 16}, {8, 410, 27, 16}, {860, 845, 27, 16}, {358, 968, 17, 15}, {448, 867, 17, 11}, {862, 678, 24, 20}, {272, 665, 20, 14}, {427, 95, 22, 11}, {703, 285, 14, 14}, {756, 124, 23, 24}, {396, 69, 27, 18}, {619, 483, 14, 23}, {671, 35, 21, 23}, {234, 717, 24, 16}, {269, 97, 24, 16}, {677, 882, 23, 27}, {852, 343, 16, 25}, {99, 902, 29, 10}, {345, 542, 28, 23}, {572, 256, 11, 26}, {576, 421, 21, 28}, {893, 727, 21, 10}, {47, 381, 15, 12}, {887, 955, 12, 16}, {637, 498, 22, 21}, {303, 530, 21, 11}, {727, 855, 25, 14}, {21, 148, 12, 16}, {537, 391, 18, 25}, {498, 670, 16, 12}, {944, 715, 20, 15}, {944, 696, 24, 26}, {907, 202, 15, 10}, {87, 68, 22, 13}, {842, 789, 25, 17}, {187, 187, 21, 18}, {679, 540, 28, 12}, {877, 681, 24, 11}, {933, 43, 15, 18}, {979, 217, 20, 24}, {596, 219, 23, 21}, {892, 403, 29, 15}, {411, 383, 10, 21}, {368, 263, 11, 19}, {65, 407, 12, 23}, {592, 666, 27, 16}, {253, 77, 29, 22}, {133, 667, 14, 20}, {439, 683, 11, 24}, {786, 881, 11, 18}, {544, 114, 19, 19}, {88, 355, 24, 10}, {148, 277, 14, 23}, {83, 553, 10, 22}, {534, 922, 27, 20}, {508, 22, 27, 17}, {700, 398, 12, 28}, {42, 288, 16, 16}, {111, 303, 15, 19}, {615, 652, 14, 28}, {243, 650, 14, 26}, {142, 551, 12, 29}, {989, 909, 4, 6}, {831, 331, 13, 17}, {53, 731, 26, 27}, {824, 453, 14, 17}, {253, 110, 10, 27}, {226, 913, 15, 23}, {745, 790, 13, 20}, {310, 928, 25, 20}, {307, 354, 10, 14}, {466, 734, 19, 23}, {159, 966, 21, 26}, {898, 55, 23, 10}, {744, 392, 11, 24}, {950, 95, 18, 15}, {886, 824, 29, 29}, {137, 689, 19, 23}, {326, 390, 12, 20}, {39, 424, 27, 15}, {606, 682, 13, 16}, {427, 244, 29, 21}, {214, 931, 13, 16}, {493, 442, 26, 13}, {718, 768, 21, 11}, {186, 199, 21, 24}, {88, 560, 29, 13}, {89, 188, 13, 23}, {801, 909, 23, 11}, {644, 975, 28, 16}, {163, 423, 15, 27}, {929, 640, 13, 16}, {135, 338, 18, 10}, {822, 573, 12, 23}, {800, 364, 19, 17}, {82, 108, 25, 25}, {795, 916, 24, 23}, {255, 548, 12, 13}, {124, 835, 25, 16}, {624, 953, 20, 22}, {47, 837, 13, 25}, {922, 239, 18, 18}, {346, 44, 10, 14}, {445, 169, 21, 19}, {833, 568, 23, 23}, {660, 608, 17, 21}, {105, 554, 15, 16}, {801, 16, 27, 26}, {750, 763, 21, 25}, {677, 280, 26, 26}, {169, 439, 29, 23}, {380, 595, 19, 28}, {808, 340, 20, 22}, {268, 556, 16, 17}, {626, 771, 23, 27}, {111, 619, 17, 13}, {578, 678, 11, 24}, {611, 387, 16, 14}, {359, 615, 14, 29}, {911, 357, 28, 21}, {958, 761, 12, 11}, {956, 302, 19, 12}, {908, 146, 20, 26}, {588, 358, 18, 17}, {645, 234, 21, 18}, {561, 432, 12, 25}, {278, 342, 26, 10}, {360, 940, 19, 12}, {495, 293, 16, 14}, {714, 728, 21, 24}, {68, 651, 21, 25}, {290, 743, 26, 18}, {355, 874, 11, 25}, {491, 754, 16, 24}, {278, 596, 19, 12}, {782, 157, 20, 16}, {118, 468, 12, 23}, {279, 783, 10, 29}, {929, 858, 25, 19}, {626, 971, 21, 13}, {713, 663, 11, 28}, {940, 493, 25, 25}, {458, 869, 11, 12}, {730, 318, 28, 20}, {957, 904, 29, 28}, {522, 693, 28, 27}, {606, 558, 14, 20}, {43, 788, 12, 21}, {554, 541, 28, 27}, {259, 118, 11, 26}, {491, 757, 15, 10}, {429, 360, 19, 13}, {560, 721, 18, 26}, {881, 31, 11, 15}, {110, 339, 24, 29}, {359, 205, 25, 25}, {926, 35, 22, 24}, {892, 550, 24, 20}, {657, 242, 25, 21}, {413, 255, 22, 21}, {673, 706, 12, 16}, {431, 306, 13, 27}, {105, 570, 18, 11}, {912, 168, 12, 27}, {157, 911, 23, 23}, {647, 398, 14, 29}, {676, 515, 14, 28}, {879, 778, 24, 13}, {129, 524, 24, 29}, {239, 560, 16, 22}, {894, 407, 10, 18}, {539, 892, 26, 19}, {46, 930, 22, 23}, {893, 152, 16, 17}, {279, 191, 21, 10}, {764, 368, 26, 11}, {138, 81, 25, 22}, {672, 207, 19, 18}, {21, 471, 26, 13}, {863, 784, 19, 25}, {754, 800, 15, 19}, {170, 292, 15, 27}, {472, 45, 10, 16}, {160, 570, 26, 17}, {3, 567, 22, 28}, {378, 134, 21, 13}, {724, 612, 10, 15}, {21, 193, 20, 19}, {861, 849, 14, 12}, {507, 666, 18, 10}, {920, 169, 21, 16}, {851, 217, 12, 27}, {356, 888, 26, 27}, {264, 513, 15, 12}, {975, 903, 10, 14}, {665, 838, 15, 25}, {582, 732, 29, 11}, {246, 413, 20, 25}, {862, 447, 17, 22}, {795, 939, 18, 18}, {317, 650, 15, 12}, {821, 123, 13, 10}, {448, 890, 20, 15}, {202, 20, 13, 18}, {706, 561, 15, 11}, {891, 480, 16, 21}, {82, 540, 24, 18}, {845, 32, 11, 13}, {184, 198, 12, 14}, {98, 141, 16, 11}, {282, 331, 20, 28}, {760, 273, 3, 7}, {776, 848, 14, 15}, {443, 285, 20, 23}, {518, 405, 29, 22}, {22, 139, 27, 14}, {260, 558, 29, 11}, {924, 369, 16, 16}, {517, 383, 13, 12}, {461, 443, 14, 18}, {526, 19, 17, 10}, {760, 904, 17, 22}, {702, 241, 20, 19}, {763, 250, 22, 28}, {408, 86, 12, 19}, {714, 493, 17, 26}, {61, 60, 22, 27}, {878, 479, 18, 14}, {422, 602, 22, 22}, {307, 527, 27, 12}, {100, 725, 29, 17}, {241, 207, 17, 12}, {156, 826, 22, 22}, {210, 22, 27, 28}, {760, 280, 28, 25}, {112, 833, 13, 19}, {770, 622, 21, 11}, {229, 881, 24, 10}, {16, 808, 20, 19}, {183, 583, 14, 28}, {181, 106, 17, 25}, {580, 65, 26, 22}, {428, 915, 27, 13}, {300, 534, 26, 14}, {810, 899, 23, 11}, {672, 627, 20, 10}, {153, 52, 11, 28}, {610, 10, 23, 10}, {379, 192, 26, 22}, {161, 743, 14, 21}, {250, 98, 23, 20}, {46, 487, 19, 18}, {628, 180, 17, 16}, {54, 761, 24, 14}, {412, 600, 21, 13}, {17, 910, 11, 23}, {841, 649, 21, 22}, {110, 310, 16, 27}, {833, 528, 15, 11}, {98, 862, 27, 12}, {88, 838, 28, 19}, {272, 464, 29, 25}, {917, 666, 29, 20}, {222, 127, 10, 27}, {449, 466, 23, 16}, {258, 331, 13, 23}, {476, 491, 18, 11}, {390, 75, 15, 29}, {217, 863, 17, 24}, {334, 227, 18, 29}, {437, 723, 11, 15}, {662, 846, 18, 12}, {384, 394, 24, 27}, {675, 965, 16, 6}, {700, 687, 16, 29}, {443, 859, 22, 27}, {245, 327, 19, 24}, {676, 807, 28, 27}, {846, 224, 14, 21}, {58, 744, 14, 19}, {680, 543, 23, 20}, {790, 267, 16, 14}, {447, 217, 27, 26}, {140, 961, 29, 18}, {53, 373, 24, 12}, {549, 222, 17, 12}, {839, 926, 22, 14}, {21, 690, 22, 19}, {377, 157, 16, 13}, {664, 637, 21, 10}, {355, 965, 20, 12}, {949, 474, 14, 26}, {161, 850, 17, 25}, {104, 408, 21, 20}, {526, 553, 20, 19}, {126, 527, 18, 24}, {308, 346, 28, 21}, {808, 406, 11, 25}, {516, 80, 14, 29}, {767, 40, 16, 28}, {2, 828, 10, 27}, {317, 655, 27, 10}, {877, 287, 15, 16}, {133, 443, 28, 24}, {141, 758, 28, 28}, {1, 105, 16, 18}, {100, 915, 14, 17}, {544, 666, 26, 14}, {167, 75, 22, 17}, {322, 922, 19, 19}, {725, 844, 13, 29}, {610, 217, 18, 16}, {397, 97, 17, 15}, {68, 52, 21, 24}, {565, 338, 12, 10}, {672, 951, 11, 24}, {561, 448, 13, 16}, {785, 858, 14, 23}, {650, 828, 15, 21}, {442, 693, 16, 15}, {612, 673, 13, 19}, {330, 215, 28, 18}, {841, 732, 23, 23}, {200, 433, 11, 12}, {507, 277, 23, 27}, {259, 917, 20, 11}, {150, 12, 11, 26}, {112, 628, 26, 17}, {263, 894, 25, 13}, {332, 251, 29, 16}, {134, 546, 22, 11}, {808, 338, 23, 17}, {610, 8, 25, 23}, {547, 908, 22, 17}, {731, 243, 28, 25}, {558, 550, 21, 25}, {833, 443, 15, 28}, {290, 823, 14, 28}, {886, 724, 12, 29}, {219, 214, 13, 14}, {397, 845, 21, 18}, {153, 639, 10, 23}, {396, 833, 13, 20}, {773, 136, 17, 16}, {523, 89, 11, 23}, {48, 692, 12, 24}, {942, 871, 20, 18}, {74, 296, 24, 28}, {10, 859, 23, 16}, {155, 478, 17, 24}, {151, 954, 18, 19}, {846, 525, 25, 28}, {277, 194, 13, 10}, {458, 935, 25, 15}, {263, 235, 23, 28}, {262, 48, 19, 21}, {499, 388, 22, 29}, {760, 776, 11, 27}, {196, 628, 19, 28}, {126, 200, 10, 11}, {632, 890, 14, 25}, {868, 275, 14, 26}, {90, 540, 20, 28}, {117, 526, 12, 16}, {276, 652, 17, 14}, {828, 206, 16, 24}, {705, 283, 12, 28}, {478, 770, 13, 23}, {838, 393, 29, 20}, {911, 791, 16, 15}, {304, 388, 12, 20}, {560, 808, 25, 24}, {213, 669, 28, 14}, {130, 842, 7, 5}, {938, 447, 15, 11}, {116, 864, 10, 12}, {234, 33, 24, 14}, {392, 850, 10, 10}, {952, 153, 21, 26}, {884, 318, 28, 13}, {413, 418, 14, 20}, {203, 908, 12, 22}, {265, 108, 19, 25}, {737, 842, 25, 21}, {380, 103, 29, 15}, {821, 323, 16, 14}, {393, 91, 4, 6}, {262, 892, 19, 17}, {355, 700, 14, 17}, {561, 755, 17, 13}, {455, 132, 28, 27}, {627, 580, 20, 20}, {363, 333, 21, 13}, {55, 812, 12, 28}, {622, 43, 22, 10}, {665, 951, 11, 14}, {468, 444, 13, 23}, {113, 796, 17, 22}, {562, 739, 18, 18}, {150, 898, 13, 14}, {822, 219, 26, 17}, {476, 851, 16, 17}, {499, 589, 23, 18}, {639, 847, 25, 22}, {543, 925, 20, 24}, {629, 203, 29, 12}, {567, 727, 23, 27}, {96, 264, 28, 24}, {618, 379, 12, 28}, {945, 429, 11, 21}, {677, 305, 24, 27}, {285, 383, 22, 10}, {949, 515, 16, 21}, {465, 20, 27, 27}, {560, 596, 13, 14}, {882, 411, 17, 10}, {659, 471, 16, 10}, {563, 866, 25, 26}, {384, 634, 20, 21}, {959, 472, 22, 10}, {757, 684, 18, 19}, {894, 247, 14, 11}, {804, 268, 29, 26}, {100, 575, 26, 16}, {741, 680, 16, 18}, {86, 343, 26, 18}, {749, 804, 24, 14}, {420, 671, 16, 26}, {661, 455, 12, 18}, {518, 394, 27, 21}, {210, 437, 16, 17}, {554, 147, 23, 23}, {622, 945, 15, 13}, {195, 325, 26, 22}, {456, 536, 22, 25}, {645, 678, 23, 10}, {367, 610, 18, 29}, {44, 35, 27, 25}, {362, 574, 27, 20}, {301, 262, 25, 17}, {278, 735, 15, 28}, {214, 19, 29, 28}, {100, 152, 27, 19}, {549, 691, 16, 11}, {413, 80, 12, 10}, {644, 129, 19, 15}, {708, 243, 25, 14}, {235, 575, 14, 15}, {26, 767, 15, 16}, {3, 97, 18, 20}, {256, 655, 24, 23}, {778, 535, 28, 23}, {773, 146, 27, 14}, {67, 287, 21, 11}, {796, 207, 24, 11}, {687, 875, 10, 19}, {593, 374, 21, 20}, {923, 620, 29, 18}, {130, 778, 23, 26}, {165, 769, 29, 26}, {262, 916, 25, 26}, {434, 530, 26, 11}, {48, 827, 10, 19}, {446, 192, 13, 28}, {292, 532, 21, 20}, {465, 308, 13, 23}, {30, 290, 21, 28}, {347, 164, 23, 19}, {3, 691, 24, 15}, {567, 201, 18, 26}, {729, 594, 27, 17}, {578, 51, 13, 26}, {652, 239, 18, 23}, {349, 259, 14, 29}, {7, 605, 23, 19}, {249, 755, 29, 21}, {836, 656, 29, 19}, {183, 838, 10, 12}, {285, 820, 22, 24}, {646, 280, 24, 16}, {176, 186, 24, 18}, {941, 165, 27, 15}, {617, 566, 23, 12}, {302, 795, 13, 17}, {729, 56, 12, 14}, {176, 422, 25, 22}, {603, 554, 25, 28}, {524, 81, 10, 13}, {840, 667, 23, 18}, {781, 949, 28, 24}, {132, 378, 12, 17}, {212, 954, 12, 12}, {760, 599, 13, 29}, {872, 461, 11, 29}, {690, 546, 21, 29}, {382, 28, 22, 15}, {703, 776, 12, 10}, {545, 317, 21, 26}, {148, 699, 27, 18} };
	std::vector<std::vector<int>> v(1000);

	for (auto& e : v)
		e.resize(1000);

	for (auto i = 0; i < 1000; ++i)
		for (auto j = 0; j < 1000; ++j)
			v[i][j];

	for (auto& d : data)
	{
		for (auto y = d.y; y != d.y+ d.height; ++y)
		{
			for (auto x = d.x; x != d.x + d.width; ++x)
			{
				++v[y][x];
			}
		}
	}

	int the_sum = 0;
	for (auto i = 0; i < 1000; ++i)
		for (auto j = 0; j < 1000; ++j)
			if (v[i][j] > 1)
				the_sum += 1;
	std::cout << "part one asnwer: " << the_sum;

	for (auto i = 0; i < data.size(); ++i)
	{
		bool flag = true;
		for (auto y = data[i].y; (y != data[i].y + data[i].height) && flag; ++y)
		{
			for (auto x = data[i].x; x != data[i].x + data[i].width; ++x)
			{
				if (v[y][x] != 1)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{
			std::cout << "match... ? " << i << std::endl;
			break;
		}
	}
	return 0;
}