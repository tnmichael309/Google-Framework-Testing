#include <limits.h>
#include "hw1.h"
#include "gtest/gtest.h"

// Tests NextDate()
TEST(NextDateTest, WN) {

	// 閏年
	EXPECT_STREQ("4/2/29", NextDate(4,2,28));	
	EXPECT_STREQ("100/3/1", NextDate(100,2,28));
	EXPECT_STREQ("400/2/29", NextDate(400,2,28));
	
	
	// 大月
	EXPECT_STREQ("2015/1/31", NextDate(2015,1,30));
	EXPECT_STREQ("2015/2/1", NextDate(2015,1,31));
	
	// 小月
	EXPECT_STREQ("2015/4/30", NextDate(2015,4,29));
	EXPECT_STREQ("2015/5/1", NextDate(2015,4,30));
	
	// 連續大月
	EXPECT_STREQ("2015/7/31", NextDate(2015,7,30));
	EXPECT_STREQ("2015/8/1", NextDate(2015,7,31));
	
	EXPECT_STREQ("2015/8/31", NextDate(2015,8,30));
	EXPECT_STREQ("2015/9/1", NextDate(2015,8,31));
	
	// 12月
	EXPECT_STREQ("2015/12/31", NextDate(2015,12,30));
	EXPECT_STREQ("2016/1/1", NextDate(2015,12,31));
}

TEST(NextDateTest, WR) {
	
	// invalid year input
	EXPECT_STREQ("Invalid input", NextDate(-1,1,1));
	
	// invalid month input
	EXPECT_STREQ("Invalid input", NextDate(2015,0,1));
	EXPECT_STREQ("Invalid input", NextDate(2015,13,1));
	
	// invalid day input
	EXPECT_STREQ("Invalid input", NextDate(2015,1,32));
	EXPECT_STREQ("Invalid input", NextDate(2015,1,0));
	EXPECT_STREQ("Invalid input", NextDate(2015,4,31));
	EXPECT_STREQ("Invalid input", NextDate(2015,4,0));
	EXPECT_STREQ("Invalid input", NextDate(4,2,30));
	EXPECT_STREQ("Invalid input", NextDate(100,2,29));
	EXPECT_STREQ("Invalid input", NextDate(400,2,30));
	EXPECT_STREQ("Invalid input", NextDate(2015,2,29));
}

TEST(NextDateTest, SR) {
	
	// year + month
	EXPECT_STREQ("Invalid input", NextDate(-1,0,1));
	EXPECT_STREQ("Invalid input", NextDate(-1,13,1));
	
	// year + day
	EXPECT_STREQ("Invalid input", NextDate(-1,1,32));
	EXPECT_STREQ("Invalid input", NextDate(-1,1,0));
	EXPECT_STREQ("Invalid input", NextDate(-1,4,31));
	EXPECT_STREQ("Invalid input", NextDate(-1,4,0));
	
	// month + day
	EXPECT_STREQ("Invalid input", NextDate(2015,0,0));
	EXPECT_STREQ("Invalid input", NextDate(2015,0,32));
	EXPECT_STREQ("Invalid input", NextDate(2015,13,0));
	EXPECT_STREQ("Invalid input", NextDate(2015,13,32));
	
	
	// year + month + day
	EXPECT_STREQ("Invalid input", NextDate(-1,0,0));
	EXPECT_STREQ("Invalid input", NextDate(-1,0,32));
	EXPECT_STREQ("Invalid input", NextDate(-1,13,0));
	EXPECT_STREQ("Invalid input", NextDate(-1,13,32));
}




// Tests Triangle()
// weak normal test
TEST(TriangleTest, WN) {
	EXPECT_STREQ("Equilateral", Triangle(5,5,5));
	EXPECT_STREQ("Isosceles", Triangle(2,2,3));
	EXPECT_STREQ("Isosceles", Triangle(2,3,2));
	EXPECT_STREQ("Isosceles", Triangle(3,2,2));
	EXPECT_STREQ("Scalene", Triangle(3,4,5));
	EXPECT_STREQ("Scalene", Triangle(5,3,4));
	EXPECT_STREQ("Scalene", Triangle(3,5,4));
	EXPECT_STREQ("Non-special triangle", Triangle(3,4,6));
	EXPECT_STREQ("Not a triangle", Triangle(4,1,2));
	EXPECT_STREQ("Not a triangle", Triangle(1,4,2));
	EXPECT_STREQ("Not a triangle", Triangle(1,2,4));
}

// weak robust test
TEST(TriangleTest, WR) {
	EXPECT_STREQ("Invalid length input", Triangle(0,5,5));
	EXPECT_STREQ("Invalid length input", Triangle(5,0,5));
	EXPECT_STREQ("Invalid length input", Triangle(5,5,0));
}

// strong robust test
TEST(TriangleTest, SR) {
	EXPECT_STREQ("Invalid length input", Triangle(0,0,5));
	EXPECT_STREQ("Invalid length input", Triangle(5,0,0));
	EXPECT_STREQ("Invalid length input", Triangle(0,5,0));
	EXPECT_STREQ("Invalid length input", Triangle(0,0,0));
}

