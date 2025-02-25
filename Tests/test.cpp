#include "pch.h"
#include "Task.h"
#include <iostream>
using namespace std;

char m1[15][15] = {
	"##############",
	"#E#          #",
	"# # ######## #",
	"# # #      # #",
	"# # # #### # #",
	"# # # #  # # #",
	"# # # #P # # #",
	"# # # ## # # #",
	"# # # ## # # #",
	"# # #    # # #",
	"# # ###### # #",
	"# #        # #",
	"# ########## #",
	"#            #",
	"##############",
};

char m2[15][15] = {
	"##############",
	"#E#          #",
	"# # ######## #",
	"# # #      # #",
	"# # # #### # #",
	"# # # #  # # #",
	"# # # #  # # #",
	"# # # ## # # #",
	"# # # ## # # #",
	"# # #    # # #",
	"# # ###### # #",
	"# #        # #",
	"# ########## #",
	"#            #",
	"##############",
};

char m3[15][15] = {
	"##############",
	"#E#          #",
	"# # ######## #",
	"# # #      # #",
	"# # # #### # #",
	"# # # #  # # #",
	"# # # #P # # #",
	"# # # ## # # #",
	"# # # ## # # #",
	"# # #    # # #",
	"# # ###### # #",
	"# #        # #",
	"############ #",
	"#            #",
	"##############",
};

char m4[15][15] = {
	"##############",
	"#            #",
	"#            #",
	"# # #      # #",
	"# # #  ### # #",
	"# # #    # # #",
	"# # #  P # # #",
	"# # #  # # # #",
	"# # #  # # # #",
	"# # #    # # #",
	"# # ###### # #",
	"# #        # #",
	"# ##   E  ## #",
	"#            #",
	"##############",
};

char m5[15][15] = {
	"##############",
	"#E#          #",
	"# # ######## #",
	"# # #      # #",
	"# # # #### # #",
	"# # # #  # # #",
	"# # # #P # # #",
	"### # ## # # #",
	"# # # ## # # #",
	"# # #    # # #",
	"# # ###### # #",
	"# #        # #",
	"# ########## #",
	"#           E#",
	"##############",
};

TEST(TestTask, NoPlayerInMaze) {
	bool result;
	EXPECT_NO_THROW(result = CanMoveToExit(m2));
	EXPECT_FALSE(result);
}

TEST(TestTask, OneExitInMaze) {
	bool result;
	EXPECT_NO_THROW(result = CanMoveToExit(m1));
	EXPECT_TRUE(result);
}

TEST(TestTask, CanNotExitInMaze) {
	bool result;
	EXPECT_NO_THROW(result = CanMoveToExit(m3));
	EXPECT_FALSE(result);
}

TEST(TestTask, OneExitInMaze1) {
	bool result;
	EXPECT_NO_THROW(result = CanMoveToExit(m4));
	EXPECT_TRUE(result);
}

TEST(TestTask, TwoExitsInMaze) {
	bool result;
	EXPECT_NO_THROW(result = CanMoveToExit(m5));
	EXPECT_TRUE(result);
}