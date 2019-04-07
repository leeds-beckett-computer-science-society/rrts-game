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
#ifndef RRTS_LOGGER_H
#define RRTS_LOGGER_H

#include <iostream>
#include <vector>

// Define logger functions here for convenience
#define FATAL(x) rrts::User::Logger::error(x, __FILE__, __LINE__, true);
#define LOG(x) rrts::User::Logger::info(x);

namespace rrts
{
    namespace User
    {
        namespace Logger
	{
            /**
             * Displays an red coloured error plus the file and line, if fexit is true it will force quit the program
             * @param error
             * @param caller
             * @param line
             * @param fexit
             */
            void error(const std::string& error, const std::string& caller, int line, bool fexit = false);

            /**
             * Displays info text in green
             * @param info
             */
            void info(const std::string& info);

            /**
             * Flushes all logs into the terminal and exits if fatal error.
             */
            void flush();

	    namespace
	    {
	        bool fatal = false;
	        std::vector<std::string> log;
	    }
	};
    }
}

#endif //RRTS_LOGGER_H
