#include "gtest/gtest.h"
#include "tests_aux.h"

char args[300];

class valgrind_sf_TestSuite : public testing::Test { 
	void SetUp() override {
        system("rm -rf ./tests/actual_outputs");
		mkdir("./tests/actual_outputs/", 0700);
	}
};

TEST_F(valgrind_sf_TestSuite, load_ppm_save_ppm) {
    const char *input_file = "./tests/images/seawolf.ppm";
    const char *actual_output_file = "./tests/actual_outputs/result.ppm";
    sprintf(args, "-i %s -o %s", input_file, actual_output_file);
	expect_no_valgrind_errors(run_using_valgrind(args));	
}

TEST_F(valgrind_sf_TestSuite, load_sbu_save_ppm) {
    const char *input_file = "./tests/images/desert.sbu";
    const char *actual_output_file = "./tests/actual_outputs/result.ppm";
    sprintf(args, "-o %s -i %s", actual_output_file, input_file);
	expect_no_valgrind_errors(run_using_valgrind(args));	
}

TEST_F(valgrind_sf_TestSuite, copy_paste_cactus_sbu) {
    const char *input_file = "./tests/images/desert.sbu";
    const char *actual_output_file = "./tests/actual_outputs/result.ppm";
    sprintf(args, "-i %s -p 90,60 -c 90,10,50,100 -o %s", input_file, actual_output_file);
    expect_no_valgrind_errors(run_using_valgrind(args));	
}

TEST_F(valgrind_sf_TestSuite, copy_paste_stony2_1) {
    const char *input_file = "./tests/images/stony.ppm";
    const char *actual_output_file = "./tests/actual_outputs/result.ppm";
    sprintf(args, "-o %s -c 170,100,90,180 -p 0,0 -i %s", actual_output_file, input_file);
    expect_no_valgrind_errors(run_using_valgrind(args));
}

TEST_F(valgrind_sf_TestSuite, overflow_corner) {
    const char *input_file = "./tests/images/seawolf.ppm";
    const char *actual_output_file = "./tests/actual_outputs/result.ppm";
    sprintf(args, "-o %s -c 36,60,50,50 -p 50,80 -i %s", actual_output_file, input_file);
    expect_no_valgrind_errors(run_using_valgrind(args));
}

TEST_F(valgrind_sf_TestSuite, overlapping1) {
    const char *input_file = "./tests/images/stony.ppm";
    const char *actual_output_file = "./tests/actual_outputs/result.ppm";
    sprintf(args, "-i %s -p 22,32 -o %s -c 20,30,120,140", input_file, actual_output_file);
    expect_no_valgrind_errors(run_using_valgrind(args));
}

TEST_F(valgrind_sf_TestSuite, print_short_message1_2) {
    const char *input_file = "./tests/images/desert.sbu";
    const char *actual_output_file = "./tests/actual_outputs/result.ppm";
    sprintf(args, "-i %s -r \"seawolves\",\"./tests/fonts/font1.txt\",1,100,150 -o %s", input_file, actual_output_file);
    expect_no_valgrind_errors(run_using_valgrind(args));
}

TEST_F(valgrind_sf_TestSuite, print_overflow_message1_2) {
    const char *input_file = "./tests/images/desert.sbu";
    const char *actual_output_file = "./tests/actual_outputs/result.ppm";
    sprintf(args, "-i %s -o %s -r \"new YORK state\",\"./tests/fonts/font3.txt\",1,10,220", input_file, actual_output_file);
    expect_no_valgrind_errors(run_using_valgrind(args));
}

TEST_F(valgrind_sf_TestSuite, combined1) {
    const char *input_file = "./tests/images/stony.sbu";
    const char *actual_output_file = "./tests/actual_outputs/result.ppm";
    sprintf(args, "-c 125,130,150,40 -p 85,130 -i %s -o %s -r \"Go STONY BROOK\",\"./tests/fonts/font1.txt\",2,50,5", input_file, actual_output_file);
    expect_no_valgrind_errors(run_using_valgrind(args));	
}

TEST_F(valgrind_sf_TestSuite, combined2) {
    const char *input_file = "./tests/images/stony.sbu";
    const char *actual_output_file = "./tests/actual_outputs/result.ppm";
    sprintf(args, "-c 125,130,150,40 -i %s -p 85,130 -o %s -r \"Go STONY BROOK\",\"./tests/fonts/font4.txt\",2,100,10", input_file, actual_output_file);
    expect_no_valgrind_errors(run_using_valgrind(args));	
}