#include "robodash/views/selector.hpp"
#include "blue_solo.hpp"
#include "world_blue_2plus2.hpp"
#include "red_solo.hpp"
#include "world_red_2plus2.hpp"
#include "skills.hpp"
#include "red_rush_mobile.hpp"
#include "red_right_three_rings.hpp"
#include "blue_rush_mobile.hpp"
//#include "red_right_sweep.hpp"
#include "blue_left_sweep.hpp"
#include "red_alliance_ladder.hpp"
#include "blue_five_rings.hpp"
#include "red_five_rings.hpp"
#include "blue_left_solo.hpp"
#include "blue_signature_solo.hpp"
#include "signature_skills.hpp"
#include "blue_left_wp.hpp"
#include "red_right_wp.hpp"
//#include "blue_rush_sweep.hpp"
#include "blue_two_stakes.hpp"
#include "red_six_rings.hpp"
#include "blue_six_rings.hpp"
#include "red_rush_new.hpp"
#include "world_red_negative.hpp"
#include "skills_states.hpp"
#include "world_blue_negative.hpp"
//#include "red_positive.hpp"
//#include "blue_positive.hpp"
#include"red_pos_Alliance.hpp"
#include"blue_pos_Alliance.hpp"
#include"Test.hpp"


rd::Selector selector({
                
                    {"world_red_negative_.hpp", world_red_negative},
                    {"world_blue_negative.hpp", world_blue_negative},
                    {"red_pos_Alliance.hpp", red_pos_Alliance},
                    {"blue_pos_Alliance.hpp", blue_pos_Alliance},
                    {"skills", skills},
                    {"wolrd_red_2plus2.hpp", world_red_2p2},
                    {"world_blue_2plus2.hpp", world_blue_2p2},
                    
                             

});


                      