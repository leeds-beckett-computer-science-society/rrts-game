/*
Copyright (C) 2019 Leeds Beckett Computer Science Society

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/
#ifndef RRTS_SESSIONTEST_HPP
#define RRTS_SESSIONTEST_HPP

#include <gtest/gtest.h>
#include <Session.h>

namespace
{
    class SessionTest : public ::testing::Test
    {
    protected:
	SessionTest()
	{
		// generate random number of each test
		randomNumber = rand();

		rrts::User::Session::getInstance()->setFPS(randomNumber);
	}

        int randomNumber;
    };

    TEST_F(SessionTest, session_frame_count)
    {
	    ASSERT_EQ(randomNumber, rrts::User::Session::getInstance()->getFPS());
	    SUCCEED();
    }
}


#endif //RRTS_SESSIONTEST_HPP
